#include <NTL/ZZ.h>
#include <iostream>
#include <random>
#include <chrono>


std::random_device rd;
std::mt19937 gen(rd());


NTL::ZZ generate_random_number(NTL::ZZ a, NTL::ZZ b)
{
    NTL::ZZ random_number;
    NTL::RandomBnd(random_number, b - a);
    return random_number + a;
}


NTL::ZZ mypow(NTL::ZZ a, NTL::ZZ b)
{
    NTL::ZZ res(1);
    while(b != 0)
    {
        if(b % 2 == 1) res *= a;
        b /= 2;
        a *= a;
    }
    return res;
}
// quick_pow
NTL::ZZ mypow(NTL::ZZ a, NTL::ZZ b, NTL::ZZ mod)
{
    NTL::ZZ res(1);
    while(b != 0)
    {
        if(b % 2 == 1) res = res * a % mod;
        b /= 2;
        a = a * a % mod;
    }
    return res;
}


void divide(NTL::ZZ n, NTL::ZZ &s, NTL::ZZ &m)
{
    m = n;
    s = 0;
    while(m % 2 == 0)
    {
        m /= 2;
        s += 1;
    }
}


bool isPrime(NTL::ZZ n, int k)
{
    NTL::ZZ s, m;
    divide(n - 1, s, m);
    for (int i = 0; i < k; i++)
    {

        auto b = generate_random_number(NTL::ZZ(2), n - 2);
        int r = 0;
        auto y = mypow(b, m, n);
        if(y == 1 or y == n - 1) continue;
        while(true)
        {
            if(r == s - 1) return false;
            r ++;
            y = mypow(y, NTL::ZZ(2), n);
            if(y == n - 1) break;
        }
    }
    return true;
}


int main()
{

    NTL::ZZ n = generate_random_number(mypow(NTL::ZZ(2), NTL::ZZ(0)), mypow(NTL::ZZ(2), NTL::ZZ(1024)));
    

    // n = 100000000007;
    // std::cout << n << std::endl;
    // std::cin >> n;
    auto start = std::chrono::high_resolution_clock::now();

    if (isPrime(n, 10))
        std::cout << n << " is a prime!" << std::endl;
    else
        std::cout << n << " is not a prime!" << std::endl;


    // if (isPrime(n, 10))
    //     std::cout << n << " is a prime!" << std::endl;
    // else
    //     std::cout << n << " is not a prime!" << std::endl;

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    std::cout << "Time: " << duration.count() << "s" << std::endl;
    return 0;
}