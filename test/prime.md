# 素数探寻与应用实战之旅

> 基于大整数库实现大整数素性判断

组长：何高磊（汇报人）
组员：李杰，吕依阳

## 1. 素数判断

给定一个正整数 $n\in N^+$，试判断其是否为素数。

考虑朴素算法，即从 $2$ 到 $n-1$ 依次判断是否能整除 $n$，时间复杂度为 $O(n)$

考虑简单改进，由于 $n$ 的因子总是成对出现的，对于 $n$ 的任意一对因子 $a, b$，必然有 $a\in [1, \sqrt{n}] \parallel b\in [1, \sqrt{n}] $ ，因此只需判断从 $2$ 到 $\sqrt{n}$ 依次判断是否能整除 $n$，时间复杂度为 $O(\sqrt{n})$

```cpp
#include <chrono>
#include <iostream>
#include <random>


bool isPrime(unsigned long long n)
{
    for (unsigned long long i = 2; i <= n / i; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}


int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned long long> distribution(0, -1);
    unsigned long long random_number = distribution(gen);

    auto start = std::chrono::high_resolution_clock::now();

    if (isPrime(random_number))
        std::cout << random_number << " is a prime!" << std::endl;
    else
        std::cout << random_number << " is not a prime!" << std::endl;

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    std::cout << "Time: " << duration.count() << "s" << std::endl;
    return 0;
}

```

限制：由于C++的语言特性，$n$ 的范围受限于 `int` 类型，即 $n\in [1, 2^{31}-1]$，即使是 `long long` 类型，甚至部分编译器支持的 `__int128` 类型，其范围也仅仅是达到 $n\in [1, 2^{127}-1]$，这对于大整数的素性判断是远远不够的。

## 2. NTL库的引入

NTL（Number Theory Library）是一个用于数论计算的C++库，其支持大整数的运算，包括大整数的素性判断。

以下介绍`Linux(Ubuntu)`下`NTL`库的安装与使用。

前往[NTL官网](https://libntl.org/)下载最新版本的`NTL`库，解压后进入目录，执行以下命令：

```bash
gunzip ntl-xxx.tar.gz
tar xf ntl-xxx.tar
cd ntl-xxx/src
./configure
make
make check
sudo make install
```

由于`NTL`库依赖于`GMP`库，因此需要前往[GMP官网](https://gmplib.org/)下载最新版本的`GMP`库，解压后进入目录，执行以下命令进行安装：

```bash
tar Jxvf gmp-xxx.tar.xz
cd gmp-xxx
./configure
make
make check
sudo make install
```

以上安装完成后，即可在`cpp`源文件中引入`NTL`库：

```cpp
#include <NTL/ZZ.h>
#include <iostream>
#include <random>
#include <chrono>


bool isPrime(NTL::ZZ n)
{
    for(NTL::ZZ i(1ll); i <= n / i; ++ i)
    {
        if(n % i == NTL::ZZ(0))
            return false;
    }
    return true;
}


int main()
{
    NTL::ZZ n(1);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(513, 1024);
    int digit = distribution(gen);
    for (int i = 0; i < digit; i++)
    {
        n *= 2;
        if(distribution(gen) % 2) n += 1;
    }
    
    auto start = std::chrono::high_resolution_clock::now();

    if (isPrime(n))
        std::cout << n << " is a prime!" << std::endl;
    else
        std::cout << n << " is not a prime!" << std::endl;

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    std::cout << "Time: " << duration.count() << "s" << std::endl;
    return 0;
}
```

限制：由于`NTL`库的实现原理，其素性判断的最坏时间复杂度仍然为 $O(\sqrt{n})$，因此对于大整数的素性判断仍然是不够的。

## 3. Miller-Rabin素性测试

将`Miller-Rabin`概率性素性检测算法与`NTL`库结合，实现大整数的素性判断。

伪代码：

输入：一个大于 3 的奇整数 n 和一个正整数 k，其中 k 是算法的安全参数，即算法的误判率为 $4^{-k}$
输出：返回 n 是否是素数，返回 `true` 表示可能是素数，返回 `false` 表示一定是合数

将 n − 1 写成 $2^s\cdot m$ 的形式，其中 $m$ 是奇数，$s$ 是非负整数，执行如下操作

1. i = 1
2. 选择一个随机整数 $b$，$2\leq b\leq n-2$，$r = 0$
3. 计算 $y = b^m \mod n$，如果 $y = 1$ 或者 $y = n-1$，转到步骤 8
4. 若 $r = s-1$，则返回 `false`
5. $r = r + 1$，$y = y^2 \mod n$
6. 若 $y = n-1$，转到步骤 8
7. 转到步骤 4
8. i = i + 1，若 $i\leq k$，转到步骤 2
9. 返回`true`

## 实现

步骤 3
计算 $y = b^m \mod n$，可以使用快速幂算法，时间复杂度为 $O(\log m)$

未取模的快速幂算法实现

```cpp
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
```

取模快速幂实现

```cpp
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
```

Miller-Rabin 算法实现

```cpp
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
```

divide 函数实现

```cpp
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
```

generate_random_number 函数实现

```cpp
NTL::ZZ generate_random_number(NTL::ZZ a, NTL::ZZ b)
{
    NTL::ZZ random_number = a;
    while(random_number <= a)
        NTL::RandomBnd(random_number, b);
    return random_number;
}
```

main 函数

```cpp
#include <NTL/ZZ.h>
#include <iostream>
#include <random>
#include <chrono>

std::random_device rd;
std::mt19937 gen(rd());


int main()
{

    NTL::ZZ n = generate_random_number(mypow(NTL::ZZ(2), NTL::ZZ(0)), mypow(NTL::ZZ(2), NTL::ZZ(1024)));
    
    auto start = std::chrono::high_resolution_clock::now();

    if (isPrime(n, 10))
        std::cout << n << " is a prime!" << std::endl;
    else
        std::cout << n << " is not a prime!" << std::endl;

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    std::cout << "Time: " << duration.count() << "s" << std::endl;
    return 0;
}
```
