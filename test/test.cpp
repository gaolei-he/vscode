#include<iostream>
using namespace std;
long long a;
int main() {
    scanf("%d%d", (int*)(&a), (int*)(&a)+1);
    printf("%d\n", *((int*)&a) + *((int*)(&a)+1));
    return 0;
}