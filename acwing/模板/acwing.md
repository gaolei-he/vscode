# <https://www.acwing.com>

## 1.排序

### 快排——分治

```c++
#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int n;
int q[N];

void quick_sort(int q[],int l,int r)
{
    if(l>=r) return;
    
    int x=q[l],i=l-1,j=r+1;
    while(i<j)
    {
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>q[i];
    
    quick_sort(q,0,n-1);
    
    for(int i=0;i<n;i++) cout<<q[i]<<" ";
    
    return 0;
}
```

## 归并

```c++
#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int n;
int q[N],tmp[N];

void merge_sort(int q[],int l,int r)
{
    if(l>=r) return ;
    int mid=(l+r)>>1;
    
    merge_sort(q,l,mid),merge_sort(q,mid+1,r);
    
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
        if(q[i]<=q[j]) tmp[k++]=q[i++];
        else tmp[k++]=q[j++];
    while(i<=mid) tmp[k++]=q[i++];
    while(j<=r) tmp[k++]=q[j++];
    
    for(i=l,j=0;i<=r;i++,j++)
        q[i]=tmp[j];
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>q[i];
    
    merge_sort(q,0,n-1);
    
    for(int i=0;i<n;i++) cout<<q[i]<<" ";
    
    return 0;
}
```

## 2.二分

### 整数二分

```c++
//区间[l,r]被划分成 [l,mid] 和 [mid+1,r] 时使用
int bsearch_1(int l,int r)
{
    while(l<r)
    {
        int mid=l+r >> 1;
        if(check(mid)) r=mid;  //check(mid)判断mid是否         
        else l=mid+1;          //满足性质
    }
    return l;
}

//区间[l,r]被划分成 [l,mid-1] 和 [mid,r] 时使用
int bsearch_2(int l,int r)
{
    while(l<r)
    {
        int mid=l+r+1 >> 1;
        if(check(mid)) l=mid;  //check(mid)判断mid是否         
        else r=mid-1;          //满足性质
    }
    return l;
}

r=mid;    l=mid+1;        mid=l+r >> 1;
l=mid;     r=mid-1;        mid=l+r+1 >> 1;(特例：当  l=r-1 )
```

### 浮点数二分

没有边界问题，直接二分。

## 3.差分

### 二维差分

在x1,y1的位置加C相当于整个5部分加C，以此类推；b(x1,y1 )+=C
b(x2,y1)-=C    b(x1,y2)--=C  b(x2,y2)+=C

```c++
/*
输入一个 n 行 m 列的整数矩阵，再输入 q 个操作，每个操作包含五个整数 x1,y1,x2,y2,c，其中 (x1,y1) 和 (x2,y2) 表示一个子矩阵的左上角坐标和右下角坐标。

每个操作都要将选中的子矩阵中的每个元素的值加上 c。

请你将进行完所有操作后的矩阵输出。

输入格式
第一行包含整数 n,m,q。

接下来 n 行，每行包含 m 个整数，表示整数矩阵。

接下来 q 行，每行包含 5 个整数 x1,y1,x2,y2,c，表示一个操作。

输出格式
共 n 行，每行 m 个整数，表示所有操作进行完毕后的最终矩阵。

数据范围
1≤n,m≤1000,
1≤q≤100000,
1≤x1≤x2≤n,
1≤y1≤y2≤m,
−1000≤c≤1000,
−1000≤矩阵内元素的值≤1000
输入样例：
3 4 3
1 2 2 1
3 2 2 1
1 1 1 1
1 1 2 2 1
1 3 2 3 2
3 1 3 4 1
输出样例：
2 3 4 1
4 3 4 1
2 2 2 2
*/
#include<bits/stdc++.h>

using namespace std;

const int N=1010;

int n,m,q;
int a[N][N],b[N][N];

void insert(int x1,int y1,int x2,int y2,int c)
{
    b[x1][y1]+=c;
    b[x2+1][y1]-=c;
    b[x1][y2+1]-=c;
    b[x2+1][y2+1]+=c;
}

int main()
{
    cin>>n>>m>>q;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            insert(i,j,i,j,a[i][j]);
        }
    }
    while(q--)
    {
        int x1,y1,x2,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        insert(x1,y1,x2,y2,c);
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
           printf("%d ",b[i][j]);
        }
        puts("");
    }
    return 0;
}
```

## 4.双指针算法

```c++
for(int i=0,j=0;i<n;i++)
{
    while(j<=i&&check(j,i)) j++;
    
    res=max(res,j-i+1);
}
```

## 5.位运算

n的二进制表示中第k位

n  >>   k & 1

lowbit(x)   返回x二进制数最后一个1以后的部分

return x&-x;

```c++
#include<bits/stdc++.h>

using namespace std;

int lowbit(int x)
{
    return x&(-x);
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int res=0;
        while(x)
            x-=lowbit(x),res++;
        
        cout<<res<<endl;
    }
    
    return 0;
}
```

## 6.离散化

数组中可能有重复元素       去重

如何算出x离散化后的值       二分

```c++
vector<int>  alls;
sort(alls.begin(),alls.endl());
alls.erase(unique(alls.begin(),alls.end()),alls.end());

int find(int x)
{
    int l=0,r=alls.size()-1;
    while(l<r)
    {
        int mid=l+r >> 1;
        if(alls[mid]>=x)
            r=mid;
        else
            l=mid+1;
    }
    return r+1;
}
```

```c++
#include<bits/stdc++.h>

using namespace std;

#define PII pair<int,int>

const int N=3e5+10;

int n,m;
int a[N],s[N];

vector<int>  alls;
vector<PII> add,query;

int find(int x)
{
    int l=0,r=alls.size()-1;
    while(l<r)
    {
        int mid=l+r >> 1;
        if(alls[mid]>=x) r=mid;
        else l=mid+1;
    }
    return r+1;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x,c;
        cin>>x>>c;
        add.push_back({x,c});
        alls.push_back(x);
    }
    
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        query.push_back({l,r});
        
        alls.push_back(l);
        alls.push_back(r);
    }
    
    sort(alls.begin(),alls.endl());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    
    for(auto item: add)
    {
        int x=find(item.first);
        a[x]+=item.second;
    }
    
    for(int i=1;i<=all.size();i++)
        s[i]=s[i-1]+a[i];
    for(auto item: query)
    {
        int l=find(item.first),r=find(item.second);
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}
```

## 7.堆

![image-20210422005624446](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210422005624446.png)

```c++
#include<bits/stdc++.h>

using namespace std;

int n,m;
const int maxn=1e5+10;

int h[maxn],size;

void down(int u)
{
    int t=u;
    if(u*2<=size&&h[u*2]<h[t]) t=2*u;
    if(u*2+1<=size&&h[u*2+1]<h[t]) t=2*u+1;
    if(u!=t)
    {
        swap(h[u],h[t]);
        down(t);
    }
}

void up(int u)
{
    /*
    int t=u;
    if(u/2&&h[u/2]>h[t]) t=u/2;
    if(u!=t)
    {
        swap(h[u],h[t]);
        up(t);
    }
    */
    while(u/2&&h[u/2]>h[u])
    {
        swap(h[u/2],h[u]);
        u/=2;
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    size=n;

    for(int i=n/2;i;i--) down(i);
    return 0;
}
```

## 8.优先队列

```c++
struct node{
    int x,y;
};

bool operator < (const node &a,const node &b)
{
    return a.y+a.x<b.y+b.x;
}

priority_queue<node > s;

priority_queue<int,vector<int>,less<> > p;
priority_queue<int,vector<int>,greater<> > q;
```

## 9.trie树

```c++
const int N=10010;

int son[N][26],cnt[N],idx;

void insert(const string& str)
{
    int p=0;
    for(auto x : str)
    {
        int u=x-'a';
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
    }

    cnt[p]++;
}

int query(const string& str)
{
    int p=0;
    for(auto x: str)
    {
        int u=x-'a';
        if(!son[p][u]) return 0;
        p=son[p][u];
    }

    return cnt[p];
}
```

给定 NN 个字符串 S1,S2…SN，接下来进行 M 次询问，每次询问给定一个字符串 T，求 S1∼SN 中有多少个字符串是 T 的前缀。

输入字符串的总长度不超过 1e6，仅包含小写字母。

输入：第一行输入两个整数 N，M。

接下来 N 行每行输入一个字符串Si。

接下来 M 行每行一个字符串 T 用以询问。

输出：对于每个询问，输出一个整数表示答案。

每个答案占一行。

```c++
3 2
ab
bc
abc
abc
efg
```

```c++3
2
0
```

```c++
#include<bits/stdc++.h>

using namespace std;
const int N=1e6+10;

int son[N][26],cnt[N],idx;

void insert(const string& str)
{
    int p=0;
    for(auto x: str)
    {
        int u=x-'a';
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
    }

    cnt[p]++;
}

int query(const string& str)
{
    int p=0;
    int sum=0;
    for(auto x: str)
    {
        int u=x-'a';
        if(!son[p][u]) return sum;
        p=son[p][u];
        sum+=cnt[p];
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();

    int n,m;
    cin>>n>>m;
    string s;
    while(n--)
    {
        cin>>s;
        insert(s);
    }

    while(m--)
    {
        cin>>s;
        cout<<query(s)<<endl;
    }
    return 0;
}

```

![image-20210517192402562](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210517192402562.png)

```c++
#include<iostream>
#include<algorithm>
using namespace std;
int const N=100010,M=31*N;

int n;
int a[N];
int son[M][2],idx;
//M代表一个数字串二进制可以到多长

void insert(int x)
{
    int p=0;  //根节点
    for(int i=30;i>=0;i--)
    {
        int u=x>>i&1;   //取X的第i位的二进制数是什么  x>>k&1(前面的模板)
        if(!son[p][u]) son[p][u]=++idx; //如果插入中发现没有该子节点,开出这条路
        p=son[p][u]; //指针指向下一层
    }
}
int search(int x)
{
    int p=0;int res=0;
    for(int i=30;i>=0;i--)
    {                               ///从最大位开始找
        int u=x>>i&1;
        if(son[p][!u]) ////如果当前层有对应的不相同的数
        {   ///p指针就指到不同数的地址

            p=son[p][!u];
            res+=1<<i;
            ///*2相当左移一位  然后如果找到对应位上不同的数res+1 例如    001
        }                                                       ///       010
        else                                            ////          --->011                                                                           //刚开始找0的时候是一样的所以+0    到了0和1的时候原来0右移一位,判断当前位是同还是异,同+0,异+1
        {
            p=son[p][u];
        }
    }
    return res;
}
int main()
{
    cin.tie(0);
    cin>>n;
    idx=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        insert(a[i]);
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        res=max(res,search(a[i]));  //search(a[i])查找的是a[i]值的最大与或值
    }
    cout<<res<<endl;
}
```

![image-20210517192642858](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210517192642858.png)

```c++
#pragma GCC optimize(2)
#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int h[2*N],e[2*N],ne[N*2],w[N*2],idx;
int d[N],vis[N];
int son[N*32][2],cnt;
int n;

void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u)
{
    vis[u]=1;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int v=e[i];
        if(!vis[v])
        {
            d[v]=d[u]^w[i];
            dfs(v);
        }
    }
}

void insert(int x)
{
    int p=0;
    for(int i=30;i>=0;i--)
    {
        int u=x>>i&1;
        if(!son[p][u]) son[p][u]=++cnt;
        p=son[p][u];
    }
}

int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i -- )
    {
        int u = x >> i & 1;
        if (son[p][!u])
        {
            p = son[p][!u];
            res += (1 << i);
        }
        else p = son[p][u];
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();

    memset(h,-1,sizeof h);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }

    dfs(0);
    int res = 0;
    for (int i = 1; i <= n; i ++ )
    {
        insert(d[i]);
    }
    for(int i=1;i<=n;i++)
        res=max(res,query(d[i]));
    cout<<res<<endl;
    return 0;
}
```

## 10.并查集

```c++
const int N=10010;

int parent[N],size[N];

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        size[i]=1;
    }
}

int find(int x)
{
    return parent[x]==x ? x : parent[x]=find(parent[x]);
}

int merge(int x,int y)
{

    if(find(x)!=find(y))
    {
        parent[find(x)]=find(y);
        size[find(y)]+=size[find(x)];
    }
}
```

### 种类并查集

```c++
#include<bits/stdc++.h>

using namespace std;

int fa[150005];

int find(int a) {
    return (fa[a] == a) ? a : (fa[a] = find(fa[a]));
}

int query(int a, int b) {
    return find(a) == find(b);
}

void merge(int a, int b) {
    int x = find(a), y = find(b);
    if(x!=y) fa[x]=y;
}

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
}

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    init(n * 3); //i吃i+n，被i+2n吃
    for (int i = 0; i < m; ++i) {
        int opr, x, y;
        cin>>opr>>x>>y;
        if (x > n || y > n) //特判x或y不在食物链中的情况
            ans++;
        else if (opr == 1) {
            if (query(x, y + n) || query(x, y + 2 * n)) //如果已知x吃y，或者x被y吃，说明这是假话
                ans++;
            else {
                merge(x, y);                 //这是真话，则x和y是一族
                merge(x + n, y + n);         //x的猎物和y的猎物是一族
                merge(x + 2 * n, y + 2 * n); //x的天敌和y的天敌是一族
            }
        } else if (opr == 2) {
            if (query(x, y) || query(x, y + 2 * n)) //如果已知x与y是一族，或者x被y吃，说明这是假话
                ans++;
            else {
                merge(x, y + n);         //这是真话，则x吃y
                merge(x + n, y + 2 * n); //x的猎物吃y的猎物
                merge(x + 2 * n, y);     //x的天敌吃y的天敌，或者说y吃x的天敌
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
```

## 11.哈希表

```c++
const int N=100003;

int h[N],e[N],ne[N],idx,w[N];//head表示头结点下标

void init()
{
    memset(h,-1,sizeof h);
}

void insert(int x,int y)
{
    int k=(x%N+N)%N;
    e[idx]=x;
    w[idx]=y;
    ne[idx]=h[k];
    h[k]=idx++;
}

int find(int x)
{
    int k=(x%N+N)%N;
    for(int i=h[k];i!=-1;i=ne[i])
    {
        if(e[i]==x)
            return w[i];
    }
    return -1;
}
```

```c++
const int N=200003,null=0x3f3f3f3f;

int h[N];

void init()
{
    memset(h,null,sizeof h);
}

int find(int x)
{
    int k=(x%N+N)%N;
    while(h[k]!=null && h[k]!=x)
    {
        k++;
        if(k==N)
            k=0;
    }

    return k;
}

void insert(int x)
{
    int k=find(x);
    h[k]=x;
}
```

### 字符串hash

