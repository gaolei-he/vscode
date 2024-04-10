#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    i64 k;
    std::cin >> n >> k;
    std::deque<int> dq;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        dq.push_back(x);
    }

    i64 front = k / 2 + k % 2, back = k / 2;
    while(dq.size() and front) {
        if(front >= dq.front()) {
            front -= dq.front();
            dq.pop_front();
        } else {
            dq.front() -= front;
            front = 0;
        }
    }
    while(dq.size() and back) {
        if(back >= dq.back()) {
            back -= dq.back();
            dq.pop_back();
        } else {
            dq.back() -= back;
            back = 0;
        }
    }
    std::cout << n - dq.size() << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}