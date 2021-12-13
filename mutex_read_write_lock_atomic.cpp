#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <vector>

// https://shengyu7697.github.io/std-atomic/
// https://zh.wikipedia.org/wiki/%E8%AF%BB%E5%86%99%E9%94%81

class Candidate {
public:
    enum Mode
    {
        NONE = 0,
        MUTEX,
        READ_WRITE_LOCK,
        ATOMIC
    };

    Candidate(int m) : votes(0), mode(Mode(m)) {}

    void increase() {
        switch(mode) {
            case NONE:
                votes++;
                break;
            case MUTEX:
                increaseMutex();
                break;
            case READ_WRITE_LOCK:
                increaseReadWriteLock();
                break;
            case ATOMIC:
                votes_atomic++;
                break;
        }
    }

    void decrease() {
        switch(mode) {
            case NONE:
                votes--;
                break;
            case MUTEX:
                decreaseMutex();
                break;
            case READ_WRITE_LOCK:
                decreaseReadWriteLock();
                break;
            case ATOMIC:
                votes_atomic--;
        }
    }

    int getVotes() {
        switch(mode) {
            case NONE:
                return votes;
            case MUTEX:
                return getVotesMutex();
            case READ_WRITE_LOCK:
                return getVotesReadWriteLock();
            case ATOMIC:
                return votes_atomic;
        }
    }

private:
    void increaseMutex() {
        std::lock_guard<std::mutex> lck(mtx);
        votes++;
    }

    void decreaseMutex() {
        std::lock_guard<std::mutex> lck(mtx);
        votes--;
    }

    int getVotesMutex() {
        std::lock_guard<std::mutex> lck(mtx);
        return votes;
    }

    void increaseReadWriteLock() {
        std::unique_lock lck(shared_mtx);
        votes++;
    }

    void decreaseReadWriteLock() {
        std::unique_lock lck(shared_mtx);
        votes--;
    }

    int getVotesReadWriteLock() {
        std::shared_lock lck(shared_mtx);
        return votes;
    }

    Mode                      mode;
    int                       votes;
    std::atomic<int>          votes_atomic;
    mutable std::mutex        mtx;
    mutable std::shared_mutex shared_mtx;
};

void upvote(Candidate* cand) {
    for(size_t i = 0; i < 100000; ++i) {
        cand->increase();
    }
}

void downvote(Candidate* cand) {
    for(size_t i = 0; i < 100000; ++i) {
        cand->decrease();
    }
}

int main() {
    size_t                   n = 100;
    std::vector<std::thread> threads;

    std::chrono::duration<double, std::milli> elapsed;

    for(size_t m = 0; m < 4; ++m) {
        Candidate* cand = new Candidate(m);

        auto start = std::chrono::high_resolution_clock::now();
        threads    = std::vector<std::thread>(n);

        for(size_t i = 0; i < n / 2; ++i) {
            threads[i * 2]     = std::thread(upvote, cand);
            threads[i * 2 + 1] = std::thread(downvote, cand);
        }

        for(size_t i = 0; i < n; ++i) {
            threads[i].join();
        }

        auto end = std::chrono::high_resolution_clock::now();
        elapsed  = end - start;
        std::cout << "result: " << cand->getVotes() << std::endl;
        std::cout << "total: " << elapsed.count() << " ms" << std::endl;

        delete cand;
    }

    return 0;
}

/*
result: 22884
total: 231.166 ms
result: 0
total: 549.761 ms
result: 0
total: 570.361 ms
result: 0
total: 424.163 ms
*/