```c++
//acwing841
/*
给定一个长度为 n 的字符串，再给定 m 个询问，每个询问包含四个整数 l1,r1,l2,r2，请你判断 [l1,r1] 和 [l2,r2] 这两个区间所包含的字符串子串是否完全相同。

字符串中只包含大小写英文字母和数字。

输入格式
第一行包含整数 n 和 m，表示字符串长度和询问次数。

第二行包含一个长度为 n 的字符串，字符串中只包含大小写英文字母和数字。

接下来 m 行，每行包含四个整数 l1,r1,l2,r2，表示一次询问所涉及的两个区间。

注意，字符串的位置从 1 开始编号。

输出格式
对于每个询问输出一个结果，如果两个字符串子串完全相同则输出 Yes，否则输出 No。

每个结果占一行。

数据范围
1≤n,m≤1e5
输入样例：
8 3
aabbaabb
1 3 5 7
1 3 6 8
1 2 1 2
输出样例：
Yes
No
Yes
*/
#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long
const int N=100010,P=131;

int n,m;
char str[N];
ull h[N],p[N];

ull get(int l,int r)
{
    return h[r]-h[l-1]*p[r-l+1];
}

int main()
{
    cin>>n>>m>>(str+1);

    p[0]=1;
    for(int i=1;i<=n;i++)
    {
        p[i]=p[i-1]*P;
        h[i]=h[i-1]*P+str[i];
    }

    while(m--)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(get(l1,r1)==get(l2,r2))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
```

## 12.bitset

```c++
bitset<10000> s;
~s  按位取反
&,|,^,<<,>>,==,!=
s.count()    返回有多少位为1
若s所有位都为0，s.any()返回false，s.none()返回true
若s至少一位为1，s.any()返回true，s.none()返回false
s.set()        把所有位变成1
s.set(k,v)     s[k]=v
s.reset()      把所有位变成0
s.reset(k)     s[k]=0
s.flip()       s=~s
s.flip(k)      s[k]^=1
```

## 13.next_permutation函数

```c++
#include<bits/stdc++.h>

using namespace std;
int a[1001];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=i;
    do{
        for(int i=1;i<n;i++) cout<<a[i]<<' ';
        cout<<a[n]<<endl;
    } while (next_permutation(a+1,a+1+n));
    return 0;
}
```

## 14.KMP

```c++
#include <bits/stdc++.h>
using namespace std;
int pmt[1000005];
string s, p;
int main()
{
    ios::sync_with_stdio(false);
    cin >> s >> p;
    pmt[0] = 0;
    int cnt = 0;
    for (int i = 1, j = 0; i < p.length(); ++i)
    {
        while (p[i] != p[j] && j >= 0)
            j = j ? pmt[j - 1] : -1;
        pmt[i] = ++j;
    }
    for (int i = 0, j = 0; i < s.length(); ++i)
    {
        while (s[i] != p[j] && j >= 0)
            j = j ? pmt[j - 1] : -1;
        ++j;
        if (j == p.length())
        {
            cout << i - j + 2 << endl; // 根据样例输出，这里要的是1-index数组，所以是加2
            j = pmt[j - 1];
        }
    }
    for (int i = 0; i < p.length(); ++i)
        cout << pmt[i] << ' ';
    cout << endl;
    return 0;
}
```

## 15.dfs和bfs

```c++
/*
给定一个整数 n，将数字 1∼n 排成一排，将会有很多种排列方法。

现在，请你按照字典序将所有的排列方法输出。

输入格式
共一行，包含一个整数 n。

输出格式
按字典序输出所有排列方案，每个方案占一行。

数据范围
1≤n≤7
输入样例：
3
输出样例：
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/
#include<bits/stdc++.h>

using namespace std;

int a[1001],n,vis[1001];

void dfs(int h)
{
    if(h==n)
    {
        for(int i=0;i<n;i++) 
            i==n-1 ? cout<<a[i]<<endl : cout<<a[i]<<" ";
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            a[h]=i;
            dfs(h+1);
            vis[i]=0;
        }
    }
}

int main()
{
    cin>>n;
    dfs(0);
    return 0;
}
```

```c++
//acwing844
/*
给定一个 n×m 的二维整数数组，用来表示一个迷宫，数组中只包含 0 或 1，其中 0 表示可以走的路，1 表示不可通过的墙壁。

最初，有一个人位于左上角 (1,1) 处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。

请问，该人从左上角移动至右下角 (n,m) 处，至少需要移动多少次。

数据保证 (1,1) 处和 (n,m) 处的数字为 0，且一定至少存在一条通路。

输入格式
第一行包含两个整数 n 和 m。

接下来 n 行，每行包含 m 个整数（0 或 1），表示完整的二维数组迷宫。

输出格式
输出一个整数，表示从左上角移动至右下角的最少移动次数。

数据范围
1≤n,m≤100
输入样例：
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
输出样例：
8
*/
#include<bits/stdc++.h>

using namespace std;

const int N=1010;

int n,m;
int g[N][N];
int d[N][N];
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int bfs()
{
    queue<pair<int,int> >q;
    q.push(make_pair(0,0));
    memset(d,-1,sizeof d);
    d[0][0]=0;

    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(auto & i : dir)
        {
            int tx=x+i[0];
            int ty=y+i[1];
            if(tx>=0&&x<n&&ty>=0&&ty<m&&g[tx][ty]==0&&d[tx][ty]==-1)
            {
                q.push(make_pair(tx,ty));
                d[tx][ty]=d[x][y]+1;
            }
        }
    }
    return d[n-1][m-1];
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>g[i][j];
    cout<<bfs()<<endl;
    return 0;
}
```

## 16.拓扑序列

```c++
//acwing848
/*
给定一个 n 个点 m 条边的有向图，点的编号是 1 到 n，图中可能存在重边和自环。

请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出 −1。

若一个由图中所有点构成的序列 A 满足：对于图中的每条边 (x,y)，x 在 A 中都出现在 y 之前，则称 A 是该图的一个拓扑序列。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含两个整数 x 和 y，表示存在一条从点 x 到点 y 的有向边 (x,y)。

输出格式
共一行，如果存在拓扑序列，则输出任意一个合法的拓扑序列即可。

否则输出 −1。

数据范围
1≤n,m≤1e5
输入样例：
3 3
1 2
2 3
1 3
输出样例：
1 2 3
*/
#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int n,m,in[N];
vector<int> G[N];
vector<int> ans;

void topsort()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(!in[i])
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        ans.push_back(t);
        for(auto i: G[t])
        {
            in[i]--;
            if(in[i]==0)
                q.push(i);
        }
    }
    if(ans.size()==n)
    {
        for(int i=0;i<ans.size();i++)
            i==ans.size()-1?cout<<ans[i]<<endl:cout<<ans[i]<<" ";
    }
    else
    {
        cout<<"-1"<<endl;
    }
}

int main()
{
    cin>>n>>m;
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        G[x].push_back(y);
        in[y]++;
    }
    topsort();
    return 0;
}
```

## 17.最短路

### 朴素算法

```c++
/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为正值。

请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。

输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。

如果路径不存在，则输出 −1。

数据范围
1≤n≤500,
1≤m≤1e5,
图中涉及边长均不超过10000。

输入样例：
3 3
1 2 2
2 3 1
1 3 4
输出样例：
3
*/
#include<bits/stdc++.h>
 
using namespace std;
 
const int N=1e5+10;
 
vector<int> G[N];
int n,m;
int g[1010][1010];
int dist[1010];
bool st[1010];
 
int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for(int i=1;i<=n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)
        {
            if(!st[j]&&(t==-1||dist[t]>dist[j]))   t=j;
        }
 
        st[t]=true;
        for(int j=1;j<=n;j++)
            dist[j]=min(dist[j],dist[t]+g[t][j]);
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}
 
int main()
{
    cin>>n>>m;
    int x,y,z;
    memset(g,0x3f,sizeof g);
 
    while(m--)
    {
        cin>>x>>y>>z;
        g[x][y]=min(g[x][y],z);
    }
 
    int t=dijkstra();
    cout<<t<<endl;
    return 0;
}
```

### 堆优化

```c++
/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为非负值。

请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。

输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。

如果路径不存在，则输出 −1。

数据范围
1≤n,m≤1.5×1e5,
图中涉及边长均不小于 0，且不超过 10000。

输入样例：
3 3
1 2 2
2 3 1
1 3 4
输出样例：
3
*/
#include<bits/stdc++.h>
 
using namespace std;
 
const int N=1.5e5+10;
#define PII pair<int,int>
 
vector<PII> G[N];
int n,m;
int dist[N];
bool st[N];
 
struct hmd{
    int first,second;
};
 
bool operator <(const hmd &a,const hmd &b)
{
    return a.second>b.second;
}
 
int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
 
    priority_queue<hmd> heap;
    heap.push({1,0});
 
    while(!heap.empty())
    {
        auto t=heap.top();
        heap.pop();
 
        int ver=t.first,distance=t.second;
        if(st[ver]) continue;
 
        st[ver]=true;
 
        for(auto x: G[ver])
        {
            if(dist[x.first]>distance+x.second)
            {
                dist[x.first]=distance+x.second;
                heap.push({x.first,dist[x.first]});
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int x,y,z;
 
    while(m--)
    {
        cin>>x>>y>>z;
        G[x].emplace_back(y,z);
    }
 
    int t=dijkstra();
    cout<<t<<endl;
    return 0;
}
```

```c++
#pragma GCC optimize(2)
#include<bits/stdc++.h>
 
using namespace std;
 
const int N=1.5e5+10;
#define PII pair<int,int>
 
vector<PII> G[N];
int n,m;
int dist[N];
bool st[N];
 
int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
 
    priority_queue<PII,vector<PII>,greater<> > heap;
    heap.push({0,1});
 
    while(!heap.empty())
    {
        auto t=heap.top();
        heap.pop();
 
        int ver=t.second,distance=t.first;
        if(st[ver]) continue;
        
        st[ver]=true;
 
        for(auto x: G[ver])
        {
            if(dist[x.first]>distance+x.second)
            {
                dist[x.first]=distance+x.second;
                heap.push({dist[x.first],x.first});
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();
    cin>>n>>m;
    int x,y,z;
 
    while(m--)
    {
        cin>>x>>y>>z;
        G[x].emplace_back(y,z);
    }
 
    int t=dijkstra();
    cout<<t<<endl;
    return 0;
}
```

```c++
#include<bits/stdc++.h>

using namespace std;

#define PII pair<int,int>

const int N=1.5e5+10;

int n,m;
int h[N],w[N],e[N],ne[N],idx;
int dist[N];
bool st[N];

void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;

    priority_queue<PII,vector<PII>,greater<> > heap;
    heap.push({0,1});

    while(!heap.empty())
    {
        auto t=heap.top();
        heap.pop();

        int ver=t.second,distance=t.first;
        if(st[ver]) continue;
        
        st[ver]=true;
        for(int i=h[ver];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>distance+w[i])
            {
                dist[j]=distance+w[i];
                heap.push({dist[j],j});
            }
        }
    }
    
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();

    cin>>n>>m;

    memset(h,-1,sizeof h);

    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }

    int t=dijkstra();
    cout<<t<<endl;
    return 0;
}
```

### bellman-ford

```c++
//Acwing 853
/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。

请你求出从 1 号点到 n 号点的最多经过 k 条边的最短距离，如果无法从 1 号点走到 n 号点，输出 impossible。

注意：图中可能 存在负权回路 。

输入格式
第一行包含三个整数 n,m,k。

接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示从 1 号点到 n 号点的最多经过 k 条边的最短距离。

如果不存在满足条件的路径，则输出 impossible。

数据范围
1≤n,k≤500,
1≤m≤10000,
任意边长的绝对值不超过 10000。

输入样例：
3 3 1
1 2 1
2 3 1
1 3 3
输出样例：
3
*/
#include<bits/stdc++.h>

using namespace std;

#define PII pair<int,int>

const int N=510,M=10010;

int n,m,k;
int dist[N],backup[N];

struct Edge{
    int a,b,c;
}edge[M];

int bellman_ford()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    
    for(int i=0;i<k;i++)
    {
        memcpy(backup,dist,sizeof dist);
        for(int i=0;i<m;i++)
        {
            int a=edge[i].a,b=edge[i].b,w=edge[i].c;
            dist[b]=min(dist[b],backup[a]+w);
        }
    }
    if(dist[n]>0x3f3f3f3f/2) return -1;
    return dist[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();

    cin>>n>>m>>k;

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge[i]={a,b,c};
    }

    int t=bellman_ford();
    if(t==-1) cout<<"impossible"<<endl;
    else cout<<t<<endl;
    return 0;
}
```

### spfa

```c++
//acwing 851
/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。

请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 impossible。

数据保证不存在负权回路。

输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。

如果路径不存在，则输出 impossible。

数据范围
1≤n,m≤105,
图中涉及边长绝对值均不超过 10000。

输入样例：
3 3
1 2 5
2 3 -3
1 3 4
输出样例：
2
*/
#include<bits/stdc++.h>

using namespace std;

#define PII pair<int,int>

const int N=1.5e5+10;

int n,m;
int h[N],w[N],e[N],ne[N],idx;
int dist[N];
bool st[N];

void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;

    queue<int> q;
    q.push(1);
    st[1]=true;

    while(!q.empty())
    {
        int t=q.front();
        q.pop();

        st[t]=false;

        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[t]+w[i])
            {
                dist[j]=dist[t]+w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
    if(dist[n]==0x3f3f3f3f)
        return -1;
    return dist[n];

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();

    cin>>n>>m;

    memset(h,-1,sizeof h);

    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }

    int t=spfa();
    if(t==-1) cout<<"impossible"<<endl;
    else cout<<t<<endl;
    return 0;
}
```

```c++
//acwing 851
#include<bits/stdc++.h>

using namespace std;

#define PII pair<int,int>

const int N=1.5e5+10;

int n,m;
vector<pair<int,int> > G[N];
int dist[N];
bool st[N];

int spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;

    queue<int> q;
    q.push(1);
    st[1]=true;

    while(!q.empty())
    {
        int t=q.front();
        q.pop();

        st[t]=false;

        for(auto x: G[t])
        {
            int j=x.first;
            if(dist[j]>dist[t]+x.second)
            {
                dist[j]=dist[t]+x.second;
                if(!st[j])
                {
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
    if(dist[n]==0x3f3f3f3f)
        return -1;
    return dist[n];

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();

    cin>>n>>m;

    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        G[a].emplace_back(b,c);
    } 

    int t=spfa();
    if(t==-1) cout<<"impossible"<<endl;
    else cout<<t<<endl;
    return 0;
}
```

### spfa判断负环

```c++
/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。

请你判断图中是否存在负权回路。

输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
如果图中存在负权回路，则输出 Yes，否则输出 No。

数据范围
1≤n≤2000,
1≤m≤10000,
图中涉及边长绝对值均不超过 10000。

输入样例：
3 3
1 2 -1
2 3 4
3 1 -4
输出样例：
Yes
*/
#include<bits/stdc++.h>

using namespace std;

#define PII pair<int,int>

const int N=1e4+10;

int n,m;
vector<pair<int,int> > G[N];
int dist[N],cnt[N];
bool st[N];

bool spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;

    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        st[i]=true;
        q.push(i);
    }

    while(!q.empty())
    {
        int t=q.front();
        q.pop();

        st[t]=false;

        for(auto x: G[t])
        {
            int j=x.first;
            if(dist[j]>dist[t]+x.second)
            {
                dist[j]=dist[t]+x.second;
                cnt[j]=cnt[t]+1;
                if(cnt[j]>=n) return true;
                if(!st[j])
                {
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }

    return false;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();

    cin>>n>>m;

    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        G[a].emplace_back(b,c);
    }

    if(spfa()) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
```

