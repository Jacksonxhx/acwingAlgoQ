/*
acwing 795.
1. 读入的时候是从1 ~ n
2. 核心思想s[N]里的每一项都代表了a[1]+...+a[i]
3. 所以想表示s[i]就是s[i - 1] + a[i]
4. 输出的时候是s[r] - s[l - 1]

前缀和：Si = a1 + a2 +...+ ai //下标从1开始
*/

#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], s[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) { //从1开始读入
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i ++) { //前缀和的初始化，从1开始
        s[i] = s[i - 1] + a[i]; //使得s中的每一项都是a从1-i的和
    }

    while (m --) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]); //区间和的计算
        cout << endl;
    }
    return 0;
}