#include <cmath>
#include <iostream>
using namespace std;
const int N = 110;
const double eps = 1e-6;
double a[N][N];
int n;

void out()
{
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n+1; j++)
    //     {
    //         printf("%.2f ", a[i][j]);
    //     }
    //     puts("");
        
    // }
    // puts("");
}

int gauss()
{
    int r, c;
    for(r = 0, c=0;c<n;c++)
    {
        int t = r;
        for(int i=r;i<n;i++)
            if(fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
        out();
        if(fabs(a[t][c]) < eps) continue;
        for(int i=c;i<=n;i++) swap(a[r][i], a[t][i]);
        out();
        for(int i=n;i>=c;i--) a[r][i] /= a[r][c];
        out();
        for(int i=r+1;i<n;i++)
            if(fabs(a[i][c]) > eps)
                for(int j=n;j>=c;j--)
                    a[i][j] -= a[i][c] * a[r][j];
        out();
        r ++;
    }
    if(r < n) return 1;
    for(int i=n-1;i>=0;i--)
        for(int j=i+1;j<n;j++)
            a[i][n] -= a[i][j] * a[j][n];
    return 0;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            cin >> a[i][j];
        }
        
    }
    int t = gauss();
    if(t) puts("No Solution");
    else
        for(int i=0;i<n;i++)
        {
            double ans = a[i][n];
            if(fabs(ans) < eps) ans = 0;
            printf("%.2f\n", ans);
        }
    
    return 0;
}