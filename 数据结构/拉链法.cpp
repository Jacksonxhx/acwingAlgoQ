/*
acwing 840. 模拟散列表

1. 拉链式
2. 实现两个最重要的操作：插入和查找
*/

#include <cstring>
#include <iostream>

using namespace std;
const int N = 100003; //最接近数据范围的质数
int h[N], e[N], ne[N], idx; //槽，链表值，下一个节点的下标，当前位置
//插入
void insert(int x) {
    int k = (x % N + N) % N; //让余数变成正数，负数的余数是负数，k就是哈希值
    e[idx] = x, ne[idx] = h[k], h[k] = idx ++; //idx位置时，值存x，下标存第几个槽，槽更新idx
}
//查找
bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) //在h[k]各个槽里，如果i!=-1，意味着没找到头，那用ne来更新i
        if (e[i] == x) return true;
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    
    memset(h, -1, sizeof h); //清空所有链表的值
    
    while (n --) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        
        if (*op == 'I') insert(x);
        else {
            if (find(x)) puts("Yes");
            else puts("No");
        }
    }
}