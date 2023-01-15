#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<bitset>
#include<queue>
#include<map>
#include<stack>
#include<string>
#include<random>
#include<cassert>
#include<functional>
#include<iomanip>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define ll long long
#define int long long
#define SZ(x) (int)x.size()
#define rep(i,a,n) for(int i = (a);i <= (n);i++)
#define dec(i,n,a) for(int i = (n);i >= (a);i--)
using namespace std;
using PII = pair<int,int>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x;}
const int N =10 + 2e5 ,mod=1e9 + 7;
void solve()
{
    int n, ans = 0;
    cin >> n;
    
    while(n --)
    {
        int a[26];
        memset(a, 0, sizeof(a));
        string s;
        cin >> s;
        int sum = 1;
        bool flag = true;
        for(int i=0, j=s.size()-1;i<j;i++, j--)
        {
            if(s[i] != s[j]) flag = false;
            else a[s[i]-'a'] ++, a[s[j]-'a'] ++;
        }
        if(flag)for(auto i:a) if(i) sum *= i;
        if(flag) ans += sum;
    }
    cout << ans;
}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    solve();

    return 0;
}