#include <iostream>
#include <string>
using namespace std;
string mymin(string s1, string s2)
{
    for(int i=0;i<s1.size();i++)
        if(s1[i]>s2[i]) return s2;
        else if(s1[i]<s2[i]) return s1;
    return s1;
}
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    string s1 = s;
    while(k--)
    {
        string tmp1 = s1;
        s1.erase(s1.size()-1, 1);
        for(int i=tmp1.size()-2;i>=0;i--)
        {
            string tmp = tmp1;
            tmp.erase(i, 1);
            s1 = mymin(tmp, s1);
        }


    }
    while(s1.size()>1&&s1.front()=='0')
        s1.erase(0, 1);
    cout << s1;
    return 0;
}