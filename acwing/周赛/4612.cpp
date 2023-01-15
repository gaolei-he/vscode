#include <iostream>
#include <cstring>
using namespace std;
char str[110];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%s", str);
        int l = 0, r = strlen(str) - 1;
        int cnt = 0;
        while(str[l] != '1' && l < r) l++;
        while(str[r] != '1' && r >= 0) r --;
        for(int i=l;i<=r;i++) if(str[i] == '0') cnt ++;
        cout << cnt << endl;
    }
    
    return 0;
}