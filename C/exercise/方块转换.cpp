#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, ans = 0;
	cin >> n;
	char a[n][n+1], b[n][n+1];
	for(int i=0;i<n;i++) scanf("%s", a[i]);
	for(int i=0;i<n;i++) scanf("%s", b[i]);
	for(int i=0;i<n;i++){	
		for(int j=0;j<n;j++){
			if(a[i][j]==b[j][n-i-1]) ans = 1;
			else{
				ans = 0;
				i = j = n;
			}
		}
	}
	if(ans!=0){
		cout << ans;
		return 0;
	}
	for(int i=0;i<n;i++){	
		for(int j=0;j<n;j++){
			if(a[i][j]==b[n-i-1][n-j-1]) ans = 2;
			else{
				ans = 0;
				i = j = n;
			}
		}
	}
	if(ans!=0){
		cout << ans;
		return 0;
	}
	for(int i=0;i<n;i++){	
		for(int j=0;j<n;j++){
			if(a[i][j]==b[n-j-1][i]) ans = 3;
			else{
				ans = 0;
				i = j = n;
			}
		}
	}
	if(ans!=0){
		cout << ans;
		return 0;
	}
	char c[n][n];
	for(int i=0;i<n;i++)	
		for(int j=0;j<n;j++)
			c[i][n-j-1] = a[i][j];
	for(int i=0;i<n;i++){	
		for(int j=0;j<n;j++){
			if(c[i][j]==b[i][j]) ans = 4;
			else{
				ans = 0;
				i = j = n;
			}
		}
	}
	if(ans!=0){
		cout << ans;
		return 0;
	}
	
			
			
		
	
	for(int i=0;i<n;i++){	
		for(int j=0;j<n;j++){
			if(c[i][j]==b[j][n-i-1]) ans = 5;
			else{
				ans = 0;
				i = j = n;
			}
		}
	}
	if(ans!=0){
		cout << ans;
		return 0;
	}
	for(int i=0;i<n;i++){	
		for(int j=0;j<n;j++){
			if(c[i][j]==b[n-i-1][n-j-1]) ans = 5;
			else{
				ans = 0;
				i = j = n;
			}
		}
	}
	if(ans!=0){
		cout << ans;
		return 0;
	}
	for(int i=0;i<n;i++){	
		for(int j=0;j<n;j++){
			if(c[i][j]==b[n-j-1][i]) ans = 5;
			else{
				ans = 0;
				i = j = n;
			}
		}
	}
	if(ans!=0){
		cout << ans;
		return 0;
	}
	for(int i=0;i<n;i++){	
		for(int j=0;j<n;j++){
			if(a[i][j]==b[i][j]) ans = 6;
			else{
				ans = 0;
				i = j = n;
			}
		}
	}
	if(ans==0) cout << "7";
	else cout << ans;
	return 0;
}
