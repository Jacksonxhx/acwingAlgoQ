/*
aciwng 2816. 判断子序列 双指针

思路：
1. 遍历整个b，如果a能按照b的顺序，依次查找到对应的值，那就是匹配成功，就输出YES
*/

#include <iostream>

using namespace std;
const int N = 100010;

int n, m;
int a[N], b[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i ++) scanf("%d", &b[i]);
    
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) { //如果满足匹配
            i ++; //i往后走一位
        }
        j ++; //不管什么情况j一直往后走，所以就是默认按照顺利了
    }
    
    if (i == n) puts("Yes"); //意味着所有的i都匹配了
    else puts("No");
    
    return 0;
}