#include <iostream>
#include <cstring>
using namespace std;
const int N = 5e5+10;
int a[26], s[N], ne[N*2];
char str[N*2], tmp[N];


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for(int i=0;i<26;i++) scanf("%d", &a[i]);
        scanf("%s", tmp+1);
        int length = strlen(tmp+1);
        for(int i=1;i<=length;i++) s[i] = s[i-1] + a[tmp[i]-'a'];
        int length1 = 0;
        str[length1++] = '^', str[length1++] = '#';
        for(int i=1;i<=length;i++) str[length1++] = tmp[i], str[length1++] = '#';
        str[length1] = '$';
        int mr = 0, ml = 0;
        for(int i=1;i<=length1;i++)
        {
            if(i < mr) ne[i] = min(ne[ml*2-i], mr-i);
            else ne[i] = 1;
            while(str[i-ne[i]] == str[i+ne[i]]) ne[i] ++;
            if(ne[i] + i > mr)
            {
                mr = ne[i] + i;
                ml = i;
            }
        }
        int ans = 0;
        for(int i=2;i<length1;i++)
        {
            int tmp = 0;
            if(str[i-ne[i]] == '^' && str[i+ne[i]] != '$') 
            {
                tmp += s[ne[i]-1];
                int p = length1 - i - ne[i] + 2;
                int pos = p + 1 >> 1;
                pos += i + ne[i] - 2;
                if(str[pos+ne[pos]] == '$' && str[pos-ne[pos]] != '^') tmp = s[length];
                ans = max(ans, tmp);
            }
        }
        for(int i=length1-2;i>1;i--)
        {
            int tmp = 0;
            if(str[i+ne[i]] == '$' && str[i-ne[i]] != '^') 
            {
                tmp += s[length] - s[(i-ne[i])/2];
                int p = i-ne[i];
                int pos = p + 1 >> 1;
                pos ++;
                if(str[pos-ne[pos]] == '^' && str[pos-ne[pos]] != '$') tmp = s[length];
                ans = max(ans, tmp);
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
/*
 aba
^#a#b#a#$
 aacd 1 2 3 4
^#a#a#c#d#$ 2 4 6 8
*/