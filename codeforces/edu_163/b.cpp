#include <bits/stdc++.h>

using i64 = long long;
std::string data = "AB";
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for(auto &x : vec) {
        std::cin >> x;
    }
    int mx = 100;
    while(vec.size()) {
        if(vec.back() <= mx) {
            mx = vec.back();
            vec.pop_back();
        } else {
            auto v = vec.back();
            vec.pop_back();
            if(v < 10) {
                std::cout << "NO\n";
                return;
            }
            int v1 = v / 10, v2 = v % 10;
            if(v2 < v1 or mx < v2) {
                std::cout << "NO\n";
                return;
            }
            mx = v1;
        }
    }
    std::cout << "YES\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}