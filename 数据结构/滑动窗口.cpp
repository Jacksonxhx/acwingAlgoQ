/*
acwing 154. 滑动窗口 单调队列

思路：
1. 队列中存的都是位置，数组下标
2. 队列保证实时存的都是窗口里的数，分两步：1. 队尾加入一个数 2. 队头就要弹出一个数
3. 如果出现队列中，前面一个点比后面的数大，那这个前面的数就一定没有用
4. 也就是，把所有逆序对删掉，剩下一个严格单调上升的队列
*/

#include <iostream>

using namespace std;

const int N = 1000010;

int n, k;
int a[N], q[N];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i ++) { //i是队尾位置
        //判断队头是否已经滑出了窗口
        if (hh <= tt && i - k + 1 > q[hh]) hh ++; //判断是否是空的队列，然后判断起点是否出窗口了，都满足hh++，i-k+1是起点
        while (hh <= tt && a[q[tt]] >= a[i]) tt --; //当队尾的数大于新加入的数，pop队尾的数
        q[++ tt] = i; //在队尾赋值
        if (i >= k - 1) printf("%d ", a[q[hh]]); //输出
    }
    puts(" ");
    
    //输出最大值
    hh = 0, tt = -1;
    for (int i = 0; i < n; i ++) { //i是队尾位置
        //判断队头是否已经滑出了窗口
        if (hh <= tt && i - k + 1 > q[hh]) hh ++; //判断是否是空的队列，然后判断起点是否出窗口了，都满足hh++，i-k+1是起点
        while (hh <= tt && a[q[tt]] <= a[i]) tt --; //当队尾的数小于新加入的数，pop队尾的数
        q[++ tt] = i; //在队尾赋值
        if (i >= k - 1) printf("%d ", a[q[hh]]); //输出
    }
    
    return 0;
}