#include <iostream>

using namespace std;

class MyNumber {
public:
    int num;
    MyNumber(): num(0) {}
    MyNumber(int n): num(n) {}
    friend istream& operator>>(istream& input, MyNumber& a)
    {
        input >> a.num;
        return input;
    }
};

int main() {
    MyNumber n1;
    cout << "Enter a number: ";
    cin >> n1;
    cout << "The number is: " << n1.num << endl;
    return 0;
}
