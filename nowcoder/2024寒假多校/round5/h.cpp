#include <bits/stdc++.h>

using i64 = long long;

std::vector<bool> st;
void check(int n) {
    st.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        for (int j = i * i; j > i and j <= n; j += i) {
            st[j] = true;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    check(2'000'001);
    int idx = 1;
    std::stack<int> stk;
    while (true) {
        idx = 1;
        while(st[idx + n]) {
            idx += 1;
        }
        for(int i=n;i>=idx;--i) stk.emplace(n + idx - i);
        n = idx - 1;
        if(n < 4) break;
    }
    if (n == 3) std::cout << "1 3 2 ";
    else if(n == 2) std::cout << "2 1 ";
    else if(n == 1) std::cout << "1 ";
    while(stk.size()) {
        std::cout << stk.top() << ' ';
        stk.pop();
    }
    return 0;
}