/*
acwing 835. Trie字符串统计

思路
1. Trie：用来高效的存储和查找字符串的集合的数据结构
2. 字典形式
3. 每个结尾要做个标记
*/

#include <iostream>

using namespace std;
const int N = 100010;

int son[N][26], cnt[N], idx; //son只包含小写英文字母，cnt以当前这个节点结尾的字符串有多少个，idx是当前的下标，0是根结点和空节点
char str[N];

void insert(char str[]) {
    int p = 0; //从根节点开始
    for (int i = 0; str[i]; i ++) { //从前往后遍历str
        int u = str[i] - 'a'; //把a～z映射成0～25
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u]; //更新位置，对应的是字符串的最后一个点
    }
    cnt[p] ++; //记录已这个点为结尾的字符串数量
}

int query(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i ++) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0; //如果没有查询到单词，结束
        p = son[p][u]; //更更新p
    }
    
    return cnt[p]; //输出p出现了几次
}

int main() {
    int n;
    scanf("%d", &n);
    while (n --) {
        char op[2];
        scanf("%s%s", op, str);
        if (op[0] == 'I') insert(str);
        else printf("%d\n", query(str));
    }
    
    return 0;
}