/*
归并排序

思路：
1. 首先定义mid点
2. 先递归两个区间
3. 归并两个有序区间
4. 双指针在两个区间查找，哪个小就先存哪个，直到两个区间的数都被跑完
*/

#include <iostream>

using namespace std;
const int N = 1e6 + 10;

int n;
int q[N], tmp[N];

void mergeSort(int q[], int l, int r) {
    if (l >= r) return;
    
    int mid = (l + r) >> 1;
    //先递归，相当于生成两个有序数组
    mergeSort(q, l, mid);
    mergeSort(q, mid + 1, r);
    //归并两个有序数组
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) tmp[k ++] = q[i ++];
        else tmp[k ++] = q[j ++];
    }
    while (i <= mid) tmp[k ++] = q[i ++];
    while (j <= r) tmp[k ++] = q[j ++];

    for (int i = l, j = 0; i <= r; i ++, j ++) {
        q[i] = tmp[j];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);

    mergeSort(q, 0 ,n - 1);

    for (int i = 0; i < n; i ++) printf("%d ", q[i]);
    cout << endl;
    return 0;
}