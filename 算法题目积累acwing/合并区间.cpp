/*
acwing 803. 合并区间

应用场景：给定若干个区间，若各区间之间有交集，那就合并这俩区间
1. 按左端点排序
2. 扫描整个区间，同时合并有交集的区间
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
const int N = 100010;

int n;
vector<PII> segs;

void merge(vector<PII> &segs) {
    vector<PII> res; //用pair存result
    
    sort(segs.begin(), segs.end()); //第一步按左端点排序，pair中排序是按照左端点排序的
    
    int st = -2e9, ed= -2e9; //定义一下边界
    for (auto seg: segs) //遍历整个segs pair
        if (ed < seg.first) { //如果当前seg的末尾<下个seg的开始，证明没有交集
            if (st != -2e9) res.push_back({st, ed}); //若没有交集且不是空集，res push
            st = seg.first, ed = seg.second; //更新
        }
        else ed = max(ed, seg.second); //如果有交集，则更新ed位置
        
    if (st != -2e9) res.push_back({st, ed}); //防止输入是空区间
    
    segs = res; //更新
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) { //push n次
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r}); //创建一个sges，用来存所有区间
    }
    merge(segs); //合并区间
    
    cout << segs.size() << endl; //输出
    
    return 0;
}