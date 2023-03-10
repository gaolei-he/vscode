#include <iostream>
#include <string>
using namespace std;

string Caesar(string laws,int w)
{

    string library="abcdefghijklmnopqrstuvwxyz";
    for(int i=0;i<laws.size();i++)
    {
        for(int j=0;j<26;j++)
        {
            if(laws[i]==library[j])
            {
                int c=(j+w) % 26;
                // cerr << c << endl;
                laws[i]=library[c];
            }
        }
    }
    return laws;
}

int main()
{
    string laws;
    int w;
    cout<<"请输入需要加密的明文"<<endl;
    cin>>laws;
   
    cout<<"请输入秘钥"<<endl;
    cin>>w;
    cout<<Caesar(laws,w);

}