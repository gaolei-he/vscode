#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10007;
typedef unsigned long long ll;
ll h[N], P = 131, p[N];
int main()
{
    int n;
    cin >> n;
    p[0] = 1;


    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        char str[1600];
        str[0] = '@';
        scanf("%s", str+1);
        int length1 = strlen(str) - 1;
        for(int i=1;i<=length1;i++) h[i] = h[i-1] * P + str[i];
        a.push_back(h[length1]);

    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    cout << a.size();
    
    return 0;
}
