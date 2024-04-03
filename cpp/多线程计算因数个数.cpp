#include <atomic>
#include <iostream>
#include <queue>
#include <thread>
#include <vector>
#include <mutex>
constexpr int size = 1'000'000'0;


std::atomic<int> counter(0);
std::atomic<int> ans(0);


/*
size = 1e7
real    0m24.809s
user    6m34.156s
sys     0m0.494s
*/
std::mutex mtx;
int now, mx;
void count_factors2() {
    while (true) {
        int n;
        std::unique_lock<std::mutex> lck(mtx);
        if(now > size) {
            return;
        }
        n = ++ now;
        lck.unlock();
        int res = 0;
        for (int i=2;i<=n/i;i++) {
            if(n % i == 0) {
                res += 1;
                if(n / i != i) {
                    res += 1;
                }
            }
        }

        lck.lock();
        mx = std::max(res, mx);
    }
}


/*
size = 1e7
real    0m24.798s
user    6m35.429s
sys     0m0.042s
*/
void count_factors1() {
    while (counter < size) {
        int res = 0;
        counter++;
        int n = counter;
        for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                res += 1;
                if (n / i != i) {
                    res += 1;
                }
            }
        }
        if (ans < res) {
            ans = res;
        }
    }
}

int main() {
    std::vector<std::thread> vec;
    for (int i = 0; i < 1; i++) {
        vec.emplace_back(count_factors1);
    }
    for (auto &th : vec) {
        th.join();
    }
    std::cout << ans << std::endl;
    return 0;
}