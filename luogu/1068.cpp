#include <iostream>
#include <algorithm>
using namespace std;
struct students
{
    int id;
    int score;
};
bool cmp(students s1, students s2)
{
    if(s1.score==s2.score) return s1.id < s2.id;
    return s1.score > s2.score;
}
int main()
{
    int n, m;
    cin >> n >> m;
    students a[n];
    for(int i=0;i<n;i++) scanf("%d %d", &a[i].id, &a[i].score);

    sort(a, a+n, cmp);

    int nscore = a[m*3/2-1].score;
    int num = m * 3 / 2 - 1;
    for(;num<n;num++)
        if(a[num].score!=nscore) break;
    num --;
    
    printf("%d %d\n", nscore, num+1);
    for(int i=0;i<num+1;i++) printf("%d %d\n", a[i].id, a[i].score);
}