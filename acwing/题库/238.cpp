#include <iostream>
using namespace std;
const int N = 3e4+10;
int p[N];
int cnt = 0;
int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}
int find2(int x)
{
    
}
int main()
{
    for(int i=1;i<=N-5;i++) p[i] = i;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int i, j;
        cin >> s >> i >> j;
        if(s[0] == 'M') p[find(i)] = find(j);
        else
        {
            if(find(a) != find(b)) cout << -1 << endl;
            else
            {

            }
        }
    }
    
    return 0;
}