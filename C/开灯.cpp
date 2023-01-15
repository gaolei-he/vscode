#include <bits/stdc++.h>
using namespace std;
int arr[2000005];
int main()
{
	int n;
	cin >> n;
	
	while(n--){
		double a;
		int t;
		scanf("%lf %d", &a, &t);
		for(int i=floor(a),cnt=1;i<=floor(a*t);cnt++,i=floor(cnt*a)){
			if(arr[i]==0) arr[i] = 1;
			else arr[i] = 0;
		}
	}
	//cout << arr[2];
	for(int i=1;i<=2000000;i++)
		if(arr[i]==1){
			cout << i;
			break;
		}
	
	return 0;
}
