#include <iostream>
using namespace std;
int main()
{
    string s, ans;
    cin >> s >> ans;
    int sum = 0;
    int j = 0;
    while(j<ans.size())
    {
        int i = 0;
        while(i<26)
        {
            if(s[i]==ans[j]) j++;
            i ++;
        }
        sum ++;
    }
    cout << sum;
    return 0;
}