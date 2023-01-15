#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long n;
    cout << 5 % -9;
    cin >> n;
    for(long long i=2;i*i<=n;i++)
    {
        while(n % (i*i) == 0) n /= i;
    }
    cout << n << endl;
    
    return 0;
}