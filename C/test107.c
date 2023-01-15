#include <stdio.h>
char a[1000000], b[1000000];
int main()
{
	gets(a);
	gets(b);
	
	while(scanf("%d %d", &m, &n)!=EOF){
		if(m==n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
