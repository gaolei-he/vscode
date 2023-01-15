#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int x, y;
		cin >> x >> y;
		a[x][y] = 1, a[x+1][y+1] = 1;
		a[x+1][y] = 1, a[x+2][y] = 1, a[x][y+1] = 1, a[x][y+2] = 1;
		if(x-1>=2) a[x-1][y] = 1, a[x-2][y] = 1, a[x-1][y+1] = 1;
		else if(x-1>=1) a[x-1][y] = 1, a[x-1][y+1] = 1;
		if(y-1>=2) a[x][y-1] = 1, a[x][y-2] = 1, a[x+1][y-1] = 1;
		else if(y-1>=1) a[x][y-1] = 1, a[x+1][y-1] = 1;
		if(x-1>=1&&y-1>=1) a[x-1][y-1] = 1;
	}
	for(int i=1;i<=k;i++){
		int x, y;
		cin >> x >> y;
		for(int j=x;j<=x+2;j++)
			for(int k=y;k<=y+2;k++)
				a[j][k] = 1;
		if(x-1>=2){
			for(int j=x-1;j>=x-2;j--)
				for(int k=y;k<=y+2;k++)
					a[j][k] = 1;
		}
		else if(x-1>=1) a[x-1][y] = 1, a[x-1][y+1] = 1, a[x-1][y+2] = 1;
		if(y-1>=2){
			for(int j=x;j<=x+2;j++)
				for(int k=y-2;k<y;k++)
					a[j][k] = 1;
		}
		else if(y-1>=1) a[x][y-1] = 1, a[x+1][y-1] = 1, a[x+2][y-1] = 1;
		if(x-1>=2&&y-1>=2) a[x-1][y-1] = 1, a[x-2][y-1] = 1, a[x-1][y-2] = 1, a[x-2][y-2] = 1;
		else if(x-1>=2&&y-1>=1)a[x-1][y-1]=1, a[x-2][y-1]=1;
		else if(x-1>=1&&y-1>=2)a[x-1][y-1]=1, a[x-1][y-2]=1;
		else if(x-1>=1&&y-1>=1)a[x-1][y-1]=1;
	}
	int cnt = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]==0) cnt ++;
	cout << cnt;
	return 0;
}
