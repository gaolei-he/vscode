#include<bits/stdc++.h>
using namespace std;
const int N=2e4+1;
#define int long long
const int mod1=1e9+7;
const int mod2=1e9+2;
signed main(){
 
    int n;cin>>n;
    vector<int>a(n+10);
    for(int i=1;i<=n;i++)cin>>a[i];
    map<pair<int,int>,int>mp;
    vector<int>len(30);
    len[0]=1;
    for(int i=1;i<=15;i++){
        len[i]=len[i-1]*10;
    }
    auto get=[&](int x){
        int cnt=0;
        while(x){
            cnt++;x/=10;
        }
        return cnt;
    };
    vector<int>lena(n+10);
    for(int i=1;i<=n;i++){
        lena[i]=len[get(a[i])];
    }
    auto dfs=[&](auto dfs,int pos,int sum1,int sum2)->void{
        if(pos==n+1){
            mp[{sum1,sum2}]=1;
            return;
        }
         dfs(dfs,pos+1,(sum1*lena[pos]%mod1+a[pos])%mod1,(sum2*lena[pos]%mod2+a[pos])%mod2);
         dfs(dfs,pos+1,sum1,sum2);
    };
    dfs(dfs,1,0,0);
    cout<<mp.size()-1<<"\n";
    return 0;
}

/*
    现在有n个数字a[i],你必须按照从1到n的顺序选取若干个数字,并将这些数字合并在一起组成一个新的数字
    输出组成的新的数字的大小种类。
    1<=n<=20;
    1<=a[i]<=1e9;(暴搜然后用哈希存种类（用字符串会超时))
    n=3; 
    1 1 12
    组成 1 1 12 11 112 112 1112
    共5种
*/  


