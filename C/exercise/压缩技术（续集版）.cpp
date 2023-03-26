#include <bits/stdc++.h>
using namespace std;
char a[209][209]; 
int main()
{
	cin >> (a[1]);
	int n = strlen(a[1]);
	for(int i=2;i<=n;i++) cin >> (a[i]);
	printf("%d ", n);
	int cnt = 0;
	char out1 = '0', out2 = '1';
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==out1) cnt ++;
			else{
				printf("%d ", cnt);
				swap(out1, out2);
				cnt = 0;
				j --;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
