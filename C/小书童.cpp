#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	char a[55];
	cin >> n;
	cin >> a;
	for(int i=0;i<strlen(a);i++){
		if(a[i]+n>122) a[i] += n - 26;
		else a[i] += n;
		cout << a[i];
	}
	
	return 0;
}
