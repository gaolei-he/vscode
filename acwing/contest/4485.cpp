#include <iostream>
using namespace std;
int sum1, sum2;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum1 += x;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum2 += x;
    }
    if(sum1 >= sum2) puts("Yes");
    else puts("No");
    
    
    return 0;
}