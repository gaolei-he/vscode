#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 0x3f3f3f3f;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> vec(1, inf);

    while (n--) {
        int x;
        std::cin >> x;
        vec.emplace_back(x);
        vec.emplace_back(inf);
    }
    vec[0] = vec[1] - 1;
    for (int i = 2; i < vec.size() - 1; i += 2) {
        vec[i] = std::min(vec[i - 1] - vec[i - 2] - 1, vec[i + 1] - 1);
    }
    vec.back() = vec[vec.size() - 2] - vec[vec.size() - 3] - 1;
    i64 ans = 0;
    for(int i=0;i<vec.size();i+=2) {
        // std::cout << vec[i] << ' ';
        ans += vec[i];
    }
    std::cout << ans << std::endl;
    return 0;
}