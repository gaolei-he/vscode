#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cout << n << '=';
    vector<int> a;
    for(int i=2;i<=n/i;i++)
    {
        if(n % i == 0)
        {
            while(n%i==0)
            {
                a.push_back(i);
                n /= i;
            }
        }
    }
    if(n > 1) a.push_back(n);
    cout << a.front();
    for (int i = 1; i < a.size(); i++)
    {
        cout << '*' << a[i];
    }
    
    return 0;
}