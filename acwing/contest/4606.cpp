#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if(s.back() & 1) puts("1");
    else puts("0");
    return 0;
}