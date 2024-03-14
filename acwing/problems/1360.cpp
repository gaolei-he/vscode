#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> ans;
    ans.emplace_back(0, 1);
    ans.emplace_back(1, 1);
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            if(std::gcd(i, j) == 1) {
                ans.emplace_back(j, i);
            }
        }
    }
    sort(ans.begin(), ans.end(), [](auto a, auto b) {
        int v1 = a.first * b.second;
        int v2 = b.first * a.second;
        return v1 < v2;
    });
    for(auto [x, y] : ans) {
        std::cout << x << "/" << y << "\n";
    }

    return 0;
}