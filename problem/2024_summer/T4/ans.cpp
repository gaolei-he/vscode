#include<bits/stdc++.h>
using namespace std;
const int N=2e4+1;
#define int long long
int mag[100][100];
void chmin(int &a,int b){
    if(a>b)a=b;
}
signed main(){
  // freopen("6.in","r",stdin);
 //  freopen("6.out","w",stdout);
    int n,m,k;cin>>n>>m>>k;
    vector<int>a(n+10);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<vector<int>>d(m+10);
    vector<int>p(n+10);
    for(int i=1;i<=m;i++){
        cin>>p[i];
        int cnt=0;cin>>cnt;
        d[i].push_back(0);
        while(cnt--){
            int x;cin>>x;
            d[i].push_back(x);
        }
    }
    for(int i=0;i<100;i++)for(int j=0;j<100;j++)mag[i][j]=1e15;
    for(int i=1;i<=n;i++)mag[i][0]=a[i];
    for(int j=1;j<=k;j++){
        for(int i=1;i<=m;i++){
              int len=d[i].size()-1;
              vector<vector<int>>temp(32,vector<int>(32,1e15));
              temp[0][0]=0;
              for(int pos=1;pos<=len;pos++){
                  for(int pre=0;pre<=j-1;pre++){
                       for(int now=0;now<=j-1-pre;now++){
                            chmin(temp[pos][pre+now],temp[pos-1][pre]+mag[d[i][pos]][now]);
                       }
                  }
              } 
              int ans=1e15;
              for(int i=0;i<j;i++)chmin(ans,temp[len][i]);
              mag[p[i]][j]=ans;
        }
    }
    for(int i=1;i<=n;i++){
        int ans=1e15;
        for(int j=0;j<=k;j++)chmin(ans,mag[i][j]);
        cout<<ans<<" ";
    }

    return 0;
}

/*  
   商店有n种药水,每种药水有个售价a[i],同时你有m种魔法但是你最多可以使用k次魔法(每种魔法可以重复使用)，第i种魔法，你可以用num[i]个药水x[1]...
    x[num[i]]合成药水p[i],现在请你输出n个整数表示得到n种药水的最小花费(分别在最多使用K次魔法的前提下)。
    1<=n<=30;
    1<=m<=30;
    1<=k<=30; 
    1<=a[i]<=100;
    1<=num[i]<=30;
*/
   
