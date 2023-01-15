#include <iostream>
using namespace std;
const int N = 1e5+10;
int a[N];
int main()
{
    int n;
    while (cin >> n)
    {
        for(int i=0;i<n;i++) scanf("%d", &a[i]);
        string s;
        for(char op='A';op<='Z';op++)
        {
            char tmp;
            for(int i=0;i<n;i++)
            {
                tmp = a[i] ^ op;
                if(tmp >= 'A' && tmp <= 'Z') s.push_back(tmp);
                else
                {
                    s.clear();
                    break;
                }
            }
            if(s.size())
            {
                cout << s << endl;
                break;
            }
        }
    }
    
    return 0;
}
/*
op = x;
x ^ ? = a[0]
*/