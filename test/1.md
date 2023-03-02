### ChatGPT原理大揭秘

解法：使用`map<string, string>`存储每个问题的最小答案，询问时输出即可

$Code(cpp)$

```cpp
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
```

$Code(python3)$

```python
for _ in range(int(input())):
    n, q = map(int, input().split())
    dic = {}
    for i in range(n):
        a, b = input().split()
        dic[a] = min(b, dic.get(a, b))
    for i in range(q):
        a = input()
        print(dic.get(a, "Not your business, don't ask more!"))
```

### 什么是ACM

使用 `string` 的 `find` 函数进行查找即可，注意两个目标字符串都出现需要输出 `N0`
注意是`N0`不是`NO`，建议竞赛中直接`copy`题目上的输出以免出错
$Code(cpp)$

```cpp
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if(s.find("Association_for_Computing_Machinery") != string::npos && \
    s.find("Air_Combat_Maneuvering") != string::npos)
        cout << "N0" << endl;
    else if(s.find("Association_for_Computing_Machinery") != string::npos)
        cout << "YES" << endl;
    else if(s.find("Air_Combat_Maneuvering") != string::npos)
        cout << "YES" << endl;
    else
        cout << "N0" << endl;
    return 0;
}
```

$Code(python3)$

```python
s = input()
if "Association_for_Computing_Machinery" in s \
    and "Air_Combat_Maneuvering" in s:
    print('N0')
elif "Association_for_Computing_Machinery" in s:
    print('YES')
elif "Air_Combat_Maneuvering" in s:
    print('YES')
else:
    print('N0')
```
