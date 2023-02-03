#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a, b;
    int times = 0;
    //scanf("%d:%d", &a, &b);
    char str[6];
    cin >> str;
    a = (int) (str[0] - '0') * 10 + (int) (str[1] - '0');
    b = (int) (str[3] - '0') * 10 + (int) (str[4] - '0');

    if(a==12&&b==0)
    {
        printf("Only 12:00.  Too early to Dang.");
        return 0;
    }
    if(a>=0&&b>=0&&a<=11&&b<=59) printf("Only %02d:%02d.  Too early to Dang.", a, b);
    //else if() 
    else times = a - 12;
    if(b>0) times ++;
    for(int i=0;i<times;i++) printf("Dang");
    return 0;
}