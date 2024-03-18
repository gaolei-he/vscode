#include <bits/stdc++.h>

using i64 = long long;

class Node {
   private:
    using ui64 = unsigned long long;
    using i64 = long long;
    std::string s;
    int P1 = 131, P2 = 11311;
    ui64 mod = 1'000'000'007;
    std::vector<ui64> h1, h2, p1;
    std::vector<i64> h3, h4, p2;
    int n;

   public:
    Node(const std::string& s) {
        this->s = s;
        n = s.size();
        h1.resize(n + 1);
        h2.resize(n + 1);
        h3.resize(n + 1);
        h4.resize(n + 1);
        p1.resize(n + 1);
        p2.resize(n + 1);
        p1[0] = p2[0] = 1;
        for (int i = 1; i <= n; i++) {
            h1[i] = h1[i - 1] * P1 + s[i - 1];
            p1[i] = p1[i - 1] * P1;

            h3[i] = h3[i - 1] * P2 % mod + s[i - 1];
            h3[i] %= mod;
            p2[i] = p2[i - 1] * P2;
            p2[i] %= mod;
        }
        for (int i = n; i > 0; i--) {
            h2[n - i + 1] = h2[n - i] * P1 + s[i - 1];

            h4[n - i + 1] = h4[n - i] * P2 % mod + s[i - 1];
            h4[n - i + 1] %= mod;
        }
    }
    std::pair<ui64, i64> get(int l, int r, int op = 0) {
        ui64 v1 = h1[r] - h1[l - 1] * p1[r - l + 1];
        i64 v3 = (h3[r] - h3[l - 1] * p2[r - l + 1] % mod + mod) % mod;
        int tl = n - r + 1, tr = n - l + 1;
        ui64 v2 = h2[tr] - h2[tl - 1] * p1[tr - tl + 1];
        i64 v4 = (h4[tr] - h4[tl - 1] * p2[tr - tl + 1] % mod + mod) % mod;
        if (!op) {
            return std::make_pair(v1, v3);
        }
        std::cerr << l << " " << r << " " << tl << " " << tr << "\n";
        // std::cerr << v1 << " " << v2 << "\n";
        return std::make_pair(v2, v4);
    }
    bool isSame(int l, int r) {
        if (l == r) {
            return true;
        }

        if (get(l, r - 1) == get(l + 1, r) and s[r - 1] == s[r - 2]) {
            return true;
        }
        return false;
    }
    bool is2Same(int l, int r) {
        if (r - l == 2 and s[r - 1] == s[r - 3] or r - l < 2) {
            return true;
        }

        if (get(l, r - 2) == get(l + 2, r) and s[r - 1] == s[r - 3] and
            s[r - 2] == s[r - 4]) {
            return true;
        }
        return false;
    }
    bool isHui(int l, int r) { return get(l, r) == get(l, r, 1); }
};

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    Node node(s);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        i64 val = r - l + 1;
        if (node.isSame(l, r)) {
            std::cout << 0 << "\n";
        } else if (node.is2Same(l, r)) {
            std::cout << (1 + val / 2) * (val / 2) << "\n";
        } else if (node.isHui(l, r)) {
            std::cout << (val + 1) * (val - 2) / 2 << "\n";
        } else {
            std::cout << (val + 2) * (val - 1) / 2 << "\n";
        }
    }
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