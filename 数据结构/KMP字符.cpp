/*
acwing 831. KMP

思路：
1. 习惯下标从1开始
2. next[j]的意义就是最大的前缀和后缀相等
3. 首先求next，求出模式串的next数据，依次得到next数组对应的值
4. kmp匹配，下标从1开始
5. 从头开始，判断s[i]和p[j + 1]是否相同，不同j跳next，继续比，直到其相同
*/
#include <iostream>

using namespace std;

const int N = 10010, M = 100010;

int n, m; 
char p[N], s[M];
int ne[N]; //next数据

int main() {
    cin >> n >> p + 1 >> m >> s + 1; //p和s的下标都从1开始
    
    //求next数组的过程
    for (int i = 2, j = 0; i <= n; i ++) { //
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }
    
    //kmp匹配的过程
    for (int i = 1, j = 0; i <= m; i ++) { //i遍历所有的s数组，j从0开始
        while (j && s[i] != p[j + 1]) j = ne[j]; //首先判断j，不满足让j往前跳，跳到最长的前缀和后缀相等的位置，直到s[i] = p[j + 1]
        if (s[i] == p[j + 1]) j ++; //如果满足，j往前进一位
        if (j == n) { //当j=n的时候，证明找到了相同的串，输出
            printf("%d ", i - n);
            j = ne[j]; //继续往前跳，开始下一轮
        }
    }
    
    return 0;
}