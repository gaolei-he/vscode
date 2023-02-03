#include <iostream>
#include <cstring>
using namespace std;
struct Ku
{
    int i, j;
    char str[1002];
    /* data */
};

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    Ku a[n+1];
    for(int i=1;i<=n;i++)
    {
        scanf("%s", a[i].str);
        a[i].i = 0;
        a[i].j = strlen(a[i].str) - 1;
    }
    int num;
    char ans[1002], kuang[501];
    memset(ans, 0, sizeof(ans));
    memset(kuang, 0, sizeof(kuang));
    int cnt = 0, cnt_k1 = 0, cnt_k2 = 0;
    while(true)
    {
        int ret = 1;
        scanf("%d", &num);
        if(num==-1) break;
        if(cnt_k1>=s&&num)
        {
            ans[cnt++] = kuang[cnt_k1--];
            //ret = 0;
        }
        if(a[num].i<=a[num].j&&num) kuang[cnt_k1++] = a[num].str[a[num].i++];
        if(num==0&&cnt_k1)
        {
            ans[cnt++] = kuang[cnt_k1-1];
            kuang[--cnt_k1] = '\0';
        }

    }

    cout << ans;
    return 0;
}