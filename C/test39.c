#include <stdio.h>
int main()
{
	char a[99999];
	scanf("%s", a);
	int i = 0;
	while(1){
		if(a[i]!='*'&&a[i]!=0){
		
		printf("%c",a[i]);
		}
		if(a[i]==0){
			break;
		}
		i ++;
		}
	return 0;
}
