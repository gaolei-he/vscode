#include <bits/stdc++.h>
using namespace std;
int main()
{
	char a[111];
	scanf("%s", a);
	for(int i=0;i<strlen(a);i++){
		if(a[i]>=97&&a[i]<=122) a[i] -= 32;
		cout << a[i];
	}
	
	return 0;
}
