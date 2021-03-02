力扣中等



实现一个  LRU (最近最少使用) 缓存机制，实现 LRUCache 类。

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。


进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？

 

示例：

输入

````
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]输出
[null, null, null, 1, null, -1, null, -1, 3, 4]
````

解释

````
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3} ？？？{3=3,4=4}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4
````


提示：

1 <= capacity <= 3000
0 <= key <= 3000
0 <= value <= 104
最多调用 3 * 104 次 get 和 put







# 总结：

LinkHashMap面试中如果明确不给用。 使用队列和HashMap 可以，或者解法二，双链表+HashMap 。

## 力扣题解总结

## 解法一：LinkedHashMap 

使用 LinkedHashMap ， 当然可以直接重写 removeEldestEntry() 方法，这里暂忽略此写法。

这里用 LinkedHashMap 有具有顺序HashMap的特点。

````java
public class LRUCache{
    int capacity;
    Map<Integer, Integer> map;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        map = new LinkedHashMap<>();
    }

    public int get(int key) {
        if (!map.containsKey(key)) {
            return -1;
        }
        // 先删除旧的位置，再放入新位置。
        Integer value = map.remove(key);
        map.put(key, value);
        return value;
    }

    public void put(int key, int value) {
        if (map.containsKey(key)) {	// 这里可以写成上边调用 get 方法的形式
            map.remove(key);
            map.put(key, value);
            return;
        }
        map.put(key, value);
        // 超出capacity，删除最久没用的。利用迭代器找到第一个key并删除。
        if (map.size() > capacity) {
            map.remove(map.entrySet().iterator().next().getKey());
        }
    }
}
````



## 解法二：双链表+HashMap 

````java
public class LRUCache{
    
    // 定义双向链表节点，既存key也存value
    private class ListNode {
        int key;
        int val;
        ListNode pre;
        ListNode next;

        public ListNode(int key, int val) {
            this.key = key;
            this.val = val;
            pre = null;
            next = null;
        }
    }

    private int capacity;
    private Map<Integer, ListNode> map;  // key->node{key,value}
    private ListNode head;  			 // dummy head
    private ListNode tail; 				 // dummy tail

    public LRUCache(int capacity) {
        this.capacity = capacity;
        map = new HashMap<>();
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head.next = tail;		//不存在 head.pre		head -> tail
        tail.pre = head;		//不存在 tail.next		head <- tail
    }

    public int get(int key) {
        if (!map.containsKey(key)) {
            return -1;
        }
        ListNode node = map.get(key);
        // 先删除该节点，再接到尾部
        node.pre.next = node.next;
        node.next.pre = node.pre;
        moveToTail(node);
        return node.val;
    }

    public void put(int key, int value) {
        // 直接调用这边的get方法，如果存在，node会在get方法中被移动到尾巴。
        if (get(key) != -1) {
            map.get(key).val = value;// 直接修改值即可
            return;
        }
        // 若不存在，new一个出来，移到尾巴。如果超出容量，把头去掉。
        ListNode node = new ListNode(key, value);
        map.put(key, node);
        moveToTail(node);

        if (map.size() > capacity) {
            map.remove(head.next.key);
            head.next = head.next.next;
            head.next.pre = head;
        }
    }

    // 把节点移动到尾巴
    private void moveToTail(ListNode node) {
        node.pre = tail.pre;
        tail.pre = node;
        node.pre.next = node;
        node.next = tail;
    }

}
````



## 解法三：单链表 + HashMap

拓展

```java
public class LRUCache{

    private int capacity;
    private Map<Integer, ListNode> map; //key -> node.pre
    private ListNode head;  // dummy
    private ListNode tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        map = new HashMap<>();
        head = new ListNode(-1, -1);
        tail = head;
    }

    public int get(int key) {
        if (!map.containsKey(key)) {
            return -1;
        }
        // map中存放的是要找的节点的前驱
        ListNode pre = map.get(key);
        ListNode cur = pre.next;

        // 把当前节点删掉并移到尾部
        if (cur != tail) {
            pre.next = cur.next;
            // 更新它后面 node 的前驱
            map.put(cur.next.key, pre); 
            map.put(cur.key, tail);
            moveToTail(cur);
        }
        return cur.val;
    }

    public void put(int key, int value) {
        if (get(key) != -1) {
            map.get(key).next.val = value;
            return;
        }
        // 若不存在则 new 一个
        ListNode node = new ListNode(key, value);
        // 当前 node 的 pre 是 tail
        map.put(key, tail); 
        moveToTail(node);

        if (map.size() > capacity) {
            map.remove(head.next.key);
            map.put(head.next.next.key, head);
            head.next = head.next.next;
        }
    }

    private void moveToTail(ListNode node) {
        node.next = null;
        tail.next = node;
        tail = tail.next;
    }

    // 定义单链表节点
    private class ListNode {
        int key, val;
        ListNode next;

        public ListNode(int key, int val) {
            this.key = key;
            this.val = val;
            this.next = null;
        }
    }

}
```

