#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll>sd[1050],su;//sd存储第i天风险地区,su风险人员名单 
struct node{
	ll d,u,r;
}a;
vector<node>v[1050];
ll n,ri,mi,d,u,r,pi;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ri>>mi;
		for(int j=1;j<=ri;j++)
		{
			cin>>pi;
			for(int j=i;j<i+7;j++)sd[j].insert(pi);//第j天插入风险地区pi 
		}
		for(int j=1;j<=mi;j++)
		{
			cin>>d>>u>>r;
			if(d<0)continue;//天数为负数必不可能高风险 
			if(!sd[d].count(r))continue;//r地区在第d天不是风险地区 
			a.d=d;
			a.u=u;
			a.r=r;
			v[i].push_back(a);//将记录第i天的第j个表格
		}
		for(int j=max(0,i-6);j<=i;j++)//从i-6天前开始遍历mi表，如果是七天前的信息就不需要隔离了(i-6) 
		{//最小从第0天开始 
			for(int k=0;k<v[j].size();k++)//遍历第j天的表 
			{
				a.d=v[j][k].d;
				a.u=v[j][k].u;
				a.r=v[j][k].r;
				if(a.d<=i-7)continue;//表内信息超过七天 
				bool flag=1;
				for(int l=a.d;l<=i;l++)
					flag&=sd[l].count(a.r);//确保一直为风险地区不间断 
				if(flag)//满足条件就隔离 
					su.insert(a.u);
			}
		}
		cout<<i;
		set<ll>::iterator it;
		for(it=su.begin();it!=su.end();it++)cout<<" "<<*it;
		cout<<" " << endl;
		su.clear();
	}
	return 0;
}
