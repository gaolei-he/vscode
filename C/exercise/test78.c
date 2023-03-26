#include <stdio.h>
#include <string.h>

int main()
{
	char a[100];
	int n;
	while(scanf("%d", &n)!=EOF){
		int cnt=0;
		int i;
		getchar();
		for(i=0;i<n;i++){
			gets(a);
			int j;
			for(j=0;j<strlen(a);j++){
				if(a[0]>'9'||a[0]<='0'){
				if((a[j]>='0'&&a[j]<='9')||(a[j]>='a'&&a[j]<='z')||(a[j]>='A'&&a[j]<='Z')||(a[j]=='_')){
					cnt++;
				}
				}
				
			}
			if(cnt==strlen(a)){
				printf("yes\n");
			}else{
				printf("no\n"); 
			}
			cnt = 0;
		}
	}
	return 0;
}
