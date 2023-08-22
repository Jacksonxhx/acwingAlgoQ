#include <iostream>

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
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    quickSort(q, 0, n - 1);
    for (int i = 0; i < n; i ++) printf("%d ", q[i]);
    cout << endl;
    return 0;
}

//思路
/*
1. 确定分界点和边界：分界点可以是最左，中间，最右，随机
2. 调整区间：把整个区间根据分界点x分成两半，第一个区间里的所有数都小于等于x，第二个区间里的所有数都大于等于x
3. 双指针：
定义两个指针i，j，i在最左边，j在最右边，两个指针一起往中间走
当i遇到第一个大于等于x的数时停下，同理当j遇到一个小于等于x的数也停下
交换swap这两个数，此时又排好序了
重复以上步骤直到i和j相遇
4. 递归处理：分别处理左边和右边，分别给左右递归排序，拼接在一起
*/