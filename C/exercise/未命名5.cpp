#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    map<string,int>m;//string->int
    while(~scanf("%d",&a)){
        for(int i=0;i<a;i++){
            string s;
            cin>>s;
            m[s]++;//尺寸++
        }
        int ans=0;
        for(int i=0;i<a;i++){
            string s;
            cin>>s;
            if(m[s]==0) ans++;//前一年的文件中没有出现过，ans++
            else m[s]--;//出现过，对应的个数减一
        }
        cout<<ans<<endl;
    }
}


