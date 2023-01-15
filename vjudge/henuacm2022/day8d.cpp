#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 3e4+10;
int n, m;
int p[N];
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    while (true)
    {
        cin >> n >> m;
        if(!n) break;
        for(int i=0;i<n;i++) p[i] = i;
        while (m--)
        {
            int k;
            cin >> k;
            int tmp;
            cin >> tmp;
            k--;
            while (k--)
            {
                int tmp1;
                cin >> tmp1;
                p[find(tmp)] = find(tmp1);
                tmp = tmp1;
            }
        
        }
        vector<int> tmp;
        for(int i=0;i<n;i++) tmp.push_back(find(i));
        cout << count(tmp.begin(), tmp.end(), find(0)) << endl;
    }
    
    return 0;
}