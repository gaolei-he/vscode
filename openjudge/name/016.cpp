#include <iostream>
using namespace std;
class Point {
   private:
    int x;
    int y;

   public:
    Point(){};
    // 在此处补充你的代码
    friend istream& operator>>(istream& is, Point& point) {
        is >> point.x >> point.y;
        return is;
    }
    friend ostream& operator<<(ostream& os, Point& point) {
        os << point.x << "," << point.y;
        return os;
    }

};

int main() {
    Point p;
    while (cin >> p) {
        cout << p << endl;
    }
    return 0;
}