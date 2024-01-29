#include <cstring>
#include <iostream>
#include <string>
using namespace std;
class MyString {
    char* p;

   public:
    MyString(const char* s) {
        if (s) {
            p = new char[strlen(s) + 1];
            strcpy(p, s);
        } else
            p = NULL;
    }
    ~MyString() {
        if (p) delete[] p;
    }
    void Copy(const char *s) {
        if(p) delete[] p;
        p = new char[strlen(s) + 1];
        strcpy(p, s);
    }
    friend ostream& operator<<(ostream &out, const MyString &s) {
        out << s.p;
        return out;
    }
    MyString operator=(const char* s) {
        cout << "called" << endl;
        if(p) delete[] p;
        p = new char[strlen(s) + 1];
        strcpy(p, s);
        return nullptr;
    }
    MyString operator=(const MyString &s) {
        if(p) delete[] p;
        p = new char[strlen(s.p) + 1];
        strcpy(p, s.p);
        return nullptr;
    }
    MyString(const MyString& s) {
        p = new char[strlen(s.p) + 1];
        strcpy(p, s.p);
    }
    // 在此处补充你的代码
};
int main() {
    char w1[200], w2[100];
    while (cin >> w1 >> w2) {
        MyString s1(w1), s2 = s1;
        MyString s3(NULL);
        s3.Copy(w1);
        cout << s1 << "," << s2 << "," << s3 << endl;

        s2 = w2;
        s3 = s2;
        s1 = s3;
        cout << s1 << "," << s2 << "," << s3 << endl;
    }
}