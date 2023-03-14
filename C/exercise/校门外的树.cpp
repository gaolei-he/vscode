#include <bits/stdc++.h>
using namespace std;
int main()
{
	int l, m;
	cin >> l >> m;
	int arr[l+1];
	for(int i=0;i<=l;i++) arr[i] = 1;
	while(m--){
		int a, b;
		scanf("%d %d", &a, &b);
		for(int i=a;i<=b;i++) arr[i] = 0;
	}
	int cnt = 0;
	for(int i=0;i<=l;i++)
		if(arr[i]==1) cnt ++;
	cout << cnt;
	
	return 0;
}
