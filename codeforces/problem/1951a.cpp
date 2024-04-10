#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int cnt = 0;
    int v1 = -1, v2 = -1;
    for(int i=0;i<n;i++) {
        char c = s[i];
        if(c == '1') {
            if(v1 == -1) {
                v1 = i;
            } else if(v2 == -1) {
                v2 = i;
            }
            cnt += 1;
        }
    }
    if(cnt % 2 == 0 and cnt > 2 or cnt == 2 and v1 + 1 != v2 or cnt == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

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