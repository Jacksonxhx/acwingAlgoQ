/*
acwing 797.

差分作用：让一个数组的区间内所有的数都加上一个k
1. 构造b，是直接insert a[i]
2. 思想是求出a数组的差分，对差分数组进行insert操作
3. insert(): 给区间[l, r]中的每个数加上c：b[l] += c, b[r + 1] -= c
4. 进行差分操作
5. 求一下前缀和，得到应该输出的数组
*/

#include <iostream>

using namespace std;
const int N = 100010;

int n, m;
int a[N], b[N];

void insert(int l, int r, int c) { //在l和r当加上c
    b[l] += c;
    b[r + 1] -= c; //只能l-r中间+c，所以r+1位要减去一个c
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]); //读入整个数组

    for (int i = 1; i <= n; i ++) insert(i, i, a[i]); //在i，i的区间加上a[i]，得到b数组

    while (m --) { //m次操作
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }

    for (int i = 1; i <= n; i ++) b[i] += b[i - 1]; //求一下原来数组，求一下b数组的前缀和
    for (int i = 1; i <= n; i ++) printf("%d ", b[i]);

    return 0;
}
