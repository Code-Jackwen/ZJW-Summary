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

用于求解   **TopK Elements**   问题，也就是 K 个最小元素的问题。使用最小堆来实现 TopK 问题，最小堆使用大顶堆来实现，大顶堆的堆顶元素为当前堆的最大元素。实现过程：不断地往大顶堆中插入新元素，当堆中元素的数量大于 k 时，移除堆顶元素，也就是当前堆中最大的元素，剩下的元素都为当前添加过的元素中最小的 K 个元素。插入和移除堆顶元素的时间复杂度都为 log<sub>2</sub>N。

堆也可以用于求解 Kth Element 问题，得到了大小为 K 的最小堆之后，因为使用了大顶堆来实现，因此堆顶元素就是第 K 大的元素。

快速选择也可以求解 TopK Elements 问题，因为找到 Kth Element 之后，再遍历一次数组，所有小于等于 Kth Element 的元素都是 TopK Elements。

可以看到，快速选择和堆排序都可以求解 Kth Element 和 TopK Elements 问题。

### 1. Kth Element

215\. Kth Largest Element in an Array (Medium)

[Leetcode](https://leetcode.com/problems/kth-largest-element-in-an-array/description/) / [215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)

```text
Input: [3,2,1,5,6,4] and k = 2
Output: 5
```

题目描述：找到倒数第 k 个的元素。

**排序**  ：时间复杂度 O(NlogN)，空间复杂度 O(1)

```java
public int findKthLargest(int[] nums, int k) {
    Arrays.sort(nums);
    return nums[nums.length - k];
}
```

**堆**  ：时间复杂度 O(NlogK)，空间复杂度 O(K)。

基于堆排序

```js
时间复杂度：O(nlogn)，建堆的时间代价是 O(n)，删除的总代价是 O(klogn)，因为 k < n，故渐进时间复杂为 O(n+klogn)=O(nlogn)。
空间复杂度：O(logn)，即递归使用栈空间的空间代价。
```

```java
public int findKthLargest(int[] nums, int k) {
    PriorityQueue<Integer> pq = new PriorityQueue<>(); // 小顶堆
    for (int val : nums) {
        pq.add(val);
        if (pq.size() > k)  // 维护堆的大小为 K
            pq.poll();
    }
    return pq.peek();
}
```

**快速选择**  ：时间复杂度 O(N)，空间复杂度 O(1)

```js
时间复杂度：O(n)，如上文所述，证明过程可以参考「《算法导论》9.2：期望为线性的选择算法」。
空间复杂度：O(logn)，递归使用栈空间的空间代价的期望为 O(logn)。
```

```java
public int findKthLargest(int[] nums, int k) {
    k = nums.length - k;
    int l = 0, h = nums.length - 1;
    while (l < h) {
        int j = partition(nums, l, h);
        if (j == k) {
            break;
        } else if (j < k) {
            l = j + 1;
        } else {
            h = j - 1;
        }
    }
    return nums[k];
}

private int partition(int[] a, int l, int h) {
    int i = l, j = h + 1;
    while (true) {
        while (a[++i] < a[l] && i < h) ;
        while (a[--j] > a[l] && j > l) ;
        if (i >= j) {
            break;
        }
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

### 1. 出现频率最多的 k 个元素

347\. Top K Frequent Elements (Medium)

[Leetcode](https://leetcode.com/problems/top-k-frequent-elements/description/) / [347. 前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)

```js
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]

