#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e2+10;
char s[N];
inline bool check(char *p1, int n)
{
    for (int i = 0; i < n; i++)
    {
        if(*(p1+i) != s[i+1]) return false;
    }
    return true;
    
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        char str[N];
        
        scanf("%d", &n);
        scanf("%s", str+1);
        memcpy(s+1, str+1, n);
        int q[N];
        for(int i=1;i<=n;i++) scanf("%d", &q[i]);
        char ans[N];
        int cnt = 0;
        do
        {
            if(cnt&1)
            {
                for(int i=1;i<=n;i++) str[i] = ans[q[i]];
                cnt ++;
                if(check(str+1, n)) break;
            }
            else
            {
                for(int i=1;i<=n;i++) ans[i] = str[q[i]];
                cnt ++;
                if(check(ans+1, n)) break;
            }
        }while(1);
        cout << cnt << endl;
    }
    
    return 0;
}