### floyd

```c++
/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，边权可能为负数。

再给定 k 个询问，每个询问包含两个整数 x 和 y，表示查询从点 x 到点 y 的最短距离，如果路径不存在，则输出 impossible。

数据保证图中不存在负权回路。

输入格式
第一行包含三个整数 n,m,k。

接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

接下来 k 行，每行包含两个整数 x,y，表示询问点 x 到点 y 的最短距离。

输出格式
共 k 行，每行输出一个整数，表示询问的结果，若询问两点间不存在路径，则输出 impossible。

数据范围
1≤n≤200,
1≤k≤n2
1≤m≤20000,
图中涉及边长绝对值均不超过 10000。

输入样例：
3 3 2
1 2 1
2 3 2
1 3 1
2 1
1 3
输出样例：
impossible
1
难度：简单
时/空限制：1s / 64MB
总通过数：8526
总尝试数：17579
来源：模板题
算法标签

*/
#include<bits/stdc++.h>

using namespace std;
#define INF 1e9

const int N=210;
int n,m,Q;
int d[N][N];

void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();

    cin>>n>>m>>Q;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) d[i][j]=0;
            else  d[i][j]=INF;
        }
    }

    while(m--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        d[a][b]=min(d[a][b],w);
    }

    floyd();
    while(Q--)
    {
        int a,b;
        cin>>a>>b;
        if(d[a][b]>INF/2) cout<<"impossible"<<endl;
        else cout<<d[a][b]<<endl;
    }
    return 0;
}
```

## 18.最小生成树

```c++
//prim算法
/*
给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环，边权可能为负数。

求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

给定一张边带权的无向图 G=(V,E)，其中 V 表示图中点的集合，E 表示图中边的集合，n=|V|，m=|E|。

由 V 中的全部 n 个顶点和 E 中 n−1 条边构成的无向连通子图被称为 G 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 G 的最小生成树。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含三个整数 u,v,w，表示点 u 和点 v 之间存在一条权值为 w 的边。

输出格式
共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

数据范围
1≤n≤500,
1≤m≤1e5,
图中涉及边的边权的绝对值均不超过 10000。

输入样例：
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
输出样例：
6
*/
#include<bits/stdc++.h>

using namespace std;

const int N=510,INF=0x3f3f3f3f;
int n,m;
int g[N][N];
int dist[N];
bool st[N];

int prim()
{
    memset(dist,0x3f,sizeof dist);

    int res=0;
    for(int i=0;i<n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)
        {
            if(!st[j]&&(t==-1||dist[t]>dist[j]))
                t=j;
        }

        if(i&&dist[t]==INF) return INF;
        
        if(i) res+=dist[t];

        for(int j=1;j<=n;j++)
            dist[j]=min(dist[j],g[t][j]);

        st[t]=true;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();

    cin>>n>>m; 
    memset(g,0x3f,sizeof g);

    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=min(g[a][b],c);
    }

    int t=prim();
    if(t==INF) cout<<"impossible"<<endl;
    else cout<<t<<endl;
    return 0;
}
```

```c++
/*
给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环，边权可能为负数。

求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

给定一张边带权的无向图 G=(V,E)，其中 V 表示图中点的集合，E 表示图中边的集合，n=|V|，m=|E|。

由 V 中的全部 n 个顶点和 E 中 n−1 条边构成的无向连通子图被称为 G 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 G 的最小生成树。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含三个整数 u,v,w，表示点 u 和点 v 之间存在一条权值为 w 的边。

输出格式
共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

数据范围
1≤n≤105,
1≤m≤2∗1e5,
图中涉及边的边权的绝对值均不超过 1000。

输入样例：
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
输出样例：
6
*/
#include<bits/stdc++.h>

using namespace std;

const int N=2e5+10;
int n,m;
int p[N];

int find(int x)
{
    return p[x]==x? x:p[x]=find(p[x]);
}

struct Edge{
    int a,b,w;
    bool operator <(const Edge &W)const
    {
        return w<W.w;
    }
}edge[N];

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edge[i]={a,b,w};
    }

    sort(edge,edge+m);

    for(int i=1;i<=n;i++) p[i]=i;

    int res=0,cnt=0;
    for(int i=0;i<m;i++)
    {
        int a=edge[i].a,b=edge[i].b,w=edge[i].w;
        a=find(a),b=find(b);
        if(a!=b)
        {
            p[a]=b;
            res+=w;
            cnt++;
        }
    }
    
    if(cnt<n-1) cout<<"impossible"<<endl;
    else cout<<res<<endl;
    return 0;
}
```

## 19.二分图

```c++
/*
给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环。

请你判断这个图是否是二分图。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含两个整数 u 和 v，表示点 u 和点 v 之间存在一条边。

输出格式
如果给定图是二分图，则输出 Yes，否则输出 No。

数据范围
1≤n,m≤1e5
输入样例：
4 4
1 3
1 4
2 3
2 4
输出样例：
Yes
*/
#include<bits/stdc++.h>

using namespace std;
const int N=1e5+10;

vector<int> G[N];
int n,m;
int color[N];

bool dfs(int u,int c)
{
    color[u]=c;
    for(auto x: G[u])
    {
        if(!color[x])
        {
            if(!dfs(x,3-c)) return false;
        }
        else if(color[x]==c) return false;
    }
    
    return true;
}

int main()
{
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(!color[i])
        {
            if(!dfs(i,1))
            {
                flag=false;
                break;
            }
        }
    }

    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
```

### 匈牙利算法

```c++
/*
给定一个二分图，其中左半部包含 n1 个点（编号 1∼n1），右半部包含 n2 个点（编号 1∼n2），二分图共包含 m 条边。

数据保证任意一条边的两个端点都不可能在同一部分中。

请你求出二分图的最大匹配数。

二分图的匹配：给定一个二分图 G，在 G 的一个子图 M 中，M 的边集 {E} 中的任意两条边都不依附于同一个顶点，则称 M 是一个匹配。

二分图的最大匹配：所有匹配中包含边数最多的一组匹配被称为二分图的最大匹配，其边数即为最大匹配数。

输入格式
第一行包含三个整数 n1、 n2 和 m。

接下来 m 行，每行包含两个整数 u 和 v，表示左半部点集中的点 u 和右半部点集中的点 v 之间存在一条边。

输出格式
输出一个整数，表示二分图的最大匹配数。

数据范围
1≤n1,n2≤500,
1≤u≤n1,
1≤v≤n2,
1≤m≤105
输入样例：
2 2 4
1 1
1 2
2 1
2 2
输出样例：
2
*/
#include<bits/stdc++.h>

using namespace std;

int n1,n2,m;
int match[510];
bool st[100010];
vector<int> G[510];

bool find(int x)
{
    for(auto i :G[x])
    {
        if(!st[i])
        {
            st[i]=true;
            if(match[i]==0||find(match[i]))
            {
                match[i]=x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n1>>n2>>m;

    while(m--)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
    }

    int res=0;
    for(int i=1;i<=n1;i++)
    {
        memset(st,false,sizeof st);
        if(find(i)) res++;
    }

    cout<<res<<endl;
    return 0;
}
```

```c++
int M, N;            //M, N分别表示左、右侧集合的元素数量
int Map[MAXM][MAXN]; //邻接矩阵存图
int p[MAXN];         //记录当前右侧元素所对应的左侧元素
bool vis[MAXN];      //记录右侧元素是否已被访问过
bool match(int i)
{
    for (int j = 1; j <= N; ++j)
        if (Map[i][j] && !vis[j]) //有边且未访问
        {
            vis[j] = true;                 //记录状态为访问过
            if (p[j] == 0 || match(p[j])) //如果暂无匹配，或者原来匹配的左侧元素可以找到新的匹配
            {
                p[j] = i;    //当前左侧元素成为当前右侧元素的新匹配
                return true; //返回匹配成功
            }
        }
    return false; //循环结束，仍未找到匹配，返回匹配失败
}
int Hungarian()
{
    int cnt = 0;
    for (int i = 1; i <= M; ++i)
    {
        memset(vis, 0, sizeof(vis)); //重置vis数组
        if (match(i))
            cnt++;
    }
    return cnt;
}
```

## 20.动态规划

### 01背包

![image-20210311143029625](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210311143029625.png)

```c++
//每件物品用一次
 #include<bits/stdc++.h>

using namespace std;

const int N=1010;

int n,m;
int v[N],w[N];
int f[N][N];

int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        memset(f,0,sizeof(f));
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>w[i];

        for(int i=1;i<=n;i++) cin>>v[i];

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                f[i][j]=f[i-1][j];
                if(j>=v[i])
                    f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
            }
        }
        cout<<f[n][m]<<endl;
    }
    return 0;
}
```

```c++
//优化
#include<bits/stdc++.h>

using namespace std;

const int N=1010;

int n,m;
int v[N],w[N];
int f[N];

int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        memset(f,0,sizeof(f));
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>w[i];

        for(int i=1;i<=n;i++) cin>>v[i];

        for(int i=1;i<=n;i++)
        {
            for(int j=m;j>=v[i];j--)
            {
                f[j]=max(f[j],f[j-v[i]]+w[i]);
            }
        }
        cout<<f[m]<<endl;
    }
    return 0;
}
```

### 完全背包

![image-20210312130438043](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210312130438043.png)

```c++
//每件物品无限次
//  f[i][j]=max(f[i-1][j-k*v[i]]+k*w[i])    0=<k*v[i]<=m
#include<iostream>

using namespace std;

const int N=1010;

int n,m;
int v[N],w[N];
int f[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k*v[i]<=j;k++)
            {
                f[i][j]=max(f[i][j],f[i-1][j-v[i]*k]+k*w[i]);
            }
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}
```

```c++
/*优化1
f[i][j]=max(f[i-1][j],f[i][j-v[i]]+w[i],f[i-1][j-2*v[i]]+2*w[i]......)
f[i][j-v[i]]=max(f[i-1][j-v[i]],f[i-1][j-2*v[i]]+w[i],f[i-1][j-3*v[i]]+2*w[i])
f[i][j]=max(f[i-1][j],f[i][j-v[i]]+w[i])   
*/
    for(int i=1;i<=n;i++) 
    {
        for(int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            if(j>=v[i])
                f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);
        }
    }
```

```c++
//优化2
    for(int i=1;i<=n;i++)
    {
        for(int j=v[i];j<=m;j++)
        {
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
```

### 多重背包

```c++
//f[i][j]=max(f[i-1][j-v[i]*k]+w[i]*k)     k=0,1.....s[i]
#include<iostream>

using namespace std;

const int N=1010;

int n,m;
int v[N],w[N];
int f[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k*v[i]<=j&&k<=s[i];k++)
            {
                f[i][j]=max(f[i][j],f[i-1][j-v[i]*k]+k*w[i]);
            }
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}
```

```c++
/*优化1
f[i][j]=max(f[i-1][j],f[i][j-v[i]]+w[i],f[i-1][j-2*v[i]]+2*w[i]......，f[i-1][j-s[i]*v[i]]+s[i]*w[i])
f[i][j-v[i]]=max(f[i-1][j-v[i]],f[i-1][j-2*v[i]]+w[i],f[i-1][j-3*v[i]]+2*w[i].....,f[i-1][j-s[i]*v[i]]+(s[i]-1)*w[i]),f[i-1][j-(s[i]+1)*v[i]]+s[i]*w[i])
*/
//二进制优化
#include<bits/stdc++.h>

using namespace std;

const int N=25000,M=2010;

int n.,m;
int v[N],w[N];
int f[N];

int main()
{
    cin>>n>>m;
    int cnt=0;
    
    for(int i=1;i<=n;i++)
    {
        int a,b,s;
        cin>>a>>b>>s;
        int k=1;
        while(k<=s)
        {
            cnt++;
            v[cnt]=a*k;
            w[cnt]=b*k;
            s-=k;
            k*=2;
        }
        if(s>0)
        {
            cnt++;
            v[cnt]=a*s;
            w[cnt]=b*s;
        }
    }
    
    n=cnt;
    for(int i=1;i<=n;i++)
    {
        for(j=m;j>=v[i];j--)
        {
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    
    cout<<f[m]<<endl;
    return 0;
}
```

### 分组背包

```c++
#include<bits/stdc++.h>

using namespace std;

const int N=110;

int n,m;
int v[N][N],w[N][N];
int f[N];

int main()
{
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j=0;j<s[i];j++)
            cin>>v[i][j]>>w[i][j];
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=0;j--)
        {
            for(int k=0;k<s[i];k++)
            {
                if(v[i][k]<=j)
                    f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
```

### 最长上升子序列

```c++
for(int i=1;i<=n;i++)
{
    f[i]=1;//只有一个数
    for(int j=1;j<i;j++)
    {
        if(a[j]<a[i])
        {
            f[i]=max(f[i],f[j]+1);
        }
    }
}

int res=0;
for(int i=1;i<=n;i++)
    res=max(res,f[i]);
cout<<res<<endl;
```

### 最大公共子序列

```c++
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=m;j++)
    {
        f[i][j]=max(f[i-1][j],f[i][j-1]);
        if(a[i]==b[j])
            f[i][j]=max(f[i][j],f[i-1][j-1]+1);
    }
}
```

## 21.试除法

### 求质因子

```c++
#include<bits/stdc++.h>

using namespace std;

void divide(int x)
{
    for(int i=2;i<=x/i;i++)
    {
        if(x%i==0)
        {
            int s=0;
            while(x%i==0)
            {
                s++;
                x/=i;
            }
            cout<<i<<" "<<s<<endl;
        }
    }
    if(x>1) cout<<x<<" "<<1<<endl;
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        divide(n);
    }
    return 0;
}
```

### 求约数

```c++
#include<bits/stdc++.h>

using namespace std;

vector<int> get_divisors(int n)
{
    vector<int> res;
    for(int i=1;i<=n/i;i++)
    {
        if(n%i==0)
        {
            res.push_back(i);
            if(i!=n/i) res.push_back(n/i);
        }
    }

    sort(res.begin(),res.end());
    return res;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        auto res= get_divisors(n);
        for(auto x: res)
        {
            cout<<x<<' ';
        }
        cout<<endl;
    }
    return 0;
}
```

### 约数个数

$$N = p_1^{\alpha _1}p_2^{\alpha _2}\cdots p_k^{\alpha _k}$$
N的约数个数
$$(\alpha _1+1)(\alpha_2+2)\cdots(\alpha_k+1) $$

