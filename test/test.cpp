#include <NTL/ZZ.h>
#include <iostream>
NTL::ZZ generate_random_number(NTL::ZZ a, NTL::ZZ b)
{
    NTL::ZZ random_number = NTL::RandomBnd(a - b + 1);
    return random_number + a;
}

int main()
{
    NTL::ZZ a, b(1);
    NTL::RandomBnd(a);
    std::cout << a << std::endl;
}