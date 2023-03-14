#include <bits/stdc++.h>
using namespace std;
int main()
{
	int w, x, h, q;
	cin >> w >> x >> h;
	int a[w+1][x+1][h+1];
	for(int i=1;i<=w;i++)
		for(int j=1;j<=x;j++)
			for(int k=1;k<=h;k++)
				a[i][j][k] = 1;
	int a1, a2, a3, a4, a5, a6;
	cin >> q;
	while(q--){
		cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
		for(int i=a1;i<=a4;i++)
			for(int j=a2;j<=a5;j++)
				for(int k=a3;k<=a6;k++)
					a[i][j][k] = 0;
	}
	int cnt = 0;
	for(int i=1;i<=w;i++)
		for(int j=1;j<=x;j++)
			for(int k=1;k<=h;k++)
				if(a[i][j][k]==1)
					cnt ++;
	cout << cnt;
	return 0;
 } 
