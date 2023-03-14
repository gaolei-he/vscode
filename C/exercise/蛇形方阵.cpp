//四个一循环，分奇偶 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, cnt = 1;
	cin >> n;
	int n1 = 1, n2 = n;
	int a[n+1][n+1] = { 0 };
	while(cnt!=n*n+1){
	
	if(n1==n2){
		a[n/2+1][n/2+1] = cnt;
		break;
	}
	for(int i=n1;i<n2;i++){
		a[n1][i] = cnt;
		cnt ++;
	}
	for(int i=n1;i<n2;i++){
		a[i][n2] = cnt;
		cnt ++;
	}
	for(int i=n2;i>n1;i--){
		a[n2][i] = cnt;
		cnt ++;
	}
	for(int i=n2;i>n1;i--){
		a[i][n1] = cnt;
		cnt ++;
	}
	n1 ++;
	n2 --;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%3d", a[i][j]);
		printf("\n");
	}
	return 0;
}
