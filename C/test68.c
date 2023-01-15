#include <stdio.h>
double fact(int i);
int main()
{
	int i, n;
	while (scanf("%d", &n)!=EOF){
	double e = 1;
	float a = 1;
	
	
	for(i=1;i<=n;i++){
		e += 1.0/fact(i);
		a += 1.0/fact(i);
	}
	printf("%.50f\n%.50f\n", e, a);
	
	}
	return 0;
}
double fact(int i)
{
	int j;
	double k=1;
	for(j=1;j<=i;j++){
		k *= j;
	}
	return k;
}
