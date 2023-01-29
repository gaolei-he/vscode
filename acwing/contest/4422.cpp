#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i;
    for(i=1;n >= 0;i++)
    {
        n -= i * (i + 1) / 2;
    }
    cout << i - 2;
    return 0;
}