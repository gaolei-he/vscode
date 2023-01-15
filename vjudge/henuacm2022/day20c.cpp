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
vector<int> prime;
bool st[1299709+10];
int main()
{
    int cnt = 0;
    for(int i=2;i<=1299709;i++)
    {
        if(!st[i]) prime.push_back(i);
        for(int j=0;prime[j] <= 1299709/i;j++)
        {
            st[prime[j]*i] = true;
            if(i % prime[j] == 0) break;
        }
    }
    int n;
    while (cin >> n)
    {
        if(!n) break;
        auto it = lower_bound(prime.begin(), prime.end(), n);
        if(*it == n) puts("0");
        else cout << *it - *(it-1) << endl;
    }
    
    return 0;
}