## 参考：

[146. LRU 缓存机制](https://leetcode-cn.com/problems/lru-cache/)









## 牛客题解总结

题目描述

设计LRU缓存结构，该结构在构造时确定大小，假设大小为K，并有如下两个功能

- set(key， value)：将记录(key， value)插入该结构
- get(key)：返回key对应的value值

[要求]

1. set和get方法的时间复杂度为 O(1)
2. 某个key的set或get操作一旦发生，认为这个key的记录成了最常使用的。
3. 当缓存的大小超过K时，移除最不经常使用的记录，即set或get最久远的。

若opt=1，接下来两个整数x， y，表示set(x， y)
若opt=2，接下来一个整数x，表示get(x)，若x未出现过或已被移除，则返回-1
对于每个操作2，输出一个答案



示例1

输入

````
[

	[1，1，1]，[1，2，2]，[1，3，2]，[2，1]，[1，4，4]，[2，2]

]，3
````

返回值

````
[1，-1]
````

说明

````
第一次操作后：最常使用的记录为("1"， 1)

第二次操作后：最常使用的记录为("2"， 2)，("1"， 1)变为最不常用的

第三次操作后：最常使用的记录为("3"， 2)，("1"， 1)还是最不常用的

第四次操作后：最常用的记录为("1"， 1)，("2"， 2)变为最不常用的

第五次操作后：大小超过了3，所以移除此时最不常使用的记录("2"， 2)，加入记录("4"， 4)，并且为最常使用的记录，然后("3"， 2)变为最不常使用的记录
````

备注:

```
1≤K≤N≤10^5
−2×10^9≤x，y≤2×10^9
```





## 牛客原题题解：LinkHashMap（推荐）

````java
import java.util.*;


public class Solution {
    /**
     * lru design
     * @param operators int整型二维数组 the ops
     * @param k int整型 the k
     * @return int整型一维数组
     */
    public int[] LRU (int[][] operators, int k) {
        // write code here
        LinkedHashMap<Integer,Integer> lruMap = new LinkedHashMap<Integer,Integer>();
        ArrayList<Integer> result = new ArrayList();
        
        for(int[] opat:operators){
            int key = opat[1];
            switch(opat[0]){
                case 1:
                    int value = opat[2];
                    if(lruMap.size()<k){
                        lruMap.put(key,value);
                    }else{
                        //删除第一个
                        Iterator ot = lruMap.keySet().iterator();
                        lruMap.remove(ot.next());
                        lruMap.put(key,value);
                    }
                    break;
                case 2:
                    if(lruMap.containsKey(key)){
                        int val = lruMap.get(key);
                        result.add(val);
                        lruMap.remove(key);
                        lruMap.put(key,val);
                    }else{
                        result.add(-1);
                    }
                    break;
                default:
            }
        }
        // ArrayList转数组。
        int[] resultArr = new int[result.size()];
        int i=0;
        for(int a:result){
            resultArr[i++]=a;
        }
        return resultArr;
    }
}
````



## 牛客题解备用：队列 + HashMap（推荐）

````java
import java.util.*;


public class Solution {
    /**
     * lru design
     * @param operators int整型二维数组 the ops
     * @param k int整型 the k
     * @return int整型一维数组
     */
    ArrayDeque<Integer> keysDeque = new ArrayDeque<>();
    Map<Integer, Integer> cache = new HashMap<>();
    int max;

    public int[] LRU(int[][] operators, int k) {
        // write code here
        this.max = k;
        int len = (int) Arrays.stream(operators).filter(x -> x[0] == 2).count();
        int[] res = new int[len];
        for (int i = 0, j = 0; i < operators.length; i++) {
            if (operators[i][0] == 1) {
                set(operators[i][1], operators[i][2]);
            } else {
                res[j++] = get(operators[i][1]);
            }
        }
        return res;
    }

    public void set(int key, int value) {
        if (cache.size() < max) {
            //操作队列
            keysDeque.remove(key);
            keysDeque.add(key);
            cache.put(key, value);
        }else if (cache.size() == max) {
            if (keysDeque.size() > 0) {
                int firstKey = keysDeque.pollFirst();
                cache.remove(firstKey);
            }
            //再去添加缓存
            keysDeque.add(key);
            cache.put(key, value);
        }
    }

    public int get(int key) {
        if (cache.containsKey(key)) {
            //操作队列
            keysDeque.remove(key);
            keysDeque.add(key);
            return cache.get(key);
        }
        return -1;
    }
}
````

## 参考：

牛客NC93：https://www.nowcoder.com/practice/e3769a5f49894d49b871c09cadd13a61?tpId=190&tqId=35214&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fjob-code-high-rd%2Fquestion-ranking&tab=answerKey