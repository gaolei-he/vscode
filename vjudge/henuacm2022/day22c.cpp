#include <cmath>
#include <iostream>
using namespace std;
const int N = 110;
const double eps = 1e-6;

int n;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
class A
{
    int fenzi, fenmu;
public:
    A(){}
    A(int a, int b){fenzi = a, fenmu = b;}
    friend istream &operator>>(istream &in, A &obj)
    {
        in >> obj.fenzi;
        obj.fenmu = 1;
        return in;
    }
    friend ostream &operator<<(ostream &out, A &obj)
    {
        int d = gcd(obj.fenmu, obj.fenzi);
        int t1 = obj.fenzi / d, t2 = obj.fenmu / d;
        if(t1 * t2 < 0) cout << '-';
        if(t2 == 1 || t2 == -1) out << abs(t1);
        else out << abs(t1) << '/' << abs(t2);
        return out;
    }
    void operator-=(A obj)
    {
        int t2 = obj.fenmu * this->fenmu;
        int t1 = this->fenzi * obj.fenmu - this->fenmu * obj.fenzi;
        int d = gcd(t1, t2);
        this->fenzi = t1 / d;
        this->fenmu = t2 / d;
    }
    A operator*(A obj)
    {
        int t1 = this->fenzi * obj.fenzi;
        int t2 = this->fenmu * obj.fenmu;
        int d = gcd(t1, t2);
        return A(t1/d, t2/d);
    }
    void operator/=(A obj)
    {
        this->fenzi *= obj.fenmu;
        this->fenmu *= obj.fenzi;
        int d = gcd(this->fenmu, this->fenzi);
        this->fenmu /= d;
        this->fenzi /= d;
    }
    double myabs()
    {
        return fabs(fenzi * 1.0 / fenmu);
    }
};
A a[N][N];
int gauss()
{
    int r, c;
    for(r = 0, c=0;c<n;c++)
    {
        int t = r;
        for(int i=r;i<n;i++)
            if(a[i][c].myabs() > a[t][c].myabs())
                t = i;
        if(a[t][c].myabs() < eps) continue;
        for(int i=c;i<=n;i++) swap(a[r][i], a[t][i]);
        for(int i=n;i>=c;i--) a[r][i] /= a[r][c];
        for(int i=r+1;i<n;i++)
            if(a[i][c].myabs() > eps)
                for(int j=n;j>=c;j--)
                    a[i][j] -= a[i][c] * a[r][j];
        r ++;
    }
    if(r < n) return 1;
    for(int i=n-1;i>=0;i--)
        for(int j=i+1;j<n;j++)
            a[i][n] -= a[i][j] * a[j][n];
    return 0;
}

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n+1; j++)
            {
                cin >> a[i][j];
            }
            
        }
        int t = gauss();
        if(t) puts("No solution");
        else for(int i=0;i<n;i++) cout << a[i][n] << endl;
    }
    
    return 0;
}