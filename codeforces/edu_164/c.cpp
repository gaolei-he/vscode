#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string a, b;
    std::cin >> a >> b;
    bool flag = true;
    for (int i = 0; i < a.size(); i++)
    {
        if(flag and a[i] != b[i]) {
            flag = false;
            if(a[i] < b[i]) {
                std::swap(a[i], b[i]);
            }
        } else if(!flag and a[i] != b[i]) {
            if(a[i] > b[i]) {
                std::swap(a[i], b[i]);
            }
        }
    }
    std::cout << a << "\n" << b << "\n";
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