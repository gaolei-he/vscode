#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 110;
class CHugeInt {
private:
    int length;
    char data[210];
public:
    CHugeInt(const char* s) {
        length = strlen(s);
        for(int i = 0;i<length;i++) {
            data[i] = s[length - i - 1];
        }
    }
    CHugeInt(int n) {
        do
        {
            data[length ++] = n % 10;
            n /= 10;
        } while (n);
    }
    
};
int main() {
    char s[210];
    int n;

    while (cin >> s >> n) {
        CHugeInt a(s);
        CHugeInt b(n);

        cout << a + b << endl;
        cout << n + a << endl;
        cout << a + n << endl;
        b += n;
        cout << ++b << endl;
        cout << b++ << endl;
        cout << b << endl;
    }
    return 0;
}