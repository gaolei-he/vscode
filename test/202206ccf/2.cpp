#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int st[60][60];
int main()
{
    int n, L, S;
    cin >> n >> L >> S;
    vector<pii> mp;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        mp.push_back({x, y});
    }
    for(int i=S;i>=0;i--)
        for(int j=0;j<=S;j++)
            scanf("%d", &st[i][j]);
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto tmp = mp[i];
        bool flag = true;
        if(tmp.first + S > L || tmp.second + S > L) continue;
        for(auto j:mp)
        {
            if(j.first >= tmp.first && j.first <= tmp.first + S && j.second >= tmp.second && j.second <= tmp.second + S)
            {
                if(!st[j.first-tmp.first][j.second-tmp.second])
                {
                    flag = false;
                    break;
                }
                else st[j.first-tmp.first][j.second-tmp.second] ++;
            }
        }
        for(int i=0;i<=S;i++)
            for(int j=0;j<=S;j++)
            {
                if(st[i][j] == 1) flag = false;
                else if(st[i][j] == 2)st[i][j] = 1;
            }
        if(flag) ans ++;
    }
    cout << ans << endl;
    return 0;
}