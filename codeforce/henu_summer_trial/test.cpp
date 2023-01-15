#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int k)
{
    for(int i=2;i<k;i++) if(k%i==0) return false;

    return true;
}

int main()
{
    int n;cin >> n;
    
    for(int i=2;i<=n;i++)
    {
        if(isPrime(i))  cout << i << ',';
        if(i % 100 == 0) cout << endl;
    }
    return 0;
}