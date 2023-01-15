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
int n, m;
const int N = 1010;
int price[N];
int f[N][N];
int main()
{
    while(cin >> n)
    {
        if(!n) break;
        memset(f, 0, sizeof(f));
        for(int i=1;i<=n;i++) scanf("%d", &price[i]);
        scanf("%d", &m);
        if(m < 5)
        {
            cout << m << endl;
            continue;
        }
        m -= 5;
        
        sort(price+1, price+n+1);
        n --;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                f[i][j] = f[i-1][j];

                if(j - price[i] >= 0) f[i][j] = max(f[i][j], f[i-1][j-price[i]] + price[i]);
            }
        cout << m + 5 - f[n][m] - price[n+1] << endl;
    }

    return 0;
}