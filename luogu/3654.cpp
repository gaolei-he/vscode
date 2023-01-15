#include <iostream>
using namespace std;
char a[110][110];

bool check(int i, int j, int k, int ret)
{
    if(ret)
    {
        for(int i1=0;i1<k;i1++, j++) if(a[i][j]!='.') return false;
        return true;
    }
    else
    {
        for(int j1=0;j1<k;i++, j1++) if(a[i][j]!='.') return false;
        return true;
    }
}

int main()
{
    int r, c, k, cnt = 0;
    cin >> r >> c >> k;
    for(int i=0;i<r;i++) scanf("%s", a[i]);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {
            if(j<=c-k){
                if(check(i, j, k, 1)) cnt ++;}
            if(i<=r-k){
                if(check(i, j, k, 0)) cnt ++;}
        }
    if(k==1) cnt /= 2;
    cout << cnt;
    return 0;
}