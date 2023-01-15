#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e7+10;
char str[N];
int main()
{
    scanf("%s", str);
    int cnt = 0;
    for(int i=0;str[i];i++)
    {
        if(str[i] == 'H' && str[i+1] == 'P' && str[i+2] == 'U') cnt ++;
    }
    cout << cnt << endl;
    return 0;
}