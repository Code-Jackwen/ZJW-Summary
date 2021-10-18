# Leetcode 题解 - 排序
<!-- GFM-TOC -->
* [Leetcode 题解 - 排序](#leetcode-题解---排序)
    * [快速选择](#快速选择)
    * [堆](#堆)
        * [1. Kth Element](#1-kth-element)
    * [桶排序](#桶排序)
        * [1. 出现频率最多的 k 个元素](#1-出现频率最多的-k-个元素)
        * [2. 按照字符出现次数对字符串排序](#2-按照字符出现次数对字符串排序)
    * [荷兰国旗问题](#荷兰国旗问题)
        * [1. 按颜色进行排序](#1-按颜色进行排序)
<!-- GFM-TOC -->


## 快速选择

用于求解   **Kth Element**   问题，也就是第 K 个元素的问题。

可以使用快速排序的 partition() 进行实现。需要先打乱数组，否则最坏情况下时间复杂度为 O(N<sup>2</sup>)。

## 堆

堆也可以用于求解 Kth Element 问题，得到了大小为 K 的最小堆之后，因为使用了大顶堆来实现，因此堆顶元素就是第 K 大的元素。插入和移除堆顶元素的时间复杂度都为 log<sub>2</sub>N。

快速选择也可以求解 TopK Elements 问题，因为找到 Kth Element 之后，再遍历一次数组，所有小于等于 Kth Element 的元素都是 TopK Elements。

### 1. Kth Element

中等： [215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)

```text
题目描述：找到倒数第 k 个的元素。	Input: [3,2,1,5,6,4] and k = 2	Output: 5
```

```java
public int findKthLargest(int[] nums, int k) {
    Arrays.sort(nums);				//库函数排序：时间复杂度 O(NlogN)，空间复杂度 O(1)
    return nums[nums.length - k];
}
```

```js
基于堆排序，时间复杂度：O(nlogn)，建堆的时间代价是 O(n)，删除的总代价是 O(klogn)，因为 k < n，故渐进时间复杂为 O(n+klogn)=O(nlogn)。
空间复杂度：O(logn)，即递归使用栈空间的空间代价。或者空间复杂度 O(K)。
```

```java
public int findKthLargest(int[] nums, int k) {
    PriorityQueue<Integer> pq = new PriorityQueue<>(); // 小顶堆
    for (int val : nums) {
        pq.add(val);
        if (pq.size() > k)  pq.poll();				   // 维护堆的大小为 K
    }
    return pq.peek();
}
```

```c
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int> > pq; //c++ 小顶堆，从小到大排序
    int sz = nums.size();
    for (int i = 0; i < k; ++i) pq.push(nums[i]);
    for (int i = k; i < sz; ++i) {
        if (nums[i] > pq.top()) {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();//直接return pq.top();是可以的
}
```

```c
1、priority_queue<int> q;								 //默认是大根堆，从大到小排序
2、自建比较器，小根堆
struct cmp{
    bool operator()(int a, int b) {
        return a > b;
    }
};
priority_queue<int, vector<int>, cmp> q;
```

```js
快速选择，时间复杂度：O(n)，如上文所述，证明过程可以参考「《算法导论》9.2：期望为线性的选择算法」。
空间复杂度：O(logn)，递归使用栈空间的空间代价的期望为 O(logn)。
```

```java
public int findKthLargest(int[] nums, int k) {
    k = nums.length - k;
    int l = 0, h = nums.length - 1;
    while (l < h) {
        int j = partition(nums, l, h);
        if (j == k) break;
        else if (j < k) l = j + 1;
        else h = j - 1;
    }
    return nums[k];
}
private int partition(int[] a, int l, int h) {
    int i = l, j = h + 1;
    while (true) {
        while (a[++i] < a[l] && i < h) ;
        while (a[--j] > a[l] && j > l) ;
        if (i >= j) break;
        swap(a, i, j);
    }
    swap(a, l, j);
    return j;
}
private void swap(int[] a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}
```

## 桶排序

### 1. 频率最多的 k 个元素

中等： [347. 前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)

```js
返回数组中出现频率前 k 高的元素,时间复杂度必须优于 O(nlogn) , n 是数组的大小。
```

桶排序，快一点，设置若干个桶，每个桶存储出现频率相同的数。桶的下标表示数出现的频率，即第 i 个桶中存储的数出现的频率为 i。从后向前遍历桶，保存最先得到的 k 个数，注意这里集合方法 addAll(); 的使用。

```java
public int[] topKFrequent(int[] nums, int k) {				//桶排序
    Map<Integer, Integer> map = new HashMap<>();
    for (int num : nums) map.put(num, map.getOrDefault(num, 0) + 1);
    List<Integer>[] buckets = new ArrayList[nums.length + 1];
    for (int key : map.keySet()) {
        int frt = map.get(key);
        if (buckets[frt] == null) buckets[frt] = new ArrayList<>();
        buckets[frt].add(key);
    }
    List<Integer> topK = new ArrayList<>();
    for (int i = buckets.length - 1; i >= 0 && topK.size() < k; i--) {
        if (buckets[i] == null) continue;
        if (buckets[i].size() <= (k - topK.size())) topK.addAll(buckets[i]);
        else topK.addAll(buckets[i].subList(0, k - topK.size()));
    }
    int[] res = new int[k];
    for (int i = 0; i < k; i++) res[i] = topK.get(i);
    return res;
}
```

```java
public int[] topKFrequent(int[] nums, int k) {				//基于自定义排序
    Map<Integer, Integer> map = new HashMap<>();
    for (int num : nums) map.put(num, map.getOrDefault(num, 0) + 1);
    ArrayList<Map.Entry<Integer, Integer>> al = new ArrayList(map.entrySet());
    Collections.sort(al, (o1, o2) -> (o2.getValue().compareTo(o1.getValue())));
    int[] ret = new int[k];
    int i = 0;
    for (Map.Entry<Integer, Integer> ent : al) {
        ret[i++] = ent.getKey();
        if(k--==0) break;
    }
    return ret;
}
```

```java
public int[] topKFrequent(int[] nums, int k) {				//基于堆
    Map<Integer, Integer> cnt = new HashMap<Integer, Integer>();
    for (int num : nums) cnt.put(num, cnt.getOrDefault(num, 0) + 1);
    // int[] 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
    PriorityQueue<int[]> que = new PriorityQueue<>(new Comparator<int[]>() {
        public int compare(int[] m, int[] n) { return m[1] - n[1]; }
    });
    for (Map.Entry<Integer, Integer> entry : cnt.entrySet()) {
        int num = entry.getKey(), count = entry.getValue();	
        if (que.size() == k) {								
            if (que.peek()[1] < count) {					//时间复杂度：堆操作共计O(Nlogk) 
                que.poll();									//空间复杂度：哈希表O(N)。
                que.offer(new int[]{num, count});
            }
        } else que.offer(new int[]{num, count});
    }
    int[] ret = new int[k];
    for (int i = 0; i < k; ++i) ret[i] = que.poll()[0];
    return ret;
}
```

```c
struct cmp{								//C++基于堆
    bool operator()(pair<int, int> m, pair<int, int> n) {
        return m.second > n.second;		//按照第二位升序排列
    }
};
vector<int> topKFrequent(vector<int>&nums, int k) {
    unordered_map<int, int> mp;			//map：num -> count
    for (auto v :nums) mp[v]++;			//pair：num，count
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
    for (auto [num, count] :mp){
        if (q.size() == k) {
            if (q.top().second < count) {
                q.pop();
                q.emplace(num, count);
            }
        } else q.emplace(num, count);
    }
    vector<int> ret;
    while (!q.empty()) {
        ret.emplace_back(q.top().first);//vector有emplace_back()，用于添加pair相关数据
        q.pop();
    }
    return ret;
}
```

```c
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;				   //堆排序	基于大根堆
    unordered_map<int, int> dict;	   //pair 来绑定 元素 和 次数 的关系。
    for (auto &i : nums) ++dict[i];    //步骤1
    priority_queue<pair<int, int>> q;
    for (auto &[key, value] : dict) {
        q.push({value, key});		   //步骤2	优先队列添加pair：q.push({value, key});
        if (q.size() > dict.size() - k) {
            res.push_back(q.top().second);
            q.pop(); 				   //步骤3、4
        }
    }
    return res;
}
```

```js
void fun(元素列表， 条件1) {			   //文字模板
    1 统计元素出现在的次数，使用hash算法来，快速得到各个元素的次数
    2 建立元素与次数之间的联系，建立联系（绑定）的方式就会比较多，如：pair/[key,value]组合/结构体等
    3 排序次数，使用的排序算法，排序次数
    4 通过排序后的次数，反查元素，也就是根据 步骤2 里面绑定数据结构，来解绑找到原始元素
}
```

```c
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ret;				   //红黑树排序，用multimap：v->k
    unordered_map<int, int> mp;
    for (auto &num : nums) ++mp[num];  //步骤1
    multimap<int, int> mtmp;
    for (auto &[k, v] : mp)
        mtmp.emplace(v, k);	   		   //步骤2	multimap添加元素：mtmp.emplace(v, k);
    for (auto iter = mtmp.rbegin(); iter != mtmp.rend() && ret.size() < k; ++iter)
        ret.push_back(iter->second);   //步骤3、4	注意反向遍历
    return ret;
}
```

```c
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;				   //桶排序
    unordered_map<int, int> dict;
    for (auto &i : nums) ++dict[i];    //步骤1
    vector<vector<int>> buckets(nums.size() + 1);
    for (auto &[key, value] : dict)	   
        buckets[value].push_back(key); //步骤2	二维vector的访问
    for (int i = buckets.size() - 1; i >= 0 && res.size() < k; --i) {
        for (auto &j : buckets[i]) {   //注意遍历
            res.push_back(j);
            if (res.size() == k) break;//步骤3、4
        }
    }
    return res;
}
```

```c
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;					//快排
    unordered_map<int, int> dict;		//pair 做关系绑定
    for (auto &i : nums) ++dict[i];	
    vector<pair<int, int>> sub;
    for (auto &[key, value] : dict)
        sub.push_back({value, key});	//vec添加pair：vec.push_back({value, key});
    sort(sub.begin(), sub.end());		//默认按照第一个值从小到大排序
    for (int i = sub.size() - 1; i >= 0 && k > 0; --i, --k)
        res.emplace_back(sub[i].second);//vec添加pair中的一个值，push_back()也可以
    return res;
}
```

基于快速选择，参考：[作者：LeetCode-Solution](https://leetcode-cn.com/problems/top-k-frequent-elements/solution/qian-k-ge-gao-pin-yuan-su-by-leetcode-solution/)

### 2. 按照字符出现次数对字符串排序

中等：[451. 根据字符出现频率排序](https://leetcode-cn.com/problems/sort-characters-by-frequency/)

```js
输入:"Aabb"  输出:"bbAa"  解释:"bbaA"也是一个有效的答案，注意'A'和'a'被认为是两种不同的字符。
输入:"tree"  输出:"eert"  解释:'e'两次，'r'和't'一次。'e'必须在'r'和't'之前。"eetr"也是有效的答案。
```

```java
public String frequencySort(String s) {				//堆排，速度快点，5ms，96%
    int[] letters = new int[128];
    for (char c : s.toCharArray()) letters[c]++;	
    PriorityQueue<Character> heap = new PriorityQueue<>(128,
                (a, b) -> Integer.compare(letters[b], letters[a]));
    StringBuilder res = new StringBuilder();
    for (int i = 0; i < letters.length; ++i) if (letters[i] != 0) heap.offer((char)i);
    while (!heap.isEmpty()) {
        char c = heap.poll();
        while (letters[c]-- > 0) res.append(c);
    }
    return res.toString();
}
```

```java
public String frequencySort(String s) {				//桶排序，14ms，67%
    if (s.isEmpty() || s.length() == 1) return s;
    Map<Character, Integer> map = new HashMap<>();	// 元素 -> 元素出现的频率
    for (char c : s.toCharArray()) map.put(c, map.getOrDefault(c, 0) + 1);
    // 构造一个桶的集合（即一系列桶），桶的个数为 s 的长度 +1。
    // 出现0次的后边不拼接，buckets[0] 没有意义。
    // 将出现频率为 frt 的字符放到第 frt 个桶里（即 buckets[frt]）
    List<Character>[] buckets = new List[s.length() + 1];
    for (char key : map.keySet()) {
        int frt = map.get(key);
        if (buckets[frt] == null) buckets[frt] = new ArrayList<Character>();
        buckets[frt].add(key);						 //二维动态数组
    }
    StringBuilder res = new StringBuilder();
    // 倒序遍历就按照频率大到小顺序，遍历一维
    for (int frt = buckets.length - 1; frt > 0; --frt) {
        if (buckets[frt] == null)  continue;    	// 这个频率 frt 没有元素就跳过。
        for (char c : buckets[frt]) {				// 遍历二维
            for (int k = frt; k > 0; --k) {			// 如果桶里有字符，那一定是出现了ft次
                res.append(c);
            }
        }
    }
    return res.toString();
}
```

C++排序题模板解法参考： [C++排序题解](https://leetcode-cn.com/problems/sort-characters-by-frequency/solution/yi-jie-duo-ti-347451692c-by-fengziluo-qqiw/) ，自定义数据结构，和不排序写法，参考：[作者：zyxwmj](https://leetcode-cn.com/problems/sort-characters-by-frequency/solution/qian-lu-qi-qu-wang-wo-men-ke-yi-hu-xiang-urwc/)

```c
string frequencySort(string s) {					//c++桶排序
    string res;
    vector<string> vec(s.size() + 1);
    unordered_map<char, int> mp;
    for (char c : s) ++mp[c];						//计次
    for (auto [k, v] : mp)	vec[v].append(v, k);	//append(v, k)是添加v次k
    for (int i = s.size(); i > 0; --i)	 if(vec[i].size()) res.append(vec[i]);//注意if条件
    return res;
}
```

```c
string frequencySort(string s) {					//c++快排
    int counts[CHAR_MAX + 1] = {0};					//初始化为1个0
    for (char c : s) ++counts[c];					//计次，又做关系绑定
    sort(s.begin(), s.end(), [&](char a, char b) {  //这里&不能省，是对s排序
        return counts[a] > counts[b] || (counts[a] == counts[b] && a < b);
    });	//mark没有明白为啥是 > 这里的 > 实际结果是从大到小排序
    return s;
}
```

```c
string frequencySort(string s) {					//c++野鸡排,vector加greater<int>排序
    string res;										//效率不低
    vector<int> count(UCHAR_MAX + 1, 0);
    for (char c : s) ++count[c];
    auto sub = count;
    sort(count.begin(), count.end(), greater<int>());
    for (int i = 0; i < (UCHAR_MAX + 1) && count[i]; ++i) {
        for (int j = 0; j < UCHAR_MAX + 1; ++j) {
            if (sub[j] && sub[j] == count[i]) {
                res.append(count[i], j);
                sub[j] = 0;
                break;
            }
        }
    }
    return res;
}
```

```c
string frequencySort(string s) {					//c++堆排
    string res;							
    unordered_map<char, int> dict;
    for (char c : s) ++dict[c];
    priority_queue<pair<int, char> > sub;
    for (auto &[key, value] : dict)
        sub.push({value, key});
    while (sub.size()) {
        res.append(sub.top().first, sub.top().second);
        sub.pop();
    }
    return res;
}
```

```java
public String frequencySort(String s) {			//Java自定义数据结构，4ms，98%
    CharCount[] arr = new CharCount[128];
    for (int i = 0; i < 128; i++) {				// 初始化每个字符
        arr[i] = new CharCount((char)i);
    }
    for (char c : s.toCharArray()) {
        arr[c].frt++;							// 统计字符串每个字符出现的频率
    }
    Arrays.sort(arr);							// 按字符出现的频率进行排序
    StringBuilder sb = new StringBuilder();
    for (int i = 127; i >= 0; i--) {
        char[] c = new char[arr[i].frt];		// 生成字符串，进行拼接
        Arrays.fill(c, arr[i].c);
        sb.append(c);
    }
    return sb.toString();
}

class CharCount implements Comparable<CharCount> {
    char c;		// 记录当前的字符
    int frt;    // 记录字符出现的频率
    public CharCount(char c) { this.c = c; }
    @Override
    public int compareTo(CharCount o) { return frt - o.frt; }
}
```

```java
public String frequencySort(String s) {		//Java不使用排序，3ms，99%
    int[] arr = new int[128];				//字符(数组下标) -> 字符频率
    for (char c : s.toCharArray()) arr[c]++;
    char[] ret = new char[s.length()];
    int i = 0;								// 结果数组的下标
    while (i < s.length()) {
        int max = 0;						// 存储频率最大值
        int maxChar = 0;					// 频率最大值对应的字符
        for (int j = 0; j < 128; j++) {
            if (arr[j] > max) {
                max = arr[j];
                maxChar = j;
            }
        }
        arr[maxChar] = 0;					// 置0
        for(int cnt = 0;i < s.length() && cnt < max;i++,cnt++){
            ret[i] = (char) maxChar;		// 生成结果字符串
        }
    }
    return new String(ret);
}
```

### 3. 前K个高频单词

中等：[692. 前K个高频单词](https://leetcode-cn.com/problems/top-k-frequent-words/)

```
输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2 输出: ["i", "love"]
解析: "i" 和 "love" 次数最多，均为2次。按字母顺序 "i" 在 "love" 之前。
```

```java
public List<String> topKFrequent(String[] strs, int k) {			   //Java小根堆思路
    Map<String, Integer> map = new HashMap();						   //word->cnt
    for (String str : strs) map.put(str, map.getOrDefault(str, 0) + 1);//计次
    PriorityQueue<String> pq = new PriorityQueue<>((o1, o2) -> {	   //核心：小根堆
        if (map.get(o1).equals(map.get(o2))) return o2.compareTo(o1);  //注意：反着的z靠前
        else return map.get(o1) - map.get(o2);						   //频率从小到大
    });
    for (String str : map.keySet()) {								   //放进去
        pq.offer(str);	
        if (pq.size() > k) pq.poll();
    }
    List<String> ret = new ArrayList<>(k);							   //转换结果
    while (pq.size() > 0) ret.add(pq.poll());
    Collections.reverse(ret);										   //细节：反转一下	
    return ret;
}
```

```c++
vector<string> topKFrequent(vector<string>& strs, int k) {
    vector<string> ret;						//c++大根堆
    unordered_map<string, int> dict;		//um不能排序
    for (auto &i : strs) ++dict[i];
    typedef pair<string, int> PIS;			//字符串，频率
    auto cmp = [](PIS &o1, PIS &o2) {		//注意：o1.first > o2.first 是从a到z
        return o1.second == o2.second ? o1.first > o2.first : o1.second < o2.second;
    };										//用大根堆对队列里的pair进行排序
    priority_queue<PIS, vector<PIS>, decltype(cmp)> pq(cmp);
    for (auto &i : dict) pq.emplace(i);
    while (k--) ret.push_back(pq.top().first), pq.pop();
    return ret;
}
```

```c
bool cmp(const pair<string, int>& s1, const pair<string, int>& s2) {
    return s1.second == s2.second ? s1.first < s2.first : s1.second > s2.second;
}														//这函数写到Solution类外边
vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> mp;			
    for(string& word : words) mp[word] ++;
    vector<pair<string, int>> vec(mp.begin(), mp.end());//mp放到vec里面
    sort(vec.begin(), vec.end(), cmp);					//频率从大到小，相等则字典序
    vector<string> ret;
    for(int i = 0; i < k; i ++) ret.push_back(vec[i].first);
    return ret;
}
```

```c++
using PIS = pair<int, string>;
vector<string> topKFrequent(vector<string>& strs, int k) {
    unordered_map<string, int> um;								//写的比较累赘，看语法
    for(auto &str : strs) um[str]++;							//计次
    vector<PIS> vk;
    for(auto &[k,v] : um) vk.push_back({v, k});					//这用的vk：vec<pair<v,k>>
    auto cmp = [](const PIS &o1, const PIS &o2) {
        return o1.first == o2.first ? o1.second < o2.second : o1.first > o2.first;		
    };//放到堆里就是小根堆										  //排序写法和堆的定义是反着的。
    nth_element(vk.begin(), vk.begin()+k, vk.end(), cmp);		//快速选择 Kth
    sort(vk.begin(), vk.begin()+k, cmp);						//再次排序...
    vector<string> ret;
    for(auto i = 0; i < k; i++) ret.push_back(vk[i].second);
    return ret;
}
```

```js
nth_element(vk.begin(), vk.begin()+k, vk.end(), cmp);//最后的cmp参数是重载过来的，不写有默认值
参数1、3是迭代器，2是第 nth 大的元素，cmp是自定义比较器。支持可以随机访问的迭代器， array、vector、deque 这 3 个容器。nth_element() 本质也是一个函数模板，定义在<algorithm>头文件中。
```

```java
public List<String> topKFrequent(String[] strs, int k) {			 //Java哈希表对值排序
    Map<String, Integer> cnt = new HashMap<>();
    for (String s : strs) cnt.put(s, cnt.getOrDefault(s, 0) + 1);
    List<String> list = new ArrayList<>(cnt.keySet());
    list.sort((o1, o2) -> {
        if (cnt.get(o1).equals(cnt.get(o2))) return o1.compareTo(o2);//字典序
        else return cnt.get(o2) - cnt.get(o1);						 //频率降序
    });
    return list.subList(0, k);										 //截取前k个
}
```

```c
vector<string> topKFrequent(vector<string>& words, int k) {			 //桶排序
    vector<string> res;
    unordered_map<string, int> dict;
    for (auto &i : words) ++dict[i];
    vector<vector<string>> sub(words.size() + 1);
    for (auto &[key, value] : dict)
        sub[value].push_back(key);
    for (int i = sub.size() - 1; i >= 0 && k > 0; --i) {
        if (sub[i].size()) {
            sort(sub[i].begin(), sub[i].end());
            int n = min(k, (int)sub[i].size());
            res.insert(res.end(), sub[i].begin(), sub[i].begin() + n);
            k -= n;
        }
    }
    return res;
}
```

## 三项切分

### 1. 按颜色进行排序

中等： [75. 颜色分类](https://leetcode-cn.com/problems/sort-colors/)

```js
只是包含3个数值，0,1,2，且重复值较多，进行排序，时间要求O(N) 空间O(1)。
输入：nums = [2,0,2,1,1,0]	输出：[0,0,1,1,2,2]
```

```java
public void sortColors(int[] nums) {
    int len = nums.length;
    if (len < 2) return;
    int l = 0,r = len - 1,i = 0;
    while (i <= r) {
        if (nums[i] == 0) swap(nums, i++, l++);
        else if (nums[i] == 1) i++;
        else swap(nums, i, r--);
    }
}
private void swap(int[] nums, int a, int b) {
    int t = nums[a];
    nums[a] = nums[b];
    nums[b] = t;
}
```

