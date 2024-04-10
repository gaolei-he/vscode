#include <functional>

int main() {
    std::function<void(int)> dfs = [&](int x) {
        dfs(x);
    };
    auto dfs = [&](auto dfs){
        dfs();
    };
    return 0;
}