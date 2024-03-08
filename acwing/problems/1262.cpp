#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> vec(n, std::vector<int>(3));
    for (auto &v : vec) {
        std::cin >> v[0];
    }
    for (auto &v : vec) {
        std::cin >> v[1];
    }
    for (int i = 0; i < n - 1; i++) {
        std::cin >> vec[i][2];
    }
    int T;
    std::cin >> T;

    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    int cnt = 0;
    int ans = 0, sm = 0;
    std::vector<int> res;
    for (int i = 0; i < n; ++i) {
        int v = vec[i][0];
        while (v > 0) {
            res.emplace_back(v);
            v -= vec[i][1];
        }
        while (vec[i][2]--) {
            res.emplace_back(0);
        }
    }

    for (int i = 0; i < res.size(); i++) {
        if(res[i] == 0) {
            cnt += 1;
        } else {
            sm += res[i];
            q.push(res[i]);
        }
        if(cnt > T) {
            break;
        }
        while(q.size() and q.size() + cnt > T) {
            sm -= q.top();
            q.pop();
        }
        ans = std::max(ans, sm);
    }
    std::cout << ans << std::endl;

    return 0;
}