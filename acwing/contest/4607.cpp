#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 5e4+10;
char str[N];

bool check(int i)
{
    vector<char> tmp;
    for(int j=i;j<i+26;j++)
        if(str[j] != '?') tmp.push_back(str[j]);
    sort(tmp.begin(), tmp.end());
    auto it = unique(tmp.begin(), tmp.end());
    if(it != tmp.end()) return false;
    
    bool st[26];
    memset(st, 0, sizeof(st));
    for(auto j:tmp) st[j-'A'] = true;
    vector<char> t1;
    for (int j = 0; j < 26; j++)
    {
        if(!st[j]) t1.push_back(j+'A');
    }
    int cnt = 0;
    for(;cnt<t1.size();i++)
        if(str[i] == '?') str[i] = t1[cnt++];

    return true;

}
void print()
{
    for(int i=0;str[i];i++) if(str[i] == '?') str[i] = 'A';
    printf("%s", str);
}

int main()
{
    scanf("%s", str);
    int length = strlen(str);
    for(int i=0;i<length-25;i++)
    {
        if(check(i))
        {
            print();
            return 0;
        }
    }
    puts("-1");
    return 0;
}