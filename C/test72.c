//1-V
#include <stdio.h>
int main()
{
	int n;

	while(scanf("%d", &n)!=EOF){
		if(n==0){
			break;
		}
		int a[101], b[101];
		int i, j, k;
		for(i=0;i<n;i++){
			scanf("%d", &a[i]);
			if(a[i]>=0){
				b[i]=a[i];
			}
			else{
				b[i]=-a[i];
			}
		}

		int max=-1;
		int ret=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(max<b[j]){
					max=b[j];
					k=j;
				}
			}

			if(ret==0){
				printf("%d", a[k]);
				ret=1;
			}else{
				printf(" %d", a[k]);
			}
			b[k]=-1;
			max=-1;
		}
		printf("\n");
	}
	return 0;
}
