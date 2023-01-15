#include <iostream> 
using namespace std;

int fact(int n){
	int c = 1;
	if(n==1) return c;
	else c = fact(n-1)*n;
	
}
int main()
{
	int a = 5;
	int x = fact(a);
	printf("%d", x);
	return 0;
}
