#include <bits/stdc++.h>

using i64 = long long;

void solve(int t) {
    int n, x, y;
    std::cin >> n >> x >> y;
    std::vector<int> vec(x);
    for (auto &v : vec) {
        std::cin >> v;
    }
    std::sort(vec.begin(), vec.end());
    std::vector<int> rec;
    i64 ans = 0, cnt = 0;
    if (x == 2) {
        if (vec.back() - vec.front() == 2) {
            ans += 1;
        }
        rec.push_back(vec.back() - vec.front());
        if ((vec.back() + 2) % n == vec.front()) {
            ans += 1;
        }
        rec.push_back(vec.front() + n - vec.back());
    } else if (x % 2 == 0) {
        for (int i = 0; i < vec.size(); i += 2) {
            int v1 = vec[i], v2 = vec[i + 1], v3 = vec[(i + 2) % x];
            if (v3 == vec.front()) {
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
            rec.push_back(v3 - v2);
            rec.push_back(v2 - v1);
            // std::cerr << v1 << " " << v2 << " " << v3 << "\n";
            // std::cerr << ans << "\n";
        }
        ans += cnt - 2;
    } else {
        cnt = 1;
        for (int i = 0; i < vec.size() - 1; i += 2) {
            int v1 = vec[i], v2 = vec[i + 1], v3 = vec[(i + 2) % x];
            if (v3 == vec.front()) {
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
            rec.push_back(v3 - v2);
            rec.push_back(v2 - v1);
            // std::cerr << v1 << " " << v2 << " " << v3 << "\n";
            // std::cerr << ans << "\n";
        }
        ans += cnt - 2;
        rec.push_back(vec.front() + n - vec.back());
        if ((vec.back() + 2) % n == vec.front()) {
            ans += 1;
        }
    }
    for(auto &x : rec) {
        x -= 1;
    }
    std::sort(rec.begin(), rec.end(), [](int a, int b) {
        if((a & 1) and (b & 1)) {
            return a < b;
        } else if(a & 1) {
            return true;
        } else if(b & 1) {
            return false;
        } else {
            return a < b;
        }
    });

    for(auto x : rec) {
        if(x < 2) {
            continue;
        }
        if(y >= x / 2) {
            ans += x;
            y -= x / 2;
        } else {
            ans += y * 2;
            y = 0;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}