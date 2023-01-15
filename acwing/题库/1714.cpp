#include <iostream>
using namespace std;
int main()
{
    int tong1, tong2, tong3;
    int nai1, nai2, nai3;
    cin >> tong1 >> nai1;
    cin >> tong2 >> nai2;
    cin >> tong3 >> nai3;
    int time = 0;
    for(int i=0;i<100;i++)
    {
        time ++;
        switch (time)
        {
        case 1:
        {
            if(tong2>=nai2+nai1)
            {
                nai2 += nai1;
                nai1 = 0;
            }
            else
            {
                nai1 -= tong2 - nai2;
                nai2 = tong2;
            }
        }
        break;
        case 2:
        {
            if(tong3>=nai2+nai3)
            {
                nai3 += nai2;
                nai2 = 0;
            }
            else
            {
                nai2 -= tong3 - nai3;
                nai3 = tong3;
            }
        }
        break;
        case 3:
        {
            if(tong1>=nai1+nai3)
            {
                nai1 += nai3;
                nai3 = 0;
            }
            else
            {
                nai3 -= tong1 - nai1;
                nai1 = tong1;
            }
        }
            break;
        
        default:
            break;
        }
        if(time==3) time = 0;
    }
    printf("%d\n%d\n%d\n", nai1, nai2, nai3);
    return 0;
}