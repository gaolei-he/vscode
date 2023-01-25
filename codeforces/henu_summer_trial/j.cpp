#include <iostream>
using namespace std;
string ans = "henu";
bool check(char * p)
{
    for (int i = 0; i < 4; i++)
    {
        if(*(p+i) != ans[i]) return false;
    }
    return true;
    
}

int main()
{
    int n;
    cin >> n;
    char str[110];
    cin >> str;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(check(str+i)) cnt ++;
    }
    cout << cnt;
    

}