#include <iostream>
#include <algorithm>
using namespace std;
int a[9];
bool tmp[9];
void dfs(int cnt)
{
    if(cnt==9)
    {
        cout << a[1];
        for(int i=2;i<=8;i++) printf(" %d", a[i]);
        cout << endl;
        return;
    }
    else
    {
        for(int i=1;i<=8;i++)
        {
            if(tmp[i])
            {
                a[cnt] = i;
                tmp[i] = false;
                dfs(cnt+1);
                tmp[i] = true;
            }
        }
    }
}

int main()
{

    for(int i=0;i<9;i++) tmp[i] = true;
    dfs(1);
    return 0;
}