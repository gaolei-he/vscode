#include <bits/stdc++.h>
using namespace std;
int main()
{
	char s[5][10][4] = {{"XXX","..X","XXX","XXX","X.X","XXX","XXX","XXX","XXX","XXX"},
	{"X.X","..X","..X","..X","X.X","X..","X..","..X","X.X","X.X"},
	{"X.X","..X","XXX","XXX","XXX","XXX","XXX","..X","XXX","XXX"},
	{"X.X","..X","X..","..X","..X","..X","X.X","..X","X.X","..X"},
	{"XXX","..X","XXX","XXX","..X","XXX","XXX","..X","XXX","XXX"},
	};
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%1d", &a[i]);
	for(int j=0;j<5;j++){
		for(int i=0;i<n;i++){
			printf("%s", s[j][a[i]]);
			if(i!=n-1) printf(".");	
		}
		printf("\n");
	}
    return 0;
}

