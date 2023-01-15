#include <stdio.h>
#include <string.h>
 
int main()
{
	char str[40];
	int m;
	while(scanf("%d", &m)!=EOF){
		int i, j;
		getchar();
		for(i=0;i<m;i++){
			int a=0, b=0, c=0, d=0;
			
			gets(str);
			if(strlen(str)>=8&&strlen(str)<16){
				for(j=0;j<strlen(str);j++){
					if(str[j]>='A'&&str[j]<='Z') a=1;
					if(str[j]>='a'&&str[j]<='z') b=1;
					if(str[j]>='0'&&str[j]<='9') c=1;
					if(str[j]=='~') d=1;
					if(str[j]=='!') d=1;
					if(str[j]=='@') d=1;
					if(str[j]=='#') d=1;
					if(str[j]=='$') d=1;
					if(str[j]=='%') d=1;
					if(str[j]=='^') d=1;
				}
				
			}
			if(a+b+c+d>=3) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
