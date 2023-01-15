#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int t;
    
    cin >> t;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int tmp = 0, tmp1 = n;
        while(tmp1)
        {
            tmp += tmp1 % 10;
            tmp1 /= 10;
        }
        vector<int> a;
        for(int i=1;i<=tmp;i++) if(n%i==0 && tmp % i == 0) a.push_back(i);
        printf("%ld\n", a.size());
        for(auto i:a) printf("%d ", i);
        puts("");
    }
    
    return 0;
}