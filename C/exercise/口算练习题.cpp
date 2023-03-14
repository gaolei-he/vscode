#include <bits/stdc++.h>
using namespace std;
void output(char a,char *b,char *c);
int pow1(int a, int b);
int main()
{
    int n;
    cin >> n;
    char a[n][3][20];
    for(int i=0;i<n;i++){
        cin >> a[i][0];
        //printf("%d",strlen(a[i][0]));
        if(a[i][0][0]<'a'||a[i][0][0]>'c') cin >> a[i][1];
        else cin >> a[i][1] >> a[i][2];            
    }
    char cha;
    for(int i=0;i<n;i++){
    	
    	if(a[i][0][0]<'a'||a[i][0][0]>'c') output(cha,a[i][0],a[i][1]);
    	else{
    		output(a[i][0][0],a[i][1], a[i][2]);
    		cha = a[i][0][0];
		}
    	
	}
    return 0;
}
void output(char a,char *b,char *c)
{
	int sum1 = 0, sum2 = 0;
	int cnt = 0;
	for(int i=strlen(b)-1;i>=0;i--){
		sum1 += ((int)(b[i]-48))*pow1(10,cnt++);
	}
	cnt = 0;
	for(int i=strlen(c)-1;i>=0;i--){
		sum2 += ((int)(c[i]-48))*pow1(10,cnt++);
	}
	if(a=='a'){
		int x = printf("%d+%d=%d\n", sum1, sum2, sum1+sum2);
		cout << x - 1 << endl;
	}
	else if(a=='b'){
		int x = printf("%d-%d=%d\n", sum1, sum2, sum1-sum2);
		cout << x - 1 << endl;
	}
	else if(a=='c'){
		int x = printf("%d*%d=%d\n", sum1, sum2, sum1*sum2);
		cout << x - 1 << endl;
	}
}
int pow1(int a, int b)
{
	int sum = 1;
	for(int i=0;i<b;i++)
		sum *= a;
	return sum;
}
