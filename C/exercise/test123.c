#include <stdio.h>
int main()
{
	int n, a[1003], b[1003];
	double m;
	while(scanf("%d\n%lf", &n, &m)!=EOF){
		int i, j, k;
		for(i=1;i<=n;i++){
			scanf("%d", &a[i]);
		}
		for(i=1;i<=n;i++){
			scanf("%d", &b[i]);
		}
		double fuel = 0.0;
		if(b[1]-1==0){
			printf("-1\n");
			continue;
		}
		fuel = m/(b[1]-1);
		m += fuel;
		int ret = 0;
		int n1=n, n2=n;
		double fuel1;
		for(i=2;i<=2*n;i++){
			if(a[n1]-1==0||b[n2]-1==0){
					printf("-1\n");
					ret = 1;
					break;
				}
			if(i%2==0){				
				fuel1 = m/(a[n1]-1);
				m += fuel1;
				fuel +=fuel1;
				n1 --;
			}else{
				fuel1 = m/(b[n2]-1);
				m += fuel1;
				fuel += fuel1;
				n2 --;
			}
		}
		if(ret==1) continue;
		else printf("%.10f\n", fuel);
	}
	return 0;
}
