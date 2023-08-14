int main() {
    int a = 0xcf;
    int& b = a;
    a <<= 2;
    b <<= 2;

    return 0;
}
