#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int suan = 1, ku = 0, zuixiao = 0x7fffffff;
int n, a[12][3], b[12];
void dfs(int k, int ans)
{
    if(k==ans)
    {
        zuixiao = (abs(suan-ku)>zuixiao?zuixiao:(abs(suan-ku)));
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!b[i])
        {

        suan *= a[i][1];
        ku += a[i][2];
        b[i] = 1;
        dfs(k+1, ans);
        b[i] = 0;
        suan /= a[i][1];
        ku -= a[i][2];
        }
    }

}

int main()
{
    memset(b, 0, sizeof(b));
    cin >> n;
    for(int i=1;i<=n;i++)
        scanf("%d %d", &a[i][1], &a[i][2]);
    for(int i=1;i<=n;i++) dfs(0, i);
    cout << zuixiao;
    
    return 0;
}