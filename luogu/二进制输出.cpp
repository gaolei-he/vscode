#include <iostream>
using namespace std;

void print_bit(int k, int i)
{
    printf("%d",((k>>i)&1));
}


void print(int k, int ret)
{
    int i;
    if(ret) i = 31;
    else i = 7;
    int cnt = 0;
    for(;i>=0;i--)
    {
        if(cnt==4)
        {
            printf(" ");
            cnt = 0;
        }
        cnt ++;
        print_bit(k, i);
    }
}

int main()
{
    int n;
    cin >> n;
    //printf("size: %d\n", sizeof(n));
    printf("char: ");
    print(n, 0);
    printf("\nint:  ");
    print(n, 1);
    printf("\n");
    return 0;
}