提示：
你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(nlogn) , n 是数组的大小。
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
你可以按任意顺序返回答案。
```

桶排序

快一点

设置若干个桶，每个桶存储出现频率相同的数。桶的下标表示数出现的频率，即第 i 个桶中存储的数出现的频率为 i。

把数都放到桶之后，从后向前遍历桶，最先得到的 k 个数就是出现频率最多的的 k 个数。

注意这里集合方法 addAll(); 的使用。

```java
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        List<Integer>[] buckets = new ArrayList[nums.length + 1];
        for (int key : map.keySet()) {
            int frt = map.get(key);
            if (buckets[frt] == null) {
                buckets[frt] = new ArrayList<>();
            }
            buckets[frt].add(key);
        }
        List<Integer> topK = new ArrayList<>();
        for (int i = buckets.length - 1; i >= 0 && topK.size() < k; i--) {
            if (buckets[i] == null) {
                continue;
            }
            if (buckets[i].size() <= (k - topK.size())) {
                topK.addAll(buckets[i]);
            } else {
                topK.addAll(buckets[i].subList(0, k - topK.size()));
            }
        }
        int[] res = new int[k];
        for (int i = 0; i < k; i++) {
            res[i] = topK.get(i);
        }
        return res;
    }
}
```

基于自定义排序

```java
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        ArrayList<Map.Entry<Integer, Integer>> al = new ArrayList(map.entrySet());
        Collections.sort(al, (o1, o2) -> (o2.getValue().compareTo(o1.getValue())));

        int[] ret = new int[k];
        int i = 0;
        for (Map.Entry<Integer, Integer> ent : al) {
            ret[i++] = ent.getKey();
            if(k--==0){
                break;
            }
        }
        return ret;
    }
}
```

基于堆

```js
时间复杂度：
O(Nlogk)，其中 N 为数组的长度。我们首先遍历原数组，并使用哈希表记录出现次数，每个元素需要 O(1) 的时间，共需 O(N) 的时间。随后，我们遍历「出现次数数组」，由于堆的大小至多为 k，因此每次堆操作需要 O(logk) 的时间，共需 O(Nlogk) 的时间。二者之和为 O(Nlogk)。
空间复杂度：
O(N)。哈希表的大小为 O(N)，而堆的大小为 O(k)，共计为 O(N)。
```

```java
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<Integer, Integer>();
        for (int num : nums) {
            cnt.put(num, cnt.getOrDefault(num, 0) + 1);
        }

        // int[] 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
        PriorityQueue<int[]> que = new PriorityQueue<>(new Comparator<int[]>() {
            public int compare(int[] m, int[] n) {
                return m[1] - n[1];
            }
        });
        for (Map.Entry<Integer, Integer> entry : cnt.entrySet()) {
            int num = entry.getKey(), count = entry.getValue();
            if (que.size() == k) {
                if (que.peek()[1] < count) {
                    que.poll();
                    que.offer(new int[]{num, count});
                }
            } else {
                que.offer(new int[]{num, count});
            }
        }
        int[] ret = new int[k];
        for (int i = 0; i < k; ++i) {
            ret[i] = que.poll()[0];
        }
        return ret;
    }
}
```

基于快速选择

参考：[作者：LeetCode-Solution](https://leetcode-cn.com/problems/top-k-frequent-elements/solution/qian-k-ge-gao-pin-yuan-su-by-leetcode-solution/)

### 2. 按照字符出现次数对字符串排序

451\. Sort Characters By Frequency (Medium)

[Leetcode](https://leetcode.com/problems/sort-characters-by-frequency/description/) / [451. 根据字符出现频率排序](https://leetcode-cn.com/problems/sort-characters-by-frequency/)

```js
给定一个字符串，请将字符串里的字符按照出现的频率降序排列。

示例 1:
输入:
"tree"
输出:
"eert"
解释:
'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。

示例 2:
输入:
"cccaaa"
输出:
"cccaaa"
解释:
'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。

