#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::set<int> st;
    while(n --) {
        int x;
        std::cin >> x;
        st.insert(x);
    }
    std::vector<int> vec;
    int lst = 0;
    while(st.size()) {
        auto x = *st.begin();
        st.erase(st.begin());
        vec.emplace_back(x - lst);
        lst = x;
    }
    int ans = 0;
    for(int i=0;i<vec.size();i++) {
        if(vec[i] > 1) {
            if(i & 1) ans = -1;
            else ans = 1;
            break;
        }
    }
    if(ans == 1) {
        std::cout << "Alice\n";
    } else if(ans == -1) {
        std::cout << "Bob\n";
    } else {
        if(vec.size() & 1) {
            std::cout << "Alice\n";
        } else {
            std::cout << "Bob\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}