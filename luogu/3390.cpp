#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b, int mod) {
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a[i].size(); j++)
            for (int k = 0; k < a[i].size(); k++)
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
    return res;
}
vector<vector<int>> qp(vector<vector<int>> a, int b, int mod) {
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < a.size(); i++) res[i][i] = 1;
    while (b) {
        if (b & 1) res = mul(res, a, mod);
        b >>= 1;
        a = mul(a, a, mod);
    }
    return res;
}

signed main() {
    long long n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> vec(n, std::vector<int>(n));
    for(auto &v : vec) {
        for(auto &x : v) {
            std::cin >> x;
        }
    }
    auto res = qp(vec, k, 1e9+7);
    for(auto &v : res) {
        for(auto x : v) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
    return 0;
}