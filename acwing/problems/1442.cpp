#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int st;
    st = k;
    int stt = n;
    while(n--)
    {
        string s;
        cin >> s;
        if(k>=s.size())
        {
            cout << ' ';
            if(stt-1==n) cout << '\b';
            cout << s;
            k -= s.size();
        }
        else 
        {
            cout << endl << s;
            k = st - s.size();
        }
    }
    return 0;
}