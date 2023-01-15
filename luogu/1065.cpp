#include <cstdio>
#include <iostream>
using namespace std;
int f(int *p, int k);
int main()
{
    int m, n;
    cin >> m >> n;
    int N = m * n;
    int a[N] = { 0 };
    for(int i=0;i<N;i++) scanf("%d", &a[i]);
    int shunxu[n][m], costime[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d", &shunxu[i][j]);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d", &costime[i][j]);//输入
    int machine[m][10000] = { 0 };
    int ma = 0;
    int gongjian[n] = { 0 };
    for(int i=0;i<N;i++){
        int j;
        for(j=0;;j++)
            if(shunxu[a[i]-1][j])//找到未执行工序工件和工序号
                break;
        
        int times = costime[a[i]-1][j];//记录该工序所需时间
        
        for(int k=gongjian[a[i]-1];;k++){
            if(f(&machine[shunxu[a[i]-1][j]-1][k], times)){
                int p;//如果该工件所需的机器找到空档就插入
                for(p=k;p-k<times;p++) machine[shunxu[a[i]-1][j]-1][p] = 1;
                gongjian[a[i]-1] =  p;//记录该工件最后完成的时间
                break;
            }

        }
        shunxu[a[i]-1][j] = 0;//工序执行后归零
    }
    int ma1 = 0;
    for(int i=0;i<n;i++) //printf("%d ", gongjian[i]);
    ma1 = (gongjian[i]>ma1)? gongjian[i] : ma1;//找到最晚执行完的工件就是时间
    cout << ma1;
    return 0;
}

int f(int *p, int k)
{
    for(int i=0;i<k;i++)
        if(*(p+i))
            return 0;//如果区间有1说明空档不够大
    return 1;
}