#if 0
#include <iostream>
#include <cstring>
using namespace std;
const int N = 3e7+10;
char s[N], p[N/2];
int ne[N/2];
int main()
{
    scanf("%s%s", s+1, p+1);
    s[0] = p[0] = '@';
    int length1 = strlen(s)-1, length2 = strlen(p)-1;
    if(length1!=length2)
    {
        cout << "YES";
        return 0;
    }
    memcpy(s+length1+1, s+1, length1);

    for(int i=2, j=0;i<=length2;i++)
    {
        while(j&&p[j+1]!=p[i]) j = ne[j];
        if(p[j+1]==p[i]) j ++;
        ne[i] = j;
    }

    for(int i=1, j=0;i<=length1*2;i++)
    {
        while(j&&s[i]!=p[j+1]) j = ne[j];
        if(p[j+1]==s[i]) j++;
        if(j==length2)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}
#endif

#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ll;
const int N = 2e5+10, P = 131;

int n, m;
char str[N], tmp[N/2];
ll h[N], p[N], h1[N];
ll get(int l, int r)
{
    return (h[r] - h[l-1] * p[r-l+1]);
}
ll get1(int l, int r)
{
    return (h1[r] - h1[l-1] * p[r-l+1]);
}

int main()
{
    cin >> str+1 >> tmp+1;
    str[0] = tmp[0] = '@';
    int length1 = strlen(str);
    int length2 = strlen(tmp);
    if(length1 != length2)
    {
        puts("YES");
        return 0;
    }
    memcpy(str+length1, str+1, length1);
    p[0] = 1;
    for (int i = 1; i <= (length1-1)*2; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }
    for (int i = 1; i<=length1;i++)
    {
        h1[i] = h[i - 1] * P + tmp[i];
    }

    for(int i=1;i<=(length1-1)*2;i++)
    {
        if(get(i, i+length1) == get1(1, length1))
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    
    
    return 0;
}