#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    map<string,int>m;//string->int
    while(~scanf("%d",&a)){
        for(int i=0;i<a;i++){
            string s;
            cin>>s;
            m[s]++;//�ߴ�++
        }
        int ans=0;
        for(int i=0;i<a;i++){
            string s;
            cin>>s;
            if(m[s]==0) ans++;//ǰһ����ļ���û�г��ֹ���ans++
            else m[s]--;//���ֹ�����Ӧ�ĸ�����һ
        }
        cout<<ans<<endl;
    }
}


