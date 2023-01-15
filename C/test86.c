#include <stdio.h>
int main()
{
	int n;
	int a[101], b[101];
	while(scanf("%d", &n)!=EOF){
		if(n==0) break;
		int i;
		for(i=0;i<n;i++){
			scanf("%d %d", &a[i], &b[i]);
		}
		int j, k;
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				if(b[i]>b[j]){
					k = b[i], b[i] = b[j], b[j] = k;
					k = a[i], a[i] = a[j], a[j] = k;
				}
			}
		}
		int cnt = 1;
		k = b[0];
		for(i=0;i<n;i++){
			if(a[i]>=k){
				cnt ++;
				k = b[i];
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
