/*
acwing 802. 离散化

1. 先离散化，使用二分，把alls里面的所有的数都离散化，也就是说按照1，2，3...这样子排序，不用去管它的位置
2. 构建完后，先构建前缀和，然后利用前缀和，找到需要求的范围内的和
3. 使用vector，和pair做
4. 去重函数背会
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII; //定义一个pair，读入操作

const int N = 300010; //n + 2m个坐标 所以是30w

int n, m; //读入n行插入c，m行求和
int a[N], s[N]; //a数组是存的数，s数组是前缀和

vector<int> alls; //所有需要离散化的值
vector<PII> add, query; //add是插入操作，第一种操作；query是求值对应第二个操作

int find(int x) { //求一下x这个值离散化之后的结果
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1; //从1开始
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c}); //把所有插入的操作存进add
        
        alls.push_back(x); //把x加入待离散化的数组去
    }
    
    for (int i = 0; i < m; i ++) { //读入所有求和操作
        int l, r;
        cin >> l >> r;
        query.push_back({l, r}); //把所有求和操作存去query
        //两个端点都需要离散化，加入待离散化数组
        alls.push_back(l); 
        alls.push_back(r);
    }
    
    //去重
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    //现在alls是已经排好序了，是一个单调递增的没有重复的数组
    //处理插入
    for (auto item : add) {
        int x = find(item.first); //离散化之后的坐标值
        a[x] += item.second; //在离散化之后的位置加上要加的数
    }
    
    //处理前缀和，构建一个新的s数组，是离散化后的a数组的前缀和数组
    for (int i = 1; i <= alls.size(); i ++) s[i] = s[i - 1] + a[i]; //得到前缀和
    
    //处理询问
    for (auto item: query) {
        int l = find(item.first), r = find(item.second); //先离散化左右区间
        cout << s[r] - s[l - 1] << endl; //输出离散化后得到的和
    }
    return 0;
}