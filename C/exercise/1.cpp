#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cout <<(int) 2e9;
    map<string,int>m;
    while(~scanf("%d",&a)){
        for(int i=0;i<a;i++){
            string s;
            cin>>s;
            m[s]++;
        }
        int ans=0;
        for(int i=0;i<a;i++){
            string s;
            cin>>s;
            if(m[s]==0) ans++;
            else m[s]--;
        }
        cout<<ans<<endl;
    }
}


