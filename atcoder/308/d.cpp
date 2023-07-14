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
const int N = 10 + 5e2, mod = 1e9 + 7;
char str[N][N];
bool sta[N][N];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
void solve()
{
    int h, w;
    cin >> h >> w;
    rep(i, 1, h) cin >> str[i] + 1;
    string s = "snuke";
    queue<pii> q;
    q.push({1, 1});
    sta[1][1] = true;
    if(str[1][1] != 's')
    {
        cout << "No" << endl;
        return;
    }
    int cnt = 0;
    while(q.size())
    {
        cnt ++;
        queue<pii> tmp;
        while(q.size())
        {
            auto [x, y] = q.front(); q.pop();
            rep(i, 0, 3)
            {
                int tx = x + dx[i], ty = y + dy[i];
                if(tx < 1 || tx > h || ty < 1 || ty > w) continue;
                if(sta[tx][ty]) continue;
                if(str[tx][ty] != s[cnt%5]) continue;
                sta[tx][ty] = true;
                if(tx == h and ty == w)
                {
                    cout << "Yes" << endl;
                    return;
                }
                tmp.push({tx, ty});
            }
        }
        q = move(tmp);
    }

    cout << "No" << endl;
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