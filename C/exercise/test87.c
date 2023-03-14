#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF){
		int t;
		double i, j, k;
		for(t=0;t<n;t++){
			scanf("%lf %lf %lf", &i, &j, &k);
			if(k<i+j&&i<k+j&&j<i+k) 
			printf("YES\n");
			else printf("NO\n");
/*			for(i=0;i<2;i++){
				for(j=i+1;j<3;j++){
					if(a[i]<a[j]){
						k = a[i], a[i] = a[j], a[j] = k;
					}
				}
			}
			if(a[0]<a[1]+a[2]){
				printf("YES");
			}else{
				printf("NO");
			}*/ 
			
		}
	}
	
	return 0;
}
