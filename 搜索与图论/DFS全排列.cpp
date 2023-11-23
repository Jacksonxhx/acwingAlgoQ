/*
acwing 842. DFS

思路：
1. 最重要的是顺序
2. 用树图，依次搜索
3. 回溯，一步一步回，回了搜，搜不到继续回
4. 恢复现场
*/›

#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N]; //存方案
bool st[N]; //存是否用过

void dfs(int u) {
    if (u == n) { //当走到最后一层的时候，输出
        for (int i = 0; i < n; i ++) printf("%d ", path[i]);
        puts("");
        return;
    }

    for (int i = 1; i <= n; i ++) { //当没有填完的时候
        if (!st[i]) { //如果当前路径没有用过的话
            path[u] = i; //记录
            st[i] = true; //这个点被用过了
            dfs(u + 1); //递归下一层
            //恢复现场，这是当所有都已经完成的时候
            st[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(0); //从第0个位置开始
    return 0;
}