#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

constexpr ui64 P = 131;

class Node {
   private:
    std::vector<ui64> h1, h2;
    std::vector<ui64> p;
    int n;

   public:
    Node(std::string& s) {
        n = s.size();
        p.resize(s.size() + 1);
        h1.resize(s.size() + 1);
        h2.resize(s.size() + 1);
        p[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            p[i] = p[i - 1] * P;
            h1[i] = h1[i - 1] * P + s[i - 1];
        }
        std::reverse(s.begin(), s.end());
        for (int i = 1; i <= s.size(); i++) {
            h2[i] = h2[i - 1] * P + s[i - 1];
        }
    }
    ui64 get_hash(int l, int r, int op) {
        ui64 res;
        if (op == 0) {
            res = h1[r] - h1[l - 1] * p[r - l + 1];
        } else {
            res = h2[r] - h2[l - 1] * p[r - l + 1];
        }
        return res;
    }
    bool isHui(int l, int r) {
        ui64 v1, v2;
        if (l == 1) {
            v1 = get_hash(l, r, 0);
            v2 = get_hash(n - r + l, n, 1);
        } else if (r == n) {
            v1 = get_hash(l, r, 0);
            v2 = get_hash(1, 1 + r - l, 1);
        }
        return v1 == v2;
    }
    ui64 substr(int l, int r) { return get_hash(l, r, 0); }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::string s, t;
    std::cin >> s >> t;
    Node n1(s), n2(t);

    std::set<int> S;
    int ans = -1;
    for (int i = 1; i <= std::min(n, m); ++i) {
        if (n1.isHui(1, i) and n2.isHui(m - i + 1, m) and
            n1.substr(1, i) == n2.substr(m - i + 1, m)) {
            S.insert(i);
        }
    }
    for (int i = 1; i <= std::min(n, m); ++i) {
        if (n2.isHui(1, i) and n1.isHui(n - i + 1, n) and
            n2.substr(1, i) == n1.substr(n - i + 1, n)) {
            while (S.size() and (*S.rbegin() + i > n or *S.rbegin() + i > m)) {
                S.erase(*S.rbegin());
            }
            if (S.size()) {
                ans = std::max(ans, (i + *S.rbegin()) * 2);
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}