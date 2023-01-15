#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
struct People
{
    char piao[110];
    int id;
};
bool cmp(People s1, People s2)
{
    if(strlen(s1.piao)==strlen(s2.piao))
    {
        int len = strlen(s1.piao);
        for(int i=0;i<len;i++)
        {
            if(s1.piao[i]==s2.piao[i]) continue;
            else return s1.piao[i] > s2.piao[i];
        }
    }
    return strlen(s1.piao) > strlen(s2.piao);
}
int main()
{
    int n;
    cin >> n;
    People a[n];
    int cnt = 1;
    for(int i=0;i<n;i++)
    {
        scanf("%s", a[i].piao);
        a[i].id = cnt ++;
    }
    sort(a, a+n, cmp);
    printf("%d\n%s", a[0].id, a[0].piao);

    return 0;
}