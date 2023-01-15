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
    int t;
    cin >> t;
    while (t--)
    {

        scanf("%d %d", &n, &m);
        memset(f, 0, 4*m+8);
        for(int i=1;i<=n;i++) scanf("%d", &w[i]);
        for(int i=1;i<=n;i++) scanf("%d", &v[i]);
        for(int i=1;i<=n;i++)
            for(int j=m;j>=v[i];j--)
            {
                f[j] = max(f[j], f[j-v[i]]+w[i]);
            }
        cout << f[m] << endl;
    }
    
    
    return 0;
}