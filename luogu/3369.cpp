#include <bits/extc++.h>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
using pii = pair<int, int>;
tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> tr;
int main()
{
    map<int, int> mp;
    int n; cin >> n;
    while(n --)
    {
        int op, x; cin >> op >> x;
        if(op == 1)
        {
            int val = 0;
            if(mp.count(x)) val = ++mp[x];
            else mp[x] = val;
            tr.insert({x, val});
        }
        else if(op == 2)
        {
            int val = mp[x]--;
            if(!val) mp.erase(x);
            tr.erase({x, val});
        }
        else if(op == 3)
        {
            int ans = tr.order_of_key({x, 0});
            cout << ans + 1 << endl;
        }
        else if(op == 4)
        {
            int ans = tr.find_by_order(x - 1)->first;
            cout << ans << endl;
        }
        else if(op == 5)
        {
            auto it = tr.lower_bound({x, 0});
            int ans = (--it)->first;
            cout << ans << endl;
        }
        else if(op == 6)
        {
            cout << tr.upper_bound({x, 100010})->first << endl;
        }
    }
}