#include <bits/stdc++.h>
using namespace std;

//typedef unsigned long long LL;

int main()
{
	int n;
	cout << "Please input the max lenth?" << endl;
	cin >> n;
	char a[n+1], b[n+1], c[n+3];
	for(int i=0;i<n+3;i++) c[i] = 0;
	cin >> a >> b;
	int cnt = 0;
	for(int i=strlen(a)-1, j=strlen(b)-1;;j--,i--){
		if(j==-1&&i>=0){
		c[cnt++] = a[i] - 48;
		j = 0;
		continue;
		}
		if(i==-1&&j>=0){
		c[cnt++] = b[j] - 48;
		i = 0;		
		continue;
		}
		if(i==-1&&j==-1) break;
		if(a[i]+b[i]-48>'9'){
			c[cnt++] += a[i] + b[j] - 48 - 10;
			c[cnt] = 1;
		}
		else c[cnt++] += a[i] + b[j] - 48;
		
	}
	for(int i=strlen(c)-1;i!=-1;i--) printf("%c", c[i]);
	printf("\n");
	return 0;
}
