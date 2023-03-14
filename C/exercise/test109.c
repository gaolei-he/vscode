#include <stdio.h>
int main()
{
	char x;
	int y;
	int cnt;
	scanf("%d", &cnt);
	
	while(cnt--){
	getchar();
	scanf("%c%d", &x, &y);
	
		int n;
		if(x>='A'&&x<='Z'){
			n = (int)x-'A';
			n ++;
		}else{
			n = (int)'a'-x;
			n --;
		}
		printf("%d\n", n+y);
	}
	
	return 0;
}
