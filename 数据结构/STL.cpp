vector:
    vector<int> a(10, 3); //长度为10的vector每个数都是3
    //减少申请的次数 
    a.empty() //返回布尔值
    a.clear() //不是所有容器都有
    a.begin()/a.end()
    
    for (vactor<int>::iterator i = a.begin(); i != a.end(); i ++) cout << *i << ' '; //用迭代器遍历vactor a

    for (auto x : a) cout << x << ' '; //auto for each 遍历

    //支持比较运算，按照字典序来比
    vector<int> a(4, 3), b(3, 4);
    if (a < b) puts("yes"); //这里输出yes
   
pair:
    //初始化二元组
    pair<int, string> p 
    p = make_pair(10, "yxc")
    p = {10, "abc"}
    pair<int, pair<int, int>> P

    p.first //第一个元素
    p.second //第二个元素

    //支持比较运算，按照字典序，以first为第一关键字，以second为第二关键字
    //可以把需要排序的存到first然后排序
    
string:
     string a = "xhxabc";
     cout << a.substr(1, 2) << endl; //hx, 第一位是从哪里开始，第二位是开始后的长度是多少
     
queue:
    //初始化
    queue<int> q;
    q.front()/q.back() //返回队头/队尾元素
    q.pop() //弹出队头元素
    q = queue<int>(); //清空一个q就是重新构造一个q
    
priority_queue:
    //优先队列，默认是大根堆
    priority_queue<int> heap;
    size()
    empty()
    push()  插入一个元素
    top()  返回堆顶元素
    pop()  弹出堆顶元素
    定义成小根堆的方式：priority_queue<int, vector<int>, greater<int>> q;
    
stack:
    size()
    empty()
    push()  向栈顶插入一个元素
    top()  返回栈顶元素
    pop()  弹出栈顶元素
    
deque:
    //双端队列，双端都可以插入弹出，支持随机访问
    size()
    empty()
    clear()
    front()/back()
    push_back()/pop_back()
    push_front()/pop_front()
    begin()/end()
    []
    
set, map, multiset, multimap, 基于平衡二叉树（红黑树），动态维护有序序列：
    ++, -- 返回前驱和后继，时间复杂度 O(logn)
    
    //初始化
    set<int> s; //不能有重复元素
    multiset<int> ms; //可以有重复元素

    insert() //插入一个数
    find() //查找一个数
    count() //返回一个数
    erase() 
        1. 输入一个x，删除所有x //O(k + logn)
        2. 输入一个迭代器，删除这个迭代器
    lower_bound()/upper_bound():
        lower_bound(x) //返回大于等于x的最小的数的迭代器
        upper_bound(x) //返回大于x的最小的数的迭代器 
        
    map/multimap
        insert()  插入的数是一个pair
        erase()  输入的参数是pair或者迭代器
        find()
        []  注意multimap不支持此操作。 时间复杂度是 O(logn)
        lower_bound()/upper_bound()
        map<string, int> a;
        a["xhx"] = 1; //跟dictionary的感觉是一样的
        cout <, a["xhx"] << endl; //输出：1
        
bitset, 圧位
    bitset<10000> s;
    ~, &, |, ^
    >>, <<
    ==, !=
    []

    count()  返回有多少个1

    any()  判断是否至少有一个1
    none()  判断是否全为0

    set()  把所有位置成1
    set(k, v)  将第k位变成v
    reset()  把所有位变成0
    flip()  等价于~
    flip(k) 把第k位取反