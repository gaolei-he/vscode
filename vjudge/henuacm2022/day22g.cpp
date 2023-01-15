#include <iostream>
#include <cstring>
using namespace std;
int a[10][10];
int b[10][10], c[10][10];
int main()
{
    int t;
    cin >> t;
    int mycnt = 0;
    while (t--)
    {
        mycnt ++;
        memset(b, 0, sizeof(t));
        for(int i=1;i<=5;i++)
            for(int j=1;j<=6;j++)
            {
                int x;
                scanf("%d", &x);
                a[i][j] = x ? 1 : 0;
            }
        int w = 0;
        int ans = 1e9+10;
        while (w < 64)
        {
            w <<= 1;
            int tmp[10][10];
            memcpy(tmp, a, sizeof(tmp));
            memset(c, 0, sizeof(c));
            int cnt = 0;
            for(int i=1;i<=6;i++)
            {
                if(w & (1 << i))
                {
                    cnt ++;
                    c[1][i] = 1;
                    tmp[1][i] ^= 1;
                    tmp[1][i+1] ^= 1;
                    tmp[1][i-1] ^= 1;
                    tmp[2][i] ^= 1;
                }
            }
            for(int i=1;i<=4;i++)
            {
                for(int j=1;j<=6;j++)
                {
                    if(tmp[i][j])
                    {
                        cnt ++;
                        c[i+1][j] = 1;
                        tmp[i][j] = 0;
                        tmp[i+1][j] ^= 1;
                        tmp[i+1][j-1] ^= 1;
                        tmp[i+1][j+1] ^= 1;
                        tmp[i+2][j] ^= 1;
                    }
                }
            }
            bool flag = true;
            for(int i=1;i<=5;i++)
                for(int j=1;j<=6;j++)
                    if(tmp[i][j]) flag = false;
            if(flag)
            {
                if(cnt < ans) memcpy(b, c, sizeof(c));
                ans = min(cnt, ans);
            }
            w >>= 1;
            w ++;
            
        }
        printf("PUZZLE #%d\n", mycnt);
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=6;j++)
                if(b[i][j]) printf("1 ");
                else printf("0 ");
            puts("");
        }
        ans = 1e9+10;
    }
    

    return 0;
}