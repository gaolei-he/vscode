#define  _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <iostream>
#include<map>
#include<cstdio> 
#include<cstring>
#include<set>
#define maxn 100005
#define int ll
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3fLL
typedef long long ll;
#define ls rt<<1     //定位左儿子：p*2
#define rs rt<<1|1   //定位右儿子：p*2 + 1
using namespace std;
int n, m, a, c, x, y, z,  k, op, res, ans, l, r;
int M = 1e9 + 7;
vector<vector<int>>s[12];
vector<string> _vs[12] = {
    {"red","edr","dre"},
    {"edr","dre","red"},
    {"dre","red","edr"},
    {"red","dre","edr"},
    {"dre","edr","red"},
    {"edr","red","dre"},
    {"der","rde","erd"},
    {"rde","erd","der"},
    {"erd","der","rde"},
    {"der","erd","rde"},
    {"erd","rde","der"},
    {"rde","der","erd"},
};
void solve() {
    return;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T = 1;
	cin >> n >> m;
	cin >> T;
    vector<string>vs(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> vs[i];
        vs[i] = ' ' + vs[i];
    }
    for (int i = 0;i < 12;i++)s[i].resize(n + 1, vector<int>(m + 1));
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            for (int k = 0;k < 12;k++) {
                s[k][i][j] = (vs[i][j] != _vs[k][i % 3][j % 3]);
                s[k][i][j] = s[k][i][j] + s[k][i - 1][j] + s[k][i][j - 1] - s[k][i - 1][j - 1];
            }
        }
    }
	while (T--) {
		//solve();
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--;
        int res = INF;
        for (int i = 0;i < 12;i++) {
            res = min(res, s[i][x2][y2] + s[i][x1][y1] - s[i][x2][y1] - s[i][x1][y2]);
        }
        if (x2 - x1 == 2 && y2 - y1 == 2) {
            if (vs[x2][y2] == vs[x2 - 1][y2 - 1] && vs[x2 - 1][y2] == vs[x2][y2 - 1] && vs[x2][y2] != vs[x2 - 1][y2])res = 0;
        }
        cout << res << endl;
	}
}




