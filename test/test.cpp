#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mp[x] ++;
    }
    int ma = 0;
    for(auto& p:mp) ma = max(p.second, ma);
    for(auto& p:mp)
        if(p.second == ma)
            cout << p.first << endl << p.second << endl;
    return 0;
}
// int a[2010];
// int main()
// {
//     int n; cin >> n;
//     vector<int> vec(n);
//     for (int i = 0; i < n; i++)
//     {
//         int x; cin >> x;
//         vec.push_back(x);
//         a[x] ++;
//     }
//     long long ans = 0;
//     for(auto x:vec)
//     {
//         for(int i=1;i < x;i ++) ans += a[i];
//         a[x] --;
//     }
//     cout << ans << endl;
//     return 0;
// }