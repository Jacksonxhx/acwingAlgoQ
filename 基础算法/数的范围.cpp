/*
acwing 789 数的范围 二分:
在一个数组内，找到一个数的起始和终点，使用二分查找
*/

/*
整数二分一定要注意边界，当r=mid时，mid=(l+r)/2; 当l=mid时，mid=(l+r+1)/2
else的请款也是会变化，当r=mid时，else l=mid+1; 当l=mid时，else r=mid-1
*/

#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n, m;
int q[N];

//这道题是要找个一个区间，所以可以先求左边界，用q[mid] >= x，找右边界用q[mid] <= x
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    while (m --) //找m个数的区间
    {
        int x;
        scanf("%d", &x);

        int l = 0, r = n - 1; //设置边界
        while (l < r) 
        {
            int mid = (l + r) >> 1; //设置mid = (l + r) / 2
            if (q[mid] >= x) r = mid; //如果答案在mid左边，设置r = mid
            else l = mid + 1; //根据r = mid得到l = mid + 1
        }    
        if (q[l] != x) cout << "-1 -1" << endl; //没找到的情况
        else 
        {
            cout << l << ' ';

            int l = 0, r = n - 1;
            while (l < r) 
            {
                int mid = (l + r + 1) >> 1; //设置mid = (l + r + 1) / 2
                if (q[mid] <= x) l = mid; //如果答案在mid右边，l向答案靠拢
                else r = mid - 1; //根据l = mid得到r = mid - 1
            }
            cout << l << endl;
        }
    }
}