#include <stdio.h>

int isPrime(int x);
int isPrime1(int x);
int main()
{
	int x;
	scanf("%d", &x);
	if(isPrime1(x)){
		printf("Yes!\n");
	}else{
		printf("No!\n");
	}
	return 0;
}
int isPrime(int x)
{
	int ret = 1;
	int i;
	if(x==ret) ret = 0;
	for(i=2;i<x;i++){
		if(x%i==0)
		ret = 0;
		break;
	}
	return ret;//是素数返回1，不是返回0  
}

int isPrime1(int x)
{
	int ret = 1;
	int i;
	if(x==ret||(x%2==0&&x!=2))
		ret = 0;
	for(i=3;i<x;i+=2){
		if(x%i==0){
			ret = 0;
			break;
		}
		
	}
	return ret;
}
