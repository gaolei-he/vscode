#include <iostream>
using namespace std;
int main()
{
    int f;
    cout << -5 / 4 << endl;
    while(std::cin>>f)
    {
        f = 5 * (f - 32) / 9;
        std::cout << "Celsius = " << f << std::endl;
    }
    
    return 0;
}