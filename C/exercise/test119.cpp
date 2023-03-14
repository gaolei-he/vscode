#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int a[100004];
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF){
		int i, j, k;
		for(i=0;i<n;i++){
			scanf("%d", &a[i]);
		}
	/*	for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				if(a[i]>a[j]){
					int t;
					t=a[i], a[i]=a[j], a[j]=t;
				}
			}
		}*/ 
		sort(a,a+i,less<int>());
		int cnt = 0;
		j = n - 2;
		for(i=n-1;j!=-1;){
			if(a[i]>a[j]){
				cnt ++;
				j --;
				i --;
			}
			else j--;
			
		}
		printf("%d\n", cnt);
	}
	
	return 0;
}
