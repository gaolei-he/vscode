#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;

int main()
{
	int n;
	cin >> n;
	LL a[n+1][n+1] = { 0 };
	a[0][1] = 1;
	for(int i=1;i<=n;i++){
	
		for(int j=1;j<=i;j++){		
			a[i][j] = a[i-1][j] + a[i-1][j-1];
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
