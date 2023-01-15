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
const int N = 60;
char str[N];
bool st[26];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        memset(st, 0, sizeof(st));
        scanf("%d %s", &n, str+1);
        int ans = 0;
        for(int i=1;i<=n;i++)
            if(!st[str[i]-'A']) {ans += 2; st[str[i]-'A'] = true;}
            else ans ++;
        printf("%d\n", ans);
    }
    
    return 0;
}