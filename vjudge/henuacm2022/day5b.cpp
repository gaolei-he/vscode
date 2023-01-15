#include <iostream>
#include <cstring>
using namespace std;
const int P = 131, N = 1e6+10, M = 1e4+10;
typedef unsigned long long ll;
char str1[N], str2[M];
ll h[N], num[N];

ll get(int l, int r)
{
    return h[r] - h[l-1] * num[r-l+1];
}

int main()
{
    int t;
    str1[0] = '1', str2[0] = '1';
    num[0] = 1;
    for(int i=1;i<=1e6+5;i++) num[i] = num[i-1] * P;
    cin >> t;
    while (t--)
    {
        memset(h, 0, sizeof(h));
        scanf("%s %s", str2+1, str1+1);
        int l1 = strlen(str1) - 1, l2 = strlen(str2) - 1;
        for (int i=1;i<=l1;i++) h[i] = h[i-1] * P + str1[i];
        ll ans = 0;
        for(int i=1;i<=l2;i++) ans = ans * P + str2[i];
        int cnt = 0;
        for (int i=1;i<=l1;i++) if(get(i, i+l2-1) == ans) cnt ++;
        cout << cnt << endl;
    }
    
    return 0;
}