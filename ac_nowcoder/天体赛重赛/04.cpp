#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int k)
{
    if(k<=1||k==4) return false;
    else if(k==2||k==3||k==5) return true;
    else if(k%2==0||k%3==0) return false;
    else
    {
        double length = sqrt(k);
        for(int i=5;i<=length;i+=6)
        {
            if(k%i==0||k%(i+2)==0) return false;
        }
        return true;
    }
}
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int num;
        scanf("%d", &num);
        if(isPrime(num)) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}