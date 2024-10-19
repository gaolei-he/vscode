#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<std::string, double>> ans;

    while (n--) {
        int k;
        std::string s;
        std::cin >> k >> s;
        int score = 0, grade = 0;
        int core_score = 0, core_grade = 0;
        double total = 0;

        std::unordered_set<std::string> st;
        while (k--) {
            std::string s1, s4;
            int s2, s3, s5;
            std::cin >> s1 >> s2 >> s3 >> s4 >> s5;
            if (s4.substr(0, 3) == "tsk" or st.count(s1)) {
                continue;
            }
            score += s2 * s3;
            grade += s3;
            if (s5) {
                core_score += s2 * s3;
                core_grade += s3;
            }
            st.insert(s1);
        }
        total += score * grade * 0.9 / grade;
        total += core_score * core_grade * 0.02 / core_grade;
        int t;
        std::cin >> t;
        double v1 = 0, v2 = 0;
        while (t--) {
            int op;
            std::cin >> op;
            if (op == 1) {
                v1 += 2.0;
            } else if (op == 2) {
                v1 += 1.8;
            } else if (op == 3) {
                v1 += 1.6;
            } else if (op == 4) {
                v1 += 0.8;
            } else if (op == 5) {
                v1 += 0.6;
            } else if (op == 6) {
                v1 += 0.3;
            }
        }
        v1 = std::min(4.8, v1);
        int tmp;
        std::cin >> tmp;
        if (tmp >= 150 and tmp < 200) {
            v2 += 0.4;
        } else if (tmp >= 200 and tmp < 300) {
            v2 += 0.8;
        } else if (tmp >= 300 and tmp < 400) {
            v2 += 1.5;
        } else if (tmp >= 400 and tmp < 450) {
            v2 += 3.2;
        } else if (tmp >= 450) {
            v2 += 4.8;
        }
        std::cin >> tmp;
        if (tmp == 1) {
            v2 += 0.4;
        } else if (tmp == 2) {
            v2 += 0.8;
        }

        v2 = std::min(4.8, v2);
        total += std::min(6.0, v1 + v2);
        std::cin >> tmp;
        if (tmp) {
            total += 2;
        }

        ans.emplace_back(s, total);
    }

    std::sort(ans.begin(), ans.end(),
              [](auto a, auto b) { return a.second > b.second; });
    for (auto &[x, y] : ans) {
        std::cout << x << "\n";
    }

    return 0;
}