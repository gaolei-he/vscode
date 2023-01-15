#include <bits/stdc++.h>
using namespace std;
int isPrime(int n);
int main()
{
	char a[109];
	cin >> a;
	sort(a, a+strlen(a));
	int max = 0, min = 100, cnt = 1;
	for(int i=0;i<strlen(a)-1;i++){
		if(a[i]==a[i+1]) cnt ++;
		else if(min>cnt){
			min = cnt;
			cnt = 1;
		}else cnt = 1;
		if(max<cnt) max = cnt;
		
	}
	if(isPrime(max-min)) cout <<"Lucky Word"<<endl<< max-min;
	else cout<<"No Answer"<<endl<<"0";
	return 0;
}
int isPrime(int n)
{
	int ret = 1;
	for(int i=2;i<n;i++){
		if(n%2==0){
			ret = 0;
			break;
		}
	}
	if(n==0||n==1) ret = 0;
	return ret;
}
