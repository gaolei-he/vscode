#include <iostream>
using namespace std;

bool isPrime(int x)
{
    if(x==2||x==3||x==5||x==7) return true;
    else return false;
}

int main()
{
    for(int i1=1;i1<=3;i1++)
    for(int i2=1;i2<=3;i2++)
    for(int i3=1;i3<=3;i3++)
    for(int i4=1;i4<=3;i4++)
    for(int i5=1;i5<=3;i5++)
    for(int i6=1;i6<=3;i6++)
    for(int i7=1;i7<=3;i7++)
    for(int i8=1;i8<=3;i8++)
    for(int i9=1;i9<=3;i9++)
    for(int i10=1;i10<=3;i10++)
    {
        int a[4] = { 0 };
        a[i1] ++, a[i2] ++, a[i3] ++, a[i4] ++, a[i5] ++;
        a[i6] ++, a[i7] ++, a[i8] ++, a[i9] ++, a[i10] ++;
        int numPrime = 0;
        if(isPrime(a[1])) numPrime ++;
        if(isPrime(a[2])) numPrime ++;
        if(isPrime(a[3])) numPrime ++;
        if(numPrime!=i1) continue;
        if(a[2]!=i2+1) continue;
        if(abs(a[3]-a[1])!=4-i3) continue;
        if(abs(i3-i4)!=3-i4) continue;
        if(a[i6]-1!=i6) continue;
        if(!(i2==i3&&i5==1||i4==i5&&i5==2||i6==i7&&i5==3)) continue;
        if(i8==1) continue;
        printf("%d%d%d%d%d%d%d%d%d%d", i1, i2, i3, i4, i5, i6, i7, i8, i9, i10);
    }
    return 0;
}
