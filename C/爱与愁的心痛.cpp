#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, min = 400000;
	cin >> n >> m;
	int a[n];
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	for(int i=0;i<n-m+1;i++){
		int sum = 0; 
	    for(int j=i;j-i<m;j++) sum += a[j];
	    if(sum<min) min = sum;
	}
	cout << min;
	return 0;
}
