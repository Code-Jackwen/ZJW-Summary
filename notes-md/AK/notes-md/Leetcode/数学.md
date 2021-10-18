# Leetcode 题解 - 数学
<!-- GFM-TOC -->
* [Leetcode 题解 - 数学](#leetcode-题解---数学)
    * [素数分解](#素数分解)
    * [整除](#整除)
    * [最大公约数最小公倍数](#最大公约数最小公倍数)
        * [1. 生成素数序列](#1-生成素数序列)
        * [2. 最大公约数](#2-最大公约数)
        * [3. 使用位操作和减法求解最大公约数](#3-使用位操作和减法求解最大公约数)
    * [进制转换](#进制转换)
        * [1. 7 进制](#1-7-进制)
        * [2. 16 进制](#2-16-进制)
        * [3. 26 进制](#3-26-进制)
    * [阶乘](#阶乘)
        * [1. 统计阶乘尾部有多少个 0](#1-统计阶乘尾部有多少个-0)
    * [字符串加法减法](#字符串加法减法)
        * [1. 二进制加法](#1-二进制加法)
        * [2. 字符串加法](#2-字符串加法)
    * [相遇问题](#相遇问题)
        * [1. 改变数组元素使所有的数组元素都相等](#1-改变数组元素使所有的数组元素都相等)
    * [多数投票问题](#多数投票问题)
        * [1. 数组中出现次数多于 n / 2 的元素](#1-数组中出现次数多于-n--2-的元素)
    * [其它](#其它)
        * [1. 平方数](#1-平方数)
        * [2. 3 的 n 次方](#2-3-的-n-次方)
        * [3. 乘积数组](#3-乘积数组)
        * [4. 找出数组中的乘积最大的三个数](#4-找出数组中的乘积最大的三个数)
<!-- GFM-TOC -->


## 素数分解

**质数**：1 自身不是 一个素数(又叫质数), 所以首批的一些素数是 2, 3, 5, 7, 11, 13, … 

每一个数都可以分解成素数的乘积，例如 84 = 2<sup>2</sup> \* 3<sup>1</sup> \* 5<sup>0</sup> \* 7<sup>1</sup> \* 11<sup>0</sup> \* 13<sup>0</sup> \* 17<sup>0</sup> \* …

**因子**：12可以被3整除，那么3就是12的一个因子或者除数。

**倍数**： A÷B=C，就可以说A是B的C倍。15能够被3或5整除，因此15是3的倍数，也是5的倍数。一个数的倍数有

无数个。不能把一个数单独叫做倍数，只能说谁是谁的倍数。 

**整除**

令 x = 2<sup>m0</sup> \* 3<sup>m1</sup> \* 5<sup>m2</sup> \* 7<sup>m3</sup> \* 11<sup>m4</sup> \* …

令 y = 2<sup>n0</sup> \* 3<sup>n1</sup> \* 5<sup>n2</sup> \* 7<sup>n3</sup> \* 11<sup>n4</sup> \* …

如果 x 整除 y（y mod x == 0），则对于所有 i，mi \<= ni。

## 最大公约数最小公倍数

**质因数分解法求最大公约数**：

求24和60的最大公约数，先分解质因数，得24=2×2×2×3，60=2×2×3×5，24与60的全部公有的

质因数是2、2、3，它们的积是2×2×3=12，所以，（24，60）=12。 

**最小公倍数**： 最小公倍数为两数的乘积除以最大公约数。

其他求法：把几个数先分别分解质因数，再把各数中的全部公有的质因数和独有的质因数提取出来连乘，所得

的积就是这几个数的**最小公倍数**。

例如：求6和15的最小公倍数。先分解质因数，得6=2×3，15=3×5，6和15的全部公有的质因数是3，6独有质因数

是2，15独有的质因数是5，2×3×5=30。30里面包含6的全部质因数2和3，还包含了15的全部质因数3和5，且30

是6和15的公倍数中最小的一个，所以[6，15]=30。 

### 1. 计数质数

简单：[204. 计数质数](https://leetcode-cn.com/problems/count-primes/)

统计所有小于非负整数 *`n`* 的质数的数量。 **埃拉托斯特尼筛法**：在每次找到一个素数时，将能被素数整除的数排除掉。

```java
public int countPrimes(int n) {
    boolean[] notPrimes = new boolean[n + 1];
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (notPrimes[i]) continue;
        count++;
        // 从 i * i 开始，因为如果 k < i，那么 k * i 在之前就已经被去除过了
        for (long j = (long) (i) * i; j < n; j += i) {
            notPrimes[(int) j] = true;
        }
    }
    return count;
}
```

质朴解法，超时，时间 n 乘 根号 n，每次判断是否是质数的时间复杂度是根号n。

```java
public int countPrimes(int n) {
     int cnt = 0;
     for (int i = 2; i < n; i++) {
         if (isPrime(i)) cnt++;
     }
     return cnt;
 }
private boolean isPrime(int num) {
    int max = (int)Math.sqrt(num);
    for (int i = 2; i <= max; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
```

### 2. 最大公约数、最小公倍数

```java
int gcd(int a, int b) {	return b == 0 ? a : gcd(b, a % b); }
//交换，并取余：60、24，  24、12，  12、0  return 12
//若是输入：24、60，	  60、24，	24、12，	12、0
```

**最小公倍数**为两数的乘积除以最大公约数。

```java
int lcm(int a, int b) { return a * b / gcd(a, b); }
//6,15	的最大公约数是3，最小公倍数是90/3得30
```

### 3. 奇偶乘除法求最大公约数

对于 a 和 b 的最大公约数 f(a, b)，有：	[编程之美：2.7](#)

- 如果 a 和 b 均为偶数，f(a, b) = 2\*f(a/2, b/2);
- 如果 a 是偶数 b 是奇数，f(a, b) = f(a/2, b);
- 如果 b 是偶数 a 是奇数，f(a, b) = f(a, b/2);
- 如果 a 和 b 均为奇数，f(a, b) = f(b, a-b);

乘 2 和除 2 都可以转换为移位操作。

```java
public int gcd(int a, int b) {
    if (a < b) return gcd(b, a);//转换为b大a小
    if (b == 0) return a;
    boolean isAEven = isEven(a), isBEven = isEven(b);		//Even 偶数
    if (isAEven && isBEven)		  return 2 * gcd(a >> 1, b >> 1);
    else if (isAEven && !isBEven) return gcd(a >> 1, b);
    else if (!isAEven && isBEven) return gcd(a, b >> 1);
    else return gcd(b, a - b);
}
```

## 进制转换

### 1. 7 进制

简单：[504. 七进制数](https://leetcode-cn.com/problems/base-7/)

```js
给定一个整数，将其转化为7进制，并以字符串形式输出。注意: 输入范围是 [-1e7, 1e7] 。
输入: 100	输出: "202"
输入: -7	输出: "-10"
```

```java
public String convertToBase7(int num) {
    if (num == 0) return "0";
    StringBuilder sb = new StringBuilder();
    boolean isNegative = num < 0;
    if (isNegative) num = -num;
    while (num > 0) {
        sb.append(num % 7);
        num /= 7;
    }
    String ret = sb.reverse().toString();
    return isNegative ? "-" + ret : ret;
}
```

Java 中 Integer 的 static String toString(int num, int radix) 可以将一个整数转换为 radix 进制表示的字符串。

```java
public String convertToBase7(int num) { return Integer.toString(num, 7); }
```

### 2. 16 进制

简单：[405. 数字转换为十六进制数](https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/)

```js
给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，负数要用它的补码形式。
输入:26	输出:"1a"			输入: -1	输出: "ffffffff"
```

int整数一共32位，4位为一个十六进制，因此int可以转为8位16进制，小于8则没有转完。

每次num和1111作与运算，得到的结果就是num的最后四位的十进制表示，从chars中查阅对应的十六进制拼接

```java
public String toHex(int num) {
    char[] map = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    if (num == 0) return "0";
    StringBuilder sb = new StringBuilder();
    while (num != 0) {
        sb.append(map[num & 0b1111]);	//0b1111 是15，15的二进制是1111
        num >>>= 4; // 考虑到时补码形式，因此符号位就不能有特殊的意义，需要使用无符号右移，左边填 0
    }
    return sb.reverse().toString();
}
```

```c++
//C++的话，不管正负，统统转成无符号整型unsigned int类型，和下边进行一样的处理。0xf就是15
string toHex(int num) {
    if(num==0)  return "0";
    string  mp = "0123456789abcdef";
    int cnt=0;		   //右移动的次数，处理-1，负数
    string res="";
    while(num && cnt<8)//32位转换成16进制就是八位
    {
        res = mp[num&0xf]+res;//+res放到后边不用再对结果反转
        num>>=4;
        cnt++;
    }
    return res;
}
```

### 3. 26 进制

简单：[168. Excel表列名称](https://leetcode-cn.com/problems/excel-sheet-column-title/)

```js
1 -> A、2 -> B、3 -> C ... 26 -> Z、27 -> AA、28 -> AB
输入: 701	输出: "ZY"	26*26+25=676+25=701
```

因为是从 1 开始计算的，而不是从 0 开始，因此需要对 n 执行 -1 操作。

```java
public String convertToTitle(int n) {//9ms，10%
    if (n == 0) return "";
    n--;
    return convertToTitle(n / 26) + (char) (n % 26 + 'A');
}
```

```java
public String convertToTitle(int n) {//99%，上边递归对应的循环版本
    char[] c = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    StringBuilder sb = new StringBuilder();
    while (n > 0) {
        --n;							// 必须n--才能和数组对上号。
        sb = sb.append(c[n % 26]);
        n /= 26;
    }
    return sb.reverse().toString();
}
```

```java
public String convertToTitle(int n) {
    StringBuilder sb = new StringBuilder();
    while (n > 0) {
        int diff = (n - 1) % 26;		//省去字符数组
        n = (n - 1) / 26;
        sb.append((char)('A' + diff));
    }
    return sb.reverse().toString();
}
```

## 阶乘

### 1. 阶乘结果尾部有多少个 0

简单：[172. 阶乘后的零](https://leetcode-cn.com/problems/factorial-trailing-zeroes/)

时间要求优化到对数级别

```
输入: 3	输出: 0	解释: 3! = 6, 尾数中没有零。
输入: 5	输出: 1	解释: 5! = 120, 尾数中有 1 个零
输入: 7	输出: 1	解释：5040		输入: 8 输出: 1 解释：40320	输入: 10 输出:2 解释：3628800
```

尾部的 0 由 2 * 5 得来，2 的数量明显多于 5 的数量，因此只要统计有多少个 5 这个因子有多少个即可。

[详细通俗的思路分析 - 阶乘后的零 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/factorial-trailing-zeroes/solution/xiang-xi-tong-su-de-si-lu-fen-xi-by-windliang-3/) 

```java
public int trailingZeroes(int n) { return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5); }
```

```java
public int trailingZeroes(int n) {
    int cnt = 0;
    while (n != 0) {
        cnt += n / 5;	// 25->5 5->1 实际25分解为2个5因子
        n = n / 5;
    }
    return cnt;
}
```

## 字符串加法减法

### 1. 二进制加法

简单：[67. 二进制求和](https://leetcode-cn.com/problems/add-binary/)

```js
给你两个二进制字符串，返回它们的和（用二进制表示）。输入为 非空 字符串且只包含数字 1 和 0。
1 <= a.length, b.length <= 10^4		字符串如果不是 "0" ，就都不含前导零。
输入: a = "1010", b = "1011"	输出: "10101"
```

```java
public String addBinary(String a, String b) {//2ms,99%
    int i = a.length() - 1, j = b.length() - 1, carry = 0;
    StringBuilder sb = new StringBuilder();
    while (carry == 1 || i >= 0 || j >= 0) {		  //从后边开始
        if (i >= 0 && a.charAt(i--) == '1') carry++;  //1010
        if (j >= 0 && b.charAt(j--) == '1') carry++;  //1011
        sb.append(carry % 2);						  //都是1的话，就会拼接0
        carry /= 2;									  //都是1的话，c会再变为1
    }
    return sb.reverse().toString();
}
```

### 2. 字符串加法

简单：[415. 字符串相加](https://leetcode-cn.com/problems/add-strings/)

```js
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。num1 和num2 都不包含任何前导零
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式
输入："11" "123"  	 输出："134"	解释：123+11=134
```

```java
public String addStrings(String num1, String num2) {
    StringBuilder sb = new StringBuilder();
    int carry = 0, i = num1.length() - 1, j = num2.length() - 1;
    while (carry == 1 || i >= 0 || j >= 0) {
        int x = i < 0 ? 0 : num1.charAt(i--) - '0';//x<0的时候要刷新x的值，为0
        int y = j < 0 ? 0 : num2.charAt(j--) - '0';//否则一直是num1.charAt(0)影响后续计算
        sb.append((x + y + carry) % 10);
        carry = (x + y + carry) / 10;
    }
    return sb.reverse().toString();
}
```

## 相遇问题

### 1. 编辑数组最少次使得元素都相等

中等： [462. 最少移动次数使数组元素相等 II](https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements-ii/)

```js
给定一个非空整数数组，找到使所有数组元素相等所需的最小移动数，其中每次移动可将选定的一个元素加1或减1。 
输入:[1,2,3]	输出:2	说明：[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
```

题目概述：每次可以对一个数组元素加一或者减一，求最小的改变次数。

这是个典型的相遇问题，移动距离最小的方式是所有元素都移动到中位数。理由如下：

设 m 为中位数。a 和 b 是 m 两边的两个元素，且 b \> a。要使 a 和 b 相等，它们总共移动的次数为 b - a，这个值等于 (b - m) + (m - a)，也就是把这两个数移动到中位数的移动次数。

设数组长度为 N，则可以找到 N/2 对 a 和 b 的组合，使它们都移动到 m 的位置。

解法 1 ：先排序，时间复杂度：O(NlogN)

```java
public int minMoves2(int[] nums) {//2ms,99%
    Arrays.sort(nums);
    int move = 0;
    int l = 0, h = nums.length - 1;
    while (l <= h) {
        move += nums[h] - nums[l];
        l++;
        h--;
    }
    return move;
}
```

解法 2  ：使用快速选择找到中位数，时间复杂度 O(N)

```java
public int minMoves2(int[] nums) {//74ms,14%
    int move = 0;
    int median = findKthSmallest(nums, nums.length / 2);
    for (int num : nums) {
        move += Math.abs(num - median);
    }
    return move;
}
private int findKthSmallest(int[] nums, int k) {
    int l = 0, h = nums.length - 1;
    while (l < h) {
        int j = partition(nums, l, h);
        if (j == k)  break;
        if (j < k) l = j + 1;
		else h = j - 1;
    }
    return nums[k];
}
private int partition(int[] nums, int l, int h) {
    int i = l, j = h + 1;
    while (true) {
        while (nums[++i] < nums[l] && i < h) ;
        while (nums[--j] > nums[l] && j > l) ;
        if (i >= j) break;
        swap(nums, i, j);
    }
    swap(nums, l, j);
    return j;
}
private void swap(int[] nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
```

## 多数投票问题

### 1. 数组中过半的元素

简单： [169. 多数元素](https://leetcode-cn.com/problems/majority-element/)

先对数组排序，最中间那个数出现次数一定多于 n / 2。

```java
public int majorityElement(int[] nums) {
    Arrays.sort(nums);
    return nums[nums.length / 2];
}
```

可以利用 Boyer-Moore Majority Vote Algorithm 来解决这个问题，使得时间复杂度为 O(N)。

```java
public int majorityElement(int[] nums) {
    int cnt = 0, majority = nums[0];
    for (int num : nums) {
        majority = (cnt == 0) ? num : majority;
        cnt = (majority == num) ? cnt + 1 : cnt - 1;
    }
    return majority;
}
```

## 其它

### 1. 判断平方数

简单： [367. 有效的完全平方数](https://leetcode-cn.com/problems/valid-perfect-square/)

```html
Input: 16	Returns: True
```

平方序列：1,4,9,16,..		间隔：3,5,7,...

间隔为等差数列，使用这个特性可以得到从 1 开始的平方序列。

```java
public boolean isPerfectSquare(int num) {
    int subNum = 1;
    while (num > 0) {
        num -= subNum;
        subNum += 2;
    }
    return num == 0;
}
```

### 2. 判断 3 的 n 次方

简单： [326. 3的幂](https://leetcode-cn.com/problems/power-of-three/)

```java
public boolean isPowerOfThree(int n) { return n > 0 && (1162261467 % n == 0); }
```

### 3. 构建乘积数组

中等：[238. 除自身以外数组的乘积](https://leetcode-cn.com/problems/product-of-array-except-self/)

```html
For example, given [1,2,3,4], return [24,12,8,6].
```

给定一个数组，创建一个新数组，新数组的每个元素为原始数组中除了该位置上的元素之外所有元素的乘积。

要求时间复杂度为 O(N)，并且不能使用除法。

```java
public int[] productExceptSelf(int[] nums) {
    int n = nums.length;
    int[] products = new int[n];
    Arrays.fill(products, 1);
    int left = 1;
    for (int i = 1; i < n; i++) {
        left *= nums[i - 1];
        products[i] *= left;
    }
    int right = 1;
    for (int i = n - 2; i >= 0; i--) {
        right *= nums[i + 1];
        products[i] *= right;
    }
    return products;
}
```

### 4. 数组中乘积最大的三个数

简单： [628. 三个数的最大乘积](https://leetcode-cn.com/problems/maximum-product-of-three-numbers/)

```html
Input: [1,2,3,4] Output: 24		数组存在负数
```

可以数组排序后，求出三个最大正数的乘积、两个最小负数与最大正数的乘积，二者之间的最大值即为所求答案。 

```java
public int maximumProduct(int[] nums) {
    int max1 = Integer.MIN_VALUE, max2 = Integer.MIN_VALUE, max3 = Integer.MIN_VALUE, min1 = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE;//最小的、第二小的
    for (int n : nums) {
        if (n > max1) {
            max3 = max2;
            max2 = max1;
            max1 = n;
        } else if (n > max2) {
            max3 = max2;
            max2 = n;
        } else if (n > max3) {
            max3 = n;
        }

        if (n < min1) {
            min2 = min1;
            min1 = n;
        } else if (n < min2) {
            min2 = n;
        }
    }
    return Math.max(max1*max2*max3, max1*min1*min2);
}
```
