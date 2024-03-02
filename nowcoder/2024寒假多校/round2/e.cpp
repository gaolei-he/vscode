#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int ans = 0;
    std::deque<int> dq;
    while(n --) {
        int x;
        std::cin >> x;
        dq.push_back(x);
    }

    while(!dq.empty()) {
        int x = dq.front();
        dq.pop_front();
        if(!dq.empty() and dq.front() != x) {
            dq.push_front(x);
            break;
        }
        ans += 1;
    }

    int lst = -1;
    if(!dq.empty()) {
        lst = dq.back();
    }
    while(!dq.empty()) {
        if (lst != dq.back()) {
            dq.pop_back();
            if(!dq.empty()) lst = dq.back();
            ans += 1;
            continue;
        }
        dq.pop_back();
        if(dq.empty()) ans += 1;
    }

    std::cout << ans << "\n";

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