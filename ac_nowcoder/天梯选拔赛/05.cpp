#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if(n==2||n==3||n==6) cout << -1;
    else if(n==1) cout << -1;
    else if(n==4) cout << "1 2 1 0";
    else if(n==5) cout << "2 1 2 0 0";
    else
    {
        cout << n - 4 << " 2 1";
        for(int i=4;i<=n;i++) if(i==n-3) printf(" 1");
        else printf(" 0");
    }
    return 0;
}

/*
-1
-1
-1
1 2 1 0
2 1 2 0 0
-1
3 2 1 1 0 0 0
4 2 1 0 1 0 0 0
5 2 1 0 0 1 0 0 0
6 2 1 0 0 0 1 0 0 0
7 2 1 0 0 0 0 1 0 0 0
*/