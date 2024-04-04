#include <bits/stdc++.h>

using i64 = long long;

class Node {
   private:
    std::set<int> rec;
    int n;

   public:
    Node(int n) {
        this->n = n;
        for (int i = 0; i <= n; i++) {
            rec.insert(i);
        }
    }
    void del(int x) { rec.insert(x); }
    void add(int x) { rec.erase(x); }
    int mex() { return *rec.begin(); }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (auto &x : vec) {
        std::cin >> x;
    }
    Node node(n);
    for (int i = 0; i < n; i++) {
        if (!i) {
            if (vec[i] == 1) {
                std::cout << 0 << " ";
                node.add(0);
            } else {
                std::cout << -vec[i] << " ";
                node.add(-vec[i]);
            }
        } else {
            int x = node.mex();
            node.add(x);
            if (node.mex() - x == vec[i]) {
                std::cout << x << " \n"[i == n - 1];
            } else {
                node.del(x);
                x = x - vec[i];
                node.add(x);
                std::cout << x << " \n"[i == n - 1];
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}