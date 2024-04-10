#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    int ans = 0;
    std::vector<std::unordered_set<int>> vec(n);
    for (auto &st : vec) {
        int cnt;
        std::cin >> cnt;
        while (cnt--) {
            int x;
            std::cin >> x;
            st.insert(x);
        }
    }
    for (int i = 1; i <= m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if(vec[j].count(i)) {
                cnt ++;
            } else {
                ans ^= cnt;
                cnt = 0;
            }
        }
        ans ^= cnt;
    }
    std::cout << (ans ? "Alice\n" : "Bob\n");
    return 0;
}