```c++
/*
给定 n 个正整数 ai，请你输出这些数的乘积的约数个数，答案对 1e9+7 取模。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个整数 ai。

输出格式
输出一个整数，表示所给正整数的乘积的约数个数，答案需对 1e9+7 取模。

数据范围
1≤n≤100,
1≤ai≤2×1e9
输入样例：
3
2
6
8
输出样例：
12
*/
#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int mod=1e9+7;

int main()
{
    unordered_map<int,int> pr;

    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        for(int i=2;i<=x/i;i++)
        {
            while(x%i==0)
            {
                x/=i;
                pr[i]++;
            }
        }
        if(x>1) pr[x]++;
    }

    ll res=1;
    for(auto i: pr)
    {
        res=res*(i.second+1)%mod;
    }

    cout<<res<<endl;
    return 0;
}
```

### 约数之和

$$N = p_1^{\alpha _1}p_2^{\alpha _2}\cdots p_k^{\alpha _k}$$
$$(p_1^0+p_1^1+\cdots+p_1^{\alpha_1})\cdots(p_k^0+p_k^1+\cdots+p_k^{\alpha_k}) $$

```c++
/*
给定 n 个正整数 ai，请你输出这些数的乘积的约数之和，答案对 1e9+7 取模。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个整数 ai。

输出格式
输出一个整数，表示所给正整数的乘积的约数之和，答案需对 1e9+7 取模。

数据范围
1≤n≤100,
1≤ai≤2×109
输入样例：
3
2
6
8
输出样例：
252
*/
#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int mod=1e9+7;

int main()
{
    unordered_map<int,int> pr;

    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        for(int i=2;i<=x/i;i++)
        {
            while(x%i==0)
            {
                x/=i;
                pr[i]++;
            }
        }
        if(x>1) pr[x]++;
    }

    ll res=1;
    for(auto i: pr)
    {
        int p=i.first,a=i.second;
        ll t=1;
        while(a--) t=(t*p+1)%mod;
        res=res*t%mod;
    }

    cout<<res<<endl;
    return 0;
}
```

## 22.筛法

### 埃氏筛法

```c++
#include<bits/stdc++.h>

using namespace std;
const int N=1000010;

int cnt,primes[N];
bool st[N];

void get_prime(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
            primes[cnt++]=i;
            for(int j=i+i;j<=n;j+=i)
                st[j]=true;
        }
    }
}

int main()
{
    int n;
    cin>>n;

    get_prime(n);

    cout<<cnt<<endl;
    return 0;
}
```

### 线性筛法

```c++
#include<bits/stdc++.h>

using namespace std;
const int N=1000010;

int cnt,primes[N];
bool st[N];

void get_prime(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
            primes[cnt++]=i;
        }
        for(int j=0;primes[j]<=n/i;j++)
        {
            st[primes[j]*i]=true;
            if(i% primes[j]==0) break;
        }
    }
}

int main()
{
    int n;
    cin>>n;

    get_prime(n);

    cout<<cnt<<endl;
    return 0;
}
```

## 23.欧几里得算法

```c++
#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int mod=1e9+7;

int gcd(int a,int b)
{
    return b ? gcd(b,a%b) :a;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<gcd(a,b)<<endl;
    }
    return 0;
}
```

## 24.欧拉函数

### 朴素筛法

$$N = p_1^{\alpha _1}p_2^{\alpha _2}\cdots p_k^{\alpha _k}$$
$$\varphi (N) = N(1-\frac{1}{p_1})(1-\frac{1}{p_2})\cdots (1-\frac{1}{p_k}) $$

```c++
#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int mod=1e9+7;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int res=n;
        for(int i=2;i<=n/i;i++)
        {
            if(n%i==0)
            {
                res=res/i*(i-1);
                while(n%i==0) n/=i;
            }
        }
        if(n>1) res=res/n*(n-1);

        cout<<res<<endl;
    }
    return 0;
}
```

### 欧拉筛

```c++
/*
给定一个正整数 n，求 1∼n 中每个数的欧拉函数之和。

输入格式
共一行，包含一个整数 n。

输出格式
共一行，包含一个整数，表示 1∼n 中每个数的欧拉函数之和。

数据范围
1≤n≤106
输入样例：
6
输出样例：
12
*/
#include<bits/stdc++.h>

using namespace std;

#define ll long long
const int N=1000010;

int cnt,primes[N];
int phi[N];
bool st[N];

ll get_eulers(int n)
{
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
            primes[cnt++]=i;
            phi[i]=i-1;
        }
        for(int j=0;primes[j]<=n/i;j++)
        {
            st[primes[j]*i]=true;
            if(i% primes[j]==0)
            {
                phi[i*primes[j]]=primes[j]*phi[i];
                break;
            }
            phi[i*primes[j]]=phi[i]*(primes[j]-1);
        }
    }
    ll res=0;
    for(int i=1;i<=n;i++) res+=phi[i];
    return res;
}

int main()
{
    int n;
    cin>>n;

    cout<<get_eulers(n)<<endl;

    return 0;
}
```

## 25.快速幂

```c++
#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll quick_pow(ll a,ll k,ll p)
{
    ll res=1%p;
    while(k)
    {
        if(k&1) res=res*a%p;
        k>>=1;
        a=a*a%p;
    }
    return res;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        cout<<quick_pow(a,b,c)<<endl;
    }
    return 0;
}
```

### 逆元

$$\frac{a}{b}\equiv ax(mod m)$$
$$\frac{a}{b}\equiv a\cdot b^{-1}(mod m)$$
$$ a\equiv a\cdot b\cdot b^{-1}(mod m) $$
$$b\cdot x\equiv1(mod m) $$
$$b与m互质则b^{m-1}\equiv 1(modm) $$
$$x=b^{m-2} $$

```c++
/*
给定 n 组 ai,pi，其中 pi 是质数，求 ai 模 pi 的乘法逆元，若逆元不存在则输出 impossible。

注意：请返回在 0∼p−1 之间的逆元。

乘法逆元的定义
若整数 b，m 互质，并且对于任意的整数 a，如果满足 b|a，则存在一个整数 x，使得 a/b≡a×x(mod m)，则称 x 为 b 的模 m 乘法逆元，记为 b^−1(modm)。
b 存在乘法逆元的充要条件是 b 与模数 m 互质。当模数 m 为质数时，b^(m−2) 即为 b 的乘法逆元。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个数组 ai,pi，数据保证 pi 是质数。

输出格式
输出共 n 行，每组数据输出一个结果，每个结果占一行。

若 ai 模 pi 的乘法逆元存在，则输出一个整数，表示逆元，否则输出 impossible。

数据范围
1≤n≤105,
1≤ai,pi≤2∗109
输入样例：
3
4 3
8 5
6 3
输出样例：
1
2
impossible
*/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll quick_pow(ll a,ll k,ll p)
{
    ll res=1%p;
    while(k)
    {
        if(k&1) res=res*a%p;
        k>>=1;
        a=a*a%p;
    }
    return res;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        if(a%b==0) cout<<"impossible"<<endl;
        else cout<<quick_pow(a,b-2,b)<<endl;
    }
    return 0;
}
```

```c++
ll exgcd(ll a, ll b, ll &x, ll &y)// 拓欧
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
ll inv(ll a, ll p)
{
    ll x, y;
    if (exgcd(a, p, x, y) != 1) // 无解的情形
        return -1;
    return (x % p + p) % p;
}
```

```c++
long long inv[10010];

void get_inv(int n,int p)
{
    inv[1] = 1;
    for(int i=2;i<=n;i++){
        inv[i] = p - (p / i * inv[p % i] % p) % p;
    }
}
```

### 矩阵快速幂

![image-20210811001631347](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210811001631347.png)

```c++
#include<bits/stdc++.h>

using namespace std;

const int N = 3;
int n, mod;
#define ll long long

struct matrix{ // c++ 中函数的返回值不能为数组，但是struct可以
    ll m[N][N];
}unit; //unit为单位矩阵

void init_unit()  //初始化unit为单位矩阵
{
    for(int i=0; i<N; i++)
        unit.m[i][i] = 1;
}
//适用于两个n*n矩阵的乘法
matrix operator *(const matrix &x, const matrix &y)
{
    matrix ans{}; // 因为此处的ans数组没有初始化为零,所以不能用它去加
    ll t;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            t = 0; //存放乘积后求和的结果
            for(int k=0; k<N; k++)
            {
                t += x.m[i][k] * y.m[k][j] % mod;
            }
            ans.m[i][j] = t % mod;
        }
    }
    return ans;
}
//矩阵快速幂 ，计算矩阵a^k %(mod)
matrix mat_qmi(matrix a, ll k)
{
    matrix res = unit; //res为单位矩阵
    while(k)
    {
        if(k&1) res = res * a; // 记住这里千万不能缩写成res *= a;
        a = a * a;
        k >>= 1;
    }
    return res;
}

ll s[N] = {2, 1, 0}; // 上述矩阵 s（转置）

void multi(ll *A, ll B[][N]) // 计算方阵 B 乘向量 A，并将结果储存在 A 中
{
    ll ans[N] = {0};
    for (int i = 0; i < N; i ++ )
    {
        for (int j = 0; j < N; j ++ )
            ans[i] += A[j] * B[i][j] % mod;
    }
    for (int i = 0; i < N; i ++ ) A[i] = ans[i] % mod;
}

int main ()
{
    cin >> n >> mod;
    init_unit();
    matrix a{};
    int arr[3][3]={{2, 0, -1},
                   {1, 0, 0},
                   {0, 1, 0}};

    for(int i = 0 ; i < 3 ; i ++ )
    {
        for(int j = 0 ; j < 3 ; j ++ ) a.m[i][j]=arr[i][j];
    }

    a = mat_qmi(a, n);

    multi(s, a.m);

    cout<<(s[2]+mod)%mod<<endl;
    return 0;
}
```

![image-20210810234832546](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210810234832546.png)

## 26.扩展欧几里得算法

```c++
/*
给定 n 对正整数 ai,bi，对于每对数，求出一组 xi,yi，使其满足 ai×xi+bi×yi=gcd(ai,bi)。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含两个整数 ai,bi。

输出格式
输出共 n 行，对于每组 ai,bi，求出一组满足条件的 xi,yi，每组结果占一行。

本题答案不唯一，输出任意满足条件的 xi,yi 均可。

数据范围
1≤n≤1e5,
1≤ai,bi≤2×1e9
输入样例：
2
4 6
8 18
输出样例：
-1 1
-2 1
*/
#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int mod=1e9+7;

int exgcd(int a,int b,int &x,int &y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,x,y;
        cin>>a>>b;
        exgcd(a,b,x,y);
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}
```

### 线性同余方程

```c++
/*
给定 n 组数据 ai,bi,mi，对于每组数求出一个 xi，使其满足 ai×xi≡bi(mod mi)，如果无解则输出 impossible。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一组数据 ai,bi,mi。

输出格式
输出共 n 行，每组数据输出一个整数表示一个满足条件的 xi，如果无解则输出 impossible。

每组数据结果占一行，结果可能不唯一，输出任意一个满足条件的结果均可。

输出答案必须在 int 范围之内。

数据范围
1≤n≤1e5,
1≤ai,bi,mi≤2×1e9
输入样例：
2
2 3 6
4 3 5
输出样例：
impossible
-3
*/
#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int mod=1e9+7;

int exgcd(int a,int b,int &x,int &y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,x,y,m;
        cin>>a>>b>>m;
        int d=exgcd(a,m,x,y);
        if(b%d) cout<<"impossible"<<endl;
        else cout<<(long long)b/d*x%m<<endl;
    }
    return 0;
}
```

## 27.中国剩余定理

```c++
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

inline ll inv(ll a, ll p) {
    ll x, y;
    exgcd(a, p, x, y);
    return (x % p + p) % p;
}

inline ll CRT(ll *a, ll *b, ll n) {
    ll p = 1, x = 0;
    for (int i = 0; i < n; ++i)
        p *= a[i];
    for (int i = 0; i < n; ++i) {
        ll r = p / a[i];
        x += (b[i] * r * inv(r, a[i])) % p;
    }
    return x % p;
}

int main() {
    ll n, a[10], b[10];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
    cout << (ll) CRT(a, b, n) << endl;
    return 0;
}
```

## 28.高斯消元

![image-20210508105922522](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210508105922522.png)

```c++
/*
输入一个包含 n 个方程 n 个未知数的线性方程组。

方程组中的系数为实数。

求解这个方程组。

下图为一个包含 m 个方程 n 个未知数的线性方程组示例：

输入格式
第一行包含整数 n。

接下来 n 行，每行包含 n+1 个实数，表示一个方程的 n 个系数以及等号右侧的常数。

输出格式
如果给定线性方程组存在唯一解，则输出共 n 行，其中第 i 行输出第 i 个未知数的解，结果保留两位小数。

如果给定线性方程组存在无数解，则输出 Infinite group solutions。

如果给定线性方程组无解，则输出 No solution。

数据范围
1≤n≤100,
所有输入系数以及常数均保留两位小数，绝对值均不超过 100。

输入样例：
3
1.00 2.00 -1.00 -6.00
2.00 1.00 -3.00 -9.00
-1.00 -1.00 2.00 7.00
输出样例：
1.00
-2.00
3.00
*/
#include<bits/stdc++.h>

using namespace std;

const int N=110;
const double eps=1e-6;

int n;
double a[N][N];

int gauss()
{
    int c,r;
    for(c=0,r=0;c<n;c++)
    {
        int t=r;
        for(int i=r;i<n;i++)
        {
            if(fabs(a[i][c])>fabs(a[t][c])))
                t=i;
        }

        if(fabs(a[t][c])<eps) continue;

        for(int i=c;i<=n;i++) swap(a[t][i],a[r][i]);
        for(int i=n;i>=c;i--) a[r][i]/=a[r][c];
        for(int i=r+1;i<n;i++)
        {
            if(fabs(a[i][c])>eps)
            {
                for(int j=n;j>=c;j--)
                    a[i][j]-=a[r][j]*a[i][c];
            }
        }
        r++;
    }

    if(r<n)
    {
        for(int i=r;i<n;i++)
        {
            if(fabs(a[i][n])>eps)
                return 2;
        }
        return 1;
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
            a[i][n]-=a[i][j]*a[j][n];
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();

    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cin>>a[i][j];
        }
    }

    int t=gauss();
    if(t==0)
    {
        for(int i=0;i<n;i++)
            cout<<fixed<<setprecision(2)<<a[i][n]<<endl;
    }
    else if(t==1)
    {
        cout<<"Infinite group solutions"<<endl;
    }
    else
    {
        cout<<"No solution"<<endl;
    }
    return 0;
}
```

## 29.组合数

### 1.递推

![image-20210508130136087](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210508130136087.png)

```c++
/*
给定 n 组询问，每组询问给定两个整数 a，b，请你输出 Cbamod(1e9+7) 的值。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一组 a 和 b。

输出格式
共 n 行，每行输出一个询问的解。

数据范围
1≤n≤10000,
1≤b≤a≤2000
输入样例：
3
3 1
5 3
2 2
输出样例：
3
10
1
*/
//N^2
#include<bits/stdc++.h>

using namespace std;

const int N=2010,mod=1e9+7;

int c[N][N];

int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!j) c[i][j]=1;
            else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
    
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<c[a][b]<<endl;
    }
    return 0;
}
```

