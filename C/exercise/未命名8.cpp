#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF){
		int a[n];
		int i, j, k;
		int ans;
		for(i=0;i<n;i++){
			int n1, n2, n3, n4;
			scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
			a[i] = n1 + n2 + n3 + n4;
			if(i==0) ans = a[i];			
		}
		sort(a, a+i, greater<int>());
		for(i=0;i<n;i++){
			if(a[i]==ans){
				printf("%d\n", i+1);
				break;
			}
		}
		
			
		
	}
	
	return 0;
}
