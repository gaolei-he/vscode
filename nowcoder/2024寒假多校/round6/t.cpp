#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#define N 300002
using namespace std;
int T,n,s,k,ans[N];
int main()
{
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&s,&k);
		int cnt=0;
		for(int i=1;i<=k;i++){
			if(i==1) ans[++cnt]=2,s-=2;
			ans[++cnt]=1;s--;
			ans[++cnt]=2;s-=2;
		}
		if(cnt>n||s<n-cnt){
			puts("-1");
			continue;
		}
		else if(cnt==n){
			int x=n/2+1;
			int res=s%x;
            // assert ( x == k ) ;
			if(res!=0&&s/x==0){
				puts("-1");
				continue;
			} 
			for(int i=1;i<=n;i+=2) ans[i]+=s/x;
			for(int i=2;i<=n&&res>0;i+=2){
				ans[i]++;
				res--;
			}
		}
		else{
			cnt++;
			ans[cnt]=s-n+cnt;
			while(cnt<n) ans[++cnt]=1;
		}
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}