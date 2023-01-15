#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
int main()
{
	int n, k;
	char a[60];
	while(scanf("%d %d", &n, &k)!=EOF){
		gets(a);
		
		sort(a,a+strlen(a));
		int i, j, k;
		int cnt = 1;
		int sum = (int)a[0];
		for(i=1;i<n;i++){
			if(a[i]-a[i-1]>1){
				sum += (int)a[i];
				cnt ++;
			}
		}
		if(cnt==k) printf("%d\n", sum-(96*k));
		else printf("-1\n");
	}
	
	return 0;
}
