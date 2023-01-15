#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
template <class T>
void myswap(T &a, T &b)
{
    T tmp = move(a);
    a = move(b);
    b = move(tmp);
}
class mystring
{
public:
    char *str;
    mystring():str(new char[1]) { str[0] = 0;}
    mystring(const char *s)
    {
        str = new char[strlen(s)+1];
        strcpy(str, s);
    }
    mystring(const mystring & s)
    {
        cout << "copy constructor called" << endl;
        str = new char[strlen(s.str)+1];
        strcpy(str, s.str);
    }
    mystring & operator=(const mystring & s)
    {
        cout << "copy operator= called" << endl;
        if(str != s.str)
        {
            delete [] str;
            str = new char[strlen(s.str)+1];
            strcpy(str, s.str);
        }
        return *this;
    }
    mystring(mystring && s):str(s.str)
    {
        cout << "move constructor called" << endl;
        s.str = new char[1];
        s.str[0] = 0;
    }

    mystring & operator =(mystring && s)
    {
        cout << "move operator= called" << endl;

        if(str != s.str)
        {
            delete []str;
            str = s.str;
            s.str = new char[1];
            s.str[0] = 0;
        }
        return *this;
    }

    ~mystring(){delete[]str;}
};
int main()
{
    mystring a, b;
    swap(a, b);
    

    return 0;
}