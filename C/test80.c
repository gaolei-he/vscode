#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
int main()
{
	int n, m;
	char a[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	char b[100];


	while(scanf("%d %d", &n, &m)!=EOF){
		if(n<0) {
			n = -n;
			printf("-");
		}
		if(n==0){
			printf("0\n");
			continue;
		}
		int i, j;
		for(i=0;n!=0;i++){
			j = n%m;
			b[i]=a[j];
			n /= m;
		}
		b[i]='\0';
		
		for(i=strlen(b)-1;i!=-1;i--){
			printf("%c", b[i]);
		}
		printf("\n");
			
		
	}
	return 0;
}
