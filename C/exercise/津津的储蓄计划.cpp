#include <bits/stdc++.h>
using namespace std;
int a[12];
int num = 0;
int ret = 1;
int main()
{
    int bank = 0;
    int budget;
    int money = 300;
    for(int i=1;i<=12;i++){
        cin >> budget;
        int yu = money - budget;
        if(yu<0){
        	a[num++] = i;
        	ret = 0;
		}
        bank += yu / 100;
        money = yu % 100 + 300;
    }
    money -= 300;
    if(ret==0) cout << "-" << a[0];
    else cout << bank*100*1.2+money << endl;
    return 0;
}

