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
#define ll long long
#define int long long
#define ull unsigned long long
#define SZ(x) (int)x.size()
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dec(i, n, a) for (int i = (n); i >= (a); i--)
using namespace std;
using pii = pair<int, int>;
using ar2 = array<int, 2>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
const int N = 10 + 1e3, mod = 1e9 + 7;
int n, m, k;
int x1, x2, y1__, y2;
char str[N][N];
bool sta[N][N][4];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int arr[] = {0, 1, 2, 3};
int cnt = 0;
int bfs()
{
    queue<pii> q;
    q.push({x1, y1__});
    if(x1 == x2 && y1__ == y2) return cnt;
    while (q.size())
    {
        cnt ++;
        queue<pii> tmp;
        while (q.size())
        {
            auto p = q.front();
            int x = p.first, y = p.second;
            q.pop();
            // random_shuffle(arr, arr+4);
            // swap(dx[arr[0]], dx[arr[1]]);
            // swap(dy[arr[0]], dy[arr[1]]);
            for (int i = 0; i < 4; i++)
            {
                rep(j, 1, k)
                {
                    int tx = x + j * dx[i], ty = y + j * dy[i];
                    if(!(tx > 0 && tx <= n && ty > 0 && ty <= m)) break;
                    else if(sta[tx][ty][i]) break;
                    if (str[tx][ty] == '#')
                        break;
                    if (!sta[tx][ty][i])
                    {
                        if(tx == x2 && ty == y2) return cnt;
                        tmp.push({tx, ty});
                        sta[tx][ty][i] = true;
                    }
                }
            }
        }
        q = move(tmp);
    }
    return -1;
}
void solve()
{
    cin >> n >> m >> k;
    rep(i, 1, n) cin >> str[i] + 1;
    cin >> x1 >> y1__ >> x2 >> y2;
    swap(x1, x2);
    swap(y1__, y2);
    cout << bfs();
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