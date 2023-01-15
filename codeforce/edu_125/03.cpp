#include <iostream>
using namespace std;
    
bool check(string s, int i)
{
    int ret1 = 0, ret2 = 1;
    int cnt1 = 0, cnt2 = 0;
    for(int j=0;j<=i;j++)
    {
        if(s[j]=='(') cnt1 += j+1;
        else cnt2 += j+1;
    }
    if((i&1)&&cnt2-cnt1>=(i+1)/2) ret1 = 1;
    for(int j=0;i>j;j++, i--)
    {
        if(s[i]!=s[j]) ret2 = 0;
    }
    if(ret1||ret2) return true;
    else return false;
    
}
    
int main()
{
    //good
    int t;
    cin >> t;
    while (t--)
    {

        int n, cnt = 0;
        cin >> n;
        
        string s;
        cin >> s;
        for(int i=1;i<s.length();i++)
        {
            if(check(s, i))
            {
                s = s.substr(i+1, s.length());
                i = 0;
                cnt ++;
            }
        }
        printf("%d %ld\n", cnt, s.length());
    }
    
    return 0;
}