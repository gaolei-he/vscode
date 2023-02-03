#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cnt = 0, a[n];
    while(n--)
    {
        int n0 = 0, n1 = 0;
        int tmp;
        cin >> tmp;
        while(tmp)
        {
            if(tmp&1) n1 ++;
            else n0 ++;
            tmp >>= 1;
        }
        if(n1==n0&&(n1&1)==0) a[cnt++] = 10;
        else if((n1&1)==0) a[cnt++] = 1;
        else if((n0&1)==0) a[cnt++] = 0;
        else a[cnt++] = 100;
    }
    for(int i=0;i<cnt;i++) cout << a[i] << ' ';
    return 0;
}