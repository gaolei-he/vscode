#include<stdio.h>
#include<math.h>
int main(void) {
	int m, n;
	while (scanf_s("%d%d", &n, &m) != EOF) {
		int k=0;
		int i, j;
		double sum=0, sum1=0;
		double a[51][6] = { 0 };
		double pj[6] = {0};
		double tx[51] = { 0 };
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				scanf_s("%lf", &a[i][j]);
			}
		}
		for (j = 1; j <= m; j++) {
			for (i = 1; i <= n; i++) {
				pj[j] += a[i][j];
			}
		}
		for (i = 1; i <= m; i++) {
			pj[i]/=n;
		}
		for (i = 1; i <= n; i++) {
			if (a[i][1] >= pj[1] && a[i][2] >= pj[2] && a[i][3] >= pj[3] && a[i][4] >= pj[4] && a[i][5] >= pj[5]) {
				k++;
			}
		}
	
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				tx[i] += a[i][j];
			}
			tx[i] = tx[i] / m;

		}
		for (i = 1; i < n; i++) {
			printf("%.2f ", tx[i]);
		}
		printf("%.2f\n", tx[i]);
		for (i = 1; i < m; i++) {
			printf("%.2f ", pj[i]);
		}
		printf("%.2f\n", pj[i]);
		printf("%d\n\n", k);
		
	}
}

