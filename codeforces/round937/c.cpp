#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int h = std::stoi(s.substr(0, 2));
    int m = std::stoi(s.substr(3, 2));
    if(h > 12) {
        h -= 12;
        s = "PM";
    } else if(h == 12){
        s = "PM";
    } else {
        s = "AM";
    }
    if(h == 0) {
        h = 12;
    }
    std::cout << std::setw(2) << std::setfill('0') << h << ":";
    std::cout << std::setw(2) << std::setfill('0') << m << " " << s << "\n";
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