#include <iostream>
using namespace std;

int f(int k)
{
    if(k==0) return 6;
    int sum = 0;
    while(k)
    {
        switch (k%10)
        {
        case 0: sum += 6; break;
        case 1: sum += 2; break;
        case 2: sum += 5; break;
        case 3: sum += 5; break;
        case 4: sum += 4; break;
        case 5: sum += 5; break;
        case 6: sum += 6; break;
        case 7: sum += 3; break;
        case 8: sum += 7; break;
        case 9: sum += 6; break;
        }
        k /= 10;
    }
    return sum;
}

int main()
{
    int n, cnt = 0;
    cin >> n;
    n -= 4;
    for(int i=0;i<=1000;i++)
    for(int j=0;j<=1000;j++)
    {
        //if(i==j) continue;
        if(f(i)+f(j)+f(i+j)==n) cnt ++;
    }
    cout << cnt;
    return 0;
}