### 2.预处理

```c++
/*
给定 n 组询问，每组询问给定两个整数 a，b，请你输出 Cbamod(1e9+7) 的值。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一组 a 和 b。

输出格式
共 n 行，每行输出一个询问的解。

数据范围
1≤n≤10000,
1≤b≤a≤1e5
输入样例：
3
3 1
5 3
2 2
输出样例：
3
10
1
*/  
//Nlogn
#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N=100010,mod=1e9+7;

ll fact[N],infact[N];

ll quick_pow(ll a,ll k,ll p)
{
    ll res=1%p;
    while(k)
    {
        if(k&1) res=res*a%p;
        k>>=1;
        a=a*a%p;
    }
    return res;
}


int main()
{
    fact[0]=infact[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
        infact[i]=infact[i-1]*quick_pow(i,mod-2,mod)%mod;
    }

    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<fact[a]*infact[b]%mod*infact[a-b]%mod<<endl;
    }
    return 0;
}

```

### 3.卢卡斯定理

$$C_a^b\equiv C_{a\%p}^{b\%p}\cdot C_{a/p}^{b/p}(mod\quad p) $$

```c++
/*
给定 n 组询问，每组询问给定三个整数 a,b,p，其中 p 是质数，请你输出 Cbamodp 的值。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一组 a,b,p。

输出格式
共 n 行，每行输出一个询问的解。

数据范围
1≤n≤20,
1≤b≤a≤1e18,
1≤p≤1e5,

输入样例：
3
5 3 7
3 1 5
6 4 13
输出样例：
3
3
2
*/

#include<bits/stdc++.h>

using namespace std;
#define ll long long
int p;

ll quick_pow(ll a,ll k,ll p1)
{
    ll res=1%p1;
    while(k)
    {
        if(k&1) res=res*a%p1;
        k>>=1;
        a=a*a%p1;
    }
    return res;
}

ll C(ll a,ll b)
{
    ll res=1;
    for(int i=1,j=a;i<=b;i++,j--)
    {
        res=res*j%p;
        res=res* quick_pow(i,p-2,p)%p;
    }
    return res;
}

ll lucas(ll a,ll b)
{
    if(a<p&&b<p)  return C(a,b);
    return C(a%p,b%p)* lucas(a/p,b/p)%p;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b>>p;
        cout<<lucas(a,b)<<endl;
    }
    return 0;
}
```

### 4.大数

```c++
/*
输入 a,b，求 Cba 的值。

注意结果可能很大，需要使用高精度计算。

输入格式
共一行，包含两个整数 a 和 b。

输出格式
共一行，输出 Cba 的值。

数据范围
1≤b≤a≤5000
输入样例：
5 3
输出样例：
10
*/
#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N=5010;

int cnt,primes[N],sum[N];
bool st[N];

void get_prime(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
            primes[cnt++]=i;
        }
        for(int j=0;primes[j]<=n/i;j++)
        {
            st[primes[j]*i]=true;
            if(i% primes[j]==0) break;
        }
    }
}

int get(int n,int p)
{
    int res=0;
    while(n)
    {
        res+=n/p;
        n/=p;
    }
    return res;
}

vector<int> mul(vector<int> a,int b)
{
    vector<int> c;
    int t=0;
    for(int i : a)
    {
        t+=i*b;
        c.push_back(t%10);
        t/=10;
    }

    while(t)
    {
        c.push_back(t%10);
        t/=10;
    }

    return c;
}

int main()
{
    int a,b;
    cin>>a>>b;

    get_prime(a);

    for(int i=0;i<cnt;i++)
    {
        int p=primes[i];
        sum[i]=get(a,p)-get(b,p)-get(a-b,p);
    }

    vector<int> res;
    res.push_back(1);

    for(int i=0;i<cnt;i++)
    {
        for(int j=0;j<sum[i];j++)
        {
            res=mul(res,primes[i]);
        }
    }

    for(int i=res.size()-1;i>=0;i--)
        cout<<res[i];
    cout<<endl;
    return 0;
}
```

## 30.卡特兰数

```c++
/*
给定 n 个 0 和 n 个 1，它们将按照某种顺序排成长度为 2n 的序列，求它们能排列成的所有序列中，能够满足任意前缀序列中 0 的个数都不少于 1 的个数的序列有多少个。

输出的答案对 109+7 取模。

输入格式
共一行，包含整数 n。

输出格式
共一行，包含一个整数，表示答案。

数据范围
1≤n≤105
输入样例：
3
输出样例：
5
*/
#include<bits/stdc++.h>

using namespace std;

const int mod=1e9+7;

#define ll long long

ll quick_pow(ll a,ll k,ll p)
{
    ll res=1%p;
    while(k)
    {
        if(k&1) res=res*a%p;
        k>>=1;
        a=a*a%p;
    }
    return res;
}

int main()
{
    int n;
    cin>>n;

    ll res=1;
    int a=2*n,b=n;
    for(int i=a;i>a-b;i--)  res=res*i%mod;
    for(int i=1;i<=b;i++) res=res* quick_pow(i,mod-2,mod)%mod;
    res=res* quick_pow(n+1,mod-2,mod)%mod;
    
    cout<<res<<endl;
    return 0;
}
```

## 31.网络流

### 1.dinic算法

```c++
//dinic
#include<bits/stdc++.h>

using namespace std;

const int N=10010,M=200010,INF=1e8;

int n,m,S,T;
int h[N],e[M],f[M],ne[M],idx;
int d[N],cur[N];//cur为当前弧优化

void add(int a,int b,int c)
{
    e[idx]=b,f[idx]=c,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,f[idx]=0,ne[idx]=h[b],h[b]=idx++;
}

bool bfs()
{
    queue<int> q;
    memset(d,-1,sizeof d);
    q.push(S);
    d[S]=0;
    cur[S]=h[S];
    while(!q.empty())
    {
        int t=q.front();
        for(int i=h[t];~i;i=ne[i])
        {
            int ver=e[i];
            if(d[ver]==-1&&f[i])
            {
                d[ver]=d[t]+1;
                cur[ver]=h[ver];//当前弧初始化
                if(ver==T)
                    return true;
                q.push(ver);
            }
        }
        q.pop();
    }
    return false;
}

int dfs(int u,int limit)
{
    if(u==T) return limit;
    int flow=0;
    for(int i=cur[u];~i&&flow<limit;i=ne[i])
    {
        cur[u]=i;//更新当前弧
        int ver=e[i];
        if(d[ver]==d[u]+1&&f[i])
        {
            int t=dfs(ver,min(f[i],limit-flow));
            if(!t) d[ver]=-1;//当前边不可用，删掉这个点
            f[i]-=t,f[i^1]+=t,flow+=t;
        }
    }
    return flow;
}

int dinic()
{
    int r=0,flow;
    while(bfs())//找到增广路径时，更新r
    {
        while(flow=dfs(S,INF))
            r+=flow;
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();

    cin>>n>>m>>S>>T;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }

    cout<<dinic()<<endl;
    return 0;
}
```

### 2.EK算法

```c++
//EK算法
#include<bits/stdc++.h>

using namespace std;

const int N=1010,M=20010,INF=1e8;

int n,m ,S,T;
int h[N],e[M],f[M],ne[M],idx;
int d[N],pre[N];
bool st[N];

void add(int a,int b,int c)
{
    e[idx]=b,f[idx]=c,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,f[idx]=0,ne[idx]=h[b],h[b]=idx++;
}

bool bfs()
{
    queue<int> q;
    memset(st,false,sizeof st);
    q.push(S),st[S]=true,d[S]=INF;

    while(!q.empty())
    {
        int t=q.front();
        for(int i=h[t];~i;i=ne[i])
        {
            int ver=e[i];
            if(!st[ver]&&f[i])
            {
                st[ver]=true;
                d[ver]=min(d[t],f[i]);
                pre[ver]=i;//前驱边
                if(ver==T) return true;
                q.push(ver);
            }
        }
        q.pop();
    }
    return false;
}

int EK()
{
    int r=0;
    while(bfs())
    {
        r+=d[T];
        for(int i=T;i!=S;i=e[pre[i]^1])
        {
            f[pre[i]]-=d[T],f[pre[i]^1]+=d[T];
        }
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();

    cin>>n>>m>>S>>T;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }

    cout<<EK()<<endl;
    return 0;
}
/*
 最大流最小割定理
（1）流f是最大流
（2）残留网络中不存在增广路径
（3）存在某一个割（S,T)，使得 |f|=c（S,T)
 */
```

### 3.无源汇上下界可行流

```c++
//dinic   
//zoj2314
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int N = 210, M = (10200+N)*2+10, INF = 1e8;

int n, m, S, T;
int h[N], e[M], f[M], ne[M], idx,l[M];
int d[N], cur[N],A[N];//cur为当前弧优化

void add(int a,int b,int c,int d)
{
    e[idx] = b, f[idx] = d - c, l[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

bool bfs()
{
    queue<int> q;
    memset(d, -1, sizeof d);
    q.push(S);
    d[S] = 0;
    cur[S] = h[S];
    while (!q.empty())
    {
        int t = q.front();
        for (int i = h[t]; ~i; i = ne[i])
        {
            int ver = e[i];
            if (d[ver] == -1 && f[i])
            {
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];//当前弧初始化
                if (ver == T)
                    return true;
                q.push(ver);
            }
        }
        q.pop();
    }
    return false;
}

int dfs(int u, int limit)
{
    if (u == T) return limit;
    int flow = 0;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i])
    {
        cur[u] = i;//更新当前弧
        int ver = e[i];
        if (d[ver] == d[u] + 1 && f[i])
        {
            int t = dfs(ver, min(f[i], limit - flow));
            if (!t) d[ver] = -1;//当前边不可用，删掉这个点
            f[i] -= t, f[i ^ 1] += t, flow += t;
            if(flow==limit) return flow;
        }
    }
    return flow;
}

/*
int dfs(int u, int limit)
{
    if (u == T) return limit;
    int flow = 0,t;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i])
    {
        cur[u] = i;//更新当前弧
        int ver = e[i];
        if (d[ver] == d[u] + 1 && f[i]&&(t = dfs(ver, min(f[i], limit - flow))))
        {
            f[i] -= t, f[i ^ 1] += t, flow += t;
            if (flow == limit) return flow;
        }
    }
    return flow;
}
*/

int dinic()
{
    int r = 0, flow;
    while (bfs())//找到增广路径时，更新r
    {
        while (flow = dfs(S, INF))
            r += flow;
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();

    cin >> n >> m;
    S = 0, T = n + 1;
    memset(h, -1, sizeof(h));
    for(int i=0;i<m;i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add(a, b, c, d);
        A[a] -= c, A[b] += c;
    }

    int tot = 0;
    for(int i=1;i<=n;i++)
    {
        if (A[i] > 0) add(S, i, 0, A[i]), tot += A[i];
        else if (A[i] < 0) add(i, T, 0, -A[i]);
    }

    if (dinic() != tot) cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for (int i = 0; i < m * 2; i += 2)
            cout << f[i^1] + l[i] << endl;
    }
    return 0;
}
```

### 4.有源汇上下界最大流

![image-20210717105246766](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210717105246766.png)

```c++
//https://loj.ac/s/1188831
#include <bits/stdc++.h>

using namespace std;

const int N = 210, M = (10000 + N) * 2, INF = INT_MAX;

int n, m, S, T;
int h[N], e[M], f[M], ne[M], idx;
int d[N], cur[N], A[N]; //cur为当前弧优化

void add(int a, int b, int c) {
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}
int q[N];
bool bfs() {
    queue<int> q;
    memset(d, -1, sizeof d);
    q.push(S);
    d[S] = 0;
    cur[S] = h[S];

    while (!q.empty()) {
        int t = q.front();
        q.pop();

        for (int i = h[t]; ~i; i = ne[i]) {
            int ver = e[i];

            if (d[ver] == -1 && f[i]) {
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];//当前弧初始化

                if (ver == T)
                    return true;

                q.push(ver);
            }
        }
    }

    return false;
}

int dfs(int u, int limit) {
    if (u == T)
        return limit;

    int flow = 0;

    for (int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        cur[u] = i;//更新当前弧
        int ver = e[i];

        if (d[ver] == d[u] + 1 && f[i]) {
            int t = dfs(ver, min(f[i], limit - flow));

            if (!t)
                d[ver] = -1;//当前边不可用，删掉这个点

            f[i] -= t, f[i ^ 1] += t, flow += t;
            //if(flow==limit) return flow;
        }
    }

    return flow;
}

/*
int dfs(int u, int limit)
{
    if (u == T) return limit;
    int flow = 0,t;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i])
    {
        cur[u] = i;//更新当前弧
        int ver = e[i];
        if (d[ver] == d[u] + 1 && f[i]&&(t = dfs(ver, min(f[i], limit - flow))))
        {
            f[i] -= t, f[i ^ 1] += t, flow += t;
            if (flow == limit) return flow;
        }
    }
    return flow;
}
*/

int dinic() {
    int r = 0, flow;

    while (bfs()) { //找到增广路径时，更新r
        while (flow = dfs(S, INF))
            r += flow;
    }

    return r;
}


int main() {
    int s, t;
    cin >> n >> m >> s >> t;
    S = 0, T = n + 1;
    memset(h, -1, sizeof h);

    while (m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add(a, b, d - c);
        A[a] -= c, A[b] += c;
    }

    int tot = 0;

    for (int i = 1; i <= n; i++) {
        if (A[i] > 0)
            add(S, i, A[i]), tot += A[i];
        else if (A[i] < 0)
            add(i, T, -A[i]);
    }

    add(t, s, INF);

    if (dinic() < tot)
        cout << "please go home to sleep" << endl;
    else {
        int res = f[idx - 1];//流量
        S = s, T = t;
        f[idx - 1] = f[idx - 2] = 0;
        cout << res + dinic() << endl;
    }

    return 0;
}
```

### 5.有源汇上下界最小流

![image-20210717111340080](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210717111340080.png)

