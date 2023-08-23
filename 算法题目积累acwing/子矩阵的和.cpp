/*
acwing 796.

1. 求和 s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j]
2. 左下角+右上角-左上角+右下角
3. 输出 s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]
4. 右下角-左下角-右上角+左上角
5. S[i, j] = 第i行j列格子左上部分所有元素的和
*/

#include <iostream>

using namespace std;

const int N = 1010;
int n, m, q;
int a[N][N], s[N][N];

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            scanf("%d", &a[i][j]);
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    
    while (q --) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
    }
    
    return 0;
}