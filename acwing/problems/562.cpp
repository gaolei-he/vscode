#include <bits/stdc++.h>

using i64 = long long;

void solve(int id) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> sm(n + 1);
    for(int i=1;i<=n;++i) {
        sm[i] = sm[i - 1] + s[i-1] - '0';
    }
    int k = n / 2 + n % 2;
    int B = 0;
    for(int i=1;i<=n-k+1;++i) {
        B = std::max(B, sm[i+k-1]-sm[i-1]);
    }
    std::cout << "Case #" << id << ": " << B << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    for(int i=1;i<=t;++i) {
        solve(i);
    }

    return 0;
}