#include <iostream>
#include <bitset>
using namespace std;
int st;
int main()
{
    int ans = 1e9+10;
    int t = 0;
    for (int i = 0; i < 20; i++)
    {
        int x;
        scanf("%d", &x);
        st |= (x << i);
    }
    while (t < 1024)
    {
        int cnt = 0;
        int tmp = st;
        t <<= 10;
        for (int i = 10; i < 20; i++)
        {
            if((t >> i) & 1)
            {
                cnt ++;
                tmp ^= (1 << i);
                if(i - 1 >= 0) tmp ^=(1 << (i-1));
                if(i + 1 < 20) tmp ^= (1 << (i+1));
            }
        }
        if(tmp < 2048)
        {
            int t1 = 0;
           
            while (t1 < 1024)
            {
                int cnt1 = cnt;
                int tmp1 = tmp;
                for (int i = 0; i < 10; i++)
                {
                    if((t1 >> i) & 1)
                    {
                        cnt1 ++;
                        tmp1 ^= (1 << i);
                        if(i - 1 >= 0) tmp1 ^=(1 << (i-1));
                        if(i + 1 < 20) tmp1 ^= (1 << (i+1));
                    }
                }
                t1 ++;
                if(!tmp1) ans = min(cnt1, ans);
            }
            
        }
        t >>= 10;
        t ++;
    }
    cout << ans << endl;
    return 0;
}