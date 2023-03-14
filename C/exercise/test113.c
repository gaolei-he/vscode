#include <stdio.h>
int ar[5000];
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF){
		int i, j, a, b;
		int max = 0, min = 5000;
		for(i=0;i<n;i++){
			scanf("%d %d", &a, &b);
			if(a>b){
				int t;
				a = b, b = t;
			}
			if(max<b) max = b;
			if(min>a) min = a;
			for(j=a;j<=b;j++){
				ar[j]++;
			}
		}
		int max1 = 0;
		int t;
		for(i=min;i<=max;i++){
			if(max1<ar[i]){
				max1 = ar[i];
				t = i;
			}
		}
		printf("%d\n",t);
	}
	return 0;
}
