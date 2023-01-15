#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c, d, x1, x2, q, m, n;

	printf("输入任意三个整数: ");
	scanf("%f %f %f", &a, &b, &c);

	d = b * b - 4 * a * c;

	if(d > 0)
    {
        q = sqrtf(d);

        x1 = (-b + q) / (2 * a);
        x2 = (-b - q) / (2 * a);

        printf("d = %.1f, x1 = %.1f, x2 = %.1f",d,x1,x2);
    }

    else
    {
    	m = -b / (2 * a);
    	n = sqrtf(-d) / (2 * a);

    	printf("d = %.1f, x1 = %.1f, x2 = %.1f",d,m,n);
	}

	return 0;
}
