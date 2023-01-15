#include <iostream>
#include <cstring>
using namespace std;

const int N = 20;
char str[N];
int n;
bool check(int mid)
{
    int len = 0;
    int cnt = 2;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='1') len = 0;
        if(len==mid) len = 0, cnt--;
        len ++;

    }
    if(cnt>=0) return true;
    else return false;
}


int main()
{
    
    cin >> n;
    cin >> str;
    int l = 0, r = n;
    while(l<r)
    {
        int mid = l + r >> 1;
        if(check(mid))r = mid;
        else l = mid + 1;
    }
    cout << l;
    return 0;
}