示例 3:
输入:
"Aabb"
输出:
"bbAa"
解释:
此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。
```

堆排

速度快点，5ms，96%

```java
class Solution {
    public String frequencySort(String s) {
        int[] letters = new int[128];
        for (char c : s.toCharArray()) letters[c]++;

        PriorityQueue<Character> heap = new PriorityQueue<>(128, (a, b) -> Integer.compare(letters[b], letters[a]));
        StringBuilder res = new StringBuilder();

        for (int i = 0; i < letters.length; ++i) {
            if (letters[i] != 0) {
                heap.offer((char)i);
            }
        }

        while (!heap.isEmpty()) {
            char c = heap.poll();
            while (letters[c]-- > 0) {
                res.append(c);
            }
        }
        return res.toString();
    }
}
```

桶排序

14ms，67%

```java
class Solution {
    public String frequencySort(String s) {
        if (s.isEmpty() || s.length() == 1) {
            return s;
        }
        // 元素 -> 元素出现的频率
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        // 构造一个桶的集合（即一系列桶），桶的个数为 s 的长度 +1。
        // 出现0次的后边不拼接，buckets[0] 没有意义。
        // 将出现频率为 frt 的字符放到第 frt 个桶里（即 buckets[frt]）
        List<Character>[] buckets = new List[s.length() + 1];

        for (char key : map.keySet()) {
            int frt = map.get(key);
            if (buckets[frt] == null) {
                buckets[frt] = new ArrayList<Character>();
            }
            buckets[frt].add(key);						 //二维动态数组
        }

        StringBuilder res = new StringBuilder();

        // 倒序遍历就按照频率大到小顺序，遍历一维
        for (int frt = buckets.length - 1; frt > 0; --frt) {
            if (buckets[frt] == null)      			    // 这个频率 frt 没有元素就跳过。
                continue;
            for (char c : buckets[frt]) {				// 遍历二维
                // 如果桶里有字符，那一定是出现了ft次
                for (int k = frt; k > 0; --k) {
                    res.append(c);
                }
            }
        }
        return res.toString();
    }
}
```

自定义数据结构

4ms，98%

[作者：zyxwmj](https://leetcode-cn.com/problems/sort-characters-by-frequency/solution/qian-lu-qi-qu-wang-wo-men-ke-yi-hu-xiang-urwc/)

```java
import java.util.Arrays;

class Solution {
    public String frequencySort(String s) {
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
        public CharCount(char c) {
            this.c = c;
        }
        @Override
        public int compareTo(CharCount o) {
            return frt - o.frt;
        }
    }
}
```

不使用排序

3ms，99%

[作者：zyxwmj](https://leetcode-cn.com/problems/sort-characters-by-frequency/solution/qian-lu-qi-qu-wang-wo-men-ke-yi-hu-xiang-urwc/)

```java
class Solution {
    public String frequencySort(String s) {
        int[] arr = new int[128];				//字符(数组下标) -> 字符频率
        for (char c : s.toCharArray()) {
            arr[c]++;
        }
        char[] ret = new char[s.length()];
        // 结果数组的下标
        int i = 0;
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
            // 生成结果字符串
            for(int cnt = 0;i < s.length() && cnt < max;i++,cnt++){
                ret[i] = (char) maxChar;
            }
        }
        return new String(ret);
    }
}
```

## 荷兰国旗问题

荷兰国旗包含三种颜色：红、白、蓝。

有三种颜色的球，算法的目标是将这三种球按颜色顺序正确地排列。它其实是三向切分快速排序的一种变种，在三向切分快速排序中，每次切分都将数组分成三个区间：小于切分元素、等于切分元素、大于切分元素，而该算法是将数组分成三个区间：等于红色、等于白色、等于蓝色。

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/7a3215ec-6fb7-4935-8b0d-cb408208f7cb.png"/> </div><br>

### 1. 按颜色进行排序

75\. Sort Colors (Medium)

[Leetcode](https://leetcode.com/problems/sort-colors/description/) / [75. 颜色分类](https://leetcode-cn.com/problems/sort-colors/)

```js
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

示例 1：
输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]

示例 2：
输入：nums = [2,0,1]
输出：[0,1,2]

示例 3：
输入：nums = [1]
输出：[1]
 
进阶：时间要求O(N) 空间O(1)
```

快速选择

- 时间复杂度：O(N)，这里 N 是输入数组的长度；
- 空间复杂度：O(1)。

```java
class Solution {
    public void sortColors(int[] nums) {
        int len = nums.length;
        if (len < 2) return;
        int l = 0;
        int r = len - 1;
        int i = 0;
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
}
```

