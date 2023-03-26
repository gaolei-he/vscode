#include <map>
#include <iostream>
using namespace std;
int main()
{
    int q;
    cin >> q;
    map<int, int> mp;
    while (q--)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int x; cin >> x;
            mp[x] ++;
        }
        else if(op == 2)
        {
            int x, c; cin >> x >> c;
            mp[x] -= min(c, mp[x]);
            if(mp[x] == 0) mp.erase(x);
        }
        else
        {
            cout << mp.rbegin()->first - mp.begin()->first << endl;
        }
    }
    
    return 0;
}