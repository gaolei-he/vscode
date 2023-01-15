#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int main()
{
    cin >> n >> m;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        while(x)
        {
            int tmp = 0;
            if(x & 1) tmp = (x + 1) / 2;
            else tmp = x / 2;
            b.push_back(tmp);
            x -= tmp;
        }
    }
    sort(b.begin(), b.end(), greater<int>());
    long long sum = 0;
    for(int i=m;i<b.size();i++) sum += b[i];
    cout << sum << endl;

    
    return 0;
}