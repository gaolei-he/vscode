code_cpp='
/*
中心极限定理实验模拟程序
进行n次实验,每次实验投掷m次硬币,0为正,1为反
每次实验取结果的平均值,最终获取n个随机变量
当n足够大时,其服从区间[0,1]正态分布
*/
#include <mutex>
#include <iostream>
#include <random>
#include <thread>
#include <vector>


int num_trials = 10000000;// 实验次数
int num_coin_tosses = 1000;// 每次实验投掷硬币次数


// 多少线程并行计算，推荐设定为本机线程数
int num_threads = 16;

std::mutex mtx;
std::vector<double> ans;

void run() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    while (true) {
        std::unique_lock<std::mutex> lck(mtx);
        if (num_trials) {
            num_trials -= 1;
        } else {
            break;
        }
        lck.unlock();
        int res = 0;
        for (int i = 0; i < num_coin_tosses; i++) {
            res += dis(gen);
        }

        lck.lock();
        ans.push_back(res * 1.0 / num_coin_tosses);
    }
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < num_threads; i++) {
        threads.emplace_back(run);
    }
    for (auto &th : threads) {
        th.join();
    }

    for(auto x : ans) {
        std::cout << x << " ";
    }

    return 0;
}
'

code_python='
import matplotlib.pyplot as plt

result = input().strip()
mean_results = list(map(float, result.split()))
# 绘制结果的直方图
plt.hist(mean_results, bins=500, density=True, color="skyblue", edgecolor="black")
plt.title("Distribution of Mean Coin Tosses")
plt.xlabel("Mean Number of Heads")
plt.ylabel("Probability Density")
plt.grid(True)
plt.show()
'

trap "rm central_limit_theorem.cpp central_limit_theorem.py a.out" SIGINT

echo "$code_cpp" >central_limit_theorem.cpp
echo "$code_python" >central_limit_theorem.py
g++ central_limit_theorem.cpp -o a.out
./a.out | python3 central_limit_theorem.py
rm central_limit_theorem.cpp central_limit_theorem.py a.out
