#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<std::string, std::string>> vec;
    for(int i=0;i<n;i++) {
        std::string a, b;
        std::cin >> a >> b;
        vec.emplace_back(a, b);
    }
    std::sort(vec.begin(), vec.end());
    int q;
    std::cin >> q;
    while(q --) {
        std::string s;
        std::cin >> s;
        std::pair<std::string, std::string> val = {s, ""};
        auto it = std::lower_bound(vec.begin(), vec.end(), val);
        if(it == vec.end()) {
            std::cout << "-1 -1\n";
        } else {
            std::cout << it->first << " " << it->second << "\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}