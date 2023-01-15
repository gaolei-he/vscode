#if 0
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e6+10;
char s[N], p[N];
int ne[N];
int main()
{
    int length1, length2;
    s[0] = p[0] = '@';
    cin >> s + 1 >> p + 1;
    length1 = strlen(s) - 1, length2 = strlen(p) - 1;

    for(int i=2, j=0;i<=length2;i++)
    {
        while(j&&p[i]!=p[j+1]) j = ne[j];
        if(p[i]==p[j+1]) j++;
        ne[i] = j;
    }

    for(int i=1, j=0;i<=length1;i++)
    {
        while(j&&s[i]!=p[j+1]) j = ne[j];
        if(s[i]==p[j+1]) j++;
        if(j==length2)
        {
            printf("%d\n", i-length2+1);
            j = ne[j];
        }
    }
    for(int i=1;i<=length2;i++) printf("%d ", ne[i]);

    return 0;
}



#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ll;
const int N = 2e6+10, P = 131;
int ne[N];
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
    int length1 = strlen(str) - 1;
    int length2 = strlen(tmp) - 1;

    
    p[0] = 1;
    for (int i = 1; i <= length1; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }
    for (int i = 1; i <= length2;i++)
    {
        h1[i] = h1[i - 1] * P + tmp[i];
    }

    for(int i=1;i<=length1;i++)
    {
        if(get(i, i+length2-1) == get1(1, length2))
        {
            cout << i << endl;
        }
    }
    
    for(int i=2, j=0;i<=length2;i++)
    {
        while(j&&tmp[i]!=tmp[j+1]) j = ne[j];
        if(tmp[i]==tmp[j+1]) j++;
        ne[i] = j;
    }
    for(int i=1;i<=length2;i++) cout << ne[i] << ' ';
    
    return 0;
}
#endif
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e6+10;
char str1[N], str2[N];
int ne[N];
int main()
{
    scanf("%s %s", str1 + 1, str2 + 1);
    int l1 = strlen(str1+1), l2 = strlen(str2 + 1);
    for(int i=2, j=0;i<=l2;i++)
    {
        while(j && str2[i] != str2[j+1]) j = ne[j];
        if(str2[i] == str2[j+1]) j++;
        ne[i] = j;
    }
    for(int i=1, j=0;i<=l1;i++)
    {
        while(j && str1[i] != str2[j+1]) j = ne[j];
        if(str1[i] == str2[j+1]) j++;
        if(j == l2)
        {
            cout << i - l2 + 1 << endl;
            j = ne[j];
        }
    }
    for(int i=1;i<=l2;i++) cout << ne[i] << ' ';
    return 0;
}