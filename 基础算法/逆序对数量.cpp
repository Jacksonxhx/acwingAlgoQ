/*
acwing 788 逆序对的数量:
在一个数组范围内找到逆序对（i < j; q[i] > q[j]）的数量
*/

/*
逆序对分为三种情况，一对在[l,mid]；一对[mid + 1,r]；一对其中一个在左一个在右
所以res是递归得到，res = mergeSort(左) + mergeSort(右)
那每次mergeSort是针对一对其中一个在左一个在右的情况
这种情况是当q[i] > q[j]时，所以在这种情况下res += mid - i + 1
mid - i + 1是因为左边是生序数组，所以i后面的数都是大于j的
*/
#include <iostream>
using namespace std;
const int N = 1e6 + 10;
typedef long long ll; //定义ll为long long type
int n;
int q[N], tmp[N];

ll mergeSort(int l, int r) { //返回一个long long
    if (l >= r) return 0;

    int mid = (l + r) >> 1;
    ll res = mergeSort(l, mid) + mergeSort(mid + 1, r); //这里记录了，在两个区间内，分别需要做多少次sort，次数就是逆数对

    //归并过程
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) tmp[k ++] = q[i ++];
        else {
            tmp[k ++] = q[j ++]; //这种情况是i<j,q[i]>q[j]满足逆数对要求
            res += mid - i + 1; //所以res加上这个i位置到mid之间的所有数，因为那些数都>q[j]
        }
    }
    while (i <= mid) tmp[k ++] = q[i ++];
    while (j <= r) tmp[k ++] = q[j ++];

    for (int i = l, j = 0; i <= r; i ++, j ++) {
        q[i] = tmp[j];
    }

    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &q[i]);
    }

    cout << mergeSort(0 , n - 1) << endl;
    return 0;
}