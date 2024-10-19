#include <openssl/sha.h>

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
const unsigned char ans[32] = {0x01, 0xc0, 0x2f, 0x5f, 0x0d, 0x8d, 0x54, 0x5f,
                               0x76, 0xb7, 0xd3, 0xc8, 0x54, 0xc8, 0x28, 0xe0,
                               0x11, 0xb7, 0x1f, 0xc1, 0x7d, 0x58, 0xb1, 0x23,
                               0x46, 0x81, 0x0e, 0x60, 0x8b, 0x72, 0x5f, 0x3d};

std::mutex mtx;

void sha256sum(int st) {
    unsigned char hash[SHA256_DIGEST_LENGTH];

    int now = 0;

    for (long long i = 0; i <= 99'999'999; i++) {

        if (i / 10'000'000'000 == now and i % 10'000'000'000 == 0) {
            now += 1;
            std::lock_guard<std::mutex> guard(mtx);
            std::cout <<"Thread " << st << " : " << i % 10'000'000'000 << std::endl;
        }
        
        std::string s = std::to_string(i + st * 1'000'000'000'000ll);
        s.push_back('\n');
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, s.c_str(), s.size());
        SHA256_Final(hash, &sha256);
        bool flag = true;
        for (int i = 0; i < 32; i++) {
            if (ans[i] != hash[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            std::cout << s;
            exit(0);
        }
    }
}

int main() {
    std::vector<std::thread> vec;
    for(int i=10;i<=25;i++) {
        vec.emplace_back(std::thread(sha256sum, i));
    }
    for(auto &th : vec) {
        th.join();
    }
    return 0;
}