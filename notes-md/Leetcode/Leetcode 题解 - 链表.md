# Leetcode 题解 - 链表
<!-- GFM-TOC -->

* [Leetcode 题解 - 链表](#leetcode-题解---链表)
    * [1. 找出两个链表的交点](#1-找出两个链表的交点)
    * [2. 链表反转](#2-链表反转)
    * [3. 归并两个有序的链表](#3-归并两个有序的链表)
    * [4. 从有序链表中删除重复节点](#4-从有序链表中删除重复节点)
    * [5. 删除链表的倒数第 n 个节点](#5-删除链表的倒数第-n-个节点)
    * [6. 交换链表中的相邻结点](#6-交换链表中的相邻结点)
    * [7. 链表求和](#7-链表求和)
    * [8. 回文链表](#8-回文链表)
    * [9. 分隔链表](#9-分隔链表)
    * [10. 链表元素按奇偶聚集](#10-链表元素按奇偶聚集)
<!-- GFM-TOC -->


链表是空节点，或者有一个值和一个指向下一个链表的指针，因此很多链表问题可以用递归来处理。

##  1. 找出两个链表的交点

160\. Intersection of Two Linked Lists (Easy)

[Leetcode](https://leetcode.com/problems/intersection-of-two-linked-lists/description/) / [160. 相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)

例如以下示例中 A 和 B 两个链表相交于 c1：

```html
A:          a1 → a2
                    ↘
                      c1 → c2 → c3
                    ↗
B:    b1 → b2 → b3
```

但是不会出现以下相交的情况，因为每个节点只有一个 next 指针，也就只能有一个后继节点，而以下示例中节点 c 有两个后继节点。

```html
A:          a1 → a2       d1 → d2
                    ↘  ↗
                      c
                    ↗  ↘
B:    b1 → b2 → b3        e1 → e2
```



要求时间复杂度为 O(N)，空间复杂度为 O(1)。如果不存在交点则返回 null。

设 A 的长度为 a + c，B 的长度为 b + c，其中 c 为尾部公共部分长度，可知 a + c + b = b + c + a。

当访问 A 链表的指针访问到链表尾部时，令它从链表 B 的头部开始访问链表 B；同样地，当访问 B 链表的指针访问到链表尾部时，令它从链表 A 的头部开始访问链表 A。这样就能控制访问 A 和 B 两个链表的指针能同时访问到交点。

如果不存在交点，那么 a + b = b + a，以下实现代码中 l1 和 l2 会同时为 null，从而退出循环。

```java
public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    ListNode l1 = headA, l2 = headB;
    while (l1 != l2) {
        l1 = (l1 == null) ? headB : l1.next;
        l2 = (l2 == null) ? headA : l2.next;
    }
    return l1;
}
```

如果只是判断是否存在交点，那么就是另一个问题，即 [编程之美 3.6]() 的问题。有两种解法：

- 把第一个链表的结尾连接到第二个链表的开头，看第二个链表是否存在环；
- 或者直接比较两个链表的最后一个节点是否相同。

##  2. 链表反转

206\. Reverse Linked List (Easy)

[Leetcode](https://leetcode.com/problems/reverse-linked-list/description/) / [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

递归

```java
public ListNode reverseList(ListNode head) {
    if (head == null || head.next == null) {
        return head;
    }
    ListNode next = head.next;
    ListNode newHead = reverseList(next);
    next.next = head;
    head.next = null;
    return newHead;
}
```

头插法

```java
public ListNode reverseList(ListNode head) {
    ListNode newHead = new ListNode(-1);
    while (head != null) {
        ListNode next = head.next;
        head.next = newHead.next;
        newHead.next = head;
        head = next;
    }
    return newHead.next;
}
```

##  3. 归并两个有序的链表

21\. Merge Two Sorted Lists (Easy)

[Leetcode](https://leetcode.com/problems/merge-two-sorted-lists/description/) / [21. 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

```java
public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
    if (l1 == null) return l2;
    if (l2 == null) return l1;
    if (l1.val < l2.val) {
        l1.next = mergeTwoLists(l1.next, l2);
        return l1;
    } else {
        l2.next = mergeTwoLists(l1, l2.next);
        return l2;
    }
}
```

##  4. 从有序链表中删除重复节点

83\. Remove Duplicates from Sorted List (Easy)

[Leetcode](https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/) / [83. 删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)

```html
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
```

```java
public ListNode deleteDuplicates(ListNode head) {
    if (head == null || head.next == null) return head;
    head.next = deleteDuplicates(head.next);
    return head.val == head.next.val ? head.next : head;
}

//来自评论
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        head.next = deleteDuplicates(head.next);
        if(head.val == head.next.val) head = head.next;
        return head;
    }
}
```

##  5. 删除链表的倒数第 n 个节点

19\. Remove Nth Node From End of List (Medium)

[Leetcode](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/) / [19. 删除链表的倒数第 N 个结点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)

```html
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
```

```java
public ListNode removeNthFromEnd(ListNode head, int n) {
    ListNode fast = head;
    while (n-- > 0) {
        fast = fast.next;
    }
    if (fast == null) return head.next;
    ListNode slow = head;
    while (fast.next != null) {
        fast = fast.next;
        slow = slow.next;
    }
    slow.next = slow.next.next;
    return head;
}
```

##  6. 交换链表中的相邻结点

24\. Swap Nodes in Pairs (Medium)

[Leetcode](https://leetcode.com/problems/swap-nodes-in-pairs/description/) / [24. 两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)

```javascript
示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]

示例 2：
输入：head = []
输出：[]

示例 3：
输入：head = [1]
输出：[1]
```

题目要求：不能修改结点的 val 值，O(1) 空间复杂度。

```java
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dum = new ListNode(-1);
        dum.next = head;				//dum.next指向1
        ListNode pre = dum;				//pre指向-1
        //head!=null&&head.next.next!=null	1\3
        while (pre.next != null && pre.next.next != null) {
            ListNode l1 = pre.next;		//1
            ListNode l2 = pre.next.next;//2

            ListNode l3 = l2.next;		//next=3
            l1.next = l3;				//1指向了3
            l2.next = l1;				//2指向了1
            pre.next = l2;				//pre指向了2			现在是   -1	2	1	3
            pre = l1;					//pre步进到1，步进2格	 原本pre是-1		pre
        }
        return dum.next;				//返回的2
    }
}

//递归
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode next = head.next;
        head.next = swapPairs(next.next);
        next.next = head;
        return next;
    }
}
//作者：guanpengchn
//链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs/solution/hua-jie-suan-fa-24-liang-liang-jiao-huan-lian-biao/
```

递归解释

```javascript
例如输入： 
1		2		3			null
head	next	
head.next = 3 	1指向了3
next.next = 1	2指向了1
return next;	也就是2

应该返回：
2	1	3					null
```

##  7. 链表求和

445\. Add Two Numbers II (Medium)

[Leetcode](https://leetcode.com/problems/add-two-numbers-ii/description/) / [445. 两数相加 II](https://leetcode-cn.com/problems/add-two-numbers-ii/)

```html
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。
进阶：如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

解释：7243+564=7807
```

题目要求：不能修改原始链表。

```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        LinkedList<Integer> l1Stack = buildStack(l1);
        LinkedList<Integer> l2Stack = buildStack(l2);
        ListNode dum = new ListNode(-1);
        int carry = 0;
        while (!l1Stack.isEmpty() || !l2Stack.isEmpty() || carry != 0) {
            int x = l1Stack.isEmpty() ? 0 : l1Stack.pop();
            int y = l2Stack.isEmpty() ? 0 : l2Stack.pop();
            
            int sum = x + y + carry;
            carry = sum / 10;
            sum = sum % 10;		  //Modulo 取余
            
            ListNode cur = new ListNode(sum);
            cur.next = dum.next;  //尾插法构建链表，最新的节点在链表头部，需要dum节点。
            dum.next = cur;
        }
        return dum.next;
    }

    private LinkedList<Integer> buildStack(ListNode head) {
        LinkedList<Integer> stack = new LinkedList<>();
        while (head != null) {
            stack.push(head.val);
            head = head.next;
        }
        return stack;
    }
}
```

##  8. 回文链表

234\. Palindrome Linked List (Easy)

[Leetcode](https://leetcode.com/problems/palindrome-linked-list/description/) / [234. 回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/)

```javascript
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true

进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
```

题目要求：以 O(1) 的空间复杂度来求解。

切成两半，把后半段反转，然后比较两半是否相等。

```java
//4ms
class Solution {
    public boolean isPalindrome(ListNode head) {
        //题目可以不加判断AC，但最好加上。
        if (head == null || head.next == null) return true;
        ListNode fast = head, slow = head;
        //通过快慢指针找到中点
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        //如果fast不为空，说明链表的长度是奇数个
        if (fast != null) {
            slow = slow.next;
        }
        //反转后半部分链表
        slow = reverse(slow);

        fast = head;
        while (slow != null) {
            //然后比较，判断节点值是否相等
            if (fast.val != slow.val)
                return false;
            fast = fast.next;
            slow = slow.next;
        }
        return true;
    }

     public ListNode reverse(ListNode head) {
        ListNode cur = head;
        ListNode pre = null;
        while (cur != null) {
            ListNode next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
}
```

扩展：栈的实现

```java
import java.util.Stack;

// 栈实现1
//全存到栈里，反向遍历与正向遍历比对。
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode cur = head;
        Stack<Integer> stack = new Stack();
        while (cur != null) {		//把链表节点的值全依次存放到栈中
            stack.push(cur.val);
            cur = cur.next;
        }
        while (head != null) {		 //然后再出栈，比较。
            if (head.val != stack.pop()) return false;
            head = head.next;
        }
        return true;
    }
}

// 栈实现2
// 优化栈实现1，其实我们只需要拿链表的后半部分和前半部分比较即可。
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null) return true;
        ListNode cur = head;
        Stack<Integer> stack = new Stack();
        int len = 0;				//链表的长度
        while (cur != null) {		//把链表节点的值存放到栈中
            stack.push(cur.val);
            cur = cur.next;
            len++;
        }
        len >>= 1;					//len长度除以2
        while (len-- >= 0) {		//然后再出栈
            if (head.val != stack.pop()) return false;
            head = head.next;
        }
        return true;
    }
}
```

扩展：递归实现

```java
class Solution {
    ListNode tem;	// 注意是全局变量
    public boolean isPalindrome(ListNode head) {
        tem = head;
        return check(head);
    }
    private boolean check(ListNode head) {
        if (head == null) return true;	
        boolean res = check(head.next) && (tem.val == head.val);
        tem = tem.next;
        return res;
    }
}

class Solution {
    private ListNode frontPointer;
    
    public boolean isPalindrome(ListNode head) {
        frontPointer = head;
        return recursivelyCheck(head);
    }
    private boolean recursivelyCheck(ListNode currentNode) {
        if (currentNode != null) {
            if (!recursivelyCheck(currentNode.next)) {
                return false;
            }
            if (currentNode.val != frontPointer.val) {
                return false;
            }
            frontPointer = frontPointer.next;
        }
        return true;
    }
}
//作者：LeetCode-Solution
//链接：https://leetcode-cn.com/problems/palindrome-linked-list/solution/hui-wen-lian-biao-by-leetcode-solution/
```

##  9. 分隔链表

725\. Split Linked List in Parts(Medium)

[Leetcode](https://leetcode.com/problems/split-linked-list-in-parts/description/) / [725. 分隔链表](https://leetcode-cn.com/problems/split-linked-list-in-parts/)

```javascript
给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。
每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。
这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。
返回一个符合上述规则的链表的列表。
举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]

示例 1：

输入: 
root = [1, 2, 3], k = 5
输出: [[1],[2],[3],[],[]]
解释:
输入输出各部分都应该是链表，而不是数组。
例如, 输入的结点 root 的 val= 1, root.next.val = 2, \root.next.next.val = 3, 且 root.next.next.next = null。
第一个输出 output[0] 是 output[0].val = 1, output[0].next = null。
最后一个元素 output[4] 为 null, 它代表了最后一个部分为空链表。

示例 2：

输入: 
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
输出: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
解释:
输入被分成了几个连续的部分，并且每部分的长度相差不超过1.前面部分的长度大于等于后面部分的长度。
 
提示:
root 的长度范围： [0, 1000].
输入的每个节点的大小范围：[0, 999].
k 的取值范围： [1, 50].
```

题目描述：把链表分隔成 k 部分，每部分的长度都应该尽可能相同，排在前面的长度应该大于等于后面的。

```java
public ListNode[] splitListToParts(ListNode root, int k) {
    int N = 0;				
    ListNode cur = root;
    while (cur != null) {	//求下链表长度 N
        N++;
        cur = cur.next;
    }
    int mod = N % k;		//10%3=1
    int size = N / k;		//10/3=3
    ListNode[] ret = new ListNode[k];
    cur = root;
    for (int i = 0; cur != null && i < k; i++) {
        ret[i] = cur;
        int curSize = size + (mod-- > 0 ? 1 : 0); // 3+1=4	3+0=3
        for (int j = 0; j < curSize - 1; j++) {
            cur = cur.next;// cur=4
        }
        ListNode next = cur.next;//next=5	缓存一下
        cur.next = null;		 //断开链表
        cur = next;				 //和缓存对接
    }
    return ret;
}
```

##  10. 链表元素按奇偶聚集

328\. Odd Even Linked List (Medium)

[Leetcode](https://leetcode.com/problems/odd-even-linked-list/description/) / [328. 奇偶链表](https://leetcode-cn.com/problems/odd-even-linked-list/)

```javascript
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。
你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(N)，N为节点总数。

示例 1:
输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL

示例 2:
输入: 2->1->3->5->6->4->7->NULL 
输出: 2->3->6->7->1->5->4->NULL

说明:
应当保持奇数节点和偶数节点的相对顺序。
链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
```

题目描述：

将奇数位置的结点放在链表前段，偶数位置的结点放在链表后段。要求空间复杂度 O(1), 时间复杂度 O(n)。

思路：

分别定义奇偶链表；

遍历原链表，将当前结点交替插入到奇链表和偶链表（尾插法）；

将偶链表拼接在奇链表后面。

```java
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null) return head;		//不加能过，最好加上。
        ListNode jHead = new ListNode();	//分别定义奇偶链表的 虚拟头结点
        ListNode oHead = new ListNode();
        ListNode curJ = jHead;				//虚拟头结点不动，使用cur来移动。
        ListNode curO = oHead;
        boolean isJ = true;
        while (head != null) {
            if (isJ) {
                curJ.next = head;		 	//尾插法
                curJ = curJ.next;
            } else {
                curO.next = head;
                curO = curO.next;
            }
            head = head.next;
            isJ = !isJ;
        }
        curJ.next = oHead.next;				//奇链表后面拼接上偶链表
        curO.next = null;					//偶链表的next设置为null
        return jHead.next;
    }
}
```

其他写法

```java
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null) return head;
        ListNode oHead = head.next;			//缓存下偶数编号的头
        ListNode curJ = head;				//奇头	odd number	奇数
        ListNode curO = oHead;				//偶头	even		偶数
        while (curO != null && curO.next != null) {
            curJ.next = curO.next;//奇
            curJ = curJ.next;

            curO.next = curJ.next;//偶
            curO = curO.next;
        }
        curJ.next = oHead;
        return head;
    }
}
//图解：https://leetcode-cn.com/problems/odd-even-linked-list/solution/qi-ou-lian-biao-by-leetcode-solution/
```

## todo

困难：[23. 合并K个升序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)

```java
给你一个链表数组，每个链表都已经按升序排列。请你将所有链表合并到一个升序链表中，返回合并后的链表。

示例 1：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
    
示例 2：
输入：lists = []
输出：[]
    
示例 3：
输入：lists = [[]]
输出：[]

提示：
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] 按 升序 排列
lists[i].length 的总和不超过 10^4
```

