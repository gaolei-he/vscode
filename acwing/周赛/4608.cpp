#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int t[110];
typedef pair<int, int> pii;
int main()
{
    int n;
    cin >> n;
    vector<pii> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back({x, i+1});
        t[x] ++;
    }
    int chaoji = 0;
    bool flag = false;
    for(int i=0;i<110;i++) if(t[i] == 1) chaoji ++; else if(t[i] > 2) flag = true;
    if(chaoji % 2 == 0 || flag ) puts("YES");
    else
    {
        puts("NO");
        return 0;
    }
    int op = 0;
    if(chaoji % 2 == 0)
    {
        for(auto i:a)
        {
            if(t[i.first] == 1) putchar(65+op);
            else putchar('A');
            if(op) op = 0;
            else op = 1;
        }
    }
    else
    {
        bool flag = true;
        for(auto i:a)
        {
            if(t[i.first] == 1) putchar(65+op);
            else if(flag && t[i.first] > 2)
            {
                putchar('B');
                flag = false;
            }
            else putchar('A');
            if(t[i.first] == 1)
            {
                if(op) op = 0;
                else op = 1;
            }
        }
    }
    return 0;
}