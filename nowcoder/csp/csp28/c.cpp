#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#define rep(i, a, n) for(int i=(a);i<=(n);++i)
using namespace std;
using pii = pair<int, int>;
int main()
{
    vector<vector<int>> Q(8, vector<int>(8));
    auto M = Q;
    for(auto &vec : Q)
        for(auto &x : vec)
            cin >> x;

    int n; cin >> n;
    int t; cin >> t;
    vector<int> scan_data(n);
    for(auto &x : scan_data) cin >> x;

    int x = 0, y = 0, dx = -1, dy = 1;
    for(auto v : scan_data)
    {
        M[x][y] = v;
        x += dx, y += dy;
        if(x < 0 or x > 7 or y < 0 or y > 7)
        {
            x -= dx, y -= dy;
            dx = -dx, dy = -dy;
            if(x == 0 and y == 0) y++;
            else if(x == 7) y ++;
            else if(y == 7) x ++;
            else if(x == 0) y ++;
            else if(y == 0) x ++;
        }
    }
    // M 3
    if(t == 0)
    {
        for(auto &vec : M)
        {
            for(auto x : vec) cout << x << ' ';
            cout << endl;
        }
        return 0;
    }
    rep(i, 0, 7)
        rep(j, 0, 7)
            M[i][j] *= Q[i][j];
    // M 4
    if(t == 1)
    {
        for(auto &vec : M)
        {
            for(auto x : vec) cout << x << ' ';
            cout << endl;
        }
        return 0;
    }
    function<double(int)> f = [](int u) {return u ? 1 : sqrt(0.5);};
    vector<vector<double>> M1(8, vector<double>(8));
    rep(i, 0, 7)
        rep(j, 0, 7)
            rep(u, 0, 7)
                rep(v, 0, 7)
                    M1[i][j] += 0.25 * f(u) * f(v) * M[u][v] * cos(acos(-1) * (i + 0.5) * u / 8) * cos(acos(-1) * (j + 0.5) * v / 8);
    // for(auto &vec : M1)
    // {
    //     for(auto x : vec) cout << x << ' ';
    //     cout << endl;
    // }
    
    for(auto &vec : M1)
        for(auto &x : vec)
            x = max(0.0, min(255.0, round(x) + 128));

    for(auto &vec : M1)
    {
        for(auto x : vec) cout << x << ' ';
        cout << endl;
    }
    return 0;

}