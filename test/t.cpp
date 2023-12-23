#include <iostream>
#include <vector>

int main()
{
    std::vector<std::pair<int, int>> vec(1);
    for(auto &[x, y] : vec)
    {
        std::cin >> x >> y;
        std::cout << x + y << std::endl;
    }
    return 0;
}