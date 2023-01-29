#include <bits/stdc++.h>
#define rep(i, a, n) for(int i=(a);i<=(n);i++)
#define dec(i, n, a) for(int i=(n);i>=(a);i--)
using namespace std;
int a[10][10];
int main()
{
    int x, y;
    rep(i, 1, 5)
        rep(j, 1, 5)
        {
            int tmp; cin >> tmp;
            if(tmp) x = i, y = j;
        }
    
    vector<set<pair<int, int>>> vec(5);
    vec[0].insert({3, 3});
    pair<int, int> ans = {x, y};
    int dx[] = {0, -1, 0, 1};
    int dy[] = {-1, 0, 1, 0};
    rep(i, 0, 5)
    {
        if(vec[i].count(ans))
        {
            cout << i << endl;
            break;
        }
        for(auto j:vec[i])
        {
            rep(k, 0, 3)
            {
                vec[i+1].insert({j.first+dx[k], j.second+dy[k]});
            }
        }
    }
    return 0;
}