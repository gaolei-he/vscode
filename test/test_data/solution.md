# N sha256sum

使用 `set` 自动去重即可

```c++
#include <set>
#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    set<string> st;
    while(n --)
    {
        string tmp; cin >> tmp;
        st.insert(tmp);
    }
    cout << st.size() << endl;
    return 0;
}
```

# D 正则表达式

按顺序依次读取并判断即可，如果使用scanf读取，注意`scanf %c`会读取换行，空格等不可见字符

```c++
#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int ans = 0;
    while(n --)
    {
        bool flag = true;
        int x;
        char c;
        cin >> x >> c;
        if(x > 255) flag = false;
        cin >> x >> c;
        if(x > 255) flag = false;
        cin >> x >> c;
        if(x > 255) flag = false;
        cin >> x;
        if(x > 255) flag = false;
        if(flag) ans ++;
    }
    cout << ans << endl;
}
```

# F 完蛋，我被美女包围了

使用`map`记录每个好感度对应的人有哪些，最后取出好感度最大的即可，注意`stl`的使用

```c++
#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    map<int, vector<string>> mp;
    set<string> st;
    for(int i=0;i<n;i++)
    {
        string s;
        int x;
        cin >> s >> x;
        st.insert(s);
        mp[x].push_back(s);
    }
    // cout << st.size() << ' ' << n << endl;
    if(st.size() != n) exit(-1);
    if(mp.rbegin()->second.size() > 1) cout << "wake up, Third!" << endl;
    else cout << mp.rbegin()->second.front() << endl;
    return 0;
}
```

# E 大数据模型在新冠疫情下的应用

很好的大模拟题，取自第27次csp认证的第三题
本题主要是题目较长，题目本身不难

```c++
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

    // 依次处理每天的数据
    for(int i=0;i<n;i++) solve(i);

    return 0;
}
```