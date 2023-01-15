#include <iostream>
using namespace std;
int mi = 0x7fffffff, cnt = 0, n, m;
char a[53][53];
void f(int i1, int j1, int k1)
{
    for(int i=0;i<i1;i++)
        for(int j=0;j<m;j++) if(a[i][j]!='W') cnt ++;
    for(int i=i1;i<i1+j1;i++)
        for(int j=0;j<m;j++) if(a[i][j]!='B') cnt ++;
    for(int i=i1+j1;i<i1+j1+k1;i++)
        for(int j=0;j<m;j++) if(a[i][j]!='R') cnt ++;
    mi = (cnt>mi?mi:cnt);
    cnt = 0;
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++) scanf("%s", a[i]);
    int i = 1, j = 1;
    for(;i<n-1;i++)
        for(j=1;i+j<n;j++) f(i, j, n-i-j);
    cout << mi;
    return 0;
}