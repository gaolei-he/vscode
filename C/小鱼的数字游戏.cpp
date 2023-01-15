#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
int main()
{
	LL ans, a[1000], i;
	cin >> ans;
	LL ans1 = ans;
	for(i=0;ans!=1;i++){
		if(ans%2==0) ans /= 2;	
		else ans = ans * 3 + 1;
		a[i] = ans;
	}
	for(i--;i!=-1;i--) cout << a[i] << " "; 
	cout << ans1;
    return 0;
}
