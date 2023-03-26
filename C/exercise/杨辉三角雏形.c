#include <stdio.h>
int a[30][30];

int main()
{
	int n;
	int j, k;
	for(j=0;j<30;j++){
		for(k=0;k<=j;k++){
			a[j][k] = 0;
			if(k==0) a[j][0] = 1;
			if(j!=0&&k!=0) a[j][k] = a[j-1][k] + a[j-1][k-1];
		}
	}


	while(scanf("%d", &n)!=EOF){
		int cnt = 0;
		int cnt1 = 1;
		for(j=0;j<n;j++){
			for(k=0;k<=j;k++){
			printf("%d", a[j][k]);

			cnt ++;
			if(cnt1 == cnt) {
				printf("\n");
				cnt1 ++;
				cnt = 0;
			}else{
				printf(" ");
		}
		}
		}
		printf("\n");
	}
	return 0;
}


