#include <stdio.h>
int main()
{
	int ret = 0;
	
	int n, m;
	scanf("%d %d", &n, &m);
	int a[n];
	int i, k;
	scanf("%d", &k);
	
	int count = 0;
	a[count++] = k;

	for(i=0;i<n-1;i++){
		scanf(" %d", &k);
		a[count++] = k;
		
	}

		for(i=0;i<n;i++){
			if(a[i]==m){	
				printf("%d", i);
				ret = 1;
			}	
		}
	if(ret == 0){
		printf("Not Found\n");
	}
	return 0; 
}
