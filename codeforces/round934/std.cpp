#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

constexpr int N = 200'100;
constexpr int P = 233;
ui64 h[2][N], p[N];
char str[N * 4], tmp[N * 2];
int ne[N * 4];
void init(std::string& s) {
    str[0] = '$', str[1] = '#';
    int length1 = 2;
    for(int i=0;i<s.size();i++) {
        str[length1 ++] = s[i];
        str[length1 ++] = '#';
    }
    str[length1++] = '^';
    int mr = 0, ml = 0;
    for(int i=1;str[i]!='^';i++) {
        if(i < mr) ne[i] = std::min(ne[2*ml-i], mr-i);
        else ne[i] = 1;
        while(str[i + ne[i]] == str[i-ne[i]]) ne[i] ++;
        if(ne[i] + i > mr) {
            mr = ne[i] + i;
            ml = i;
        }
    }
}
void solve() {
    int n, q;
    std::cin >> n >> q;
    std::string s, t;
    std::cin >> s;
    init(s);
    t = s;
    std::reverse(t.begin(), t.end());
    t = " " + t;
    s = " " + s;
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * P;
        h[0][i] = h[0][i - 1] * P + s[i] - 'a';
        h[1][i] = h[1][i - 1] * P + t[i] - 'a';
    }
    auto get = [&](int l, int r, int op) {
        return h[op][r] - h[op][l - 1] * p[r - l + 1];
    };
    auto isSame = [&](int l, int r) {
        if (l == r) {
            return true;
        }
        if (get(l, r - 1, 0) == get(l + 1, r, 0) and s[r] == s[r - 1]) {
            return true;
        }
        return false;
    };
    auto is2Same= [&](int l, int r) {
        if(r - l < 2) {
            return true;
        }
        if (get(l, r - 2, 0) == get(l + 2, r, 0) and s[r] == s[r-2] and s[r-1] ==s[r-3]) {
            return true;
        }
        return false;
    };
    auto isHui = [&](int l, int r) {
        // return get(n - r + 1, n - l + 1, 1) == get(l, r, 0);
        int len = r - l + 1;
        l *= 2, r *= 2;
        int idx = l + r >> 1;
        if(ne[idx] - 1 >= len) {
            return true;
        }
        return false;
    };
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        i64 tn = r - l + 1;
        // std::cerr << get(n - r + 1, n - l + 1, 1) << " " << get(l, r, 0) <<
        // "\n";
        if (isSame(l, r)) {
            std::cout << 0 << "\n";
        } else if (is2Same(l, r)) {
            std::cout << (1 + tn / 2) * (tn / 2) << "\n";
        } else if (isHui(l, r)) {
            std::cout << (tn + 1) * (tn - 2) / 2 << "\n";
        } else {
            std::cout << (tn + 2) * (tn - 1) / 2 << "\n";
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