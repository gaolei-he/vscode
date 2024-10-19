#include<bits/stdc++.h>
using namespace std;
const int N=2e4+1;
mt19937_64 rng(time(0));
int main(){
	int n;cin>>n;
	set<int>s;s.insert(0);
	map<int,int>mp;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		mp[x]++;
		mp[y+1]--;
	}
	map<int,int>cnt;
	int pre=0;
	for(auto [x,y]:mp){
		cnt[x]=cnt[pre]+y;
		s.insert(cnt[x]);
		pre=x;
	}
	cout<<s.size()<<"\n";
    return 0;
}

/*
  给定n条线段放在x坐标轴上每条线段的位置为L[i]~R[i],现在问你坐标轴上所有的点有多少种覆盖次数
  1<=L[i]<R[i]<=1e9
  //map或者离散化 后差分
*/  
