#include <iostream>
class A {
   private:
    int val;

   public:
    A() {val = 0;}
    A(const A& a) { this->val = a.val; std::cout << "called\n"; }
    A operator=(const A& a) {
        std::cout << "calle\n";
        return A(a);
    }
};
int main() {
    A a;
    A b = a;
    A c(a);
    return 0;
}