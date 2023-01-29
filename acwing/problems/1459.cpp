#include <iostream>
using namespace std;
int k, n, a[22][22];
bool check(int a1, int b)
{
    int ret = 1;
    for(int i=1;i<k;i++)
    {
        
        for(int j=0;j<n;j++)
            if(a[i][j]==a1&&ret) break;
            else if(a[i][j]==b) return false;
    }
    return true;
}

int main()
{
    
    cin >> k >> n;
    for(int i=0;i<k;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &a[i][j]);
    int ans = 0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(check(a[0][i], a[0][j])) ans ++;
        }
    }
    cout << ans;
    return 0;
}