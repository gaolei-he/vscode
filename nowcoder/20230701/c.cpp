#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <stack>
#include <random>
#include <cassert>
#include <functional>
#include <iomanip>
#include <array>
#include <unordered_map>
#include <unordered_set>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
// mt19937 mrand(random_device{}());
// int rnd(int x) { return mrand() % x; }
const int N = 10 + 40, mod = 1e9 + 7;
char str[N][N];
int ways[N][N][N][N];
int dis[N][N][N][N];
int n, m;
bool sta[N][N];
int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
void bfs(int sx, int sy)
{
    queue<pii> q;
    q.push({sx, sy});
    dis[sx][sy][sx][sy] = 0;
    while(q.size())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        sta[x][y] = true;
        for (int i = 0; i < 3; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || str[nx][ny] == '*')
                continue;
            if (sta[nx][ny])
                continue;
            if (ways[sx][sy][nx][ny] > 1)
                continue;
            q.push({nx, ny});
            dis[sx][sy][nx][ny] = dis[sx][sy][x][y] + 1;
            ways[sx][sy][nx][ny] += 1;
        }
    }
}
void solve()
{
    int x, y;
    cin >> n >> m;
    rep(i, 1, n) cin >> str[i] + 1;
    rep(i, 1, n)
        rep(j, 1, m)
        {
            if (str[i][j] == '*')
                continue;
            else if (str[i][j] == 'R')
                x = i, y = j;
            memset(sta, 0, sizeof sta);
            bfs(i, j);
        }
    string s;
    cin >> s;
    unordered_map<string, int> mp;
    int l = 0;
    vector<pii> loc(s.size());
    unordered_map<string, int> tmp;
    rep(i, 0, SZ(s)-1)
    {
        mp[to_string(x) + " " + to_string(y)] = i;
        loc[i] = {x, y};
        char op = s[i];
        if(op == 'W') x--;
        else if(op == 'S') x++;
        else if(op == 'A') y--;
        else if(op == 'D') y++;
    }
    int ans = 0;
    auto check = [&](int i, int mid){
        int x = loc[mid].first, y = loc[mid].second;
        if(dis[loc[i].first][loc[i].second][x][y] == mid - i && ways[loc[i].first][loc[i].second][x][y] == 1) return true;
        return false;
    };
    rep(i, 0, SZ(s) - 1)
    {
        ans ++;
        int l = i + 1, r = SZ(s) - 1;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(check(i, mid)) l = mid;
            else r = mid - 1;
        }
        if(check(i, l))
        i = l;
        // cerr << i << endl;
    }
    cout << ans + 1 << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t; cin >> t;
    // while(t--)
        solve();

    return 0;
}