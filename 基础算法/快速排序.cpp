/*
快速排序：

思路：
1. 定义边界，可以去左右中三个端点
2. i，j的设置，需要往外扩一格
3. 核心思想是；分治，x的左边是都小于x的，x的右边是都大于x的
4. 所以当满足这个情况的时候，i一直往右移，j往左移，直到遇到不满足的，交换位置
*/

#include  <iostream>

using namespace std;
const int N = 1e6 + 10;

int n;
int q[N];

void quickSort(int q[], int l, int r) {
    if (l >= r) return;

    int x = q[l], i = l - 1, j = r + 1;
    while (i < j) {
        do i ++; while (q[i] < x);
        do j --; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    quickSort(q, l, j);
    quickSort(q, j + 1, r);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &q[i]);
    }
    quickSort(q, 0, n - 1);
    for (int i = 0; i < n; i ++) {
        printf("%d ", q[i]);
    }
    cout << endl;
    return 0;
}