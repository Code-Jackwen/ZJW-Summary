# Leetcode 题解 - 树 - 进阶

* [BST](#bst)
  * [1. 修剪二叉查找树](#1-修剪二叉查找树)
  * [2. 寻找二叉查找树的第 k 个元素](#2-寻找二叉查找树的第-k-个元素)
  * [3. 把二叉查找树每个节点的值都加上比它大的节点的值](#3-把二叉查找树每个节点的值都加上比它大的节点的值)
  * [4. 二叉查找树的最近公共祖先](#4-二叉查找树的最近公共祖先)
  * [5. 二叉树的最近公共祖先](#5-二叉树的最近公共祖先)
  * [6. 从有序数组中构造二叉查找树](#6-从有序数组中构造二叉查找树)
  * [7. 根据有序链表构造平衡的二叉查找树](#7-根据有序链表构造平衡的二叉查找树)
  * [8. 在二叉查找树中寻找两个节点，使它们的和为一个给定值](#8-在二叉查找树中寻找两个节点，使它们的和为一个给定值)
  * [9. 在二叉查找树中查找两个节点之差的最小绝对值](#9-在二叉查找树中查找两个节点之差的最小绝对值)
  * [10. 寻找二叉查找树中出现次数最多的值](#10-寻找二叉查找树中出现次数最多的值)
* [Trie](#trie)
  * [1. 实现一个 Trie](#1-实现一个-trie)
  * [2. 实现一个 Trie，用来求前缀和](#2-实现一个-trie，用来求前缀和)

## BST

二叉查找树（BST）：左孩子 <= 根节点 <= 右孩子。二叉查找树中序遍历有序。

### 1. 修剪 - BST

简单： [669. 修剪二叉搜索树](https://leetcode-cn.com/problems/trim-a-binary-search-tree/)

```
输入BST和两个边界值，修剪BST使得边界以外的节点都删除掉，返回新的根节点，根节点可能会因删减发生改变。
```

<img src="../../../ZJW-Summary/assets/1619186148844.png" alt="1619186148844" style="zoom:50%;" />

解题方法：迭代，非队列。改变头节点的指针。[三种解法：递归，迭代，DFS - 修剪二叉搜索树 ](https://leetcode-cn.com/problems/trim-a-binary-search-tree/solution/san-chong-jie-fa-di-gui-die-dai-dfs-by-r-ikyk/) 

```java
public TreeNode trimBST(TreeNode root, int low, int high) {		//普通迭代：0ms、100%
    if (root == null) return root;								
    while (root != null && (root.val > high || root.val < low)) //必须判空
        root = root.val > high ? root.left : root.right;		//先找修剪后的头节点
    TreeNode cur = root;    
    while (cur != null) {   //操作头的左儿子，将小于low的节点排除掉
        while (cur.left != null && cur.left.val < low) 
            cur.left = cur.left.right;
        cur = cur.left;
    }
    cur = root;     		
    while (cur != null) {   //操作头的右儿子，将大于high的节点排除掉
        while (cur.right != null && cur.right.val > high)
            cur.right = cur.right.left;
        cur = cur.right;
    }
    return root;
}
```

```java
public TreeNode trimBST(TreeNode root, int l, int h) {	//官解
    if (root == null) return null;						//下边限制遍历的方向
    if (root.val < l) return trimBST(root.right, l, h); //将修剪后的右子树替换当前节点并返回
    if (root.val > h) return trimBST(root.left, l, h);	//将修剪后的左子树替换当前节点并返回
    root.left = trimBST(root.left, l, h);				//数字在区间内，两边寻找第一个越界的结点
    root.right = trimBST(root.right, l, h);
    return root;
}
```

```java
public TreeNode trimBST(TreeNode root, int low, int high) {	//官解改编，为了透漏思路
    if (root == null) return null;							//递归
    if (root.val < low) {
        root = root.right;
        root = trimBST(root, low, high);
    } else if (root.val > high) {
        root = root.left;
        root = trimBST(root, low, high);
    } else {
        root.left = trimBST(root.left, low, high);
        root.right = trimBST(root.right, low, high);
    }
    return root;
}
```

### 2. BST - 第 k 小的元素

中等：[230. 二叉搜索树中第K小的元素](https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/)

```java
private int cnt = 0;
private int val;
public int kthSmallest(TreeNode root, int k) {		//中序遍历
    inOrder(root, k);								//k=1,就是返回最小的
    return val;
}
private void inOrder(TreeNode node, int k) {
    if (node == null) return;
    inOrder(node.left, k);
    cnt++;											//遍历到底之后开始算起
    if (cnt == k) {
        val = node.val;
        return;
    }
    inOrder(node.right, k);
}
```

分治解法：类似于二分查找，需要**先计算左子树的节点个数**，记为 n，然后有三种情况。

- n 加 1 等于 k，那就说明当前根节点就是我们要找的。

- n 加 1 小于 k，那就说明第 k 小的数一定在右子树中，只需要递归的在右子树中寻找第 k - n - 1 小的数即可。

- n 加 1 大于 k，那就说明第 k 小个数一定在左子树中，我们只需要递归的在左子树中寻找第 k 小的数即可。

```java
public int kthSmallest(TreeNode root, int k) {//总共20个节点吧，0ms、100%
    int cnt = nodeCount(root.left);		//cnt:9			右边有10个
    if (cnt + 1 == k) return root.val;			
    else if (cnt + 1 < k) 				//10 < k=12
        return kthSmallest(root.right, k - cnt - 1);//10 < k=12，12-9-1=2
    return kthSmallest(root.left, k);
}
int nodeCount(TreeNode root) {
    if (root == null) return 0;
    return 1 + nodeCount(root.left) + nodeCount(root.right);
}
```

### 3. 累加树 - BST

简单：[538. 把二叉搜索树转换为累加树](https://leetcode-cn.com/problems/convert-bst-to-greater-tree/)

```js
输入：         5					输出：      18
            /   \						    /   \
           2     13					      20     13
```

```java
private int sum = 0;
public TreeNode convertBST(TreeNode root) {
    traver(root);
    return root;
}
void traver(TreeNode node) {
    if (node == null) return;
    traver(node.right);			//先遍历右子树。
    sum += node.val;
    node.val = sum;
    traver(node.left);
}
```

### 4. BST - 最近公共祖先

简单：[235. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

```java
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if (root.val > p.val && root.val > q.val) 
        return lowestCommonAncestor(root.left, p, q);
    if (root.val < p.val && root.val < q.val) 
        return lowestCommonAncestor(root.right, p, q);
    return root;
}
```

### 5. BT - 最近公共祖先

中等：[236. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)

```java
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    if(root == null || root == p || root == q) return root;		//后序遍历
    TreeNode left = lowestCommonAncestor(root.left, p, q);
    TreeNode right = lowestCommonAncestor(root.right, p, q);
    if(left == null && right == null) return null; // 1.
    if(left == null) return right; // 3.
    if(right == null) return left; // 4.
    return root; // 2. if(left != null and right != null)

    //1合并到3、4
    //if(left == null) return right;
    //if(right == null) return left;
    //return root;
    //也可以再合并
    //return left == null ? right : right == null ? left : root;
}
```

### 6. 有序数组构造 - BST

简单：[108. 将有序数组转换为二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)

有序数组转换为**高度平衡二叉树**，要求每个节点的左右两个子树的高度差的绝对值不超过 1 。

```java
public TreeNode sortedArrayToBST(int[] nums) {
    return dfs(nums, 0, nums.length - 1);
}
TreeNode dfs(int[] nums, int l, int h) {
    if (l > h) return null;
    int mid = l + (h - l) / 2;				
    TreeNode root = new TreeNode(nums[mid]);// 以升序数组的中间元素作为根节点 root。
    root.left = dfs(nums, l, mid - 1);		// 递归的构建 root 的左子树与右子树。
    root.right = dfs(nums, mid + 1, h);
    return root;
}
```

### 7. 有序链表构造 - BST

中等： [109. 有序链表转换二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)

有序链表转换为**高度平衡二叉树**，要求每个节点的左右两个子树的高度差的绝对值不超过 1 。

```java
public TreeNode sortedListToBST(ListNode head) {
    if (head == null) return null;
    if (head.next == null) return new TreeNode(head.val);
    ListNode s = head, f = head, preMid = null;	//快慢指针找中心节点
    while (f != null && f.next != null) {		//用快指针判断前后双null
        preMid = s;								//preMid指向中点前个节点
        s = s.next;
        f = f.next.next;
    }
    preMid.next = null;							//断开链表
    TreeNode root = new TreeNode(s.val);		//升序链表的中间元素作为根节点
    root.left = sortedListToBST(head);			//构建 root 的左子树
    root.right = sortedListToBST(s.next);		//构建 root 的右子树
    return root;
}
```

基础题目：[876. 链表的中间结点](https://leetcode-cn.com/problems/middle-of-the-linked-list/)

```js
找出链表的中间节点，例如，输入：[1,2,3,4,5,6]	输出：4 有两个中间结点，3 和 4，返回第二个结点。
```

```java
ListNode middleNode(ListNode head) {
    ListNode slow = head, fast = head;
    while (fast != null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    return slow;
}
```

### 8. 两数之和 - BST

简单：[653. 两数之和 IV - 输入 BST](https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/)

```html
    5		k = 9，输出: True
   / \
  3   6
 / \   \
2   4   7
```

应该注意到，这一题不能用分别在左右子树两部分来处理这种思想，因为两个待求的节点可能分别在左右子树中。

```java
public boolean findTarget(TreeNode root, int k) {	//中序遍历+集合+双指针
    List<Integer> nums = new ArrayList<>();
    inOrder(root, nums);							//中序遍历存储所有节点到集合中
    int i = 0, j = nums.size() - 1;
    while (i < j) {									//双指针操作有序集合找两数之和
        int sum = nums.get(i) + nums.get(j);
        if (sum == k) return true;
        if (sum < k) i++;
        else j--;
    }
    return false;
}
void inOrder(TreeNode root, List<Integer> nums) {
    if (root == null) return;
    inOrder(root.left, nums);
    nums.add(root.val);
    inOrder(root.right, nums);
}
```

```java
public boolean findTarget(TreeNode root, int k) {	   //BFS + HashSet
    Set<Integer> set = new HashSet();
    LinkedList<TreeNode> queue = new LinkedList();
    queue.add(root);
    while (!queue.isEmpty()) {
        TreeNode node = queue.remove();
        if (set.contains(k - node.val)) return true;
        set.add(node.val);
        if (node.left != null) queue.add(node.left);	//先放左还是右都可以
        if (node.right != null) queue.add(node.right); 
    }
    return false;
}
```

```java
public boolean findTarget(TreeNode root, int k) {		//先序遍历 + Set
    Set<Integer> set = new HashSet();
    return find(root, k, set);
}
boolean find(TreeNode root, int k, Set<Integer> set) {
    if (root == null) return false;
    if (set.contains(k - root.val)) return true;
    set.add(root.val);
    return find(root.left, k, set) || find(root.right, k, set);
}
```

### 9. BST - 两个节点之差的最小绝对值

简单： [530. 二叉搜索树的最小绝对差](https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/)

利用二叉查找树的中序遍历为有序的性质，**计算中序遍历中临近的两个节点之差的绝对值，取最小值。**

```java
private int minDiff = Integer.MAX_VALUE;					//存储结果
private TreeNode preNode = null;							//全局缓存下上一个遍历到的节点
public int getMinimumDifference(TreeNode root) {			//中序遍历
    inOrder(root);
    return minDiff;
}
void inOrder(TreeNode node) {
    if (node == null) return;
    inOrder(node.left);			
    if (preNode != null) minDiff = Math.min(minDiff, node.val - preNode.val);
    preNode = node;
    inOrder(node.right);
}
```

### 10. BST - 众数

简单： [501. 二叉搜索树中的众数](https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/)

```java
      1			BST 考虑在寻找出现次数最多的数时，不使用哈希表。 
    /   \		因为中序遍历结果：{−1,0,0,1,2,2}中，重复出现的数字一定连续出现的，例如0和2
   0     2		只需用一个 滚动变量就可以了
  / \    /
-1   0  2
```

```java
private int curCnt = 1;			//如果众数超过1个，全部输出不考虑顺序。
private int maxCnt = 1;
private TreeNode preNode = null;//前指针，需要指向中序遍历的前一个较小的节点

public int[] findMode(TreeNode root) {
    List<Integer> maxCntNums = new ArrayList<>();
    inOrder(root, maxCntNums);					//核心处理函数
    int[] ret = new int[maxCntNums.size()];		//集合转数组	
    int idx = 0;
    for (int num : maxCntNums) ret[idx++] = num;
    return ret;
}

void inOrder(TreeNode node, List<Integer> nums) {
    if (node == null) return;
    
    inOrder(node.left, nums);					//必须中序遍历
    
    if (preNode != null) {						//因为初始值为null，注意判断null
        if (preNode.val == node.val) curCnt++;  //累加一个连续相同出现的数的次数
        else curCnt = 1;						//出现间断置位1
    }
    if (curCnt > maxCnt) {
        maxCnt = curCnt;						//更新众数的最值
        nums.clear();							//清空之前同的相同频率众数集合
        nums.add(node.val);						//加入新的更高频率的众数
    } else if (curCnt == maxCnt) {				//如果出现频率相同的众数，那就添加到众数集合
        nums.add(node.val);
    }
    preNode = node;								//更新下滚动变量
    
    inOrder(node.right, nums);
}
```

### 11. 由前序遍历构造 - BST

中等：[1008. 前序遍历构造二叉搜索树](https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal/)

```js
输入BST前序遍历结果：[8,5,1,7,10,12]		输出原本的BST：[8,5,10,1,7,null,12]
```

<img src="../../../ZJW-Summary/assets/1623235345111.png" alt="1623235345111" style="zoom:67%;" />

```java
private int idx = 0;								  //官解之一：双O(N)
private int[] preorder;								  //解法：先序遍历+上下界限制
private int len;

public TreeNode bstFromPreorder(int[] preorder) {
    this.preorder = preorder;
    this.len = preorder.length;
    return dfs(Integer.MIN_VALUE, Integer.MAX_VALUE); //dfs并传递左右边界的值
}

private TreeNode dfs(int low, int high) {//通过下限和上限来控制指针移动的范围
    if (idx == len) return null;					  //添加完毕
    int cur = preorder[idx];
    if (cur < low || cur > high) return null;
    idx++;
    TreeNode root = new TreeNode(cur);
    root.left = dfs(low, cur);
    root.right = dfs(cur, high);
    return root;
}
```



