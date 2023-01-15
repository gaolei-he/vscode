#include <iostream>
#include <cstring>
using namespace std;
int sum = 0, n;
int dp[20][20];

int dfs(int i, int j)
{
    if(dp[i][j]) return dp[i][j];
    else if(i==0) dp[i][j] = 1;
    else if(j==0) dp[i][j] = dfs(i-1, j+1);
    else dp[i][j] = dfs(i-1, j+1) + dfs(i, j-1);
    return dp[i][j];
}

int main()
{
    cin >> n;
    dp[n][0] = 1;
    cout << dfs(0, n);
    return 0;
}