#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
int main()
{
    int n;
    cin >> n;
    vector<int> a[n+1];
    int b[n+1];
    for(int i=1;i<=n;i++) scanf("%d", &b[i]);
    a[1].push_back(0);
    for(int i=0,x,y;i<n-1;i++)
    {
        cin >> x >> y;
        a[y].push_back(x);
        a[x].push_back(y);

    }
    vector<int> s(n+1, 0);
    for(int i=1;i<=n;i++)
    {
        int tmp;
        for(int j=0;j<a[i].size();j++)
            if(a[i][j]<i) tmp = a[i][j];
        int tmp1 = s[tmp];
        s[i] = tmp1 + b[i];
    }
    
    vector<int> s1(n+1, 0);
    for(int i=n;i>0;i--)
    {
        s1[i] += b[i];
        for(int j=0;j<a[i].size();j++)
        {
            if(a[i][j]>i) s1[i] += s1[a[i][j]];
        }
    }
    for(int i=1;i<=n;i++) cout << s1[i] << " " << s[i] << endl;
    return 0;
}