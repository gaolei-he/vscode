#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
const int N = 1e3+10;
int a[N], n, m;
bool check(int k)
{
    vector<int> vec;
    rep(i, 1, k) vec.push_back(a[i]);
    sort(vec.begin(), vec.end(), greater<int>());
    int tm = m;
    for(int i=0;i<vec.size();i++)
    {
        tm -= vec[i];
        i ++;
    }
    if(tm < 0) return false;
    return true;

}
signed main()
{
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    dec(i, n, 1)
    {
        if(check(i))
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}