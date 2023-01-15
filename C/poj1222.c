#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        long double n;
        long double n1;
        cin>>n;
        n1 = sqrt(n);
        n1 = floor(n1);
        if(n1==n) cout>>"YeS">>endl;
        else cout>>"n0">>endl;
    }
    return 0;
}
