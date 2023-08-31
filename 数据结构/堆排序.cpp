/*
acwing 838 堆排序

思路：
1. 把数组建成堆，使用n/2 down到 1
2. 依次输出堆顶
3. down操作的编写，在三个点里判断根节点是不是最小的
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int h[N], sizeh;

void down(int u) {
    int t = u; //t是三个点里的最小值
    if (u * 2 <= sizeh && h[u * 2] < h[t]) t = u * 2; //如果左儿子存在并且左儿子小于t，更新t
    if (u * 2 + 1 <= sizeh && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) {
        swap(h[u], h[t]);
        down(t); //更新t
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &h[i]);
    sizeh = n;
    
    for (int i = n / 2; i ; i --) down(i); //从n/2 done 到 1，建立堆
    
    while (m --) {
        printf("%d ", h[1]);
        h[1] = h[sizeh];
        sizeh --;
        down(1);
    }
    return 0;
}