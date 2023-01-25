#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void sub(string s1, string s2)
{
    vector<int> a1, a2, ans;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for(auto i:s1) a1.push_back(i - '0');
    for(auto i:s2) a2.push_back(i - '0');
    for (int i = 0, t = 0; i < a1.size() || t; i++)
    {
        if(i < a2.size()) t -= a2[i];
        t += a1[i];
        ans.push_back((t+10)%10);
        if(t < 0) t = -1;
        else t = 0;
    }
    while(ans.back() == 0 && ans.size() > 1) ans.pop_back();
    reverse(ans.begin(), ans.end());
    for(auto i:ans) cout << i;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string t1;
        cin >> n >> t1;
        string t2 = "1";
        char op = '0';
        if(t1.front() == '9') op = '1';
        while(--n) t2 += op;
        t2 += '1';
        sub(t2, t1);
        puts("");
    }
    
    return 0;
}