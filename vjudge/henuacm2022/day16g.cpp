#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 3500, M = 13000;
int n, m;
int f[M];
int w[N], v[N];
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) scanf("%d %d", &v[i], &w[i]);
    for(int i=1;i<=n;i++)
        for(int j=m;j>=v[i];j--)
        {
            f[j] = max(f[j], f[j-v[i]]+w[i]);
        }
    cout << f[m];
    return 0;
}