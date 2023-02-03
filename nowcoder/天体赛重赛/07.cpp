#include <iostream>
#include <cstring>
#include <cstdio>
struct Groups
{
    int sum;
    int group;
    int ans[101];

    /* data */
};


using namespace std;
int main()
{
    int n;
    cin >> n;
    Groups a[n+1];
    int total = 0;
    for(int i=1;i<=n;i++)
    {
        //scanf("%d", &a[i].group);
        cin >> a[i].group;
        a[i].sum = a[i].group * 10;
        total += a[i].sum;
        a[i].group = a[i].sum;
    }

    int cnt1 = 1;
    for(int i=1;i<=total;i++)
    {
        int ret = 0;
        //int cnt1 = 1;
        for(;;cnt1++)
        {
            if(ret&&cnt1>n) break;
            if(cnt1>n){
                cnt1 = 1;
                ret = 1;
            }
            if(a[cnt1].sum)
            {
                a[cnt1].ans[a[cnt1].sum] = i;
                a[cnt1].sum --;
                cnt1 ++;
                break;
            }
        }
        if(cnt1>n) cnt1 = 1;
    }
    for(int i=1;i<=n;i++)
    {
        printf("#%d\n", i);
        int ret1 = 0;
        for(int j=1;a[i].group;j++)
        {
            int out = 0;
            if(a[i].ans[a[i].group]-1==a[i].ans[a[i].group+1]&&j!=1)
            {
                ret1 ++;
                out += ret1;
                //out += a[i].ans[a[i].group] % 10;
                //if(out==0) out += 10;
            }
            out += a[i].ans[a[i].group--];
            if(j%10==1) printf("%d", out);
            else printf(" %d", out);
            if(j%10==0) printf("\n");
        }
    }
    return 0;
}