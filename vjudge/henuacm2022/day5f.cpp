#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10, P = 131;
char src[N], dst[N];
int main()
{
    int n;
    cin >> n;
    src[0] = dst[0] = ' ';
    scanf("%s", src + 1);
    for(int i=1;i<=n;i++) dst[n-i+1] = (src[i]=='0')?'1':'0';
    cout << 1;
    return 0;
}
11001011
00101100