#include <iostream>
using namespace std;
char s[210];
int main()
{
    int n;
    s[0] = '0';
    cin >> n;
    for(int i = 1;i<=n;i++) s[i] = 'o';
    for(int i=n+1;i<=2*n;i++) s[i] = '*';
    s[2*n+1] = s[2*n+2] = '-';
    int i = n, j = 2*n+1;
    int ret = 1;
    while(1)
    {
        
        cout << s+1 << endl;
        if(s[4]=='-') break;
        swap(s[i], s[j]);
        swap(s[i+1], s[j+1]);
        ret *= -1;
        if(ret==-1) j-= 2;
        else i -= 1;
    }
    swap(s[4], s[8]), swap(s[5], s[9]);
    cout << s+1 << endl;
    swap(s[2], s[8]), swap(s[3], s[9]);
    cout << s+1 << endl;
    swap(s[2], s[7]), swap(s[3], s[8]);
    cout << s+1 << endl;
    swap(s[1], s[7]), swap(s[2], s[8]);
    cout << s+1 << endl;
    return 0;
}