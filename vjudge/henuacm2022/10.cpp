#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<double, pair<int, int> > PII;
int main()
{
    double m;
    int n;
    while (true)
    {
        cin >> m >> n;
        vector<PII> ans;
        if(m == -1) break;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            ans.push_back({a==0?1e6:b*1.0/a, {a, b}});
        }
        sort(ans.begin(), ans.end());
        double sum = 0;
        for(auto i:ans)
        {
            if(m + 1e-6 > i.second.second)
            {
                sum += i.second.first;
                m -= i.second.second;
            }
            else
            {
                sum += i.second.first * m / i.second.second;
                break;
            }
        }
        printf("%.3f\n", sum);
    }
    
    return 0;
}