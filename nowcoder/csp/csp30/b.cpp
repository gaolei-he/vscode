// def f(A: list[list], B: list[list], C: int)->list[list]:
//     n, m, q = len(A), len(A[0]), len(B[0])
//     if C == 1:
//         q = len(B)
//     res = [[0 for i in range(q)] for j in range(n)]
//     for i in range(n):
//         for j in range(q):
//             val = 0
//             for k in range(m):
//                 if C == 1:
//                     val += A[i][k] * B[j][k]
//                 else:
//                     val += A[i][k] * B[k][j]
//             res[i][j] = val
//     return res

// # n = list(map(int, input().split()))
// # Q = [list(map(int, input().split())) for _ in range(n)]
// # K = [list(map(int, input().split())) for _ in range(n)]
// # V = [list(map(int, input().split())) for _ in range(n)]
// # W = list(map(int, input().split()))
// # ans = f(f(Q, K, 1), V, 0)
// print(1)
// # for lst, k in zip(ans, W):
// #     for val in lst:
// #         print(val * k, end=' ')
// #     print()
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
#include <random>
#include <cassert>
#include <functional>
#include <iomanip>
#include <array>
#include <unordered_map>
#include <unordered_set>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e5, mod = 1e9 + 7;
vector<vector<int>> f(vector<vector<int>> A, vector<vector<int>> B, bool flag)
{
    int n = A.size(), m = A.front().size(), q = B.front().size();
    if(flag) swap(n, m);
    vector<vector<int>> res(n, vector<int>(q, 0));
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < q; j ++)
        {
            int val = 0;
            for(int k = 0; k < m; k ++)
            {
                if(flag) val += A[k][i] * B[k][j];
                else val += A[i][k] * B[k][j];
            }
            res[i][j] = val;
        }
    }
    return res;
}
void solve()
{
    int n, d; cin >> n >> d;
    vector<vector<int>> Q(n, vector<int>(d)), K(n, vector<int>(d)), V(n, vector<int>(d));
    vector<int> W(n);
    for(auto& vec : Q)
        for(auto& val : vec)
            cin >> val;
    for(auto& vec : K)
        for(auto& val : vec)
            cin >> val;
    for(auto& vec : V)
        for(auto& val : vec)
            cin >> val;
    for(auto& val : W) cin >> val;
    auto ans = f(Q, f(K, V, true), false);
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < d; j ++)
        {
            cout << ans[i][j] * W[i] << " \n"[j == d - 1];
        }
    }

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}