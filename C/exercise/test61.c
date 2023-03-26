#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF){
		getchar();
		int i, j;
		char str[10000];
		for(i=0;i<n;i++){
			int count = 0;
			
			gets(str);
			for(j=0;j<strlen(str);j++){
				if(str[j]>='0'&&str[j]<='9'){
					count ++;
				}
				
			}
			printf("%d\n", count);
		}
	}
	return 0;
}
