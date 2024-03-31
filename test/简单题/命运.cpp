#include <bits/stdc++.h>

using i64 = long long;

int mx;
std::queue<int> buffer;
std::mutex mtx;
void f() {
    int i;
    while (true) {
        std::unique_lock<std::mutex> lck(mtx);
        if(buffer.empty()) {
            return;
        }
        i = buffer.front();
        buffer.pop();
        lck.unlock();
        int cnt = 0;
        for (int j = 2; j <= i / j; j++) {
            if (i % j == 0) {
                cnt++;
            }
            if (i % j == 0 and i / j != j) {
                cnt++;
            }
        }
        lck.lock();
        mx = std::max(mx, cnt);
        lck.unlock();
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 2; i <= 10000000; i++) {
        buffer.push(i);
    }
    std::cout << "buffer input complete" << std::endl;
    std::vector<std::thread> consumers;
    for (int i = 0; i < 16; i++) {
        consumers.emplace_back(f);
    }
    for(auto &th : consumers) {
        th.join();
    }
    std::cout << mx << "\n";

    return 0;
}