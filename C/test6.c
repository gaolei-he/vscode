#include <stdio.h>
int main()
{
	int a=0, i,j,k;
	scanf("%d", &a);
	i=a;
	int cnt = 0;
	while (i<=a+3){
		j=a;
		while(j<=a+3){
			k=a;
			while(k<=a+3){
				if(i!=j){
					if(i!=k){
						if(j!=k){
							printf("%d%d%d",i,j,k);
							cnt++;
							if(cnt!=6){
								printf(" ");
								
							}else{
								printf("\n");
								cnt = 0;
							}
						}
					}
				}
				
			
			k++;
			}
		j++;
		}
	i++;
	}
	return 0;
}
