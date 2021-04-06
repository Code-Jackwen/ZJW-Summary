# Leetcode 题解 - 栈和队列
<!-- GFM-TOC -->
* [Leetcode 题解 - 栈和队列](#leetcode-题解---栈和队列)
    * [1. 用栈实现队列](#1-用栈实现队列)
    * [2. 用队列实现栈](#2-用队列实现栈)
    * [3. 最小值栈](#3-最小值栈)
    * [4. 用栈实现括号匹配](#4-用栈实现括号匹配)
    * [5. 数组中元素与下一个比它大的元素之间的距离](#5-数组中元素与下一个比它大的元素之间的距离)
    * [6. 循环数组中比当前元素大的下一个元素](#6-循环数组中比当前元素大的下一个元素)
<!-- GFM-TOC -->


## 1. 用栈实现队列

232\. Implement Queue using Stacks (Easy)

[Leetcode](https://leetcode.com/problems/implement-queue-using-stacks/description/) / [剑指 Offer 09. 用两个栈实现队列](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)

栈的顺序为后进先出，而队列的顺序为先进先出。使用两个栈实现队列，一个元素需要经过两个栈才能出队列，在经过第一个栈时元素顺序被反转，经过第二个栈时再次被反转，此时就是先进先出顺序。

```java
//实现类中的三个方法
class CQueue {
    public CQueue() {}
    public void appendTail(int value) {}
    public int deleteHead() {}
}
```

题解

```java
class CQueue {
    //一般不选用Stack作栈，而是选用LinkedList， 解释：
    //Stack继承Vector接口，Vector底层是一个Object[]数组，且加同步锁，扩容慢。
    //LinkedList实现了Deque接口，所以Stack能做的事LinkedList都能做,双向链表，扩容容易点。
    LinkedList<Integer> in, out;
    public CQueue() {
        in = new LinkedList<Integer>();
        out = new LinkedList<Integer>();
    }
    public void appendTail(int value) {
        in.addLast(value);
    }
    public int deleteHead() {
        if(!out.isEmpty()) return out.removeLast();
        if(in.isEmpty()) return -1;
        while(!in.isEmpty())
            out.addLast(in.removeLast());
        return out.removeLast();
    }
}
```

## 2. 用队列实现栈

225\. Implement Stack using Queues (Easy)

[Leetcode](https://leetcode.com/problems/implement-stack-using-queues/description/) / [225. 用队列实现栈](https://leetcode-cn.com/problems/implement-stack-using-queues/)

在将一个元素 x 插入队列时，为了维护原来的后进先出顺序，需要让 x 插入队列首部。而队列的默认插入顺序是队列尾部，因此在将 x 插入队列尾部之后，需要让除了 x 之外的所有元素出队列，再入队列。

核心点：

就是在添加的时候，如果队列元素多余1，也就是>=2，那就将新添加元素前面的元素依次出队，再入队。这时，新添加的元素就跑到了队头。

```javascript
队列常用方法：
Queue<Integer> queue = new LinkedList<>();

queue.add(x); 
queue.peek(); 		// peek() 是队列和栈都能通用的方法
queue.remove();		// 返回删除的元素，实际是删除 LinkedList 左边第一个
queue.size();
queue.isEmpty();
```

题解：

```java
class MyStack {

    private Queue<Integer> queue;
    
    public MyStack() { queue = new LinkedList<>(); }

    public void push(int x) {
        queue.add(x);
        int cnt = queue.size();
        while (cnt-- > 1) {				//1、2循环一次变成2、1，再次添加3，循环两次变成3、2、1
            queue.add(queue.remove());
        }
    }

    public int pop() { return queue.remove(); }
    public int top() { return queue.peek(); }
    public boolean empty() { return queue.isEmpty(); }
}
```

## 3. 最小值栈

155\. Min Stack (Easy)

[Leetcode](https://leetcode.com/problems/min-stack/description/) / [面试题30. 包含min函数的栈](https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/)

```javascript
//定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中.
//实现类中的方法,调用 min、push 及 pop 的时间复杂度都是 O(1)。
class MinStack {
    public MinStack() {}
    public void push(int x) {}
    public void pop() {}
    public int top() {}
    public int min() {}
}
```

对于实现最小值队列问题，可以先将队列使用栈来实现，然后就将问题转换为最小值栈，这个问题出现在 编程之美：3.7。

```java
class MinStack {
    private Stack<Integer> dataStack = new Stack<>();
    private Stack<Integer> minStack = new Stack<>();
    public void push(int node) {
        dataStack.push(node);
        //注意这里的优化,也就是minStack空时候直接先放进去一个，之后有更小的值就放到栈顶。
        minStack.push(minStack.isEmpty() ? node : Math.min(minStack.peek(), node));
    }
    public void pop() {
        dataStack.pop();
        minStack.pop();
    }
    public int top() {
        return dataStack.peek();
    }
    public int min() {
        return minStack.peek();
    }
}
```

## 4. 用栈实现括号匹配

20\. Valid Parentheses (Easy)

[Leetcode](https://leetcode.com/problems/valid-parentheses/description/) / [20. 有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)

```html
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
 
示例 1：
输入：s = "()"
输出：true

示例 2：
输入：s = "()[]{}"
输出：true

示例 3：
输入：s = "(]"
输出：false

示例 4：
输入：s = "([)]"
输出：false

示例 5：
输入：s = "{[]}"
输出：true
```

```java
class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) {		//处理："]"
                    return false;
                }
                char cStack = stack.pop();
                boolean b1 = c == ')' && cStack != '(';
                boolean b2 = c == ']' && cStack != '[';
                boolean b3 = c == '}' && cStack != '{';
                if (b1 || b2 || b3) {
                    return false;
                }
            }
        }
        return stack.isEmpty();				//执行String长度次后，空的就是对的。
    }
}
```

## 5. 数组中元素与下一个比它大的元素之间的距离

739\. Daily Temperatures (Medium)

[Leetcode](https://leetcode.com/problems/daily-temperatures/description/) / [739. 每日温度](https://leetcode-cn.com/problems/daily-temperatures/)

```js
请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。

例如:
Input: 	[73, 74, 75, 71, 69, 72, 76, 73]
Output: [1,   1,  4,  2,  1,  1,  0,  0]

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
```

在遍历数组时用栈把数组中的数存起来，如果当前遍历的数比栈顶元素来的大，说明栈顶元素的下一个比它大的数就是当前元素。

解法一：

```js
时间复杂度：O(n)，其中 n 是温度列表的长度。正向遍历温度列表一遍，对于温度列表中的每个下标，最多有一次进栈和出栈的操作。
空间复杂度：O(n)，其中 n 是温度列表的长度。需要维护一个单调栈存储温度列表中的下标。

//作者：LeetCode-Solution	有视频讲解
//链接：https://leetcode-cn.com/problems/daily-temperatures/solution/mei-ri-wen-du-by-leetcode-solution/
```

题解：单调栈

```java
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] dist = new int[n];
        Stack<Integer> indexs = new Stack<>();
        for (int curIndex = 0; curIndex < n; curIndex++) {
            while (!indexs.isEmpty() 
                   && temperatures[curIndex] > temperatures[indexs.peek()]) {
                
                int preIndex = indexs.pop();
                dist[preIndex] = curIndex - preIndex;
            }
            indexs.add(curIndex);
        }
        return dist;
    }
}
```

解法二：

```js
时间复杂度：O(nm)，其中 n 是温度列表的长度，m 是数组 next 的长度，在本题中温度不超过 100，所以 m 的值为 100。反向遍历温度列表一遍，对于温度列表中的每个值，都要遍历数组 next 一遍。
空间复杂度：O(m)，其中 m 是数组 next 的长度。除了返回值以外，需要维护长度为 m 的数组 next 记录每个温度第一次出现的下标位置。
```

题解：暴力

```java
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int length = T.length;
        int[] ans = new int[length];
        int[] next = new int[101];
        Arrays.fill(next, Integer.MAX_VALUE);
        for (int i = length - 1; i >= 0; --i) {
            int warmerIndex = Integer.MAX_VALUE;
            for (int t = T[i] + 1; t <= 100; ++t) {
                if (next[t] < warmerIndex) {
                    warmerIndex = next[t];
                }
            }
            if (warmerIndex < Integer.MAX_VALUE) {
                ans[i] = warmerIndex - i;
            }
            next[T[i]] = i;
        }
        return ans;
    }
}
//作者：LeetCode-Solution
//链接：https://leetcode-cn.com/problems/daily-temperatures/solution/mei-ri-wen-du-by-leetcode-solution/
```



## 6. 循环数组中比当前元素大的下一个元素

503\. Next Greater Element II (Medium)

[Leetcode](https://leetcode.com/problems/next-greater-element-ii/description/) / [力扣](https://leetcode-cn.com/problems/next-greater-element-ii/description/)

```text
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number;
The second 1's next greater number needs to search circularly, which is also 2.
```

与 739. Daily Temperatures (Medium) 不同的是，数组是循环数组，并且最后要求的不是距离而是下一个元素。

```java
public int[] nextGreaterElements(int[] nums) {
    int n = nums.length;
    int[] next = new int[n];
    Arrays.fill(next, -1);
    Stack<Integer> pre = new Stack<>();
    for (int i = 0; i < n * 2; i++) {
        int num = nums[i % n];
        while (!pre.isEmpty() && nums[pre.peek()] < num) {
            next[pre.pop()] = num;
        }
        if (i < n){
            pre.push(i);
        }
    }
    return next;
}
```
