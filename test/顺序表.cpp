#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
class SeqList {
private:
    int length;
    int* data;
public:
    SeqList():length(0){
        data = new int[MAX_SIZE];
    }
    int size() {
        return length;
    }
    void clear() {
        length = 0;
    }
    bool empty() {
        return length == 0;
    }
    int get(int index) {
        if(index < 0 || index >= length) {
            cerr << "位置不合法，失败" << endl;
            return -1;
        }
        return data[index];
    }
    int getFront(int index) {
        if(index > 0 && index < length) return data[index - 1];
        else if(index == 0)
        {
            cerr << "第一个元素没有前驱，失败" << endl;
            return -1;
        }
        cerr << "表中不存在该元素，无前驱，失败" << endl;
        return -1;
    }
    int getBack(int index) {
        if(index >= 0 && index < length - 1) return data[length + 1];
        else if(index == length - 1)
        {
            cerr << "最后一个元素没有后驱，失败" << endl;
            return -1;
        }
        cerr << "表中不存在该元素，无后驱，失败" << endl;
        return -1;
    }
    bool insert(int index, int e) {
        if(length >= MAX_SIZE) {
            cerr << "顺序表已满，插入失败" << endl;
            return false;
        }
        else if(index < 0 || index > length) {
            cerr << "插入位置不合法，插入失败" << endl;
            return false;
        }
        for(int i=length - 1; i >= index; i --) data[i + 1] = data[i];
        data[index] = e;
        length ++;
        return true;
    }
    bool remove(int index) {
        if(index < 0 || index >= length) {
            cerr << "删除位置不合法，失败" << endl;
            return false;
        }
        for(int i=index;i<length;i++) data[i] = data[i + 1];
        length --;
        return true;
    }
    void print() {
        for (int i = 0; i < length; i++)
        {
            cout << data[i] << ' ';
        }
        cout << endl;
    }

};
int main()
{
    int op;
    cout << "1----清空线性表" << endl;
    cout << "2----判断线性表是否为空" << endl;
    cout << "3----求线性表长度" << endl;
    cout << "4----获取线性表指定位置元素" << endl;
    cout << "5----求前驱" << endl;
    cout << "6----求后驱" << endl;
    cout << "7----在线性表指定位置插入元素" << endl;
    cout << "8----删除线性表指定位置元素" << endl;
    cout << "9----显示线性表" << endl;
    cout << "     退出，输入一个负数" << endl;
    SeqList seqlist;
    while(cin >> op) {
        if(op > 9)
        {
            cout << "操作无效，请重新输入" << endl;
            continue;
        }
        switch (op)
        {
        case 1:seqlist.clear(); break;
        case 2:cout << (seqlist.empty()?"空":"非空") << endl; break;
        case 3:cout << seqlist.size() << endl; break;
        case 4:{
            int index;
            cout << "请输入元素下标: ";
            cin >> index;
            int val = seqlist.get(index);
            if(val != -1) cout << "值为：" << index << endl;
            break;
        }
        case 5:{
            int index;
            cout << "请输入元素下标： ";
            cin >> index;
            int val = seqlist.getFront(index);
            if(val != -1) cout << "该元素前一个元素的值为： " << endl;
            break;
        }
        case 6:{
            int index;
            cout << "请输入元素下标： ";
            cin >> index;
            int val = seqlist.getBack(index);
            if(val != -1) cout << "该元素后一个元素的值为： " << endl;
            break;
        }
        case 7:{
            int index, val;
            cout << "请输入插入位置和插入值（空格隔开）： " << endl;
            cin >> index >> val;
            seqlist.insert(index, val);
            break;
        }
        case 8:{
            int index;
            cout << "请输入所要删除元素的下标： " << endl;
            cin >> index;
            seqlist.remove(index);
            break;
        }
        case 9:seqlist.print(); break;
        default: break;
        }
        cout << endl;
    }
}