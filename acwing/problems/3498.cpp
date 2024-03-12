#include <iostream>
#include <unordered_map>
std::unordered_map<std::string, int> mp;
void init() {
    int y = 0, m = 1, d = 1;
    int days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int id = 0;
    while (y != 400) {
        if (y % 100 != 0 and y % 4 == 0 or y % 400 == 0) {
            days[2] = 29;
        } else {
            days[2] = 28;
        }
        if (d < days[m]) {
            d += 1;
        } else if (m < 12) {
            m += 1;
            d = 1;
        } else {
            y += 1;
            m = 1;
            d = 1;
        }
        std::string key = std::to_string(y) + " " + std::to_string(m) + " " +
                          std::to_string(d);
        mp[key] = id;
        id += 1;
    }
}
int count(int year, int month, int day) {
    int res = year / 400 * 146097;
    year -= year / 400 * 400;
    std::string key = std::to_string(year) + " " + std::to_string(month) + " " +
                      std::to_string(day);
    res += mp[key];
    return res;
}

void solve(std::string& a, std::string& b) {
    int y1 = std::stoi(a.substr(0, 4));
    int m1 = std::stoi(a.substr(4, 2));
    int d1 = std::stoi(a.substr(6, 2));
    int y2 = std::stoi(b.substr(0, 4));
    int m2 = std::stoi(b.substr(4, 2));
    int d2 = std::stoi(b.substr(6, 2));

    int v1 = count(y1, m1, d1);
    int v2 = count(y2, m2, d2);
    // std::cerr << v1 << " " << v2 << "\n";
    std::cout << v2 - v1 + 1 << "\n";
}

int main() {
    init();
    std::string a, b;
    while (std::cin >> a >> b) {
        if (a > b) {
            std::swap(a, b);
        }
        solve(a, b);
    }
    return 0;
}