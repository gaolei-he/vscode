#include <cstring>
#include <iostream>
using namespace std;

class Array2 {
   private:
    int **data;

   public:
    Array2(int x, int y) {
        data = new int *[x];
        for (int i = 0; i < x; i++) {
            data[i] = new int[y];
        }
    }
    Array2() {}
    int operator()(int x, int y) { return data[x][y]; }
    int *operator[](int x) { return data[x]; }
};

int main() {
    Array2 a(3, 4);
    int i, j;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 4; j++) a[i][j] = i * 4 + j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; j++) {
            cout << a(i, j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;
    b = a;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; j++) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}