#include <iostream>
#include <vector>
#define int long long
using namespace std;
vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b, int mod)
{
    vector<vector<int>> res(a.size(), vector<int>(a.size()));
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a[i].size(); j++)
            for (int k = 0; k < a[i].size(); k++)
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
    return res;
}
vector<vector<int>> qp(vector<vector<int>> a, int b, int mod)
{
    vector<vector<int>> res(a.size(), vector<int>(a.size()));
    for(int i=0;i<a.size();i ++) res[i][i] = 1;
    while(b)
    {
        if(b & 1) res = mul(res, a, mod);
        b >>= 1;
        a = mul(a, a, mod);
    }
    return res;
}
signed main()
{
    int a, x, m;
    cin >> a >> x >> m;
    vector<vector<int>> f = {{a, 1}, {0, 1}};
    vector<vector<int>> g = qp(f, x, m);
    cout << g[0][1] << endl;
    return 0;
}