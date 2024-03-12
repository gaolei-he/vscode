#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> sm(1'000'010);
    int st = 1'000'100, ed = 0;
    while (n--) {
        int l, r;
        std::cin >> l >> r;
        r -= 1;
        ed = std::max(ed, r);
        st = std::min(st, l);
        sm[l] += 1;
        sm[r + 1] -= 1;
    }
    for (int i = 1; i <= 1'000'000; i++) {
        sm[i] += sm[i - 1];
    }
    int ans0 = 0, ans1 = 0;
    if(sm[ed]) {
        sm[ed + 1] = 0;
    } else {
        sm[ed + 1] = 1;
    }
    int cnt = 0;
    for(int i=st;i<=ed;i++) {
        cnt += 1;
        if(sm[i + 1] == 0 and sm[i] != 0) {
            ans1 = std::max(ans1, cnt);
            cnt = 0;
        } else if(sm[i + 1] != 0 and sm[i] == 0) {
            ans0 = std::max(ans0, cnt);
            cnt = 0;
        }
    }
    std::cout << ans1 << " " << ans0 << "\n";

    return 0;
}