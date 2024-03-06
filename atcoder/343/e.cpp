#include <bits/stdc++.h>

using i64 = long long;

int v1, v2, v3;
int a[7];
bool check(int x1, int y1, int z1, int x2, int y2, int z2) {
    memset(a, 0, sizeof(a));
    for (int x = 1; x <= 7; x++) {
        for (int y = 1; y <= 7; y++) {
            for (int z = 1; z <= 7; z++) {
                bool flag1 = x > x1 and x <= x1 + 7 and y > y1 and
                             y <= y1 + 7 and z > z1 and z <= z1 + 7;
                bool flag2 = x > x2 and x <= x2 + 7 and y > y2 and
                             y <= y2 + 7 and z > z2 and z <= z2 + 7;
                if (flag1 and flag2) {
                    a[6] += 1;
                } else if (flag1) {
                    a[3] += 1;
                } else if (flag2) {
                    a[4] += 1;
                } else {
                    a[0] += 1;
                }
            }
        }
    }
    for (int x = x1 + 1; x <= x1 + 7; x++) {
        for (int y = y1 + 1; y <= y1 + 7; y++) {
            for (int z = z1 + 1; z <= z1 + 7; z++) {
                bool flag1 =
                    x > 0 and x <= 7 and y > 0 and y <= 7 and z > 0 and z <= 7;
                bool flag2 = x > x2 and x <= x2 + 7 and y > y2 and
                             y <= y2 + 7 and z > z2 and z <= z2 + 7;
                if (flag1 and flag2) {
                    a[6] += 1;
                } else if (flag1) {
                    a[3] += 1;
                } else if (flag2) {
                    a[5] += 1;
                } else {
                    a[1] += 1;
                }
            }
        }
    }
    for (int x = x2 + 1; x <= x2 + 7; x++) {
        for (int y = y2 + 1; y <= y2 + 7; y++) {
            for (int z = z2 + 1; z <= z2 + 7; z++) {
                bool flag1 =
                    x > 0 and x <= 7 and y > 0 and y <= 7 and z > 0 and z <= 7;
                bool flag2 = x > x1 and x <= x1 + 7 and y > y1 and
                             y <= y1 + 7 and z > z1 and z <= z1 + 7;
                if (flag1 and flag2) {
                    a[6] += 1;
                } else if (flag1) {
                    a[4] += 1;
                } else if (flag2) {
                    a[5] += 1;
                } else {
                    a[2] += 1;
                }
            }
        }
    }
    // if(x1 == 6 and y1 == 6 and z1 == 6 and x2 == 13 and y2 == 13 and z2 == 13) {
    //     for(int i=0;i<7;i++) {
    //         std::cerr << a[i] << ' ';
    //     }
    // }
    if (a[0] + a[1] + a[2] == v1 and a[3] + a[4] + a[5] == v2 * 2 and
        a[6] == v3 * 3) {
        std::cout << "Yes\n";
        std::cout << "0 0 0 " << x1 << " " << y1 << " " << z1 << " " << x2
                  << " " << y2 << " " << z2 << "\n";
        return true;
    }
    return false;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> v1 >> v2 >> v3;
    for (int x1 = 0; x1 <= 7; x1++) {
        for (int y1 = 0; y1 <= 7; y1++) {
            for (int z1 = 0; z1 <= 7; z1++) {
                for (int x2 = 0; x2 <= 7; x2++) {
                    for (int y2 = 0; y2 <= 7; y2++) {
                        for (int z2 = 0; z2 <= 7; z2++) {
                            if (check(x1, y1, z1, x2, y2, z2)) {
                                return 0;
                            }
                        }
                    }
                }
                for (int x2 = x1; x2 <= x1 + 7; x2++) {
                    for (int y2 = y1; y2 <= y1 + 7; y2++) {
                        for (int z2 = z1; z2 <= z1 + 7; z2++) {
                            if (check(x1, y1, z1, x2, y2, z2)) {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << "No\n";
    return 0;
}