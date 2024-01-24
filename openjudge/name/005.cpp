#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int id;
    int age;
    int s1;
    int s2;
    int s3;
    int s4;
    double ave;
public:
    void input()
    {
        string tmp;
        getline(cin, tmp);
        stringstream ss(tmp);
        getline(ss, name, ',');
        string tmp1;
        getline(ss, tmp1, ',');
        age = stoi(tmp1);
        getline(ss, tmp1, ',');
        id = stoi(tmp1);
        getline(ss, tmp1, ',');
        s1 = stoi(tmp1);
        getline(ss, tmp1, ',');
        s2 = stoi(tmp1);
        getline(ss, tmp1, ',');
        s3 = stoi(tmp1);
        getline(ss, tmp1, ',');
        s4 = stoi(tmp1);
        // cerr << age << ' ' << id << ' ' << s1 << endl;
    }
    void calculate()
    {
        this->ave = (s1 + s2 + s3 + s4) / 4.0;
    }
    void output()
    {
        cout << name << "," << age << "," << id << ",";
        cout << ave << endl;
    }
};

int main() {
    Student student;      // 定义类的对象
    student.input();      // 输入数据
    student.calculate();  // 计算平均成绩
    student.output();     // 输出数据
}