#include <iostream>
#include <algorithm>
using namespace std;
bool f(int year, int n)
{
    int a[4];

    for(int i=0;i<4;i++)
    {
        if(year==0) a[i] = 0;
        else 
        {
            a[i] = year % 10;
            year /= 10;
        }
    }
    int times = 1;
    sort(a, a+4);
    for(int i=1;i<4;i++)
    {
        if(a[i-1]!=a[i]) times ++;
    }
    if(times==n)return true;
    else return false;
}
int main()
{
    int year, n;
    cin >> year >> n;
    int tmp = year;
    for(;;year++)
        if(f(year, n)) break;
    printf("%d %04d", year-tmp, year);
    return 0;
}