/*
acwing 840. 模拟散列表

思路：
1. 核心是find函数
2. 跟上厕所一样，每次查看一个h[k]的位置，如果有了，往下找
*/

#include <cstring>
#include <iostream>

using namespace std;
const int N = 200003, null = 0x3f3f3f3f; //每次要先找到数据范围内最近的一个质数，设置一下null的定义

int h[N];

int find(int x) { //核心是find函数
    int k = (x % N + N) % N;
    
    while (h[k] != null && h[k] != x) { //当k位不是空且k位不是x，查找下一位
        k ++; 
        if (k == N) k = 0; //如果看完了所有坑位，到第一位查看
    }
    
    return k; //如果k在哈希表中，则返回哈希表中的位置；若不在哈希表中，则返回应该存放k的下标
}

int main() {
    
    int n;
    scanf("%d", &n);
    
    memset(h, null, sizeof h);
    
    while (n --) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        
        int k = find(x);
        if (*op == 'I') h[k] = x;
        else {
            if (h[k] != null) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}