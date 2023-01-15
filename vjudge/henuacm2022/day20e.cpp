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
bool st[10010];
int main()
{
    for(int i=2;i<=10000;i++)
    {
        if(!st[i]) prime.push_back(i);
        for(int j=0;prime[j] <= 10000/i;j++)
        {
            st[prime[j]*i] = true;
            if(i % prime[j] == 0) break;
        }
    }
    int n;
    while(cin >> n)
    {
        if(!n) break;
        int cnt = 0;
        for (int i = 0; i < prime.size(); i++)
        {
            int tmp = 0;
            for(int j=i;j<prime.size();j++)
            {
                tmp += prime[j];
                if(tmp == n)
                {
                    cnt ++;
                    break;
                }
                else if(tmp > n) break;
            }
        }
        cout << cnt << endl;
    }
    
    return 0;
}