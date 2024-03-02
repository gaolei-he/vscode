#include <iostream>
#include <vector>
#include <set>

using namespace std;
using pii = pair<int, int>;

void solve()
{
    int n, L, S;
    cin >> n >> L >> S;
    set<pii> st;
    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        st.emplace(x, y);
    }
    
    vector<vector<int>> maps(S + 1, vector<int>(S + 1));
    for(auto &vec : maps)
        for(auto &x : vec)
            cin >> x;
    
    auto check = [&](int x, int y)
    {
        for(int i=0;i<=S;i++)
            for(int j=0;j<=S;j++)
                if(maps[S-i][j] and st.count({i + x, j + y})) continue;
                else if(maps[S-i][j]) return false;
                else if(st.count({i + x, j + y})) return false;
                else if(i + x > L or j + y > L) return false;
        
        return true;
    };

    int ans = 0;
    for(auto &p : st)
    {
        int x = p.first, y = p.second;
        if(check(x, y)) ans ++;
    }

    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}