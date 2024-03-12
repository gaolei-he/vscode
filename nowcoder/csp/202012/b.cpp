#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m;
    std::cin >> m;
    std::vector<int> vec1, vec2;
    for(int i=1;i<=m;i++) {
        int a, b;
        std::cin >> a >> b;
        if(b) {
            vec1.push_back(a);
        } else {
            vec2.push_back(a);
        }
    }
    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());
    int mx = -1, ans = -1;
    for(auto x : vec1) {
        int val = 0;
        int l = 0, r = vec1.size() - 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(vec1[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        val += vec1.size() - l;
        l = 0, r = vec2.size() - 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(vec2[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(vec2[l] >= x) {
            val += l;
        } else {
            val += vec2.size();
        }

        if(mx <= val) {
            mx = val;
            ans = x;
        }
    }
    std::cout << ans << "\n";

    return 0;
}