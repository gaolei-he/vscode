#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n+2][7];
	for(int i=0;i<7;i++){
		a[0][i] = 0;
		scanf("%d", &a[1][i]);
	}
	for(int i=2;i<n+2;i++)
		for(int j=0;j<7;j++)
			scanf("%d", &a[i][j]);
	//for(int i=1;i<n+2;i++)
	//	sort(a[i], a[i]+7);
	//for(int i=0;i<7;i++) printf("%d ", a[3][i]);
	for(int i=2;i<n+2;i++){
		int cnt = 0;
		for(int j=0;j<7;j++){
			for(int k=0;k<7;k++)
				if(a[1][j]==a[i][k]) cnt ++;
		}
		if(cnt>0) a[0][cnt-1] ++;
	}
	for(int i=6;i!=-1;i--) printf("%d ", a[0][i]);		
	return 0;
 } 
