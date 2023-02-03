#include <cstring>
#include <iostream>
using namespace std;
const int N = 5e6+10;
char p[N/2], s[N];
int ne[N];
int main()
{
    int n;
    cin >> n;
    scanf("%s", p+1);
    memcpy(s+1, p+1, sizeof(char) * n);
    memcpy(s+1+n, p+1, sizeof(char) * n);
    int ans = 0;
    for (int i=2, j=0;i<=n;i++)
    {
        while(j && p[j+1] != p[i]) j = ne[j];
        if (p[j+1] == p[i]) j ++;
        ne[i] = j;
    }
    for (int i=1, j=0;i<=(n<<1);i++)
    {
        while(j && s[i] != p[j+1]) j = ne[j];
        if (s[i] == p[j+1]) j ++;
        if (j == n)
        {
            j = ne[j];
            ans ++;
        }
    }
    cout << ans - 1 << endl;
    return 0;
}