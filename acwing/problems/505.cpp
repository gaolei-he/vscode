#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 99'999'997;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n), b(n);
    std::vector<std::pair<int, int>> tmp(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i].first;
        b[i].second = i;
    }
    int ans = 0;
    std::function<void(std::vector<std::pair<int, int>> &, int l, int r)>
        merge_sort = [&](std::vector<std::pair<int, int>> &vec, int l, int r) {
            if (l >= r) {
                return;
            }
            int mid = l + r >> 1;
            merge_sort(vec, l, mid);
            merge_sort(vec, mid + 1, r);
            int i = l, j = mid + 1;
            int k = 0;
            while (i <= mid and j <= r) {
                if (vec[i] <= vec[j]) {
                    tmp[k++] = vec[i++];
                } else {
                    tmp[k++] = vec[j++];
                    ans += mid - i + 1;
                    ans %= mod;
                }
            }
            while (i <= mid) {
                tmp[k++] = vec[i++];
            }
            while (j <= r) {
                tmp[k++] = vec[j++];
            }

            for (int i = l, j = 0; i <= r; i++, j++) {
                vec[i] = tmp[j];
            }
        };

    auto back_a = a, back_b = b;

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    auto tmp_b = back_b;
    for (int i = 0; i < n; ++i) {
        tmp_b[b[i].second].first = a[i].second;
    }
    merge_sort(tmp_b, 0, n - 1);
    int res = ans;
    ans = 0;

    a = back_a;
    b = back_b;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    auto tmp_a = back_a;
    for (int i = 0; i < n; i++) {
        tmp_a[a[i].second].first = b[i].second;
    }
    merge_sort(tmp_a, 0, n - 1);
    std::cout << std::min(res, ans) << std::endl;

    return 0;
}