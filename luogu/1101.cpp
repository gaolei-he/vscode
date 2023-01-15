#include <iostream>
#include <cstring>
using namespace std;
const int N = 200;
struct A
{
    char str[N+1][N+1];
    bool check[N+1][N+1];
};
A a;
int main()
{
    int n;
    cin >> n;
    
    //memset(a, 0, sizeof(a));
    for(int i=10;i<n+10;i++) 
        scanf("%s", a.str[i]+10);

    for(int i=10;i<10+n;i++)
    {
        for(int j=10;j<10+n;j++)
        {
            if(a.str[i][j]=='y'&&a.str[i][j+1]=='i'&&a.str[i][j+2]=='z'&&a.str[i][j+3]=='h'&&a.str[i][j+4]=='o'&&a.str[i][j+5]=='n'&&a.str[i][j+6]=='g')
            {
                a.check[i][j] = true;
                a.check[i][j+1] = true;
                a.check[i][j+2] = true;
                a.check[i][j+3] = true;
                a.check[i][j+4] = true;
                a.check[i][j+5] = true;
                a.check[i][j+6] = true;
            }
            if(a.str[i][j]=='y'&&a.str[i+1][j]=='i'&&a.str[i+2][j]=='z'&&a.str[i+3][j]=='h'&&a.str[i+4][j]=='o'&&a.str[i+5][j]=='n'&&a.str[i+6][j]=='g')
            {
                a.check[i][j] = true;
                a.check[i+1][j] = true;
                a.check[i+2][j] = true;
                a.check[i+3][j] = true;
                a.check[i+4][j] = true;
                a.check[i+5][j] = true;
                a.check[i+6][j] = true;
            }
            if(a.str[i][j]=='y'&&a.str[i][j-1]=='i'&&a.str[i][j-2]=='z'&&a.str[i][j-3]=='h'&&a.str[i][j-4]=='o'&&a.str[i][j-5]=='n'&&a.str[i][j-6]=='g')
            {
                a.check[i][j] = true;
                a.check[i][j-1] = true;
                a.check[i][j-2] = true;
                a.check[i][j-3] = true;
                a.check[i][j-4] = true;
                a.check[i][j-5] = true;
                a.check[i][j-6] = true;
            }
            if(a.str[i][j]=='y'&&a.str[i-1][j]=='i'&&a.str[i-2][j]=='z'&&a.str[i-3][j]=='h'&&a.str[i-4][j]=='o'&&a.str[i-5][j]=='n'&&a.str[i-6][j]=='g')
            {
                a.check[i][j] = true;
                a.check[i-1][j] = true;
                a.check[i-2][j] = true;
                a.check[i-3][j] = true;
                a.check[i-4][j] = true;
                a.check[i-5][j] = true;
                a.check[i-6][j] = true;
            }
            if(a.str[i][j]=='y'&&a.str[i+1][j+1]=='i'&&a.str[i+2][j+2]=='z'&&a.str[i+3][j+3]=='h'&&a.str[i+4][j+4]=='o'&&a.str[i+5][j+5]=='n'&&a.str[i+6][j+6]=='g')
            {
                a.check[i][j] = true;
                a.check[i+1][j+1] = true;
                a.check[i+2][j+2] = true;
                a.check[i+3][j+3] = true;
                a.check[i+4][j+4] = true;
                a.check[i+5][j+5] = true;
                a.check[i+6][j+6] = true;
            }
            if(a.str[i][j]=='y'&&a.str[i-1][j-1]=='i'&&a.str[i-2][j-2]=='z'&&a.str[i-3][j-3]=='h'&&a.str[i-4][j-4]=='o'&&a.str[i+-5][j-5]=='n'&&a.str[i-6][j-6]=='g')
            {
                a.check[i][j] = true;
                a.check[i-1][j-1] = true;
                a.check[i-2][j-2] = true;
                a.check[i-3][j-3] = true;
                a.check[i-4][j-4] = true;
                a.check[i-5][j-5] = true;
                a.check[i-6][j-6] = true;
            }
            if(a.str[i][j]=='y'&&a.str[i+1][j-1]=='i'&&a.str[i+2][j-2]=='z'&&a.str[i+3][j-3]=='h'&&a.str[i+4][j-4]=='o'&&a.str[i+5][j-5]=='n'&&a.str[i+6][j-6]=='g')
            {
                a.check[i][j] = true;
                a.check[i+1][j-1] = true;
                a.check[i+2][j-2] = true;
                a.check[i+3][j-3] = true;
                a.check[i+4][j-4] = true;
                a.check[i+5][j-5] = true;
                a.check[i+6][j-6] = true;
            }
            if(a.str[i][j]=='y'&&a.str[i-1][j+1]=='i'&&a.str[i-2][j+2]=='z'&&a.str[i-3][j+3]=='h'&&a.str[i-4][j+4]=='o'&&a.str[i-5][j+5]=='n'&&a.str[i-6][j+6]=='g')
            {
                a.check[i][j] = true;
                a.check[i-1][j+1] = true;
                a.check[i-2][j+2] = true;
                a.check[i-3][j+3] = true;
                a.check[i-4][j+4] = true;
                a.check[i-5][j+5] = true;
                a.check[i-6][j+6] = true;
            }

            
        }
    }

    for(int i=10;i<10+n;i++)
    {
        for(int j=10;j<10+n;j++)
        {
            if(a.check[i][j]) printf("%c", a.str[i][j]);
            else putchar('*');
        }
        puts("");
    }
    return 0;
}