#include <stdio.h>
int main()
{
	char c;
	int sum = 0;
	while(1){
	scanf("%c", &c);
	if(c=='.'){
		break;
	}
	sum += (c-48);
	}
	int t = sum;
	int count = 1;
	while(t!=0){
		t /= 10;
		count *=10;
	}
	count /= 10;
	
	int mark;
	while (count!=0){
		mark = sum / count;
		sum = sum % count;
		count /= 10;
		if(count==0){
			switch(mark){
			case 0:printf("ling ");break;
			case 1:printf("yi ");break;
			case 2:printf("er ");break;
			case 3:printf("san ");break;
			case 4:printf("si ");break;
			case 5:printf("wu ");break;
			case 6:printf("liu ");break;
			case 7:printf("qi ");break;
			case 8:printf("ba ");break;
			case 9:printf("jiu ");break;
		}
		break;
		}
		switch(mark){
			case 0:printf("ling ");break;
			case 1:printf("yi ");break;
			case 2:printf("er ");break;
			case 3:printf("san ");break;
			case 4:printf("si ");break;
			case 5:printf("wu ");break;
			case 6:printf("liu ");break;
			case 7:printf("qi ");break;
			case 8:printf("ba ");break;
			case 9:printf("jiu ");break;
		}
	}
	return 0;
}
