#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
map<string, int> mp[11000];
map<int, string> mp2;
int cnt = 0;
int p[N];
signed main()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        vector<string> t;
        int p1 = 0, p2 = 0;
        while (1)
        {
            p1 = s.find('/', p2);
            p2 = s.find('/', p1 + 1);
            if (p1 == s.npos)
                break;
            t.push_back(s.substr(p1 + 1, p2 - p1 - 1));
        }
        int now = 0;
        mp2[now] = "/";
        for (int i = 0; i < t.size(); i++)
        {
            if (mp[now][t[i]])
            {
                now = mp[now][t[i]];
            }
            else
            {
                mp[now][t[i]] = ++cnt;
                mp2[cnt] = t[i];
                p[cnt] = now;
                now = cnt;
            }
        }
    }
    int now = 0;
    cin >> m;
    while (m--)
    {
        string op;
        cin >> op;
        if (op == "cd")
        {
            string s;
            cin >> s;
            if(s=="pwd")
            {
                int cc = 2;
            }
            if (s == ".")
                continue;
            else if (s == "..")
            {
                now = p[now];
            }
            else
            {
                now = mp[now][s];
            }
        }
        else if (op == "pwd")
        {
            vector<string> t;
            int res = now;
            while (res != 0)
            {
                t.push_back(mp2[res]);
                res = p[res];
            }
            reverse(t.begin(), t.end());
            for (int i = 0; i < t.size(); i++)
            {
                cout << "/" << t[i];
            }
            if (t.size() == 0)
                cout << "/" << '\n';
            else
                cout << "\n";
        }
        else if (op == "ls")
        {
            for (auto i : mp[now])
            {
                cout << i.first << '\n';
            }
        }
    }
}