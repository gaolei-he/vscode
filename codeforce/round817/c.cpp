#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    // ios::sync_with_stdio(false);
    // cout.tie(0);
    // cin.tie(0);
    while (t--)
    {
        int n;
        cin >> n;
        set<string> st1, st2, st3;
        map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            string tmp;
            cin >> tmp;
            st1.insert(tmp);
            mp[tmp] ++;
        }
        for (int i = 0; i < n; i++)
        {
            string tmp;
            cin >> tmp;
            st2.insert(tmp);
            mp[tmp] ++;
        }
        for (int i = 0; i < n; i++)
        {
            string tmp;
            cin >> tmp;
            st3.insert(tmp);
            mp[tmp] ++;

        }
        int c1 = 0, c2 = 0, c3 = 0;
        for(auto i:st1)
        {
            switch (mp[i])
            {
            case 1:
                c1 += 3;
                break;
            case 2:
                c1 ++;
            default:
                break;
            }
        }
        for(auto i:st2)
        {
            switch (mp[i])
            {
            case 1:
                c2 += 3;
                break;
            case 2:
                c2 ++;
            default:
                break;
            }
        }
        for(auto i:st3)
        {
            switch (mp[i])
            {
            case 1:
                c3 += 3;
                break;
            case 2:
                c3 ++;
            default:
                break;
            }
        }
        cout << c1 << ' ' << c2 << ' ' << c3 << '\n';
    }
    
    return 0;
}