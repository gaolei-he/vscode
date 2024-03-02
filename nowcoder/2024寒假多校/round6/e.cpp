#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;
    int x = std::stoi(s.substr(2));
    std::cin >> s;
    int l = 0, r = 0;
    for(auto c : s) {
        if (c == 'R') {
            l += 1;
        } else if(c == 'P') {
            r += 1;
        }
        if(l > x / 2 ){
            std::cout << "kou!\n" << l + r << "\n";
            return 0;
        } else if (r > x / 2) {
            std::cout << "yukari!\n" << l + r << "\n";
            return 0;
        }
    }
    std::cout << "to be continued.\n" << l + r << "\n";
    return 0;
}