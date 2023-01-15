#include <stdio.h>
#include <string.h>

//using namespace std;
int pow1(int n, int m);
int main()
{
	int n;
	scanf("%d", &n);
	char a[n][50];
	getchar();
	int i;
	for(i=0;i<n;i++) gets(a[i]);
	
	for(i=0;i<n;i++){
		if(a[i][0]=='a'){
			int sum1 = 0, sum2 = 0, cnt = 0;
			int j=strlen(a[i])-1;
			for(;a[i][j]!=' ';j--)	
				sum1 += (int)(a[i][j]-48)*pow1(10,cnt++);
			cnt = 0;
			for(j--;a[i][j]!=' ';j--)
				sum2 += (int)(a[i][j]-48)*pow1(10,cnt++);
			int lenth = printf("%d+%d=%d\n", sum2, sum1, sum1+sum2);
			printf("%d\n", lenth-1);
		}
		else if(a[i][0]=='b'){
			int sum1 = 0, sum2 = 0, cnt = 0;
			int j=strlen(a[i])-1;
			for(;a[i][j]!=' ';j--)	
				sum1 += (int)(a[i][j]-48)*pow1(10,cnt++);
			cnt = 0;
			for(j--;a[i][j]!=' ';j--)
				sum2 += (int)(a[i][j]-48)*pow1(10,cnt++);
			int lenth = printf("%d-%d=%d\n", sum2, sum1, sum2-sum1);
			printf("%d\n", lenth-1);
		}
		else if(a[i][0]=='c'){
			int sum1 = 0, sum2 = 0, cnt = 0;
			int j=strlen(a[i])-1;
			for(;a[i][j]!=' ';j--)	
				sum1 += (int)(a[i][j]-48)*pow1(10,cnt++);
			cnt = 0;
			for(j--;a[i][j]!=' ';j--)
				sum2 += (int)(a[i][j]-48)*pow1(10,cnt++);
			int lenth = printf("%d*%d=%d\n", sum2, sum1, sum1*sum2);
			printf("%d\n", lenth-1);
		}
		else{
			int sum1 = 0, sum2 = 0, cnt = 0;
			int j=strlen(a[i])-1;
			for(;a[i][j]!=' ';j--)	
				sum1 += (int)(a[i][j]-48)*pow1(10,cnt++);
			cnt = 0;
			for(j--;j>=0;j--)
				sum2 += (int)(a[i][j]-48)*pow1(10,cnt++);
			int lenth = printf("%d+%d=%d\n", sum2, sum1, sum1+sum2);
			printf("%d\n", lenth-1);
		}
	}
	return 0;
}
int pow1(int n, int m)
{
	int sum = 1;
	int i;
	for(i=0;i<m;i++)
		sum *= n;
	return sum;
}
