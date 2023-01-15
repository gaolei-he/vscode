#include <iostream>
using namespace std;
const int N = 10000;
int f(int n)
{
    if(n==1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 5;
    
    else return 2*f(n-1)+f(n-3)%10000;
}
int main()
{
    int n;
    cin >> n;
    int a[1000010];
    a[1] = 1, a[2] = 2, a[3] = 5;
    for(int i=4;i<=n;i++)
    {
        a[i] = (2*a[i-1] + a[i-3]) % N;
    }
    cout << a[n];
    return 0;
}
