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
	printf("ƽ�����ǣ�%f", ans*1.0/count);
	return 0;
}
