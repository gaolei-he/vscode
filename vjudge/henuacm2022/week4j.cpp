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
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    vector<int> a1;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            a1.push_back(a[i]-a[j]);
        }
        
    }
    sort(a1.begin(), a1.end());
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            int t = a[i] + a[j];
            if(binary_search(a1.begin(), a1.end(), t))
            {
                puts("Yes");
                return 0;
            }
        }
        
    }
    puts("No");
    
    return 0;
}