牛客：https://www.nowcoder.com/practice/fd711bdfa0e840b381d7e1b82183b3ee?tpId=117&&tqId=35559&rp=1&ru=/activity/oj&qru=/ta/job-code-high/question-ranking



转述：给定字符串数组和一个 k，k 代表输出几组数据，优先输出数据频率高的，数据频率如果相同那就按照字典顺序输出。



示例1

## 输入

```
["1","2","3","4"],2
```

## 返回值

```
[
	["1","1"],
	["2","1"]
]
```

解释：第一位代表数字，第二位代表出现的频率。





示例2

## 输入

```
["1","1","2","3"],2
```

## 返回值

```
[
	["1","2"],
	["2","1"]
]
```













力扣中等：[347. 前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)









给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

不同点：力扣是只返回其中出现频率前 k 高的元素。





示例 1:

输入: nums = [1,1,1,2,2,3], k = 2

输出: [1,2]



示例 2:

输入: nums = [1], k = 1

输出: [1]




提示：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。

你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。

题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。

你可以按任意顺序返回答案。



时间复杂度要优于 O(n log n) ,而不是等于。







就是 TOP K  

参考

- [40. 最小的 K 个数](https://github.com/Code-Jackwen/ZJW-Summary/blob/main/notes-md/To offer/排序/40. 最小的 K 个数.md)



未看

补充：桶排序

时间复杂度：O(n)，nn 表示数组的长度。首先，遍历一遍数组统计元素的频率，这一系列操作的时间复杂度是 O(n)O(n)；桶的数量为 n + 1n+1，所以桶排序的时间复杂度为 O(n)O(n)；因此，总的时间复杂度是 O(n)O(n)。
空间复杂度：很明显为 O(n)O(n)



````java
//基于桶排序求解「前 K 个高频元素」
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        List<Integer> res = new ArrayList();
        // 使用字典，统计每个元素出现的次数，元素为键，元素出现的次数为值
        HashMap<Integer,Integer> map = new HashMap();
        for(int num : nums){
            if (map.containsKey(num)) {
               map.put(num, map.get(num) + 1);
             } else {
                map.put(num, 1);
             }
        }
        
        //桶排序
        //将频率作为数组下标，对于出现频率不同的数字集合，存入对应的数组下标
        List<Integer>[] list = new List[nums.length+1];
        for(int key : map.keySet()){
            // 获取出现的次数作为下标
            int i = map.get(key);
            if(list[i] == null){
               list[i] = new ArrayList();
            } 
            list[i].add(key);
        }
        
        // 倒序遍历数组获取出现顺序从大到小的排列
        for(int i = list.length - 1;i >= 0 && res.size() < k;i--){
            if(list[i] == null) continue;
            res.addAll(list[i]);
        }
        return res;
    }
}

作者：MisterBooo
链接：https://leetcode-cn.com/problems/top-k-frequent-elements/solution/leetcode-di-347-hao-wen-ti-qian-k-ge-gao-pin-yuan-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
````







相似题目：

[692. 前K个高频单词](https://leetcode-cn.com/problems/top-k-frequent-words/)

不同点是，输入的字符串，字符串的TOP K





给一非空的单词列表，返回前 k 个出现次数最多的单词。

返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。

示例 1：

输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
输出: ["i", "love"]
解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
    注意，按字母顺序 "i" 在 "love" 之前。


示例 2：

输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
输出: ["the", "is", "sunny", "day"]
解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
    出现次数依次为 4, 3, 2 和 1 次。


注意：

假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。
输入的单词均由小写字母组成。


扩展练习：

尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/top-k-frequent-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



## 方法一：排序



时间复杂度：O(N \log{N})O(NlogN)。其中 NN 是 words 的长度。我们用 O(N)O(N) 时间计算每个单词的频率，然后用 O(N \log{N})O(NlogN) 时间对给定的单词进行排序。
空间复杂度：O(N)O(N)，用来存放候答案的地方

````java
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> count = new HashMap();
        for (String word: words) {
            count.put(word, count.getOrDefault(word, 0) + 1);
        }
        List<String> ret = new ArrayList(count.keySet());
        Collections.sort(ret, (w1, w2) -> count.get(w1).equals(count.get(w2)) ?
                w1.compareTo(w2) : count.get(w2) - count.get(w1));
        return ret.subList(0, k);
    }
}
作者：LeetCode
链接：https://leetcode-cn.com/problems/top-k-frequent-words/solution/qian-kge-gao-pin-dan-ci-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
````





## 方法二：堆

复杂度分析

时间复杂度： O(N \log{k})O(Nlogk)。其中 NN 是 words 的长度。我们用 O(N)O(N) 的时间计算每个单词的频率，然后将 NN 个单词添加到堆中，添加每个单词的时间为 O(\log {k})O(logk) 。最后，我们从堆中弹出最多 kk 次。因为 k \leq Nk≤N 的值，总共是 O(N \log{k})O(Nlogk)。
空间复杂度：O(N)O(N)，用于存储我们计数的空间

````java
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> count = new HashMap();
        for (String word: words) {
            count.put(word, count.getOrDefault(word, 0) + 1);
        }
        PriorityQueue<String> heap = new PriorityQueue<String>(
                (w1, w2) -> count.get(w1).equals(count.get(w2)) ?
                w2.compareTo(w1) : count.get(w1) - count.get(w2) );

        for (String word: count.keySet()) {
            heap.offer(word);
            if (heap.size() > k) heap.poll();
        }

        List<String> ans = new ArrayList();
        while (!heap.isEmpty()) ans.add(heap.poll());
        Collections.reverse(ans);
        return ans;
    }
}

作者：LeetCode
链接：https://leetcode-cn.com/problems/top-k-frequent-words/solution/qian-kge-gao-pin-dan-ci-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
````





