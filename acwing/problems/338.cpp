#include <iostream>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
int power10(int x)
{
    int res = 1;
    while(x--) res *= 10;
    return res;
}
int count(int n, int x)
{
    int res = 0;
    int l, r, cnt = 0, m = n;
    while(m) {cnt ++; m /= 10;}

    rep(i, 1, cnt)
    {
        
    }
}
int ans[11];
int main()
{
    cout << count(100, 0) << endl;
    // int a, b;
    // while(cin >> a >> b)
    // {
    //     if(!a) break;
    //     rep(i, 0, 9) ans[i] = count(b, i) - count(a-1, i);
    //     rep(i, 0, 9) cout << ans[i] << ' ';
    //     cout << endl;
    // }
    return 0;
}