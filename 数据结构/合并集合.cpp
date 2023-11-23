/*
acwing 836. 并查集

思路：
1. 将两个集合合并
2. 询问两个元素是否在一个集合当中
3. 每一个集合的编号是根节点的编号
4. 每个集合的副节点也要存，这样查找每个点就去找这个点的父节点p[x]，直到查找到根节点
5. 树根：p[x] == x
6. 求x集合的编号：while(p[x] != x) x = p[x];
7. 合并集合：px是x的集合编号，py是y的集合编号，让p[x] = y，就是把x合并到y里
8. 优化，路经压缩：当找到根节点，把所有点都直接指向根节点
9. 时间复杂度：O(1)
*/
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N];

int find(int x) { //返回x所在集合的编号，x的根节点 + 路经压缩
    if (p[x] != x) p[x] = find(p[x]); //如果x不是跟节点，往上找
    return p[x]; //直到找到父节点
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) p[i] = i; //定义所有的树根
    
    while (m --) {
        char op[2]; //构造成字符串可以不读空格
        int a, b;
        scanf("%s%d%d", op, &a, &b); //用scanf读字符串可以省略空格
        
        if (op[0] == 'M') p[find(a)] = find(b); //让a的根节点=b的根节点
        else {
            if (find(a) == find(b)) puts("Yes"); //如果找到返回yes
            else puts("No");
        }
    }
}