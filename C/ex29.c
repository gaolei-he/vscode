//求质数（十个一行） 
#include <stdio.h>
int main()
{
	int nu, num;
	scanf("%d %d", &nu, &num);
	while(nu>num){
		printf("ERROR! type again\n");
		scanf("%d %d", &nu, &num);//输出区间 
	}
	
	int prime = 2, a = 2;
	int listPrime[10001];
	int i = 0;
	int shang = 0;
	while(1){//判断质数 
	
	while(prime>a){
		shang = prime%a;
		if(shang == 0){
			a = 1;
			prime ++;//如果整除，直接下一个算下一个数 
		}
		a ++;
	}//一直没有整除，就是质数，通过下半个循环将质数加入列表，并开始求下一个数 
	a = 2;
	listPrime[i]=prime;//质数放进列表 
	if(i==num-1){
		break;//到达输出上限，不再追加质数 跳出找质数循环 
	}
	i ++;
	prime ++;	
	}
	int count = 0;
	for(i=nu-1;i<=num-1;i++){
		printf("%d",listPrime[i]);
		count ++;
		if(count<10){//十个一行 
			printf(" ");
		}else{
			printf("\n");
			count = 0;
		}
	}
	return 0;
}
