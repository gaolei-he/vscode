#include <stdio.h>
int main()
{
	int n;
	while(scanf("%d", &n)!=EOF){
		int i;
		int h1, h2, h3, h4, h5, h6;
		for(i=0;i<n;i++){
			scanf("%d %d %d %d %d %d", &h1, &h2, &h3, &h4, &h5, &h6);
			int a1 = h3 +h6;
			if(a1>=60){
				a1 -= 60;
				h2 ++;
			}
			int a2 = h2 + h5;
			if(a2>=60){
				a2 -= 60;
				h1 ++;
			}
			int a3 = h1 + h4;
			printf("%d %d %d\n", a3, a2, a1);
		}
	}

}
