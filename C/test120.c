#include <stdio.h>
#include <string.h>
int main()
{
	char str[102];
	while(gets(str)){
		int i, j, k, ret = 0;
	
		for(i=0;i<strlen(str)-1;i++){
		/*	if(str[i]=='n'&&str[i+1]!='a'&&str[i+1]!='e'&&str[i+1]!='i'&&str[i+1]!='o'&&str[i+1]!='u'&&str[i+1]!='n'){
				printf("NO\n");
				ret = 1;
				break;
			}*/
			if(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u'&&str[i]!='n'){
				if(str[i+1]=='a'||str[i+1]=='e'||str[i+1]=='i'||str[i+1]=='o'||str[i+1]=='u');
				else{
					printf("NO\n");
					ret = 1;
					break;
				}
			}
		}
		if(str[strlen(str)-1]!='a'&&str[strlen(str)-1]!='e'&&str[strlen(str)-1]!='i'&&str[strlen(str)-1]!='o'&&str[strlen(str)-1]!='u'&&str[strlen(str)-1]!='n'&&ret==0){
			printf("NO\n");
			ret = 1;
		}
		if(ret==0) printf("YES\n");
	}
	
	return 0;
}
