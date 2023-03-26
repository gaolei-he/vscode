#include <stdio.h>
int main(){
	int count = 0;
	int number = 0;
	int ans = 0;
	while(number != -1){
		scanf("%d", &number);
		count ++;
		ans += number;
	}
	printf("平均数是：%f", ans*1.0/count);
	return 0;
}
