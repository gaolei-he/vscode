#include <bits/stdc++.h>
#define int long long
void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pqm, pqk;
    int sm = 0;
    while (n--) {
        int x;
        std::cin >> x;
        if (pqk.size() < k) {
            pqk.push(x);
        } else if (pqk.size() and x > pqk.top()) {
            if (sm + pqk.top() >= m) {
                break;
            }
            pqk.push(x);
            pqm.push(pqk.top());
            sm += pqk.top();
            pqk.pop();
        } else {
            if (sm + x >= m) {
                break;
            }
            sm += x;
            pqm.push(x);
        }
        // std::cerr << sm << "\n";
    }
    std::cout << pqk.size() + pqm.size() << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::priority_queue<int, std::vector<int>, std::greater<int>> pqm, pqk;
    pqk.push(1), pqk.push(2);
    pqm.push(1), pqm.push(2);
    // std::cout << pqk.top() << " " << pqm.top();
    solve();

    return 0;
}
