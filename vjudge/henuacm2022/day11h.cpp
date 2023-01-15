#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5+10;
char str[N];
int ne[N];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int length;
        scanf("%d", &length);
        scanf("%s", str+1);
        
        int cnt = 0;
        for(int i=2, j=0;i<=length;i++)
        {
            while(j && str[i] != str[j+1]) j = ne[j];
            if(str[i] == str[j+1]) j ++;
            ne[i] = j;
            
        }
        for(int i=length;i;i--)
        {
            for(int j=ne[i];j;j=ne[j]) cnt ++;
        }
        cnt += length;
        cout << cnt  % 10007 << endl;
        
        
    }
    return 0;
}