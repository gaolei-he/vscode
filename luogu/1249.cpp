#include <cstdio>
#include <iostream>
using namespace std;
#define N 5000
int a[N];
int ans[N];
int main()
{
    int n, num = 2, cnt = 0;
    cin >> n;
    while(n>=num){
        a[cnt++] = num;
        n -= num ++;
    }
    int pos = cnt - 1;
    while(n!=0){
        a[--cnt] ++;
        n --;
    }
    //
    ans[0] = 1;
    int jw = 0, po = 0;
    for(int i=0;i<=pos;i++){
        int j;
        for(j=0;j<=po;j++){
            ans[j] *= a[i];
            ans[j] += jw;
            jw = ans[j] / 10;
            ans[j] %= 10;
        }
        while(jw>0){
            ans[j] += jw % 10;
            jw /= 10;
            po = j;
            j++;
        }
    }
    for(int i=0;i<=pos;i++) printf("%d ", a[i]);
    cout << endl;
    for(int i=po;i>=0;i--) printf("%d", ans[i]);
    return 0;
}