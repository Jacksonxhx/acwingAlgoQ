/*
acwing 826. 单链表

思路：
1. 注意第k个数其实下标是k - 1
2. 特判当k = 0的时候
*/



#include <iostream>

using namespace std;

const int N = 100010;

//head表示头节点的下标，e[i]表示节点i的值是多少，ne[i]表示节点i的下一个节点下标是多少，idx存储当前用到的点
int head, e[N], ne[N], idx;

//初始化
void init() {
    head = -1;
    idx = 0;
}

//将x插到头节点
void add_to_head(int x) {
    e[idx] = x; //存储插入节点的值
    
    //将这个插入指针指向head原本下一个的指针
    ne[idx] = head; //让插入节点的指针指向下一个（head中存的值）
    
    //删掉head原本的指针，指向插入指针
    head = idx ++; //让head指向插入的节点，并更新idx
}

//将x插到k的节点后面
void add(int k, int x) {
    e[idx] = x; //存储插入节点的值
    
    //将插入的节点指向k节点后面一个节点
    ne[idx] = ne[k];
    
    //把k节点指向插入的节点
    ne[k] = idx;
    idx ++;
}

//将下标k后面的节点删掉
void remove(int k) {
    //直接让k节点指向下下一个节点
    ne[k] = ne[ne[k]];
} 

int main() {
    int m;
    cin >> m;
    
    init();
    
    while (m --) {
        int k, x;
        char op;
        
        cin >> op;
        if (op == 'H') {
            cin >> x;
            add_to_head(x);
        }
        else if (op == 'D') {
            cin >> k;
            if (k == 0) head = ne[head]; //如果是删除头节点，让head直接指向头节点的下一个节点
            remove(k - 1);
        }
        else {
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    
    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    cout << endl;
    
    return 0;
}