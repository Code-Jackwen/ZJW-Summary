# Leetcode 题解 - 双指针
<!-- GFM-TOC -->
* [Leetcode 题解 - 双指针](#leetcode-题解---双指针)
    * [1. 有序数组的 Two Sum](#1-有序数组的-two-sum)
    * [2. 两数平方和](#2-两数平方和)
    * [3. 反转字符串中的元音字符](#3-反转字符串中的元音字符)
    * [4. 回文字符串](#4-回文字符串)
    * [5. 归并两个有序数组](#5-归并两个有序数组)
    * [6. 判断链表是否存在环](#6-判断链表是否存在环)
    * [7. 最长子序列](#7-最长子序列)
<!-- GFM-TOC -->


双指针主要用于遍历数组，两个指针指向不同的元素，从而协同完成任务。

## 1. 有序数组的 Two Sum

167\. Two Sum II - Input array is sorted (Easy)

[Leetcode](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/) / [167. 两数之和 II - 输入有序数组](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)

```html
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
```

题目描述：在有序数组中找出两个数，使它们的和为 target。

使用双指针，一个指针指向值较小的元素，一个指针指向值较大的元素。指向较小元素的指针从头向尾遍历，指向较大元素的指针从尾向头遍历。

- 如果两个指针指向元素的和 sum == target，那么得到要求的结果；
- 如果 sum \> target，移动较大的元素，使 sum 变小一些；
- 如果 sum \< target，移动较小的元素，使 sum 变大一些。

数组中的元素最多遍历一次，时间复杂度为 O(N)。只使用了两个额外变量，空间复杂度为  O(1)。

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/437cb54c-5970-4ba9-b2ef-2541f7d6c81e.gif" width="200px"> </div><br>
```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        if (numbers == null) return null;
        int i = 0, j = numbers.length - 1;
        while (i <= j) {							//等号加不加都可以
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return new int[]{i + 1, j + 1};
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return null;
    }
}
```

## 2. 两数平方和

633\. Sum of Square Numbers (Easy)

[Leetcode](https://leetcode.com/problems/sum-of-square-numbers/description/) / [633. 平方数之和](https://leetcode-cn.com/problems/sum-of-square-numbers/)

```html
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。

示例 1：
输入：c = 5
输出：true
解释：1 * 1 + 2 * 2 = 5

示例 2：
输入：c = 3
输出：false

示例 3：
输入：c = 1
输出：true

提示：0 <= c <= 231 - 1
```

题目描述：判断一个非负整数是否为两个整数的平方和。

可以看成是在元素为 0\~target 的有序数组中查找两个数，使得这两个数的平方和为 target，如果能找到，则返回 true，表示 target 是两个整数的平方和。

本题和 167\. Two Sum II - Input array is sorted 类似，只有一个明显区别：一个是和为 target，一个是平方和为 target。本题同样可以使用双指针得到两个数，使其平方和为 target。

本题的关键是右指针的初始化，实现剪枝，从而降低时间复杂度。设右指针为 x，左指针固定为 0，为了使 0<sup>2</sup> + x<sup>2</sup> 的值尽可能接近 target，我们可以将 x 取为 sqrt(target)。

因为最多只需要遍历一次 0\~sqrt(target)，所以时间复杂度为 O(sqrt(target))。又因为只使用了两个额外的变量，因此空间复杂度为 O(1)。

```java
class Solution {
    public boolean judgeSquareSum(int target) {
        if (target < 0) return false;
        int i = 0, j = (int) Math.sqrt(target);		//注意j的初始化
        while (i <= j) {							//必须等号
            int powSum = i * i + j * j;
            if (powSum == target) {
                return true;
            } else if (powSum > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
}
```

## 3. 反转字符串中的元音字符

345\. Reverse Vowels of a String (Easy)

[Leetcode](https://leetcode.com/problems/reverse-vowels-of-a-string/description/) / [345. 反转字符串中的元音字母](https://leetcode-cn.com/problems/reverse-vowels-of-a-string/)

```html
编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
示例 1：
输入："hello"
输出："holle"

示例 2：
输入："leetcode"
输出："leotcede"
提示：元音字母不包含字母 "y" 。
```

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/a7cb8423-895d-4975-8ef8-662a0029c772.png" width="400px"> </div><br>
使用双指针，一个指针从头向尾遍历，一个指针从尾到头遍历，当两个指针都遍历到元音字符时，交换这两个元音字符。

为了快速判断一个字符是不是元音字符，我们将全部元音字符添加到集合 HashSet 中，从而以 O(1) 的时间复杂度进行该操作。

- 时间复杂度为 O(N)：只需要遍历所有元素一次
- 空间复杂度 O(1)：只需要使用两个额外变量

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/ef25ff7c-0f63-420d-8b30-eafbeea35d11.gif" width="400px"> </div><br>
```java
class Solution {
    private final static HashSet<Character> set = new HashSet<>(
     Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));

    public String reverseVowels(String s) {
        if (s == null) return null;
        int i = 0, j = s.length() - 1;
        char[] ret = new char[s.length()];
        while (i <= j) {					//=不能去掉
            char ci = s.charAt(i);
            char cj = s.charAt(j);
            if (!set.contains(ci)) {
                ret[i++] = ci;
            } else if (!set.contains(cj)) {
                ret[j--] = cj;
            } else {
                ret[i++] = cj;
                ret[j--] = ci;
            }
        }
        return new String(ret);
    }
}
```

## 4. 回文字符串

680\. Valid Palindrome II (Easy)

[Leetcode](https://leetcode.com/problems/valid-palindrome-ii/description/) / [680. 验证回文字符串 Ⅱ](https://leetcode-cn.com/problems/valid-palindrome-ii/)

```js
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:
输入: "aba"
输出: True

示例 2:
输入: "abca"
输出: True

解释: 你可以删除c字符。
注意:字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
```

题目描述：可以删除一个字符，判断是否能构成回文字符串。

所谓的回文字符串，是指具有左右对称特点的字符串，例如 "abcba" 就是一个回文字符串。

使用双指针可以很容易判断一个字符串是否是回文字符串：令一个指针从左到右遍历，一个指针从右到左遍历，这两个指针同时移动一个位置，每次都判断两个指针指向的字符是否相同，如果都相同，字符串才是具有左右对称性质的回文字符串。

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/fcc941ec-134b-4dcd-bc86-1702fd305300.gif" width="250px"> </div><br>
本题的关键是处理删除一个字符。在使用双指针遍历字符串时，如果出现两个指针指向的字符不相等的情况，我们就试着删除一个字符，再判断删除完之后的字符串是否是回文字符串。

在判断是否为回文字符串时，我们不需要判断整个字符串，因为左指针左边和右指针右边的字符之前已经判断过具有对称性质，所以只需要判断中间的子字符串即可。

在试着删除字符时，我们既可以删除左指针指向的字符，也可以删除右指针指向的字符。

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/db5f30a7-8bfa-4ecc-ab5d-747c77818964.gif" width="300px"> </div><br>
```java
class Solution {
    public boolean validPalindrome(String s) {
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            if (s.charAt(i) != s.charAt(j)) {
                return isPalindrome(s, i, j - 1) || isPalindrome(s, i + 1, j);
            }
        }
        return true;
    }

    private boolean isPalindrome(String s, int i, int j) {
        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) {
                return false;
            }
        }
        return true;
    }
}
```

## 5. 归并两个有序数组

88\. Merge Sorted Array (Easy)

[Leetcode](https://leetcode.com/problems/merge-sorted-array/description/) / [88. 合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array/)

```html
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。

示例 1：
输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]

示例 2：
输入：nums1 = [1], m = 1, nums2 = [], n = 0
输出：[1]
 
提示：
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[i] <= 109
```

题目描述：把归并结果存到第一个数组上。

需要从尾开始遍历，否则在 nums1 上归并得到的值会覆盖还未进行归并比较的值。

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int idx1 = m - 1, idx2 = n - 1;
        int p = m + n - 1;
        while (idx1 >= 0 || idx2 >= 0) {
            if (idx1 < 0) {
                nums1[p--] = nums2[idx2--];
            } else if (idx2 < 0) {
                nums1[p--] = nums1[idx1--];
            } else if (nums1[idx1] > nums2[idx2]) {
                nums1[p--] = nums1[idx1--];
            } else {
                nums1[p--] = nums2[idx2--];
            }
        }
    }
}
```

## 6. 判断链表是否存在环

141\. Linked List Cycle (Easy)

[Leetcode](https://leetcode.com/problems/linked-list-cycle/description/) / [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)

使用双指针，一个指针每次移动一个节点，一个指针每次移动两个节点，如果存在环，那么这两个指针一定会相遇。

```java
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {	//head.next == null不加能过，最好加。
            return false;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        while (slow != fast) {
            if (fast == null || fast.next == null) {
                return false;
            }
            slow = slow.next;
            fast = fast.next.next;
        }
        return true;
    }
}
```

## 7. 最长子序列

524\. Longest Word in Dictionary through Deleting (Medium)

[Leetcode](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/) / [524. 通过删除字母匹配到字典里最长单词](https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/)

```js
给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。
如果答案不止一个，返回长度最长且字典顺序最小的字符串。
如果答案不存在，则返回空字符串。

示例 1:
输入:
s = "abpcplea", d = ["ale","apple","monkey","plea"]
输出: "apple"

示例 2:
输入:
s = "abpcplea", d = ["a","b","c"]
输出: "a"

说明:所有输入的字符串只包含小写字母。字典的大小不会超过 1000。所有输入的字符串长度不会超过 1000。
```

题目描述：删除 s 中的一些字符，使得它构成字符串列表 d 中的一个字符串，找出能构成的最长字符串。如果有多个相同长度的结果，返回字典序的最小字符串。

通过删除字符串 s 中的一个字符能得到字符串 t，可以认为 t 是 s 的子序列，我们可以使用双指针来判断一个字符串是否为另一个字符串的子序列。

暴力加剪枝。

```java
class Solution {
    public String findLongestWord(String s, List<String> dic) {
        String longestWord = "";		//处理答案不存在返回空串
        for (String d : dic) {
            int lstLen = longestWord.length();
            int curLen = d.length();
            // 首先判断一波是否可以进行判断，如果是长度不够或者长度相等字典序大的直接剪枝
            // 如果之前单词匹配到的长度比当前遍历到的单词都长，直接跳过当前单词。
            // 如果之前单词匹配到的长度和当前遍历到的单词一样长，但是当前单词的字典序靠后，跳过。
            if (lstLen > curLen || (lstLen == curLen && longestWord.compareTo(d) < 0)) {
                continue;
            }
            if (isSubstr(s, d)) {
                longestWord = d;		//单词能全部匹配上，就更新下最长单词。
            }
        }
        return longestWord;
    }

    private boolean isSubstr(String s, String d) {
        int i = 0, j = 0;	 // 双指针判断target是否是s的子序列
        while (i < s.length() && j < d.length()) {
            if (s.charAt(i) == d.charAt(j)) {
                j++;
            }
            i++;
        }
        return j == d.length();
    }
}
```
