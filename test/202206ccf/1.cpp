#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 1e3+10;
int a[N];
int main()
{
    int n;
    cin >> n;
    double tmp = 0;
    for(int i=0;i<n;i++) {scanf("%d", &a[i]); tmp += a[i];}
    double ave = tmp / n;
    tmp = 0;
    for (int i = 0; i < n; i++) tmp += (a[i] - ave) * (a[i] - ave);
    tmp = tmp / n;
    for (int i = 0; i < n; i++) printf("%f\n", (a[i]-ave)/sqrt(tmp));
    

    return 0;
}