```c++
//dinic
//https://loj.ac/p/117
#include <bits/stdc++.h>

using namespace std;

const int N = 50010, M = (1250003 + N) * 2, INF = INT_MAX;

int n, m, S, T;
int h[N], e[M], f[M], ne[M], idx;
int d[N], cur[N], A[N]; //cur为当前弧优化

void add(int a, int b, int c) {
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}
int q[N];
bool bfs() {
    int hh = 0, tt = -1;
    memset(d, -1, sizeof d);
    q[++tt] = S;
    d[S] = 0;
    cur[S] = h[S];

    while (hh <= tt) {
        int t = q[hh++];

        for (int i = h[t]; ~i; i = ne[i]) {
            int ver = e[i];

            if (d[ver] == -1 && f[i]) {
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];//当前弧初始化

                if (ver == T)
                    return true;

                q[++tt] = ver;
            }
        }
    }

    return false;
}

int dfs(int u, int limit) {
    if (u == T)
        return limit;

    int flow = 0, t;

    for (int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        cur[u] = i;//更新当前弧
        int ver = e[i];

        if (d[ver] == d[u] + 1 && f[i] && (t = dfs(ver, min(f[i], limit - flow)))) {
            f[i] -= t, f[i ^ 1] += t, flow += t;

            if (flow == limit)
                return flow;
        }
    }

    return flow;
}

int dinic() {
    int r = 0, flow;

    while (bfs()) { //找到增广路径时，更新r
        while (flow = dfs(S, INF))
            r += flow;
    }

    return r;
}


int main() {
    int s, t;
    cin >> n >> m >> s >> t;
    S = 0, T = n + 1;
    memset(h, -1, sizeof h);

    while (m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add(a, b, d - c);
        A[a] -= c, A[b] += c;
    }

    int tot = 0;

    for (int i = 1; i <= n; i++) {
        if (A[i] > 0)
            add(S, i, A[i]), tot += A[i];
        else if (A[i] < 0)
            add(i, T, -A[i]);
    }

    add(t, s, INF);

    if (dinic() < tot)
        cout << "please go home to sleep" << endl;
    else {
        int res = f[idx - 1];
        S = t, T = s;
        f[idx - 1] = f[idx - 2] = 0;
        cout << res - dinic() << endl;
    }

    return 0;
}
```

### 6.多源汇最大流

![image-20210717112915587](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210717112915587.png)

```c++
//dinic
//acwing 2234
#include<bits/stdc++.h>

using namespace std;

const int N = 50010, M = (1250003+N)*2, INF = INT_MAX;

int n, m, S, T;
int h[N], e[M], f[M], ne[M], idx;
int d[N], cur[N],A[N];//cur为当前弧优化

void add(int a,int b,int c)
{
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}
int q[N];
bool bfs()
{
    int hh=0,tt=-1;
    memset(d, -1, sizeof d);
    q[++tt]=S;
    d[S] = 0;
    cur[S] = h[S];
    while (hh<=tt)
    {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int ver = e[i];
            if (d[ver] == -1 && f[i])
            {
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];//当前弧初始化
                if (ver == T)
                    return true;
                q[++tt]=ver;
            }
        }
    }
    return false;
}

int dfs(int u, int limit)
{
    if (u == T) return limit;
    int flow = 0,t;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i])
    {
        cur[u] = i;//更新当前弧
        int ver = e[i];
        if (d[ver] == d[u] + 1 && f[i]&&(t = dfs(ver, min(f[i], limit - flow))))
        {
            f[i] -= t, f[i ^ 1] += t, flow += t;
            if (flow == limit)return flow;
        }
    }
    return flow;
}

int dinic()
{
    int r = 0, flow;
    while (bfs())//找到增广路径时，更新r
    {
        while (flow = dfs(S, INF))
            r += flow;
    }
    return r;
}


int main()
{
    int sc,tc;
    cin>>n>>m>>sc>>tc;
    S=0,T=n+1;
    memset(h,-1,sizeof h);

    while(sc--)
    {
        int x;
        cin>>x;
        add(S,x,INF);
    }

    while(tc--)
    {
        int x;
        cin>>x;
        add(x,T,INF);
    }

    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }

    cout<<dinic()<<endl;
    return 0;
}
```

### 7.关键边

```c++
//dinic
//acwing2236
//poj3204
#include<bits/stdc++.h>

using namespace std;

const int N = 510, M = 10010, INF = INT_MAX;

int n, m, S, T;
int h[N], e[M], f[M], ne[M], idx;
int d[N], cur[N];//cur为当前弧优化
bool vis_s[N],vis_t[N];//源点所有能到的点，所有能到汇点的点

void add(int a,int b,int c)
{
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}
int q[N];
bool bfs()
{
    int hh=0,tt=-1;
    memset(d, -1, sizeof d);
    q[++tt]=S;
    d[S] = 0;
    cur[S] = h[S];
    while (hh<=tt)
    {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int ver = e[i];
            if (d[ver] == -1 && f[i])
            {
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];//当前弧初始化
                if (ver == T)
                    return true;
                q[++tt]=ver;
            }
        }
    }
    return false;
}

int dfs(int u, int limit)
{
    if (u == T) return limit;
    int flow = 0,t;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i])
    {
        cur[u] = i;//更新当前弧
        int ver = e[i];
        if (d[ver] == d[u] + 1 && f[i]&&(t = dfs(ver, min(f[i], limit - flow))))
        {
            f[i] -= t, f[i ^ 1] += t, flow += t;
            if (flow == limit)return flow;
        }
    }
    return flow;
}

int dinic()
{
    int r = 0, flow;
    while (bfs())//找到增广路径时，更新r
    {
        while (flow = dfs(S, INF))
            r += flow;
    }
    return r;
}

void dfs1(int u,bool *st,int t)
{
    st[u]=true;
    for(int i=h[u];~i;i=ne[i])
    {
        int j=i^t,ver=e[i];
        if(f[j]&&!st[ver])
            dfs1(ver,st,t);
    }
}

int main()
{
    cin>>n>>m;
    S=0,T=n-1;//题目中确定的
    memset(h,-1,sizeof h);

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    dinic();
    dfs1(S,vis_s,0);
    dfs1(T,vis_t,1);

    int res=0;
    for(int i=0;i<2*m;i+=2)
    {
        if(!f[i]&&vis_s[e[i^1]]&&vis_t[e[i]])
            res++;
    }
    cout<<res<<endl;
    return 0;
}
```

### 8.最大流判定

![image-20210719175229633](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210719175229633.png)

![image-20210719175337284](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210719175337284.png)

```c++
//#include<bits/stdc++.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

const int N = 1101 * 22 + 10, M = (1100 + N + 22 * 1101) * 2 + 10, INF = 0x3f3f3f3f;

int n, m, S, T, k;
int h[N], e[M], f[M], ne[M], idx;
int d[N], cur[N];
int p[N];

struct ships {
    int h, r, id[30];
} ship[30];

void add(int a, int b, int c) {
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

bool bfs() {
    queue<int> q;
    memset(d, -1, sizeof d);
    q.push(S), d[S] = 0, cur[S] = h[S];

    while (!q.empty()) {
        int t = q.front();
        q.pop();

        for (int i = h[t]; ~i; i = ne[i]) {
            int ver = e[i];

            if (d[ver] == -1 && f[i]) {
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];

                if (ver == T)
                    return true;

                q.push(ver);
            }
        }
    }

    return false;
}

int dfs(int u, int limit) {
    if (u == T)
        return limit;

    int flow = 0;

    for (int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        cur[u] = i;//更新当前弧
        int ver = e[i];

        if (d[ver] == d[u] + 1 && f[i]) {
            int t = dfs(ver, min(f[i], limit - flow));

            if (!t)
                d[ver] = -1;

            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }

    return flow;
}
int dinic() {
    int r = 0, flow;

    while (bfs())
        while (flow = dfs(S, INF))
            r += flow;

    return r;
}

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);

    return p[x];
}

int get(int i, int day) {
    return day * (n + 2) + i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n >> m >> k;
    S = N - 2, T = N - 1;
    memset(h, -1, sizeof h);

    for (int i = 0; i < N; i++)
        p[i] = i;

    for (int i = 0; i < m; i++) {
        cin >> ship[i].h >> ship[i].r;
        int b = ship[i].r;

        for (int j = 0; j < b; j++) {
            int id;
            cin >> id;

            if (id == -1)
                id = n + 1;

            ship[i].id[j] = id;

            if (j) {
                int x = ship[i].id[j - 1];
                p[find(x)] = find(id);
            }
        }
    }

    if (find(0) != find(n + 1))
        cout << "0" << endl;
    else {
        add(S, get(0, 0), k);
        add(get(n + 1, 0), T, INF);
        int day = 1, res = 0;

        while (true) {
            add(get(n + 1, day), T, INF);

            for (int i = 0; i <= n + 1; i++)
                add(get(i, day - 1), get(i, day), INF);

            for (int i = 0; i < m; i++) {
                int r = ship[i].r;
                int a = ship[i].id[(day - 1) % r], b = ship[i].id[day % r];
                add(get(a, day - 1), get(b, day), ship[i].h);
            }

            res += dinic();

            if (res >= k)
                break;

            day++;
        }

        cout << day << endl;
    }

    return 0;
}
```

![image-20210719210719932](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210719210719932.png)

```c++
//poj2455
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>

using namespace std;

const int N=210,M=(40000+N)*2,INF=0x3f3f3f3f;

int n,m,S,T,K;
int h[N],e[M],f[M],w[M],ne[M],idx;
int d[N],cur[N];

void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,w[idx]=c,ne[idx]=h[b],h[b]=idx++;
}

bool bfs()
{
    queue<int> q;
    memset(d,-1,sizeof d);
    q.push(S),d[S]=0,cur[S]=h[S];
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i=h[t];~i;i=ne[i])
        {
            int ver=e[i];
            if(d[ver]==-1&&f[i])
            {
                d[ver]=d[t]+1;
                cur[ver]=h[ver];
                if(ver==T) return true;
                q.push(ver);
            }
        }
    }
    return false;
}

int dfs(int u, int limit)
{
    if (u == T) return limit;
    int flow = 0,t;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i])
    {
        cur[u] = i;//更新当前弧
        int ver = e[i];
        if (d[ver] == d[u] + 1 && f[i]&&(t = dfs(ver, min(f[i], limit - flow))))
        {
            f[i] -= t, f[i ^ 1] += t, flow += t;
            if (flow == limit) return flow;
        }
    }
    return flow;
}
int dinic()
{
    int r=0,flow;
    while(bfs())
        while(flow=dfs(S,INF)) r+=flow;
    return r;
}

bool check(int mid)
{
    for(int i=0;i<idx;i++)
    {
        if(w[i]>mid) f[i]=0;
        else f[i]=1;
    }

    return dinic()>=K;
}

int main()
{
    scanf("%d%d%d", &n, &m, &K);
    S=1,T=n;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        add(a,b,c);
    }

    int l=1,r=1e6;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}
```

### 9.拆点

![image-20210719205524113](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210719205524113.png)

```c++
//dinic
//https://loj.ac/s/1192125
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1010, M = (251010 + 10) * 2, INF = 1e8;

int n, m, S, T;
int h[N], e[M], f[M], ne[M], idx;
int d[N], cur[N]; //cur为当前弧优化
int g[N], w[N];

void add(int a, int b, int c) {
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

bool bfs() {
    queue<int> q;
    memset(d, -1, sizeof d);
    q.push(S);
    d[S] = 0;
    cur[S] = h[S];

    while (!q.empty()) {
        int t = q.front();

        for (int i = h[t]; ~i; i = ne[i]) {
            int ver = e[i];

            if (d[ver] == -1 && f[i]) {
                d[ver] = d[t] + 1;
                cur[ver] = h[ver]; //当前弧初始化

                if (ver == T)
                    return true;

                q.push(ver);
            }
        }

        q.pop();
    }

    return false;
}

int dfs(int u, int limit) {
    if (u == T)
        return limit;

    int flow = 0;

    for (int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        cur[u] = i; //更新当前弧
        int ver = e[i];

        if (d[ver] == d[u] + 1 && f[i]) {
            int t = dfs(ver, min(f[i], limit - flow));

            if (!t)
                d[ver] = -1; //当前边不可用，删掉这个点

            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }

    return flow;
}

int dinic() {
    int r = 0, flow;

    while (bfs()) { //找到增广路径时，更新r
        while (flow = dfs(S, INF))
            r += flow;
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n;
    S = 0, T = 2 * n + 1;
    memset(h, -1, sizeof h);

    for (int i = 1; i <= n; i++)
        cin >> w[i];

    int s = 0;

    for (int i = 1; i <= n; i++) {
        add(i, n + i, 1);
        g[i] = 1;

        for (int j = 1; j < i; j++) {
            if (w[j] <= w[i])
                g[i] = max(g[j] + 1, g[i]);
        }

        s = max(s, g[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (g[i] == s)
            add(n + i, T, 1);
        else if (g[i] == 1)
            add(S, i, 1);

        for (int j = 1; j < i; j++) {
            if (w[j] <= w[i] && g[j] + 1 == g[i])
                add(n + j, i, 1);
        }
    }

    cout << s << endl;

    if (s == 1)
        cout << n << endl << n << endl;
    else {
        int res = dinic();
        cout << res << endl;

        for (int i = 0; i < idx; i += 2) {
            int a = e[i ^ 1], b = e[i];

            if (a == S && b == 1)
                f[i] = INF;

            if (a == 1 && b == n + 1)
                f[i] = INF;

            if (a == n && b == n + n)
                f[i] = INF;

            if (a == n + n && b == T)
                f[i] = INF;
        }

        cout << dinic() + res << endl;
    }

    return 0;
}
```

### 10.最小割

![image-20210723192800500](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210723192800500.png)

```c++
//zoj2676
//dinic
#include<bits/stdc++.h>

using namespace std;

const int N=110,M=2010,INF=0x3f3f3f3f;
const double eps=1e-8;

int n,m,S,T;
int h[N],e[M],ne[M],idx;
double f[M];
int d[N],cur[N];//cur为当前弧优化
int x[M],y[M],z[M];
bool vis[N];

void search_point();

void add(int a, int b, double c)
{
    e[idx]=b,f[idx]=c,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,f[idx]=c,ne[idx]=h[b],h[b]=idx++;
}

bool bfs()
{
    queue<int> q;
    memset(d,-1,sizeof d);
    q.push(S);
    d[S]=0;
    cur[S]=h[S];
    while(!q.empty())
    {
        int t=q.front();
        for(int i=h[t];~i;i=ne[i])
        {
            int ver=e[i];
            if(d[ver]==-1&&f[i]>eps)
            {
                d[ver]=d[t]+1;
                cur[ver]=h[ver];//当前弧初始化
                if(ver==T)
                    return true;
                q.push(ver);
            }
        }
        q.pop();
    }
    return false;
}

double dfs(int u,double limit)
{
    if(u==T) return limit;
    double flow=0;
    for(int i=cur[u];~i&&flow<limit;i=ne[i])
    {
        cur[u]=i;//更新当前弧
        int ver=e[i];
        if(d[ver]==d[u]+1&&f[i]>eps)
        {
            double t=dfs(ver,min(f[i],limit-flow));
            if(t<eps) d[ver]=-1;//当前边不可用，删掉这个点
            f[i]-=t,f[i^1]+=t,flow+=t;
        }
    }
    return flow;
}

double dinic(double mid)
{
    memset(h,-1,sizeof h);
    idx=0;

    double res=0;
    for(int i=1;i<=m;i++)
    {
        if(z[i]>mid)
        {
            add(x[i],y[i],z[i]-mid);
        }
        else
        {
            res+=z[i]-mid;
        }
    }

    double r=0,flow;
    while(bfs())//找到增广路径时，更新r
    {
        while((flow=dfs(S,INF))>eps)
            r+=flow;
    }
    return r+res;
}

void search_point(int u)
{
    vis[u]=true;
    for(int i=h[u];~i;i=ne[i])
    {
        int ver=e[i];
        if(!vis[ver]&&f[i]>eps)
            search_point(ver);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();

    while(cin>>n>>m)
    {
        S=1,T=n;
        memset(vis,false,sizeof vis);

        double l=0,r=0;
        for(int i=1;i<=m;i++)
        {
            cin>>x[i]>>y[i]>>z[i];
            r+=z[i];
        }

        while(r-l>eps)
        {
            double mid=(l+r)/2;

            if(dinic(mid)<0) r=mid;
            else l=mid;
        }

        //cout<<r<<endl;
        //dinic(r);
        search_point(1);

        vector<int> q;
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            if(z[i]<r||(vis[x[i]]!=vis[y[i]]))
            {
                q.push_back(i);
                ans++;
            }
        }
        cout<<ans<<endl;
        for(int i=0;i<ans;i++)
        {
            if(i!=ans-1)
                cout<<q[i]<<" ";
            else
                cout<<q[i]<<endl;
        }

        cout<<endl;
    }
    return 0;
}
```

