#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            a.push_back(x);
            
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        if((n-a.size())%2 == 0) cout << a.size() << endl;
        else cout << max((int)a.size() - 1, 0) << endl;
        
    }
    
    return 0;
}