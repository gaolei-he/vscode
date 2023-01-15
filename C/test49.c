#include <stdio.h>
#include <string.h>
int main()
{
	char str[80];
	gets(str);
	int n, i;
	scanf("%d", &n);
	if(n%strlen(str)==0){
		puts(str);
	}else{
		for(i=n;i<strlen(str);i++){
			printf("%c", str[i]);
		}
		for(i=0;i<n;i++){
			printf("%c", str[i]);
		}
	}

	return 0;
}