## 32.快读

```c++
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x;
}
```

```c++
inline int read()
{
    int x=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*w;
}

```

## 33.悬线法

```c++
#include<bits/stdc++.h>

using namespace std;

const int N=1e3+10;

int s[N][N];
int l[N][N], r[N][N], up[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(),cout.tie();

    int n, m; 
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>s[i][j];
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            l[i][j]=r[i][j]=j;
            up[i][j]=1;
        }
    }
    
    for(int i=1; i<=n; i++){//预处理l[][]
        for(int j=2; j<=m; j++){
            if(s[i][j]==0&&s[i][j-1]==0){
                l[i][j]=l[i][j-1];
            }
        }
    }

    for(int i=1; i<=n; i++){//预处理r[][]
        for(int j=m-1; j>=1; j--){
            if(s[i][j]==0&&s[i][j+1]==0){
                r[i][j]=r[i][j+1];
            }
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i>1&&s[i][j]==0&&s[i-1][j]==0){
                l[i][j]=max(l[i][j], l[i-1][j]);
                r[i][j]=min(r[i][j], r[i-1][j]);
                up[i][j]=up[i-1][j]+1;
            }
            int temp=min((r[i][j]-l[i][j]+1), up[i][j]);
            ans=max(ans, temp);
        }
    }
    cout<<ans<<endl;
    return 0;
}
```

## 34.BSGS

![image-20210725171427434](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210725171427434.png)

```c++
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int BSGS(int a,int b,int p)
{
    if(1%p==b%p) return 0;
    int k=sqrt(p)+1;
    unordered_map<int,int> hash;
    for(int i=0,j=b%p;i<k;i++)
    {
        hash[j]=i;
        j= (ll)j*a%p;
    }
    int ak=1;
    for(int i=0;i<k;i++)
        ak=(ll)ak*a%p;
    for(int i=1,j=ak;i<=k;i++)
    {
        if(hash.count(j)) return (ll)i*k-hash[j];
        j=(ll)j*ak%p;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(),cout.tie();

    int a,p,b;
    while(cin>>a>>p>>b&&a&&p&&b)
    {
        int res=BSGS(a,b,p);
        if(res==-1) cout<<"No Solution"<<endl;
        else cout<<res<<endl;
    }
    return 0;
}
```

### 扩展BSGS

![image-20210725210019703](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210725210019703.png)

```c++
#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int INF=INT_MAX;

ll h[N],e[N],ne[N],idx,w[N];

void insert(ll x,ll y)
{
    ll k=(x%N+N)%N;
    e[idx]=x;
    w[idx]=y;
    ne[idx]=h[k];
    h[k]=idx++;
}

ll find(ll x)
{
    ll k=(x%N+N)%N;
    for(int i=h[k];i!=-1;i=ne[i])
    {
        if(e[i]==x)
            return w[i];
    }
    return -1;
}

int BSGS(int a,int b,int p)
{
    if(1%p==b%p) return 0;
    int k=sqrt(p)+1;
   
    unordered_map<int,int> hash;
    /*
    memset(h,-1,sizeof h);
    idx=0;
    */
    
    for(int i=0,j=b%p;i<k;i++)
    {
        //insert(j,i);
        hash[j]=i;
        j= (ll)j*a%p;
    }
    int ak=1;
    for(int i=0;i<k;i++)
        ak=(ll)ak*a%p;
    for(int i=1,j=ak;i<=k;i++)
    {
        if(hash.count(j)) return (ll)i*k-hash[j];
        /*
        if(find(j)!=-1)
            return i*k-find(j);
        */
        j=(ll)j*ak%p;
    }
    return -1;
}

int exgcd(int a,int b,int &x,int &y)
{
    if (!b)
    {
        x=1,y=0;
        return a;
    }
    int d= exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

int EXBSGS(int a,int b,int p)
{
    b=(b%p+p)%p;
    if(1%p==b%p) return 0;
    int x,y;
    int d= exgcd(a,p,x,y);
    if(d>1)
    {
        if(b%d) return -INF;
        exgcd(a/d,p/d,x,y);
        return EXBSGS(a,(ll)b/d*x%(p/d),p/d)+1;
    }
    return BSGS(a,b,p);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(),cout.tie();

    int a,p,b;
    while((cin>>a>>p>>b)&&(a||b||p))
    {
        if(a==0&&b==0&&p==0) break;
        int res=EXBSGS(a,b,p);
        if(res<0) cout<<"No Solution"<<endl;
        else cout<<res<<endl;
    }
    return 0;
}
```

## 35.莫比乌斯反演

### 1.质数个数

![image-20210728175509960](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210728175509960.png)

```c++
#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N=5e4+10;

int cnt,primes[N],mu[N],sum[N];
bool st[N];

void get_mu(int n)
{
    mu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
            primes[cnt++]=i;
            mu[i]=-1;//质数为-1
        }
        for(int j=0;primes[j]<=n/i;j++)
        {
            st[primes[j]*i]=true;//合数
            if(i% primes[j]==0)
            {
                mu[i*primes[j]]=0;
                break;
            }
            else
            {
                mu[i*primes[j]]=-mu[i];//  mu[ prime[j] ]=-1
            }
        }
    }
    for(int i=1;i<N;i++) sum[i]=sum[i-1]+mu[i];//预处理前缀和
}

int h(int k,int x)
{
    return k/(k/x);
}

ll solve(int a,int b,int k)
{
    a/=k,b/=k;
    ll res=0;
    int n=min(a,b);
    for(int l=1,r;l<=n;l=r+1)
    {
        r=min(n,min(h(a,l),h(b,l)));
        res+=(ll) (sum[r]-sum[l-1]) * (a/l) *(b/l);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(),cout.tie();

    get_mu(N);

    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        ll ans=solve(b,d,k)-solve(a-1,d,k)-solve(b,c-1,k)+solve(a-1,c-1,k);
        cout<<ans<<endl;
    }

    return 0;
}
```

### 2.约数个数

![image-20210728175745023](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210728175745023.png)

```c++
#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N=5e4+10;

int cnt,primes[N],mu[N],sum[N],h[N];
bool st[N];

int get_max(int k,int x)
{
    return k/(k/x);
}

void get_mu(int n)
{
    mu[1]=1;
    for(int i=2;i<=n;i++){
        if(!st[i]){
            primes[cnt++]=i;
            mu[i]=-1;//质数为-1
        }
        for(int j=0;primes[j]<=n/i;j++){
            st[primes[j]*i]=true;//合数
            if(i% primes[j]==0){
                mu[i*primes[j]]=0;
                break;
            }
            else{
                mu[i*primes[j]]=-mu[i];//  mu[ prime[j] ]=-1
            }
        }
    }
    for(int i=1;i<N;i++) sum[i]=sum[i-1]+mu[i];//预处理前缀和
    for(int i=1;i<N;i++){
        for(int l=1,r;l<=i;l=r+1){
            r=min(i,get_max(i,l));
            h[i]+=(r-l+1)*(i/l);
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(),cout.tie();

    get_mu(N);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        ll res=0;
        int k=min(n,m);
        for(int l=1,r;l<=k;l=r+1)
        {
            r=min(k,min(get_max(n,l), get_max(m,l)));
            res+=(ll)(sum[r]-sum[l-1])*h[n/l]*h[m/l];
        }
        cout<<res<<endl;
    }
    return 0;
}
```

## 36.计算几何

### 1.基础知识

```c++
1. 前置知识点
    (1) pi = acos(-1);
    (2) 余弦定理 c^2 = a^2 + b^2 - 2abcos(t)

2. 浮点数的比较
const double eps = 1e-8;
int sign(double x)  // 符号函数
{
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    return 1;
}
int cmp(double x, double y)  // 比较函数
{
    if (fabs(x - y) < eps) return 0;
    if (x < y) return -1;
    return 1;
}

3. 向量
    3.1 向量的加减法和数乘运算
    3.2 内积（点积） A·B = |A||B|cos(C)
        (1) 几何意义：向量A在向量B上的投影与B的长度的乘积。
        (2) 代码实现
        double dot(Point a, Point b)
        {
            return a.x * b.x + a.y * b.y;
        }
    3.3 外积（叉积） AxB = |A||B|sin(C)
        (1) 几何意义：向量A与B张成的平行四边形的有向面积。B在A的逆时针方向为正。
        (2) 代码实现
        double cross(Point a, Point b)
        {
            return a.x * b.y - b.x * a.y;
        }
    3.4 常用函数
        3.4.1 取模
        double get_length(Point a)
        {
            return sqrt(dot(a, a));
        }
        3.4.2 计算向量夹角
        double get_angle(Point a, Point b)
        {
            return acos(dot(a, b) / get_length(a) / get_length(b));
        }
        3.4.3 计算两个向量构成的平行四边形有向面积
        double area(Point a, Point b, Point c)
        {
            return cross(b - a, c - a);
        }
        3.4.5 向量A顺时针旋转C的角度：
        Point rotate(Point a, double angle)
        {
            return Point(a.x * cos(angle) + a.y * sin(angle), -a.x * sin(angle) + a.y * cos(angle));
        }
4. 点与线
    4.1 直线定理
        (1) 一般式 ax + by + c = 0
        (2) 点向式 p0 + vt
        (3) 斜截式 y = kx + b
    4.2 常用操作
        (1) 判断点在直线上 A x B = 0
        (2) 两直线相交
        // cross(v, w) == 0则两直线平行或者重合
        Point get_line_intersection(Point p, Vector v, Point q, vector w)
        {
            vector u = p - q;
            double t = cross(w, u) / cross(v, w);
            return p + v * t;
        }
        (3) 点到直线的距离
        double distance_to_line(Point p, Point a, Point b)
        {
            vector v1 = b - a, v2 = p - a;
            return fabs(cross(v1, v2) / get_length(v1));
        }
        (4) 点到线段的距离
        double distance_to_segment(Point p, Point a, Point b)
        {
            if (a == b) return get_length(p - a);
            Vector v1 = b - a, v2 = p - a, v3 = p - b;
            if (sign(dot(v1, v2)) < 0) return get_length(v2);
            if (sign(dot(v1, v3)) > 0) return get_length(v3);
            return distance_to_line(p, a, b);
        }
        (5) 点在直线上的投影
        double get_line_projection(Point p, Point a, Point b)
        {
            Vector v = b - a;
            return a + v * (dot(v, p - a) / dot(v, v));
        }
        (6) 点是否在线段上
        bool on_segment(Point p, Point a, Point b)
        {
            return sign(cross(p - a, p - b)) == 0 && sign(dot(p - a, p - b)) <= 0;
        }
        (7) 判断两线段是否相交
        bool segment_intersection(Point a1, Point a2, Point b1, Point b2)
        {
            double c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1);
            double c3 = cross(b2 - b1, a2 - b1), c4 = cross(b2 - b1, a1 - b1);
            return sign(c1) * sign(c2) <= 0 && sign(c3) * sign(c4) <= 0;
        }
5. 多边形
    5.1 三角形
    5.1.1 面积
        (1) 叉积
        (2) 海伦公式
            p = (a + b + c) / 2;
            S = sqrt(p(p - a) * (p - b) * (p - c));
    5.1.2 三角形四心
        (1) 外心，外接圆圆心
            三边中垂线交点。到三角形三个顶点的距离相等
        (2) 内心，内切圆圆心
            角平分线交点，到三边距离相等
        (3) 垂心
            三条垂线交点
        (4) 重心
            三条中线交点（到三角形三顶点距离的平方和最小的点，三角形内到三边距离之积最大的点）
    5.2 普通多边形
        通常按逆时针存储所有点
        5.2.1 定义
        (1) 多边形
            由在同一平面且不再同一直线上的多条线段首尾顺次连接且不相交所组成的图形叫多边形
        (2) 简单多边形
            简单多边形是除相邻边外其它边不相交的多边形
        (3) 凸多边形
            过多边形的任意一边做一条直线，如果其他各个顶点都在这条直线的同侧，则把这个多边形叫做凸多边形
            任意凸多边形外角和均为360°
            任意凸多边形内角和为(n−2)180°
        5.2.2 常用函数
        (1) 求多边形面积（不一定是凸多边形）
        我们可以从第一个顶点除法把凸多边形分成n − 2个三角形，然后把面积加起来。
        double polygon_area(Point p[], int n)
        {
            double s = 0;
            for (int i = 1; i + 1 < n; i ++ )
                s += cross(p[i] - p[0], p[i + 1] - p[i]);
            return s / 2;
        }
        (2) 判断点是否在多边形内（不一定是凸多边形）
        a. 射线法，从该点任意做一条和所有边都不平行的射线。交点个数为偶数，则在多边形外，为奇数，则在多边形内。
        b. 转角法
        (3) 判断点是否在凸多边形内
        只需判断点是否在所有边的左边（逆时针存储多边形）。
    5.3 皮克定理
        皮克定理是指一个计算点阵中顶点在格点上的多边形面积公式该公式可以表示为:
            S = a + b/2 - 1
        其中a表示多边形内部的点数，b表示多边形边界上的点数，S表示多边形的面积。
6. 圆
    (1) 圆与直线交点
    (2) 两圆交点
    (3) 点到圆的切线
    (4) 两圆公切线
    (5) 两圆相交面积

链接：https://www.acwing.com/activity/content/code/content/635453/
```

### 2.凸包

![image-20210803202419876](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210803202419876.png)

