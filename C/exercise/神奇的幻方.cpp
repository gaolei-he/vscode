#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n+1][n+1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j] = 0;
	a[1][n/2+1] = 1;
	int i = 1, j = n / 2 + 1;
	for(int cnt=2;cnt<=n*n;cnt++){
		if(i==1&&j!=n){
			a[n][j+1] = cnt;
			i = n, j = j + 1;
		}else if(j==n&&i!=1){
			a[i-1][1] = cnt;
			i = i - 1, j = 1;
		}else if(i==1&&j==n){
			a[i+1][j] = cnt;
			i = i + 1, j = j;
		}else if(i!=1&&j!=n){
			if(a[i-1][j+1]==0){
				a[i-1][j+1] = cnt;
				i = i - 1, j = j + 1;
			}else{
				a[i+1][j] = cnt;
				i = i + 1, j = j;
			}
		}
			
	}
	for(int a1=1;a1<=n;a1++){
		for(int a2=1;a2<=n;a2++)
			printf("%d ", a[a1][a2]);
			printf("\n");
		}
	return 0;
}
