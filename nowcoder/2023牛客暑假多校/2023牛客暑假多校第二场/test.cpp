#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>
#define int long long

using namespace std;

const int maxn = 1000010;
int n;
int f[maxn][4], a[maxn], b[maxn];

signed main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) cin >> b[i];
	if(b[1]) f[1][1] = a[1];
	
	for(int i = 2; i <= n; ++i) {
		if(b[i]) {
			if(b[i - 1]) {
				f[i][1] = max(f[i - 1][1], f[i - 1][0]) + a[i];
				f[i][0] = f[i - 1][0] + a[i - 1];
				f[i][3] = max(f[i - 1][3] + a[i], max(f[i - 1][1], f[i - 1][0]));
			} else {
				f[i][1] = max(f[i - 1][0], f[i - 1][2]) + a[i];
				f[i][0] = f[i - 1][0] + a[i - 1];
				f[i][3] = max(f[i - 1][0], f[i - 1][2]);
			}
		} else {
			if(b[i - 1]) {
				f[i][0] = max(f[i - 1][1], f[i - 1][0]);
				f[i][2] = max(f[i - 1][1] - a[i - 1] + a[i], f[i - 1][3] + a[i]);
			} else f[i][0] = max(f[i - 1][0], f[i - 1][2]);
		}
	}
	//for(int i = 1; i <= n; ++i) cout << f[i][0] << ' ' << f[i][1] << ' ' << f[i][2] << ' ' << f[i][3] << endl;
	cout << max(f[n][0], max(f[n][1], max(f[n][2], f[n][3]))) << endl;
	return 0;
}