```c++
#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define PDD pair<double,double>

const int N=100010;
const double eps=1e-8;

int n;
PDD q[N];
bool used[N];
int stk[N];

double get_dist(PDD a,PDD b)
{
    double dx=a.x-b.x;
    double dy=a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

PDD operator-(PDD a,PDD b)
{
    return {a.x-b.x,a.y-b.y};
}

double cross(PDD a,PDD b)
{
    return a.x*b.y-b.x*a.y;
}

double area(PDD a,PDD b,PDD c)
{
    return cross(b-a,c-a);
}

double andrew()
{
    sort(q,q+n);
    int top=0;
    for(int i=0;i<n;i++)
    {
        while(top>=2&&area(q[stk[top-1]],q[stk[top]],q[i])>0)
            used[stk[top--]]=false;
        stk[++top]=i;
        used[i]=true;
    }
    used[0]=false;
    for(int i=n-1;i>=0;i--)
    {
        if(used[i]) continue;
        while(top>=2&&area(q[stk[top-1]],q[stk[top]],q[i])>0)
            top--;
        stk[++top]=i;
    }
    double res=0;
    for(int i=2;i<=top;i++)
    {
        res+= get_dist(q[stk[i-1]],q[stk[i]]);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(),cout.tie();

    cin>>n;
    for(int i=0;i<n;i++) cin>>q[i].x>>q[i].y;

    double res=andrew();
    cout<<fixed<<setprecision(2)<<res<<endl;
    return 0;
}
```

### 3.半平面交

## 37.斯特林数

![image-20210812173920629](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210812173920629.png)

![image-20210812174127092](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210812174127092.png)

```c++
#pragma GCC optimize(2)

#include<bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

const int N=1010,mod=1e9+7;

int n,m;
int f[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(), cout.tie();

    cin>>n>>m;
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            f[i][j]=(f[i-1][j-1]+(ll)(i-1)*f[i-1][j])%mod;
        }
    }
    
    cout<<f[n][m]<<endl;
    return 0;
}
```

![image-20210812202537108](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210812202537108.png)

![image-20210812202648491](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210812202648491.png)

```c++
#pragma GCC optimize(2)

#include<bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long

const int N = 1010, mod = 1e9 + 7;

int n, m;
int f[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(), cout.tie();

    cin >> n >> m;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = (f[i - 1][j - 1] + (ll) j * f[i - 1][j]) % mod;
        }
    }

    cout << f[n][m] << endl;
    return 0;
}
```

## 38.线性基

![image-20210812220828002](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210812220828002.png)

```c++
#pragma GCC optimize(2)

#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 1e5 + 10;

vector<ll> B;

void insert(ll x) {
    for (auto b : B)
        x = min(x, b ^ x);
    for (auto &b : B)
        b = min(b, b ^ x);
    if (x)
        B.push_back(x);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(), cout.tie();

    int n;
    ll x;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x, insert(x);

    ll v = 0;
    for (auto b: B)
        v = max(v, v ^ b);

    cout << v << endl;
}
```

```c++
#pragma GCC optimize(2)

#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 1e5 + 10;

vector<ll> B;

void insert(ll x) {
    for (auto b : B)
        x = min(x, b ^ x);
    for (auto &b : B)
        b = min(b, b ^ x);
    if (x)
        B.push_back(x);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(), cout.tie();

    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++) {
        cout << "Case #" << cas << ":" << endl;
        B.clear();
        int n;
        ll x;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> x, insert(x);

        sort(B.begin(), B.end());

        int q;
        cin >> q;
        while (q--) {
            ll k;
            cin >> k;
            ll ans = 0;
            if (B.size() < n)
                k--;
            for (auto b : B) {
                if (k & 1)
                    ans ^= b;
                k >>= 1;
            }
            if (k == 0)
                cout << ans << endl;
            else
                cout << -1 << endl;
        }
    }
    return 0;
}
```

把它尝试插入进线性基里面去，假如可以插入，说明不能异或得到，假如插不进去，则说明可以异或得到。

## 39.差分约束

```c++
#include <bits/stdc++.h>

const int N = 10010;

using namespace std;

int h[N], e[N], ne[N], f[N], idx;

bool inqueue[N];
int cnt[N], dis[N];
queue<int> q;

void add(int a, int b, int c) {
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool SPFA(int s, int n) {
    memset(dis, 0x3f, sizeof(dis));
    //  memset(dis, -0x3f, sizeof(dis));
    dis[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int t = q.front();
        if (cnt[t] > n)
            return false;
        q.pop();
        inqueue[t] = false;
        for (int i = h[t]; ~i; i = ne[i]) {
            int ver = e[i];
            if (f[i] + dis[t] < dis[ver]) // if (f[i] + dis[t] > dis[ver])
            {
                dis[ver] = f[i] + dis[t];
                if (!inqueue[ver]) {
                    q.push(ver);
                    inqueue[ver] = true;
                    cnt[ver]++;
                }
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(), cout.tie();

    int n, m;
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        add(y, x, w);
    }
    for (int i = 1; i <= n; ++i)
        add(0, i, 0);
    if (SPFA(0, n)) {
        for (int i = 1; i <= n; ++i)
            cout << dis[i] << " ";
    } else
        cout << "NO" << endl;
    return 0;
}
```

## 40.ST

```c++
#include <bits/stdc++.h>

using namespace std;
const int N = 50005;

int Log2[N], Min[N][17], Max[N][17];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(), cout.tie();

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        Min[i][0] = x;
        Max[i][0] = x;
    }
    for (int i = 2; i <= n; ++i)
        Log2[i] = Log2[i / 2] + 1;
    for (int i = 1; i <= 16; ++i)
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            Min[j][i] = min(Min[j][i - 1], Min[j + (1 << (i - 1))][i - 1]);
            Max[j][i] = max(Max[j][i - 1], Max[j + (1 << (i - 1))][i - 1]);
        }
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        int s = Log2[r - l + 1];
        int ma = max(Max[l][s], Max[r - (1 << s) + 1][s]);
        int mi = min(Min[l][s], Min[r - (1 << s) + 1][s]);
        cout << (ma - mi) << endl;
    }
    return 0;
}
```

## 41.树状数组和线段树

## 42.珂朵莉树

珂朵莉树的适用范围是有**区间赋值**操作且**数据随机**的题目。

![image-20210815205421756](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210815205421756.png)

```c++
#include <bits/stdc++.h>

using namespace std;
#define ll long long

inline ll read() {
    ll ans = 0;
    char c = getchar();
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c)) {
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans;
}

struct node {
    ll l, r;
    mutable ll v; // 这里mutable要写不然可能会CE
    node(ll l, ll r, ll v) : l(l), r(r), v(v) {} // 构造函数
    bool operator<(const node &o) const { return l < o.l; } // 重载小于运算符
};

set<node> tree;

auto split(ll pos)
// 若不支持C++14，auto须改为set<node>::iterator
{
    auto it = tree.lower_bound(node(pos, 0, 0)); // 寻找左端点大于等于pos的第一个节点
    // 若不支持C++11，auto须改为set<node>::iterator
    if (it != tree.end() && it->l == pos) // 如果已经存在以pos为左端点的节点，直接返回
        return it;
    it--; // 否则往前数一个节点
    ll l = it->l, r = it->r, v = it->v;
    tree.erase(it); // 删除该节点
    tree.insert(node(l, pos - 1, v)); // 插入<l,pos-1,v>和<pos,r,v>
    return tree.insert(node(pos, r, v)).first; // 返回以pos开头的那个节点的迭代器
    // insert默认返回值是一个pair，第一个成员是我们要的
}

int sum;

void assign(int l, int r, int v) {
    int tot = 0, len = 0;
    auto end = split(r + 1), it = split(l), begin = it;
    for (it; it != end; it++) {
        len += (it->r - it->l + 1);
        tot += it->v * (it->r - it->l + 1);//为1的天数
    }
    tree.erase(begin, end);
    tree.insert(node(l, r, v));
    if (v == 1)
        sum += (len - tot);
    else
        sum -= tot;
}

int main() {
    int n = read(), q = read();
    tree.insert(node(1, n, 1));
    sum = n;
    while (q--) {
        int l = read(), r = read(), k = read();
        assign(l, r, k == 1 ? 0 : 1);
        printf("%d\n", sum);
    }
    return 0;
}
```

![image-20210815212608841](C:\Users\1\AppData\Roaming\Typora\typora-user-images\image-20210815212608841.png)

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read()
{
    ll ans = 0;
    char c = getchar();
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c))
    {
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans;
}
struct node
{
    ll l, r;
    mutable ll v;
    node(ll l, ll r, ll v) : l(l), r(r), v(v) {}
    bool operator<(const node &o) const { return l < o.l; }
};
set<node> tree;
auto split(ll pos)
{
    auto it = tree.lower_bound(node(pos, 0, 0));
    if (it != tree.end() && it->l == pos)
        return it;
    it--;
    ll l = it->l, r = it->r, v = it->v;
    tree.erase(it);
    tree.insert(node(l, pos - 1, v));
    return tree.insert(node(pos, r, v)).first;
}
void assign(ll l, ll r, ll v)
{
    auto end = split(r + 1), begin = split(l);
    tree.erase(begin, end);
    tree.insert(node(l, r, v));
}
ll qpow(ll a, ll n, ll p)
{
    ll ans = 1;
    a %= p;
    while (n)
    {
        if (n & 1)
            ans = ans * a % p;
        n >>= 1;
        a = a * a % p;
    }
    return ans;
}
ll n, m, seed, vmax;
ll rnd()
{
    ll ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
}
void add(ll l, ll r, ll v)
{
    auto end = split(r + 1);
    for (auto it = split(l); it != end; it++)
        it->v += v;
}
ll kth(ll l, ll r, ll k)
{
    auto end = split(r + 1);
    vector<pair<ll, ll>> v;
    for (auto it = split(l); it != end; it++)
        v.push_back(make_pair(it->v, it->r - it->l + 1));
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        k -= v[i].second;
        if (k <= 0)
            return v[i].first;
    }
}
ll sum_of_pow(ll l, ll r, ll x, ll y)
{
    ll tot = 0;
    auto end = split(r + 1);
    for (auto it = split(l); it != end; it++)
        tot = (tot + qpow(it->v, x, y) * (it->r - it->l + 1)) % y;
    return tot;
}
int main()
{
    n = read(), m = read(), seed = read(), vmax = read();
    for (int i = 1; i <= n; ++i)
    {
        int r = rnd();
        tree.insert(node(i, i, r % vmax + 1));
    }
    for (int i = 1; i <= m; ++i)
    {
        ll opr = rnd() % 4 + 1, l = rnd() % n + 1, r = rnd() % n + 1, x, y;
        if (l > r)
            swap(l, r);
        if (opr == 3)
            x = rnd() % (r - l + 1) + 1;
        else
            x = rnd() % vmax + 1;
        if (opr == 4)
            y = rnd() % vmax + 1;
        switch (opr)
        {
        case 1:
            add(l, r, x);
            break;
        case 2:
            assign(l, r, x);
            break;
        case 3:
            printf("%lld\n", kth(l, r, x));
            break;
        case 4:
            printf("%lld\n", sum_of_pow(l, r, x, y));
        }
    }
    return 0;
}
```

## 43.生成函数

**生成函数**（Generating Function，也叫**母函数**）是**组合数学**中一种重要的方法，它把**离散数列**与**形式幂级数**对应了起来。

## 44.FFT

```c++
#include <bits/stdc++.h>

using namespace std;

inline int read() {
    int ans = 0;
    char c = getchar();
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c)) {
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans;
}

typedef complex<double> comp;
const int MAXN = 1000005;
const comp I(0, 1);
const double PI = acos(-1);
comp A[MAXN * 3], B[MAXN * 3], tmp[MAXN * 3], ans[MAXN * 3]; // 数组开大一些
int rev[MAXN * 3];

void fft(comp F[], int N, int sgn = 1) {
    int bit = __lg(N);
    for (int i = 0; i < N; ++i) // 蝴蝶变换
    {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
        if (i < rev[i])
            swap(F[i], F[rev[i]]);
    }
    for (int l = 1; l < N; l <<= 1) // 枚举合并前的区间长度
    {
        comp step = exp(sgn * PI / l * I);
        for (int i = 0; i < N; i += l * 2) // 遍历起始点
        {
            comp cur(1, 0);
            for (int k = i; k < i + l; ++k) {
                comp g = F[k], h = F[k + l] * cur;
                F[k] = g + h, F[k + l] = g - h;
                cur *= step;
            }
        }
    }
}

int main() {
    int n = read(), m = read(), N = 1 << (__lg(n + m + 1) + 1); // 补成2的整次幂
    for (int i = 0; i <= n; ++i)
        A[i] = read();
    for (int i = 0; i <= m; ++i)
        B[i] = read();
    fft(A, N), fft(B, N);
    for (int i = 0; i < N; ++i)
        ans[i] = A[i] * B[i];
    fft(ans, N, -1);
    for (int i = 0; i <= n + m; ++i)
        printf("%d ", int(ans[i].real() / N + 0.1)); // +0.1规避浮点误差
    return 0;
}
/*
comp F[MAXN*3];
int main() {
    int n = read(), m = read(), N = 1 << (__lg(n + m + 1) + 1); // 补成2的整次幂
    for (int i = 0; i <= n; ++i)
        A[i] = read();
    for (int i = 0; i <= m; ++i)
        B[i] = read();
    for (int i = 0; i <= max(n, m); ++i)
        F[i] = comp(A[i].real(), B[i].real());
    fft(F, N);
    for (int i = 0; i < N; ++i)
        F[i] = F[i] * F[i];
    fft(F, N, -1);
    for (int i = 0; i <= n + m; ++i)
        printf("%d ", int(F[i].imag() / (N * 2) + 0.1));
    return 0;
}
*/
```

```c++
#include<bits/stdc++.h>

using namespace std;

const int N = 3000010;
const double PI = acos(-1);
int n, m;

struct Complex {
    double x, y;

    Complex operator+(const Complex &t) const {
        return {x + t.x, y + t.y};
    }

    Complex operator-(const Complex &t) const {
        return {x - t.x, y - t.y};
    }

    Complex operator*(const Complex &t) const {
        return {x * t.x - y * t.y, x * t.y + y * t.x};
    }

} a[N], b[N];

int rev[N], bit, tot;  //tot = 1 << bit;

void fft(Complex a[], int inv) {
    for (int i = 0; i < tot; ++i) {
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    }
    for (int mid = 1; mid < tot; mid <<= 1) {
        auto w1 = Complex({cos(PI / mid), inv * sin(PI / mid)});

        for (int i = 0; i < tot; i += mid * 2) {
            auto wk = Complex({1, 0});
            for (int j = 0; j < mid; ++j, wk = wk * w1) {
                auto x = a[i + j], y = wk * a[i + j + mid];
                a[i + j] = x + y, a[i + j + mid] = x - y;
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++i) scanf("%lf", &a[i].x);
    for (int i = 0; i <= m; ++i) scanf("%lf", &b[i].x);
    while ((1 << bit) < n + m + 1) bit++;
    tot = 1 << bit;//大于实际长度的最小2的整次,长度扩充
    for (int i = 0; i < tot; ++i)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));//得到蝴蝶序列
    fft(a, 1), fft(b, 1);//转点值
    for (int i = 0; i < tot; ++i) a[i] = a[i] * b[i];//计算a*b
    fft(a, -1);//转系数
    for (int i = 0; i <= n + m; ++i)
        printf("%d ", (int) (a[i].x / tot + 0.5));//+0.5防止1存成0.99999出现精度问题
    return 0;
}
```
