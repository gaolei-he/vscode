#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e5+10;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if(n & 1)
        {
            printf("7");
            n -= 3;
            while (n)
            {
                n -= 2;
                printf("1");
            }
            puts("");
            
        }
        else
        {
            while (n)
            {
                n -= 2;
                printf("1");
            }
            puts("");
            
        }
    }
    
    return 0;
}