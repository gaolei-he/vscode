#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> ans;
    for(int i=0;i<n*2;i++) {
        ans.push_back("");
        char op;
        if(i % 4 < 2) {
            op = '#';
        } else {
            op = '.';
        }
        for(int j=0;j<n;j++) {
            ans.back().push_back(op);
            ans.back().push_back(op);
            if(op == '#') {
                op = '.';
            } else {
                op = '#';
            }
        }
    }
    for(auto &s : ans) {
        std::cout << s << "\n";
    }
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