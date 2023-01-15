#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
const int N = 1e3+10;
int main()
{
    int cnt = 0;
    while (1)
    {
        cnt ++;
        cin >> n >> m;
        vector<int> a;
        if(n == 0 && m == 0) break;
        for(int i=0;i<m;i++)
        {
            int x;
            scanf("%d", &x);
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        vector<int> b;
        for(int i=n*m;1;i--)
        {
            if(!binary_search(a.begin(), a.end(), i)) b.push_back(i);
            if(i==1) break;
        }
        
        int ans = m;
        for(int i=0;i<b.size();i++)
        {
            auto it = upper_bound(a.begin(), a.end(), b[i]);
            if(it == a.begin()) break;
            *(it-1) = 0;
            b.erase(b.end()-n+2, b.end());
            sort(a.begin(), a.end());
        }
        printf("Case %d: ", cnt);
        if(n == 1) cout << 0 << endl;
        else cout << (a.end() - upper_bound(a.begin(), a.end(), 0))  << endl;
    }
    
    
    return 0;
}
