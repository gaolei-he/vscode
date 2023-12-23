#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#define rep(i, a, n) for(int i=(a);i<=(n);++i)
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> g(m + 1);
    vector<int> deg(m + 1, 0);
    rep(i, 1, m)
    {
        int op; cin >> op;
        if(op) g[op].push_back(i);
        if(op) deg[i] ++;
    }
    vector<int> scheduler(m + 1);
    rep(i, 1, m) cin >> scheduler[i];
    vector<int> early(m + 1, 1);
    auto bfs = [&](){
        queue<int> q;
        rep(i, 1, m) if(!deg[i]) q.push(i);
        while(q.size())
        {
            auto ver = q.front(); q.pop();
            for(auto v : g[ver])
            {
                early[v] = max(early[ver] + scheduler[ver], early[v]);
                q.push(v);
            }
        }
    };
    bfs();


    vector<vector<int>> g1(m + 1);
    deg.assign(m + 1, 0);
    // rep(i, 1, m) cerr << deg[i] << ' ';
    rep(i, 1, m)
        for(auto x : g[i])
        {
            g1[x].push_back(i), deg[i] ++;
            // cerr << i << ' ' << x << endl;
        }
    // rep(i, 1, m) cerr << deg[i] << ' ';
    vector<int> latest(m + 1, n);
    auto bfs1 = [&]() {
        queue<int> q;
        rep(i, 1, m) if(!deg[i]) q.push(i);
        while(q.size())
        {
            auto ver = q.front(); q.pop();
            for(auto v : g1[ver])
            {
                latest[v] = min(latest[v], latest[ver] - scheduler[ver]);
                q.push(v);
            }
        }
    };
    bfs1();
    rep(i, 1, m) cout << early[i] << ' ';
    cout << endl;
    rep(i, 1, m) if(latest[i] - scheduler[i] + 1 < 1) exit(0);
    rep(i, 1, m) cout << latest[i] - scheduler[i] + 1 << ' ';
    cout << endl;

    

    return 0;
}