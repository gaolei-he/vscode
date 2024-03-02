#include <iostream>
#include <vector>
#include <functional>
#define int long long
using namespace std;

signed main()
{
    int n, N;
    cin >> n >> N;
    int ans = 0;
    vector<int> vec(n);
    for(auto &x : vec) cin >> x;
    
    int l = 0, cnt = 0;
    int p = N / (n + 1);
    function<int(int,int,int)> check = [&](int l, int r, int op)
    {
        int res = 0;
        if(op == 0)
        {
            int a0 = cnt - r / p;
            int an = cnt - l / p;
            res = (a0 + an) * (an - a0 + 1) / 2 * p;
            res -= a0 * (p - 1 - r % p);
            res -= an * (l % p);
//            cerr << op << ' ' << l << ' ' << r << ' ' << a0 << ' ' << an << ' ' << res << endl;
        }
        else if(op == 1)
        {
            int a0 = l / p - cnt;
            int an = r / p - cnt;
            res = (a0 + an) * (an - a0 + 1) / 2 * p;
            res -= a0 * (l % p);
            res -= an * (p - 1 - r % p);
//            cerr << op << ' ' << l << ' ' << r << ' ' << a0 << ' ' << an << ' ' << res << endl;
        }
        return res;
    };
    function<int(int, int)> calc = [&](int l, int r)
    {
        if(r / p <= cnt)
        {
            int res = check(l, r, 0);
            return res;
        }
        else if(l / p >= cnt)
        {
            int res = check(l, r, 1);
            return res; 
        }
        else
        {
            int x = cnt * p;
            int res = check(l, x, 0) + check(x + 1, r, 1);
            return res;
        }
    };
    for(auto x : vec)
    {
        int r = x - 1;
        ans += calc(l, r);
        l = x;
        cnt ++;
    }
    ans += calc(l, N - 1);
//    if(n > 200) exit(-1);
    cout << ans << endl;
    
    return 0;
}