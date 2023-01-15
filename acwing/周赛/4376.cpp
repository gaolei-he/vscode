#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    char str[20];
    memset(str, 0, sizeof(str));
    sprintf(str, "%llX", n);
    int cnt = 0, length = strlen(str);
    for(int i=0;i<length;i++)
    {
        if(strchr("0469AD", str[i])) cnt ++;
        else if(strchr("8B", str[i])) cnt += 2;
    }
    cout << cnt;
    return 0;
}