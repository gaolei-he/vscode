#include <ostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
typedef long long LL;
const int N =2000010;
int n;
struct node{
    string name;
    int id,type;//type 0是文件夹 1是文件  id是唯一的
    mutable LL ld,lr;//最大目录配额 最大后代配额
    mutable LL sd,sr;//实际目录配额 实际后代配额
    bool operator<(const node& t)const
    {
        return name<t.name;
    }
};
set<node>son[N];//判断一个文件存不存在
//son【1】是根节点 son【1】内部存的是根节点的所有的文件
// son【2】就是编号为二的文件夹
// 普通文件无id
int idx;//记录文件夹的id
char str[N];//帮助读入的
bool F;
int U;
LL SZ;
vector<string>get(char *str)//  将路径拆成目录 /a/b   a b
{
    vector<string> res(1,"root");
    for(int i=0;str[i];i++)
    {
        if(str[i]=='/')continue;
        string s;
        int j=i;
        while (str[j]&&str[j]!='/')s+=str[j++];
        res.push_back(s);
        i=j-1;
    }
    return  res;
}
LL dfs_remove(vector<string>&t,int u,int p)
//u是当前走到第几个路径
// p当前走到那个文件夹里面了 即id
//son[p]在这里搜索其中我们想要的文件或者文件夹
{
    string name=t[u];//取出该层路径
    if(!son[p].count({name}))return -1;//该文件夹不存在
    auto it=son[p].find({name});//在当前目录下 找到我们名字所对应的目录
    //it 是一个node类型 是在该目录下的文件或者文件夹
    // 有含于同一目录的文件，它们的文件名互不相同；
    if(u==t.size()-1)//找到最后了
        /*
            p
        |   |  |
        f1  f2  f3
        */
    {
        if(it->type==1)t[u]="#file";//标记要删除的文件
        auto sz=it->sr;//存被删的大小
        son[p].erase(it);
        return sz;
    }
    if(it->type==1)return -1;//路径不正确
    auto sz= dfs_remove(t,u+1,it->id);
    //在it文件夹中继续搜索
    if(sz>=0)
    {
        it->sr-=sz;//删文件或文件夹都需要更新 后代配额
        if(t[u+1]=="#file")it->sd-=sz;//删的是文件 需要更新当前目录的大小  目录配额
    }
    return sz;
}
bool dfs_create(vector<string>&t,int u,int p,LL sz)
{
    string name =t[u];
    if(u==t.size()-1)//到最后一层
    {
        if(son[p].count({name}))//有同名文件或文件夹
        {
            auto it=son[p].find({name});
            if(it->type==0)return false;//是文件夹
            SZ= dfs_remove(t,0,0);//删掉 用SZ记录删掉的文件大小
            node cur{name,++idx,1,0,0,0,sz};
            son[p].insert(cur);
            return true;
        } else
        {
            node cur{name,++idx,1,0,0,0,sz};
            son[p].insert(cur);
            return true;
        }
    }
    else
    {
        if(!son[p].count({name}))//没有这个文件夹就创建它
        {
            if(U==-1)U=u;
            node cur{name,++idx,0,0,0,0,0};
            son[p].insert(cur);
        }
        auto it=son[p].find({name});
        if(it->type)return false;//还没走完就遇到文件  说明错误
        auto res= dfs_create(t,u+1,it->id,sz);
        if(res)
        {
            it->sr+=sz;//后代配额增加
            //判断是不是自己的孩子 如果是就需要更新目录配额
            if(u+1==t.size()-1)it->sd+=sz;
            if(it->lr&&it->sr>it->lr)F= false;//超内存 需标记 过后慢慢处理
            if(it->ld&&it->sd>it->ld)F= false;
        }
        return res;
    }
}
bool create(char *str,LL sz)
{
    auto t=get(str);
    F= true;//插入过程中有没有文件超过了配额上限
    U=-1;//如果我们创建了文件夹 那么创建的第一个文件夹是第几层
    SZ=-1;//被我们替换的重名文件原大小  用来恢复现场用
    auto res= dfs_create(t,0,0,sz);
    auto ans=res&&F;
    if(res&&!F)//恢复现场 删掉所有新创建的路径
    {
        auto t=get(str);
        if(U!=-1)//恢复替换文件
        {//路径与原来一样 所以只需记录恢复文件的大小
            while (t.size()-1>U)t.pop_back();
        }
        dfs_remove(t,0,0);
        if(SZ!=-1)create(str,SZ);
    }
    return ans;
}
bool update(char *str,LL d,LL r)
{
    auto t= get(str);
    int p=0;
    for (int i = 0; i < t.size(); ++i) {
        string& s=t[i];
        auto it=son[p].find({s});
        if(it==son[p].end())return false;
        if(it->type)return false;//能修改的只能是文件夹 文件就直接返回false
        if(i==t.size()-1)//找到了那个文件夹
        {
            if(d&&d<it->sd)return false;
            if(r&&r<it->sr)return false;
            it->ld=d;
            it->lr=r;
        }
        p=it->id;
    }
    return true;
}
int main()
{
    scanf("%d",&n);
    char op[2];
    sprintf(str,"/tmp");
    create(str,1);
    auto t=get(str);
    dfs_remove(t,0,0);
    //创建根目录 随便建文件 然后删掉
    while (n--)
    {
        scanf("%s",op);
        bool res;
        if(*op=='C')
        {
            LL sz;
            scanf("%s%lld",str,&sz);
            res=create(str,sz);//目录 str 大小 sz
            //res true 说明操作成功
        } else if(*op=='R')
        {
            scanf("%s",str);
            auto t=get(str);
            dfs_remove(t,0,0);
            res= true;
        } else
        {
            LL d,r;
            scanf("%s%lld%lld",str,&d,&r);
            res=update(str,d,r);
        }
        if(res)puts("Y"); else
        {
            puts("N");
        }
    }
    return 0;
}