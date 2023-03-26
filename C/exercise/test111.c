#include <stdio.h>
#include <string.h>
void result(char *a);
char a[100000], b[100000];
int main()
{
	while(scanf("%s %s", a, b)!=EOF){
		
		result(a);
		result(b);
		if(strcmp(a,b)==0){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
}
void result(char *a){
	int i;
	for(i=0;i<strlen(a);i++){
		if(a[i]!='0') break;
	}
	strcpy(a,a+i);
	int flag = 0;
	for(i=0;i<strlen(a);i++){
		if(a[i]=='.') flag = 1;
	}
	if(flag){
		for(i=strlen(a)-1;i!=-1;i--){
			if(a[i]=='.'){
				a[i]='\0';
				break;
			}
			if(a[i]=='0') a[i]='\0';
			else break;
		}
	}
}
