/*
acwing 801.

1. lowbit操作，减去最后一位1
2. 根据lowbit操作的性质，通过lowbit操作的次数得出有几个1
*/

#include <iostream>
#include <string.h>

using namespace std;

int lowbit(int x) { //每次call，都会得到二进制中开头是最后一个1，结尾是末尾的一个二进制数
    return x & -x;
}

int main() {
    int n;
    cin >> n;
    
    while (n --) {
        int x;
        cin >> x;
        
        int res = 0;
        while (x > 0) { 
            x -= lowbit(x); //减去带1的位置，直到x被减完
            res ++; //每减一次代表有一个1，res++
        }
        cout << res << ' ';
    }
    return 0;
}