/*
acwing 837. 并查集

思路：
1. 用集合来表示联通块
2. 在两个联通块中间connect就相当于合并两个集合
*/
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N], sizec[N]; //sizec表示每一个集合的大小

int find(int x) { //查找
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    scanf("%d%d", &n ,&m);
    
    for (int i = 1; i <= n; i ++) {
        p[i] = i; //读入n个父节点
        sizec[i] = 1; //首先每一个集合的初始大小是1
    }
    
    while (m --) {
        
        char op[5];
        int a, b;
        scanf("%s", op);
        //当操作是connect时
        if (op[0] == 'C') {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) continue; //如果a和b是在一个集合，跳过
            sizec[find(b)] += sizec[find(a)]; //connect后，集合的size = a集合+b集合
            p[find(a)] = find(b); //把a集合connect到b里
            
        } else if (op[1] == '1') {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
            
        } else {
            scanf("%d", &a);
            printf("%d\n", sizec[find(a)]);
        }
        
    }
    return 0;
}