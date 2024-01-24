#include <iostream>
using namespace std;
class Sample {
   public:
    int v;
    // 在此处补充你的代码
    Sample(int v) {this->v = v;}
    Sample(const Sample &x) {this->v = x.v + 2;}
    Sample(){}
};
void PrintAndDouble(Sample o) {
    cout << o.v;
    cout << endl;
}
int main() {
    Sample a(5);
    Sample b = a;
    PrintAndDouble(b);
    Sample c = 20;
    PrintAndDouble(c);
    Sample d;
    d = a;
    cout << d.v;
    return 0;
}