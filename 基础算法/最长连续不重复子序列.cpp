/*
acwing 799.

1. 明确j的意义，是从0开始，到i之间第一位，序列里没有重复的数的位置
2. 用一个数组s来存每个位数出现了多少次
*/

#include <iostream>

using namespace std;
const int N = 100010;
int n, a[N], s[N]; //s记录了这个数组中，每个数出现了多少次

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]); //读入数组
    
    int res = 0;
    for (int i = 0, j = 0; i < n; i ++) { //i往后走
        s[a[i]] ++; //数组记录每次值出现的次数
    
        while (s[a[i]] > 1) { //如果出现了重复的情况
            s[a[j]] --; //每次j往左走，看j能走多远
            j ++; //如果区间里有一样的，j沿着i的路径一路走过来，确保从j到i之间，所有数就只出现过一次
        }
        res = max(res, i - j + 1); //更新答案
    }
    cout << res << endl;
    return 0;
}