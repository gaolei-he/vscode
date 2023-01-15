#include <algorithm>
#include <iostream>
using namespace std;
struct OI
{
    char name[22];
    int year;
    int month;
    int day;
    int id;
};
bool cmp(OI a, OI b)
{
    if(a.year==b.year)
    {
        if(a.month==b.month)
        {
            if(a.day==b.day) return a.id > b.id;
            else return a.day < b.day;
        }
        else return a.month < b.month;
    }
    else return a.year < b.year;
}
int main()
{
    int n;
    cin >> n;
    OI a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%s %d %d %d", a[i].name, &a[i].year, &a[i].month, &a[i].day);
        a[i].id = i;
    }
    sort(a, a+n, cmp);

    for(int i=0;i<n;i++) printf("%s\n", a[i].name);
    return 0;
}