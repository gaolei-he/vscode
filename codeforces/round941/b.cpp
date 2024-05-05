#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<char>> vec(n + 1, std::vector<char>(m + 1));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            std::cin >> vec[i][j];
        }
    }
    int cnt = 0;
    bool flag = true;
    for(int i=1;i<=m;i++) {
        if(vec[1][i] != vec[1][1]) {
            flag = false;
        }
    }
    if(flag) cnt ++;
    flag = true;
    for(int i=1;i<=m;i++) {
        if(vec[n][i] != vec[n][1]) {
            flag = false;
        }
    }
    if(flag) cnt ++;
    flag = true;
    for(int i=1;i<=n;i++) {
        if(vec[i][1] != vec[1][1]) {
            flag = false;
        }
    }
    if(flag) cnt ++;
    flag = true;
    for(int i=1;i<=n;i++) {
        if(vec[i][m] != vec[1][m]) {
            flag = false;
        }
    }
    if(flag) cnt ++;
    auto check = [&]() {
        if(vec[1][1] == vec[1][m] and vec[n][1] == vec[n][m] and vec[n][1] != vec[1][1]
        or vec[1][1] == vec[n][1] and vec[1][m] == vec[n][m] and vec[1][1] != vec[1][m]) {
            return true;
        }
        return false;
    };
    if(cnt == 2 and check()) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}