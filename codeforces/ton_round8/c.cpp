#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, x, y;
    std::cin >> n >> x >> y;
    std::vector<int> vec(x);
    for (auto &v : vec) {
        std::cin >> v;
    }
    std::sort(vec.begin(), vec.end());
    int ans = 0, cnt = 0;
    if (x == 2) {
        if (vec.back() - vec.front() == 2) {
            ans += 1;
        }
        if ((vec.back() + 2) % n == vec.front()) {
            ans += 1;
        }
    } else if (x % 2 == 0) {
        for (int i = 0; i < vec.size(); i += 2) {
            int v1 = vec[i], v2 = vec[i + 1], v3 = vec[(i + 2) % x];
            if(v3 == vec.front()) {
                v3 += n;
            }
            if (v1 + 1 == v2 and v2 + 1 == v3) {
                ans += 1;
                cnt += 1;
            } else if (v1 + 1 == v2 and v2 + 2 == v3) {
                ans += 2;
                cnt += 1;
            } else if (v1 + 1 == v2 and v2 + 2 < v3) {
                ans += 1;
                cnt += 1;
            } else if (v1 + 2 == v2 and v2 + 1 == v3) {
                ans += 2;
                cnt += 1;
            } else if (v1 + 2 == v2 and v2 + 2 == v3) {
                ans += 2;
                cnt += 2;
            } else if (v1 + 2 == v2 and v2 + 2 < v3) {
                ans += 1;
                cnt += 2;
            } else if (v1 + 2 < v2 and v2 + 1 == v3) {
                ans += 1;
                cnt += 1;
            } else if (v1 + 2 < v2 and v2 + 2 == v3) {
                ans += 2;
                cnt += 1;
            } else if (v1 + 2 < v2 and v2 + 2 < v3) {
                cnt += 2;
            }
            // std::cerr << v1 << " " << v2 << " " << v3 << "\n";
            // std::cerr << ans << "\n";
        }
        ans += cnt - 2;
    } else {
        cnt = 1;
        for (int i = 0; i < vec.size() - 1; i += 2) {
            int v1 = vec[i], v2 = vec[i + 1], v3 = vec[(i + 2) % x];
            if(v3 == vec.front()) {
                v3 += n;
            }
            if (v1 + 1 == v2 and v2 + 1 == v3) {
                ans += 1;
                cnt += 1;
            } else if (v1 + 1 == v2 and v2 + 2 == v3) {
                ans += 2;
                cnt += 1;
            } else if (v1 + 1 == v2 and v2 + 2 < v3) {
                ans += 1;
                cnt += 1;
            } else if (v1 + 2 == v2 and v2 + 1 == v3) {
                ans += 2;
                cnt += 1;
            } else if (v1 + 2 == v2 and v2 + 2 == v3) {
                ans += 2;
                cnt += 2;
            } else if (v1 + 2 == v2 and v2 + 2 < v3) {
                ans += 1;
                cnt += 2;
            } else if (v1 + 2 < v2 and v2 + 1 == v3) {
                ans += 1;
                cnt += 1;
            } else if (v1 + 2 < v2 and v2 + 2 == v3) {
                ans += 2;
                cnt += 1;
            } else if (v1 + 2 < v2 and v2 + 2 < v3) {
                cnt += 2;
            }
            // std::cerr << v1 << " " << v2 << " " << v3 << "\n";
            // std::cerr << ans << "\n";
        }
        ans += cnt - 2;
        if ((vec.back() + 2) % n == vec.front()) {
            ans += 1;
        }
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