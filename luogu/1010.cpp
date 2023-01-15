#include <iostream>
using namespace std;

int getbit(int i, int k)
{
    return (i >> k) & 1;
}

void setbit(int &n, int i)
{
    n &= ~(1<<i);
}
bool check(int n, int i)
{
    for(i--;i>=0;i--) if(getbit(n, i)) return true;
    return false;
}
void f(int n)
{
    for(int i=31;i>=0;i--)
    {
        if(getbit(n, i))
        {
            if(i==1)
            {
                cout << "2";
                if(n&1) cout << "+";
            }
            else
            {
            printf("2(");
            fflush(stdout);
            if(i==0) printf("0");
            else if(i>1)
            {
                f(i);
            }
            

            
            
            printf(")");
            if(check(n, i)) cout << "+";
            fflush(stdout);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    f(n);
    return 0;
}