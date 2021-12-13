#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

// https://shengyu7697.github.io/std-atomic/

class Candidate {
public:
    enum Mode
    {
        NONE = 0,
        MUTEX,
        ATOMIC
    };

    Candidate(int m) : votes(0), mode(Mode(m)) {}

    void increase() {
        switch(mode) {
            case 0:
                votes++;
                break;
            case 1:
                increaseMutex();
                break;
            case 2:
                votes_atomic++;
        }
    }

    void decrease() {
        switch(mode) {
            case 0:
                votes--;
                break;
            case 1:
                decreaseMutex();
                break;
            case 2:
                votes_atomic--;
        }
    }

    int getVotes() {
        switch(mode) {
            case 0:
            case 1:
                return votes;
            case 2:
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

    Mode               mode;
    int                votes;
    std::atomic<int>   votes_atomic;
    mutable std::mutex mtx;
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

    for(size_t m = 0; m < 3; ++m) {
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
result: 248590
total: 217.507 ms
result: 0
total: 712.404 ms
result: 0
total: 525.8 ms
*/
