#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], b[n] = { 0 };
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    for(int i=0;i<n-1;i++)
        b[abs(a[i]-a[i+1])>n-1?0:abs(a[i]-a[i+1])] = 1;
    for(int i=1;i<n;i++)
        if(b[i]==0)
        {
            cout << "Not jolly";
            return 0;
        }
    cout << "Jolly";
    return 0;
}