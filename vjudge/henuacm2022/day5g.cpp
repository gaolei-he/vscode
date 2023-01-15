#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int n, m;
int main()
{
    cin >> n >> m;
    map<string, bool> mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mp.insert({s, 1});
    }
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        string op1, op2;
        bool flag = true;
        for(auto &j:s)
        {
            switch (j)
            {
            case 'a':
                op1 = "bc", op2 = "a";
                break;
            case 'b':
                op1 = "ac", op2 = "b";
                break;
            case 'c':
                op1 = "ab", op2 = "c";
            default:
                break;
            }
            for(auto k:op1)
            {
                j = k;
                if(mp.find(s) != mp.end())
                {
                    puts("YES");
                    flag = false;
                    break;
                }
            }
            j = op2[0];
            if(!flag) break;
        }
        if(flag) puts("NO");
    }
    
    
    return 0;
}