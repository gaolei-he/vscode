#include <iostream>
#include <algorithm>
using namespace std;
struct Students
{
    int chi;
    int math;
    int eng;
    int sum;
    int id;
};
bool cmp(Students s1, Students s2)
{
    
        if(s1.sum==s2.sum)
            if(s1.chi==s2.chi) return s1.id < s2.id;
            else return s1.chi > s2.chi;
        else return s1.sum > s2.sum;
        
    
}

int main()
{
    int n;
    cin >> n;
    Students a[n];
    int cnt = 1;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d", &a[i].chi, &a[i].math, &a[i].eng);
        a[i].sum = a[i].chi + a[i].math + a[i].eng;
        a[i].id = cnt ++;
    }
    sort(a, a+n, cmp);
    for(int i=0;i<5;i++) printf("%d %d\n", a[i].id, a[i].sum);

    return 0;
}