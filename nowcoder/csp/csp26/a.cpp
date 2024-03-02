#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>


int main()
{
    int n; std::cin >> n;
    double avg = 0;
    std::vector<int> a(n);
    int sm = 0;
    for(auto &x : a)
    {
        std::cin >> x;
        sm += x;
    }
    avg = sm * 1.0 / n;
    double sigma = 0;
    for(auto x : a) sigma += (x - avg) * (x - avg);
    sigma /= n;
    for(auto x : a)
    {
        std::cout << (x - avg) / sqrt(sigma) << ' ';
    }
    return 0;
}