#include <chrono>
#include <iostream>

int main() {
    std::chrono::year_month_day today = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
    return 0;
}