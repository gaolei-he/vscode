#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int out1 = 0, out2 = 1, cnt = 0, cnt1 = 0, cnt2 = 0;
	int a[n*n];
	int sum = 0;
	for(int i=0;sum!=n*n;i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for(int i=1;cnt2!=n*n;i++){
		for(int j=1;j<=a[cnt];j++){
			printf("%d", out1);
			cnt1 ++;
			cnt2 ++;
			if(cnt1==n){
				printf("\n");
				cnt1 = 0;
			}
		}
		
		cnt ++;
		swap(out1, out2);
	}
	
	return 0;
}
