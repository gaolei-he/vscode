#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char a[500];
	
	int n;
	while(scanf("%d", &n)!=EOF){
		int cnt = 0;
		getchar();
		int i, j;
		for(i=0;i<n;i++){
			
			gets(a);		
			for(j=0;j<strlen(a);j++){
				if(a[j]<0){
					cnt ++;
				}
				
		}
		printf("%d\n", cnt/2);
		cnt = 0;
		}
	}
	return 0;
	
}
