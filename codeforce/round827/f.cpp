#include <iostream>
#include <cstring>
#define int long long
using namespace std;
int S[26], T[26];
const int N = 5e5+10;
char str[N];
bool cmp()
{
    int t1 = 0, t2 = 0;
    int sums = 0, sumt = 0;
    string s, t;
    for (int i = 0; i < 26; i++)
    {
        sums += S[i];
        sumt += T[i];
        if(S[i]) t1 ++, s.push_back('a' + i);
        if(T[i]) t2 ++, t.push_back('a' + i);
    }
    if(t1 >= 2 && t2 >= 2) return true;
    else if(t1 == 1 && t2 == 1) return sums < sumt;
    else if(t2 == 1)
    {
        if(t.back() > s.front()) return true;
        else if(t.back() <= s.front()) return false;

    }
    else if(t1 == 1)
    {
        if(s.back() > t.back() || s.back() == t.back() && S[s.back()-'a'] > T[s.back()-'a'])  return false;
        else return true;
    }
    return true;
    

}
signed main()
{
    int t;
    cin >> t;
    while (t -- )
    {
        int q;
        cin >> q;
        memset(S, 0, sizeof(S));
        memset(T, 0, sizeof(T));
        S[0] = T[0] = 1;
        while (q--)
        {
            int num, k;
            scanf("%lld %lld %s", &num, &k, str);
            for(int i=0;str[i];i++)
            {
                if(num == 1) S[str[i]-'a'] += k;
                else T[str[i]-'a'] += k;
                
            }
            if(cmp()) puts("YES");
            else puts("NO");
        }
        
    }
    
    return 0;
}