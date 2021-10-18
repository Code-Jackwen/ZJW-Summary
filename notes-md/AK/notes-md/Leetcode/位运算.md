# Leetcode 题解 - 位运算
<!-- GFM-TOC -->
* [Leetcode 题解 - 位运算](#leetcode-题解---位运算)
    * [0. 原理](#0-原理)
    * [1. 统计两个数的二进制表示有多少位不同](#1-统计两个数的二进制表示有多少位不同)
    * [2. 数组中唯一一个不重复的元素](#2-数组中唯一一个不重复的元素)
    * [3. 找出数组中缺失的那个数](#3-找出数组中缺失的那个数)
    * [4. 数组中不重复的两个元素](#4-数组中不重复的两个元素)
    * [5. 翻转一个数的比特位](#5-翻转一个数的比特位)
    * [6. 不用额外变量交换两个整数](#6-不用额外变量交换两个整数)
    * [7. 判断一个数是不是 2 的 n 次方](#7-判断一个数是不是-2-的-n-次方)
    * [8.  判断一个数是不是 4 的 n 次方](#8--判断一个数是不是-4-的-n-次方)
    * [9. 判断一个数的位级表示是否不会出现连续的 0 和 1](#9-判断一个数的位级表示是否不会出现连续的-0-和-1)
    * [10. 求一个数的补码](#10-求一个数的补码)
    * [11. 实现整数的加法](#11-实现整数的加法)
    * [12. 字符串数组最大乘积](#12-字符串数组最大乘积)
    * [13. 统计从 0 \~ n 每个数的二进制表示中 1 的个数](#13-统计从-0-\~-n-每个数的二进制表示中-1-的个数)
<!-- GFM-TOC -->

**基本原理** 

0s 表示一串 0，1s 表示一串 1。

```
x ^ 0s = x      x & 0s = 0      x | 0s = x
x ^ 1s = ~x     x & 1s = x      x | 1s = 1s
x ^ x = 0       x & x = x       x | x = x
```

利用 x ^ 1s = \~x 的特点，可以将一个数的位级表示翻转；利用 x ^ x = 0 的特点，可以将三个数中重复的两个数去除，只留下另一个数。

```
1^1^2 = 2
```

利用 x & 0s = 0 和 x & 1s = x 的特点，可以实现**掩码操作**。一个数 num 与 mask：00111100 进行位与操作，只保留 num 中与 mask 的 1 部分相对应的位。

```
01011011 &
00111100
--------
00011000
```

利用 x | 0s = x 和 x | 1s = 1s 的特点，可以实现设值操作。一个数 num 与 mask：00111100 进行位或操作，将 num 中与 mask 的 1 部分相对应的位都设置为 1。

```
01011011 |
00111100
--------
01111111
```

**位与运算技巧** 

n&(n-1) 去除 n 的位级表示中最低的那一位 1。例如对于二进制表示 01011011，减去 1 得到 01011010，这两个数相与得到 01011010。

```
01011011 &
01011010
--------
01011010
```

n&(-n) 得到 n 的位级表示中最低的那一位 1。-n 得到 n 的反码加 1，也就是 -n=\~n+1。

例如对于二进制表示 10110100，-n 得到 01001100，相与得到 00000100。

```
10110100 &
01001100
--------
00000100
```

n-(n&(-n)) 则可以去除 n 的位级表示中最低的那一位 1，和 n&(n-1) 效果一样。

**移位运算** 

\>\> n 为算术右移，相当于除以 2n，例如 -7 \>\> 2 = -2。

```
11111111111111111111111111111001  >> 2
--------
11111111111111111111111111111110
```

\>\>\> n 为无符号右移，左边会补上 0。例如 -7 \>\>\> 2 = 1073741822。

```
11111111111111111111111111111001  >>> 2
--------
00111111111111111111111111111111
```

\<\< n 为算术左移，相当于乘以 2n。-7 \<\< 2 = -28。

```
11111111111111111111111111111001  << 2
--------
11111111111111111111111111100100
```

**mask 计算** 

要获取 111111111，将 0 取反即可，\~0。

要得到只有第 i 位为 1 的 mask，将 1 向左移动 i-1 位即可，1\<\<(i-1) 。例如 1\<\<4 得到只有第 5 位为 1 的 mask ：00010000。

要得到 1 到 i 位为 1 的 mask，(1\<\<i)-1 即可，例如将 (1\<\<4)-1 = 00010000-1 = 00001111。

要得到 1 到 i 位为 0 的 mask，只需将 1 到 i 位为 1 的 mask 取反，即 \~((1\<\<i)-1)。

**Java 中的位操作**  

```java
static int Integer.bitCount();           // 统计 1 的数量
static int Integer.highestOneBit();      // 获得最高位
static String toBinaryString(int i);     // 转换为二进制表示的字符串
```

## 1. 两数有多少位不同

简单： [461. 汉明距离](https://leetcode-cn.com/problems/hamming-distance/)

```html
输入: x = 1, y = 4	输出: 2	解释：1   (0 0 0 1)，4   (0 1 0 0)
```

```java
public int hammingDistance(int x, int y) {
    int z = x ^ y;				//z为1的位是x和y不同的位
    int cnt = 0;
    while(z != 0) {
        if ((z & 1) == 1) cnt++;//统计z有多少个 1 即可。
        z = z >> 1;
    }
    return cnt;
}
```

```java
public int hammingDistance(int x, int y) {
    int z = x ^ y;
    int cnt = 0;
    while (z != 0) {
        z &= (z - 1);			//使用 z&(z-1) 去除 z 位级表示最低的那一位。
        cnt++;
    }
    return cnt;
}
```

```java
public int hammingDistance(int x, int y) {
    return Integer.bitCount(x ^ y);	//使用 Integer.bitcount() 来统计数中 1 的个数。
}
```

```c++
int hammingDistance(int x, int y) { return __builtin_popcount(x ^ y); }
```

## 2. 只出现一次的数

简单：[[136. 只出现一次的数字](https://leetcode-cn.com/problems/single-number/)](https://leetcode-cn.com/problems/single-number/description/)

```html
Input: [4,1,2,1,2]	Output: 4		要求：线性时间复杂度，不使用额外空间
```

两个相同的数异或的结果为 0，对所有数进行异或操作，最后的结果就是单独出现的那个数。

```java
public int singleNumber(int[] nums) {
    int ret = 0;
    for (int n : nums) ret = ret ^ n;
    return ret;
}
```

## 3. 找出数组中缺失的数

简单：[268. 丢失的数字](https://leetcode-cn.com/problems/missing-number/)

```javascript
数组元素在 0-n 之间，找到 nums 缺失的那个数。不存在负数。数组不一定有序。要求：线性时间、常数空间。
输入：nums = [9,6,4,2,3,5,7,0,1] 输出：8 解释：n = 9	  输入：nums = [0,1] 输出：2 解释：n = 2	
```

位运算解法，不存在 int[] nums ={50,51,48,52}; 这样的用例。时间：O(N)，空间：O(1)，思路，看下边例子。

| 下标 | 0    | 1    | 2    | 3    |
| ---- | ---- | ---- | ---- | ---- |
| 数字 | 0    | 1    | 3    | 4    |

遍历一遍异或后的结果是 ret 是 2^4  ，再得到缺失的数字是 2，只需要 ret ^ nums.length

```java
public int missingNumber(int[] nums) {						   //位运算
    int ret = 0;
    for (int i = 0; i < nums.length; i++) ret = ret ^ i ^ nums[i];
    return ret ^ nums.length;
}
```

```java
public int missingNumber(int[] nums) {			//数学，O(N)，O(1)，官解
    int expSum = nums.length*(nums.length + 1)/2;		
    int actSum = 0;
    for (int num : nums) actSum += num;
    return expSum - actSum;
}//利用数组长度加上与高斯求和公式，求得等差数列预期的总和 expSum 然后再减去所有数组元素，差为缺失数。
```

```java
public int missingNumber(int[] nums) {			//哈希表，双O(N)，需要遍历两遍。官解
    Set<Integer> set = new HashSet<>();
    for (int num : nums) set.add(num);
    for (int i = 0; i < nums.length + 1; i++) 
        if (!set.contains(i)) return i;
    return -1;
}
```

```java
public int missingNumber(int[] nums) {						   //排序解法，官解
    Arrays.sort(nums);
    if (nums[nums.length-1] != nums.length) return nums.length;//判断 n 是否出现在末位
    else if (nums[0] != 0) return 0;						   //判断 0 是否出现在首位
    for (int i = 1; i < nums.length; i++) {					   //缺失的数字一定在 (0, n) 
        int expNum = nums[i-1] + 1;
        if (nums[i] != expNum) return expNum;
    }
    return -1;												   //未缺失，随便给个返回值
}
```



## 4. 不重复的两个元素

中等： [260. 只出现一次的数字 III](https://leetcode-cn.com/problems/single-number-iii/)

和剑指的一道题重复了。两个不相等的元素在位级表示上必定会有一位存在不同。将数组的所有元素异或得到的结果为不存在重复的两个元素异或的结果。diff &= -diff 得到出 diff 最右侧不为 0 的位，也就是不存在重复的两个元素在位级表示上最右侧不同的那一位，利用这一位就可以将两个元素区分开来。

```java
public int[] singleNumber(int[] nums) {
    int diff = 0;
    for (int num : nums) diff ^= num;
    diff &= -diff;  // 得到最右一位
    int[] ret = new int[2];
    for (int num : nums) {
        if ((num & diff) == 0) ret[0] ^= num;
        else ret[1] ^= num;
    }
    return ret;
}
```

## 5. 翻转二进制数位

简单： [190. 颠倒二进制位](https://leetcode-cn.com/problems/reverse-bits/)

```javascript
颠倒给定的 32 位无符号整数的二进制位。多次调用这个函数，如何优化？
输入：11111111111111111111111111111101  输出：10111111111111111111111111111111
```

```java
public int reverseBits(int n) {
    int ret = 0;
    for (int i = 0; i < 32; i++) {
        ret <<= 1;	
        ret |= (n & 1);
        n >>>= 1;
    }
    return ret;
}
```

如果该函数需要被调用很多次，可以将 int 拆成 4 个 byte，然后缓存 byte 对应的比特位翻转，最后再拼接起来。

```java
private static Map<Byte, Integer> cache = new HashMap<>();

public int reverseBits(int n) {
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        ret <<= 8;
        ret |= reverseByte((byte) (n & 0b11111111));
        n >>= 8;
    }
    return ret;
}

private int reverseByte(byte b) {
    if (cache.containsKey(b)) return cache.get(b);
    int ret = 0;
    byte t = b;
    for (int i = 0; i < 8; i++) {
        ret <<= 1;
        ret |= t & 1;
        t >>= 1;
    }
    cache.put(b, ret);
    return ret;
}
```

## 6. 交换两数

```java
a = a ^ b;		//使用位运算交换两个数，要求不涉及额外变量。
b = a ^ b;
a = a ^ b;
```

## 7. 2 的 n 次方

简单：[231. 2 的幂](https://leetcode-cn.com/problems/power-of-two/)

2 的 n 次方数字的二进制表示只有一个 1 存在，可以使用 Integer.bitcount() 来统计 1 个的个数。

```java
public boolean isPowerOfTwo(int n) { return n > 0 && Integer.bitCount(n) == 1; }
```

```java
public boolean isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }//1000&0111==0
```

## 8.  4 的 n 次方

简单： [342. 4的幂](https://leetcode-cn.com/problems/power-of-four/)

 4 的 n 次方在二进制表示中有且**只有一个奇数位为 1**，例如 16（10000）。

```java
public boolean isPowerOfFour(int num) { return num > 0 && (num & (num - 1)) == 0 && (num & 0b01010101010101010101010101010101) != 0; }
```

```java
public boolean isPowerOfFour(int num) {
    return Integer.toString(num, 4).matches("10*");		//正则表达式进行匹配。
}
```

## 9. 判断 0 和 1 是否交替

简单： [693. 交替位二进制数](https://leetcode-cn.com/problems/binary-number-with-alternating-bits/)

```html
输入: 10 输出: True   解释: 10的二进制1010.      输入: 11 输出: False   解释: 11的二进制1011.
```

```java
public boolean hasAlternatingBits(int n) {
    int a = (n ^ (n >> 1));		//1010 ^ 101 => 1111		1011 ^ 101 => 1110
    return (a & (a + 1)) == 0;  //1111 & 10000 = 0			1110 & 1111 = 1110
}
```

## 10. 数的补码

简单：[476. 数字的补数](https://leetcode-cn.com/problems/number-complement/)

```html
输入：num = 5	输出：2  解释：5的二进制101，其补数为 010。所以输出2，不考虑二进制表示中的首 0 部分。
```

对于 00000101，要求补码可以将它与 00000111 进行异或操作。那么问题就转换为求掩码 00000111。

```java
public int findComplement(int num) {
    if (num == 0) return 1;
    int mask = 1 << 30;
    while ((num & mask) == 0) mask >>= 1;
    mask = (mask << 1) - 1;
    return num ^ mask;
}
```

```java
public int findComplement(int num) {
    if (num == 0) return 1;		//Java 的 Integer.highestOneBit() 方法来获得含有首 1 的数。
    int mask = Integer.highestOneBit(num); 
    mask = (mask << 1) - 1;
    return num ^ mask;
}
```

对于 10000000 这样的数要扩展成 11111111，可以利用以下方法：

```html
mask |= mask >> 1    11000000
mask |= mask >> 2    11110000
mask |= mask >> 4    11111111
```

```java
public int findComplement(int num) {
    int mask = num;
    mask |= mask >> 1;
    mask |= mask >> 2;
    mask |= mask >> 4;
    mask |= mask >> 8;
    mask |= mask >> 16;
    return (mask ^ num);
}
```

## 11. 位运算加法

中等： [371. 两整数之和](https://leetcode-cn.com/problems/sum-of-two-integers/)

剑指系列也有相同题目，a ^ b 表示没有考虑进位的情况下两数的和，(a & b) \<\< 1 就是进位。递归会终止的原因是 (a & b) \<\< 1 最右边会多一个 0，那么继续递归，进位最右边的 0 会慢慢增多，最后进位会变为 0，递归终止。

```java
public int getSum(int a, int b) { return b == 0 ? a : getSum((a ^ b), (a & b) << 1); }
```

## 12. 字符串长度的最大乘积

中等：[318. 最大单词长度乘积](https://leetcode-cn.com/problems/maximum-product-of-word-lengths/)

```javascript
两个互相不包含同一个字母单词长度的成绩最大值，不存在这样的单词返回0。
输入: ["a","ab","abc","d","cd","bcd","abcd"]  输出: 4   解释: 这两个单词为 "ab", "cd"。
输入: ["a","aa","aaa","aaaa"]					输出: 0 	解释: 不存在这样的两个单词。
```

本题主要问题是判断两个字符串是否含相同字符，由于字符串只含有小写字符，总共 26 位，因此可以用一个 32 位的整数来存储每个字符是否出现过。

```java
public int maxProduct(String[] strs) {
    int n = strs.length;
    int[] val = new int[n];
    for (int i = 0; i < n; i++)
        for (char c : strs[i].toCharArray())
            val[i] |= 1 << (c - 'a');	//记录这个字符串单词，用二进制位表示1的位置。
    int ret = 0;						// |= 在 1<< 移动后执行
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) //从 j = i + 1 开始匹配
            if ((val[i] & val[j]) == 0) //两字符串无重复字符，二进制数相同位置就不会出现两个1。
                ret = Math.max(ret, strs[i].length() * strs[j].length());
    return ret;
}
```

```java
public boolean noCommonLetters(String s1, String s2){	//其他判重复方法
  for (char ch : s1.toCharArray()) if (s2.indexOf(ch) != -1) return false;
  return true;
}
```

## 13. 递增数字中 1 的个数

简单：[338. 比特位计数](https://leetcode-cn.com/problems/counting-bits/)

```javascript
输入: 5 输出: [0,1,1,2,1,2]  解释：数组6个数分别对应 0,1,2,3,4,5这几个数上二进制位上1的个数的和。
```

动态规划：对于数字 6(110)，它可以看成是 4(100) 再加一个 2(10)，因此 dp[i] = dp[i&(i-1)] + 1;

```java
public int[] countBits(int num) {
    int[] ret = new int[num + 1];		
    for(int i = 1; i <= num; i++)  ret[i] = ret[i&(i-1)] + 1;  //0就默认不算了
    return ret;
}
```

直接遍历计算：时间：O(k×num)，其中 k 是 int 型的二进制位数，k=32。空间：O(1)

```java
public int[] countBits(int num) {
    int[] bits = new int[num + 1];
    for (int i = 0; i <= num; i++) bits[i] = countOnes(i);
    return bits;
}

public int countOnes(int x) {//可以用Java 库函数：Integer.bitCount 省去countOnes()这个方法。
    int ones = 0;
    while (x > 0) {
        x &= (x - 1);
        ones++;
    }
    return ones;
}
```



