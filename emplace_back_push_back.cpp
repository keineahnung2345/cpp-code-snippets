#include <iostream>
#include <vector>

long get_time(){
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    );
    return ms.count();
}

int main(){
    std::vector<int*> v;
    long long N = 10000000;

    long start, end;

    start = get_time();
    for(size_t i = 0; i < N; i++){
        int x = 0;
        v.push_back(&x); 
    }
    end = get_time();
    std::cout << "it takes: " << end - start << " milliseconds." << std::endl;

    v.clear();

    start = get_time();
    for(size_t i = 0; i < N; i++){
        int x = 0;
        v.emplace_back(&x); 
    }
    end = get_time();
    std::cout << "it takes: " << end - start << " milliseconds." << std::endl;

    return 0;
}

/*
it takes: 636 milliseconds.
it takes: 328 milliseconds.
*/
