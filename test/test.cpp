#include <unordered_set>
struct Node {
    int a, b;
    std::size_t operator()(const Node& node) {
        return a * 10000 + b;
    }
};
int main() {
    std::unordered_set<Node, Node> st;

    return 0;
}