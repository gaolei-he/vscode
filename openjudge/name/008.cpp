#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
class Complex {
   private:
    double r, i;

   public:
    void Print() { cout << r << "+" << i << "i" << endl; }
    Complex() {}
    Complex(const char *s) {
        r = s[0] - '0';
        i = s[2] - '0';
    }
    // 在此处补充你的代码
};
int main() {
    Complex a;
    a = "3+4i";
    a.Print();
    a = "5+6i";
    a.Print();
    return 0;
}