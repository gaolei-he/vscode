#include <stdio.h>
 
int main()
{
	int min = 10;
	int a[10];
	int i, j;
	int t;
	for(i=0;i<10;i++){
		scanf("%d", &a[i]);
	}
	for(i=0;i<10;i++){
		if(a[i]!=0){
			if(a[i]<min){
				min=a[i];
				t = i;
			}	
		}
	}
	printf("%d",a[t]);
	a[t]=10;
	min = 10;


	for(j=0;j<10;j++){
	
	for(i=0;i<10;i++){
		if(min>a[i]){
			min=a[i];
			t = i;
		}
	}
	if(a[t]!=10){
	
	printf("%d", a[t]);
	a[t]=10;
	}
	min=10;
	}
	return 0;

}
