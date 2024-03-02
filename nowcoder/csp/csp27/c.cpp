#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <array>
#include <algorithm>
#include <functional>

using namespace std;
using pii = pair<int, int>;

map<int, set<int>> risk_dict;
map<int, set<array<int, 3>>> user_list;

void solve(int day)
{
    int r, m; cin >> r >> m;
    for(int i=0;i<r;i++)
    {
        int p; cin >> p;
        auto &st = risk_dict[p];
        for(int d0=day;d0<day+7;d0++) st.insert(d0);
        while(st.size() and *st.begin() <= day - 7) st.erase(st.begin());
    }

    auto risk = [&](int d, int r)
    {
        if(d <= day - 7) return false;
        if(!risk_dict.count(r)) return false;
        auto &st = risk_dict[r];
        for(int d0 = d; d0 <= day; d0 ++) if(!st.count(d0)) return false;
        return true;
    };

    for(int i=0;i<m;i++)
    {
        int d, u, r;
        cin >> d >> u >> r;
        if(risk(d, r)) user_list[u].insert({day, r, d});
    }
    vector<int> ans;
    for(auto &udp : user_list)
    {
        int u = udp.first;
        while(udp.second.size() and *udp.second.begin()->begin() <= day-7) udp.second.erase(udp.second.begin());
        for(auto &arr : udp.second)
        {
            if(arr[0] <= day - 7) continue;
            int d = arr[2], r = arr[1];
            // cerr << d << ' ' << r << endl;
            if(risk(d, r))
            {
                ans.emplace_back(u);
                break;
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << day << ' ';
    for(auto x : ans) cout << x << ' ';
    cout << endl;
}

int main()
{
    int n; cin >> n;

    for(int i=0;i<n;i++) solve(i);

    return 0;
}