#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> PII;
int main()
{
    int n, s, a, b;
    cin >> n >> s >> a >> b;
    vector<PII> app;
    int num1, num2;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d", &num1, &num2);
        app.push_back({num2, num1});
    }
    sort(app.begin(), app.end());
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(app[i].second<=a+b&&s>=0) s -= app[i].first, cnt++;
        if(s<0) break;
    }
    if(s<0) cnt --;
    cout << cnt;
    return 0;
}