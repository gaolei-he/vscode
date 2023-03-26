#include <stdio.h>
int main()
{
	int a, b, c;
	int num[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	
	while(scanf("%d/%d/%d", &a, &b, &c)!=EOF){
			b --; 
			int sum = 0;
			int i = 0;
		if(a%100==0){
			if(a%400==0){
				sum ++; 
			}else{	
			}
			while(b!=0){
				sum += num[i];
				i ++;
				b --;
			}
			printf("%d\n", sum+c);
			continue;
		}
		if(a%4==0){
			sum ++;
		} else{
			 
		}
		while(b!=0){
				sum += num[i];
				i ++;
				b --;
			}
			printf("%d\n", sum+c); 
	}
	return 0;
}
