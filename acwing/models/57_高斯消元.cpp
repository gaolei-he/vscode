#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
const double eps = 1e-6;
int n;
double a[N][N];
int gauss()
{
    int c, r;
    for(c=0, r=0;c<n;c++)
    {
        int t = r;
        for (int i=r;i<n;i++)
            if(fabs(a[i][c]) > fabs(a[t][c]))
                t = i;//找到绝对值最大的一列
        
        if(fabs(a[t][c]) < eps) continue;//是零就下一列

        for(int i=c;i<=n;i++) swap(a[t][i], a[r][i]);//交换绝对值最大的行与当前行
        for(int i=n;i>=c;i--) a[r][i] /= a[r][c];//当前行第一个数变成1
        for(int i=r+1;i<n;i++)
            if(fabs(a[i][c]) > eps)
                for(int j=n;j>=c;j--)
                    a[i][j] -= a[r][j] * a[i][c];//把c下面每个数变成0，就是减去当前行的a[i][c]倍
        
        r++;
    }
    if(r < n)
    {
        for(int i=r;i<n;i++)
            if(fabs(a[i][n]) > eps)
                return 2;//无解
        return 1; //无穷多解
    }
    for(int i=n-1;i>=0;i--)
        for(int j=i+1;j<n;j++)
            a[i][n] -= a[i][j] * a[j][n];//算出答案
    return 0;//唯一解
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n+1; j++)
            cin >> a[i][j];
    
    int t = gauss();
    if(t == 0) for (int i=0;i<n;i++)
    {
        double ans = a[i][n];
        if(fabs(ans) < eps) ans = 0;
        printf("%.2f\n", ans);
    }
    else if(t == 1) puts("Infinite group solutions");
    else puts("No solution");
    
    return 0;
}