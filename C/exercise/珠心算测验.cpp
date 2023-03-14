#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	sort(a, a+n);
	int cnt = 0;
	int b[n];
	for(int k=n-1;k!=1;k--)
		for(int j=k-1;j!=0;j--)
			for(int i=j-1;i!=-1;i--)
			
				if(a[k]==a[i]+a[j]&&a[k]!=b[cnt-1]){
					b[cnt++] = a[k];	
				}
			
	cout << cnt;		
	return 0;
}
