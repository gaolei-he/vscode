#include <iostream>
using namespace std;


int total = 0;
int ans[14];
int n;
bool fl1[14], fl2[28], fl3[28];
void f(int cnt)
{
    if(cnt-1==n&&total<3)
    {
        for(int i=1;i<=n;i++) printf("%d ", ans[i]);
        puts("");
        total ++;
        return;
    }
    else if(cnt-1==n)
    {
        total ++;
        return; 
    }
    
    for(int i=1;i<=n;i++)
    {
        if(!fl1[i]&&!fl2[cnt-i+n]&&!fl3[cnt+i])
        {
            fl1[i] = true;
            fl2[cnt-i+n] = true;
            fl3[cnt+i] = true;
            ans[cnt] = i;
            f(cnt+1);

            fl1[i] = false;
            fl2[cnt-i+n] = false;
            fl3[cnt+i] = false;
        }
    }
}
int main()
{
    
    cin >> n;
    f(1);
    cout << total;
    return 0;
}