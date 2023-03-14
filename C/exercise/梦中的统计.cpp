#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m, n;
	cin >> m >> n;
	int a[10];
	for(int i=0;i<10;i++) a[i]=0;
	for(int i=m;i<=n;i++){
		int temp = i;
		while(temp){
			a[temp%10] ++;
			temp /= 10;
		}
	}
	for(int i=0;i<10;i++)
		printf("%d ", a[i]);
	return 0;
}
