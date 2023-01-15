#include <bits/stdc++.h>
using namespace std;
int n, k;
void f()
{
    int a[n + 1][k + 1];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++)
        a[i][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= i && j <= k; j++)
            a[i][j] = a[i - j][j] + a[i - 1][j - 1];
    cout << a[n][k];
}

int main()
{
    cin >> n >> k;
    f();
    return 0;
}
/*
void solve()
{
int n,k;
cin>>n>>k;
vector<vector<int>>dp(n+1,vector<int>(k+1));
//dp数组一维表示当前一共分了多少个，二维表示当前给多少个朋友分了
dp[0][0]=1;//初始状态：总共分了0个，给0个朋友分了的方案数，自然只有一种
//以下算法为分层完全背包做法
for(int i=1;i<=n;++i)//枚举给当前朋友分多少个
for(int j=i;j<=n;++j)//总共分了多少个
for(int g=1;g<=k;++g)//第几个朋友
dp[j][g]+=dp[j-i][g-1];
//由子状态给g-1个朋友分了j-i个，归入到父状态方案数
//由于分割蛋糕大小单调上升，装包时亦单调，
//由枚举的有序性，可保证组合的不重复性
cout<<dp[n][k];
}
int main()
{
ios::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
int t=1;
//cin>>t;
while(t--) solve();
return 0;
}*/