#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct A
{
    int x, y;
    /* data */
};
bool rule(A a, A b)
{
    if(a.x==b.x) return a.y<b.y;
    else return a.x<b.x;
}
bool check(A a, A b, A c)
{
    int x1, x2, x3, y1, y2, y3;
    x1 = a.x, x2 = b.x, x3 = c.x;
    y1 = a.y, y2 = b.y, y3 = c.y;
    if(x1-x2==0&&y1-y3==0||x1-x3==0&&y1-y2==0) return false;
    else if(x2-x1==0&&y2-y3==0||x2-x3==0&&y2-y1==0) return false;
    else if(x3-x1==0&&y3-y2==0||x3-x2==0&&y3-y1==0) return false;
    else return true;
}

int main()
{
    int n;
    cin >> n;

    A a[n];

    for(int i=0;i<n;i++) scanf("%d %d", &a[i].x, &a[i].y);
    double S = 0;
    for(int i=0;i<n-2;i++)
        for(int j=i+1;j<n-1;j++)
            for(int k=j+1;k<n;k++)
            {
                double a1, b, c;
                if(check(a[i], a[j], a[k])) continue;
                a1 = sqrt(pow(a[i].x-a[j].x, 2)+pow(a[i].y-a[j].y, 2));
                b = sqrt(pow(a[i].x-a[k].x, 2)+pow(a[i].y-a[k].y, 2));
                c = sqrt(pow(a[j].x-a[k].x, 2)+pow(a[j].y-a[k].y, 2));
                
                double p = (a1+b+c)/2;
                double tmp = 2 * sqrt(p*(p-a1)*(p-b)*(p-c));
                S = max(tmp, S);
            }
    printf("%.0f", S);
    return 0;
}