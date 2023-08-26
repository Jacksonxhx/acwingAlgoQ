/*
acwing 827. 双链表

思路：
1. 双链表没有空指针！所有的节点都是连起来的
*/

#include <iostream>

using namespace std;

const int N = 100010;

int m;
//e[N]表示每个节点的值，l[N]表示当前节点左边的节点下标，r[N]则是右边，idx是当前节点的下标
int e[N], l[N], r[N], idx;

//初始化
void init() {
    //0表示左端点，1表示右端点
    r[0] = 1, l[1] = 0; //0号点的右边是1号点，1号点的左边是0号点
    idx = 2;
}

//在下标是k的右边插入一个x
void add(int k, int x) {
    //赋值
    e[idx] = x;
    //让插入的节点的右边变成k的下一个节点
    r[idx] = r[k];
    //插入节点的左边指向k
    l[idx] = k;
    //被插入的节点的左边指向插入节点，先修改l[r[k]]，然后修改r[k]
    l[r[k]] = idx;
    //k节点的右边指向插入节点
    r[k] = idx ++;
}
//如果想要在k的左边插入x，直接调用add(l[k], x)就可以了

//删除第k个节点
void remove(int k) {
    r[l[k]] = r[k]; //k左边节点的右边=k右边节点
    l[r[k]] = l[k]; //k右边节点的左边=k左边节点
}

int main() {
    cin >> m;
    
    init();
    
    while (m --) {
        string op;
        int k, x;
        cin >> op;
        if (op == "L") {
            cin >> x;
            add(0, x);
        } else if (op == "R") {
            cin >> x;
            add(l[1], x); //最左端的前面
        } else if (op == "D") {
            cin >> k;
            remove(k + 1); //k初始化是idx = 2
        } else if (op == "IL") {
            cin >> k >> x;
            add(l[k + 1], x);
        } else {
            cin >> k >> x;
            add(k + 1, x);
        }
    }
    
    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
    cout << endl;
    return 0;
}