#include<bits/stdc++.h>
using namespace std;
const int N=2e4+1;
#define int long long
signed main(){
 
     int n,m,k;cin>>n>>m>>k;
    vector<int>a(n+10);
    for(int i=1;i<=n;i++)cin>>a[i];
    auto check=[&](int x){
        vector<int>cnt(n+10);
        int num=0;
        for(int i=n;i>=1;i--){
            cnt[i]+=cnt[i+1];
            int one=0;
            if(a[i]+cnt[i]>0){
                one=(a[i]+cnt[i]+x-1)/x;
            }
            cnt[i]-=one*x;
            cnt[max(0ll,i-k)]+=one*x;
            num+=one;
        }
        return num<=m;
    };
    int l=1;int r=1e9;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    if(check(l)){
        cout<<l<<"\n";
    }
    else cout<<"-1\n";
    return 0;
}

/*
    有一排n个怪物血量为a[1]....a[n]你每次可以选择一个长度为k的区间对该区间内每个怪兽造成x点伤害
    (当怪物血量小于等于0时死亡)
    假设你最多可以选择m次区间，请你在保证杀死全部怪物的前提下输出x的最小值(若无论如何都杀不完输出-1)
    1<=a[i]<=1e9 
    1<=m<=n<=1e5;
    1<=k<=n
*/
