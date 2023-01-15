#include <stdio.h>
#include <string.h>
int main()
{
	char a[222][10];
	int n;
	while(scanf("%d", &n)!=EOF){
		int i, j, k;
		for(i=0;i<n*2;i++){		
			scanf("%s", a[i]);			
		}
		int ret = 0, cnt = 0;
		for(i=0;i<n;i++){
			for(j=n;j<2*n;j++){
				if(strcmp(a[i], a[j])==0){
				
					strcpy(a[j], "ending");
					strcpy(a[i], "ending");
					}
			}
		}
		for(i=0;i<n;i++){
			if(strlen(a[i])==6) continue;
				for(j=n;j<2*n;j++){
					if(strlen(a[i])==strlen(a[j])){
						cnt ++;
						strcpy(a[j], "ending");
						break;
					}									
				}
				
			
			
		}
		printf("%d\n", cnt);
	}
	return 0;
}
