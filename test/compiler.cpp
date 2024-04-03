#include <iostream>
#include <map>
#include <set>
std::map<std::string, int> dic{
    {"begin", 1}, {"end", 2},   {"if", 3},  {"then", 4}, {"while", 5},
    {"do", 6},    {"const", 7}, {"var", 8}, {"call", 9}, {"procedure", 10},
    {"odd", 11},  {"+", 14},    {"-", 15},  {"*", 16},   {"/", 17},
    {"=", 18},    {"#", 19},    {"<", 20},  {">", 21},   {":=", 22},
    {"(", 23},    {")", 24},    {",", 25},  {".", 26},   {";", 27}};
std::set<char> st{'\t', ' ', '\n'};

// 从标准输入读取，每次调用返回对应编号和内容
std::pair<int, std::string> solve() {
    char op;
    while (st.count(op = getchar()))
        ;

    if (op == EOF) {
        return {};
    }

    std::string s;
    s.push_back(op);
    if (std::isdigit(op)) {
        while (std::isdigit(std::cin.peek())) {
            op = getchar();
            s.push_back(op);
        }
        return std::make_pair(13, s);
    } else if (dic.count(s)) {
        return std::make_pair(dic[s], s);
    } else if (s == ":" and std::cin.peek() == '=') {
        s.push_back(op = getchar());
        return std::make_pair(dic[s], s);
    } else {
        while (std::isalpha(std::cin.peek()) or std::isdigit(std::cin.peek())) {
            op = getchar();
            s.push_back(op);
        }
        if (dic.count(s)) {
            return std::make_pair(dic[s], s);
        } else {
            return std::make_pair(12, s);
        }
    }
}
// 返回预处理之后的文本
std::string pre_process() {
    std::string str;
    char lst, op = '\0';
    std::cin.get(lst);
    while (std::cin.get(op)) {
        if (lst == '/' and op == '/') {
            while (std::cin.get() != '\n')
                ;
            lst = '\0';
            continue;
        } else if (lst == '(' and op == '*') {
            lst = '\0';
            while (std::cin.get(op)) {
                if (lst == '*' and op == ')') {
                    break;
                }
                lst = op;
            }
            lst = '\0';
            continue;
        }
        if (lst != '\0') {
            str.push_back(lst);
        }
        lst = op;
    }
    if (lst != '\0') {
        str.push_back(lst);
    }
    return str;
}
int main() {
    std::string str = std::move(pre_process());
    std::cout << str;
    std::pair<int, std::string> res;
    while (!(res = solve()).second.empty()) {
        std::cout << res.first << " " << res.second << "\n";
    }
    return 0;
}

/*
1   begin
2   end
3   if
4   then
5   while
6   do
7   const
8   var
9   call
10  procedure
11  odd
12  identifier
13  integer
14  +
15  -
16  *
17  /
18  =
19  #
20  <
21  >
22  :=
23  (
24  )
25  ,
26  .
27  ;
*/