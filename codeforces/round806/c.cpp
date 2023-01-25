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
const int N = 110;
int a[N];
char str[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for(int i=1;i<=n;i++) scanf("%d", &a[i]);
        for(int i=1;i<=n;i++)
        {
            int k;
            scanf("%d %s", &k, str+1);
            for(int j=1;j<=k;j++)
            {
                if(str[j] == 'D') a[i] ++;
                else a[i] --;
                if(a[i] == 10) a[i] = 0;
                if(a[i] == -1) a[i] = 9;
            }
            
        }
        for(int i=1;i<=n;i++) printf("%d ", a[i]);
        puts("");
    }
    
    return 0;
}