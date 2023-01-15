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
    int t;
    cin >> t;
    vector<int> a;
    for(int i=1;i<=1000;i++) a.push_back(i*i*i);
    while (t--)
    {
        int n, cnt = 0;
        scanf("%d", &n);
        for (int i = 0; i < a.size(); i++)
        {
            if(n % a[i] == 0) cnt ++;
        }
        
        cout << cnt << endl;
    }
    
    return 0;
}