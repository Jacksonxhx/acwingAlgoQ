/*
acwing 830. 单调栈

思路
1. 找到一个数列中，每个数，满足一个条件下，另一个数的位置
2. 这里就比如：每个数左边第一个比他小的数的位置
3. i从左往右遍历，每遍历一个数，就在栈里加一个数
4. 观察栈内，有些元素永远不可能是答案，比如a3>=a5时，a3就永远不可能是答案，因为a5在a3右边且比a3小，所以a3可以被pop掉
5. 所以存在这种逆序的话，就可以删掉，留下的就是单调的序列

*/

#include <iostream>

using namespace std;

const int N = 100010;

int n;
int stk[N], tt; //定义栈

int main() {
    ios::sync_with_stdio(false); //优化速度，scanf和printf也会快很多
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i ++) {
        int x;
        scanf("%d", &x);
        while (tt && stk[tt] >= x) tt --; //当栈不是空的且栈顶元素大于等于x，则这个栈顶元素不会再被用到，t--
        if (tt) printf("%d ", stk[tt]); //如果栈不是空的，那while停下后，栈顶元素一定小于x，输出
        else printf("-1 "); //若空，输出-1
        
        stk[++ tt] = x; //把x读入到栈里
    }
    return 0;
}