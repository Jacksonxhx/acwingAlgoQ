/*
acwing 841. 字符串哈希

思路：
1. 背公式，get公式和h[i]前缀和的公式
2. 当需要快速判断两个字符串相等的时候可以用
*/

#include <iostream>

using namespace std;

typedef unsigned long long ULL; //这样溢出就不用mod Q了

const int N = 100010, P = 131; //P取131，不容易冲突

int n, m;
char str[N]; //读入的字符串
ULL h[N], p[N]; //h是hash值，p是P的多少次方

ULL get(int l, int r) { //核心是这个公式
    return h[r] - h[l - 1] * p[r - l + 1]; //背过：求出l-r这个区间内的哈希值
}


int main() {
    scanf("%d%d%s", &n, &m, str + 1);
    
    p[0] = 1; //p的0次方=1
    for (int i = 1; i <= n; i ++) {
        p[i] = p[i - 1] * P; //P的i次方
        h[i] = h[i - 1] * P + str[i]; //前缀和思想，背
    }
    
    while (m --) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        
        if (get(l1, r1) == get(l2, r2)) puts("Yes");
        else puts("No");
    }
    
    return 0;
}