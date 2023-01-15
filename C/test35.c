#include <stdio.h>
int a[1002];
int main()

{
	
	int count[10];
	int i;
	for(i=0;i<10;i++){
		count[i]=0;
	}
	int t;
	int p;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d", &a[i]);
	
	}
	for(i=0;i<t;i++){
		while(a[i]!=0){
			count[a[i]%10]++;
			a[i]/=10;
		}
	}
	int max = 0;
	for(i=0;i<10;i++){
		if(max<count[i]){
			max = count[i];
			
		}
	}
	printf("%d:", max);
	for(i=0;i<10;i++){
		if(count[i]==max){
			printf(" %d", i);
		}
	}
	printf("\n");
	return 0;


} 
