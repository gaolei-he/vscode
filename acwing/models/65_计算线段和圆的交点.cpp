// https://ac.nowcoder.com/acm/contest/67746/H
#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128;

i128 dist(i64 x1, i64 y1, i64 x2, i64 y2) {
    return ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int calc(i64 x1, i64 y1, i64 x2, i64 y2, i64 x, i64 y, i64 r) {
    bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
    if (dist(x1, y1, x, y) < r * r) flag1 = true;  // 圆内
    if (dist(x2, y2, x, y) < r * r) flag2 = true;
    if (dist(x1, y1, x, y) == r * r) flag3 = true;  // 圆上
    if (dist(x2, y2, x, y) == r * r) flag4 = true;
    if (flag1 and flag2) {
        return 0;  // 两点都在圆内
    } else if (flag1 or flag2) {
        return 1;  // 一点在圆内，一点不在，必有一个交点
    }

    i128 A = dist(x1, y1, x2, y2) * r * r;
    // 叉乘结果的值替代absinθ
    i128 B = (x1 - x) * (y2 - y) - (x2 - x) * (y1 - y);
    B = B * B;
    // 圆心到直线距离大于半径，肯定没有交点
    if (B > A) {
        return 0;
    }

    i128 angle1 = (x - x1) * (x2 - x1) + (y - y1) * (y2 - y1);
    i128 angle2 = (x - x2) * (x1 - x2) + (y - y2) * (y1 - y2);

    // 如果两个角都是锐角，说明此时直线和圆的关系是相切或相交
    if (angle1 > 0 and angle2 > 0) {
        if (A == B) {
            return 1;  // 相切
        } else {
            return 2;  // 相交
        }
    } else {
        // 否则如果存在至少一个圆上的点也可以说明是有一个交点的
        if (flag3 or flag4) {
            return 1;
        } else {
            return 0;  // 相离
        }
    }
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 x, y, r;
    std::cin >> x >> y >> r;
    int n;
    std::cin >> n;
    std::vector<std::pair<i64, i64>> points(n);
    for (auto &[x, y] : points) {
        std::cin >> x >> y;
    }

    i64 cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x1 = points[i].first, y1 = points[i].second;
        if (r * r == (x - x1) * (x - x1) + (y - y1) * (y - y1)) {
            cnt -= (n - 1) * 1ll * (n - 2) / 2;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cnt += (n - 2) * calc(points[i].first, points[i].second,
                                  points[j].first, points[j].second, x, y, r);
        }
    }

    i64 num = 1ll * n * (n - 1) * (n - 2) / 6;
    long double ans = cnt * 1.0 / num;
    std::cout << std::fixed << std::setprecision(8) << ans << std::endl;

    return 0;
}