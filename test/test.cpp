#include <map>
#include <iostream>
using namespace std;
void solve()
{
    int n, q; cin >> n >> q;
    map<string, string> mp;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        if(mp.count(a)) mp[a] = min(mp[a], b);
        else mp[a] = b;
    }
    while(q --)
    {
        string a;
        cin >> a;
        if(mp.count(a)) cout << mp[a] << endl;
        else cout << "Not your business, don't ask more!" << endl;
    }
}
int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t --)
        solve();
    return 0;
}