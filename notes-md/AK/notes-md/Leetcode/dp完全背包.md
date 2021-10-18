## 完全背包

有 N件物品和一个容量是 V 的背包。每件物品只能使用一次，每种物品都有无限件可用。第 i 件物品的体积是 w[i]
，价值是 v[i]。求将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。

**分析**：「完全背包问题」的重点在于：每种物品都有无限件可用，且不计算顺序。

**状态**：`dp[i][j]` 表示考虑物品区间 `[0, i]` 里，不超过背包容量，能够获得的最大价值； 

```js
方程：dp[i][j] = max(dp[i−1][j] , dp[i−1][j− k × w[i]] + k × v[i])		这里 k>= 0
```

```java
public static int[][] npack(int W, int N, int[] weights, int[] values) {
    int[][] dp = new int[N + 1][W + 1];			//原始版本，复杂度高，3层循环，有重复计算
    for (int i = 1; i <= N; i++) {
        int w = weights[i - 1], v = values[i - 1];
        for (int j = 0; j <= W; j++) {			//j从1开始也对
            for (int k = 0; k * w <= j; k++) 
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - k * w] + k * v);
            //dp[i][j] = dp[i - 1][j];
            //if (j - w >= 0) dp[i][j] = Math.max(dp[i][j], dp[i][j - w] + v);
        }
    }
    return dp;
}
```

```java
public static int[] npack(int W, int N, int[] weights, int[] values) {
    int[] dp = new int[W + 1];							//完全背包，最终版本
    for (int i = 1; i <= N; i++) {						//只保留列
        int w = weights[i - 1], v = values[i - 1];
        for (int j = w; j <= W; j++) {					//从j从w开始，正序遍历
            dp[j] = Math.max(dp[j], dp[j - w] + v);		//完全背包问题
        }
    }
    return dp;
}
```

### 4. 找零钱的最少硬币数

中等：[322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/)

```js
凑成总金额所需的最少的硬币个数，硬币的数量是无限的。没有任何一种硬币组合能组成总金额，返回 -1。
输入：coins = [1, 2, 5], amount = 11	输出：3 	解释：11 = 5 + 5 + 1
输入：coins = [2], amount = 3	输出：-1
```

题意转换：背包：amount。物品：coins，硬币可以重复使用，且不考虑硬币顺序，因此是一个完全背包问题。 

**完全背包只需要将 0-1 背包的逆序遍历 dp 数组改为正序遍历即可。**

一系列题目（未看完）： [一套框架解决「背包问题」 - 零钱兑换 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/coin-change/solution/yi-tao-kuang-jia-jie-jue-bei-bao-wen-ti-h0y40/) 

状态意义：dp[i] 表示和为 i 的 coin 组合中硬币最少有 dp[i] 个。公式：dp[i] = min(dp[i], dp[i - coin] + 1)

不考虑顺序，因此是外物品，内背包。对于边界条件，我们定义 dp[0] = 0。

参考： [「代码随想录」322. 零钱兑换【完全背包】详解 - 零钱兑换 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/coin-change/solution/322-ling-qian-dui-huan-wan-quan-bei-bao-yged0/) 

```java
public int coinChange(int[] coins, int sum){//21ms,28%
    if (sum == 0 || coins == null) return 0;
    int[] dp = new int[sum + 1];
    Arrays.fill(dp, Integer.MAX_VALUE - 1); //如果初始为Integer.MAX_VALUE那么它+1就是
    dp[0] = 0;							    //-2147483648 解决方法可以是int类型的dp改为long
    for (int coin : coins)  			    //Arrays.fill(dp, sum + 1);
        for (int i = coin; i <= sum; i++)   //将逆序遍历改为正序遍历
            if (coin <= i)
                dp[i] = Math.min(dp[i], dp[i - coin] + 1);
    return dp[sum] == Integer.MAX_VALUE - 1 ? -1 : dp[sum];
}
```

### 5. 找零钱的最多方案数

中等：[518. 零钱兑换 II](https://leetcode-cn.com/problems/coin-change-2/)

```js
输入: amount=5, coins=[1, 2, 5]  输出: 4  解释: 4种方案，5=5，5=2+2+1，5=2+1+1+1，5=1+1+1+1+1
```

dp[j]：表示当前背包容量为 j 时，可以凑成 j 的硬币组合数。

初始化：dp[0] = 1，当背包容量为 0 时，只有一种情况满足条件，就是一个硬币也不选。

```java
public int change(int amount, int[] coins) {	//一维模板(推荐)
    if (coins == null) return 0;				
    int[] dp = new int[amount + 1];
    dp[0] = 1;									//套用完全背包模板
    for (int coin : coins) 						//coins:物品，放在外循环
        for (int i = coin; i <= amount; i++) 	//amount：背包容量，在内循环，且内循环正序。
            dp[i] += dp[i - coin];
    return dp[amount];
}
```

dp\[i][j]：表示背包容量为 j 时，在前 i 枚硬币中能组成的硬币组合个数。参考：[零钱兑换 II -  完全背包问题](https://leetcode-cn.com/problems/coin-change-2/solution/ling-qian-dui-huan-iidong-tai-gui-hua-wa-tgrm/) 

```java
public int change(int amount, int[] coins) {	//二维
    int n = coins.length;
    int[][] dp = new int[n + 1][amount + 1];
    for (int i = 0; i <= n; i++) 				//第一列amount是0，所有的硬币都不放就是1中情况
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {				//遍历硬币，i为第i个物品，j为容量
        int c = coins[i - 1];
        for (int j = 1; j <= amount; j++) {		//从小到大遍历目标值,目标值就是 背包大小
            if (j - c>= 0)						//放得下这个硬币
                dp[i][j] = dp[i - 1][j] + dp[i][j - c];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][amount];
}
```

### 6. 字符串按单词列表分割

中等：[139. 单词拆分](https://leetcode-cn.com/problems/word-break/)

```js
判定 s 是否可以被拆分为一个或多个在字典中出现的单词。拆分时可以重复使用字典中的单词，字典中没有重复的单词。
输入: s = "applepenapple", wordDict = ["apple", "pen"]	输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
```

**求解顺序的完全背包问题时，对物品的迭代应该放在最里层，对背包的迭代放在外层，只有这样才能让物品按一定顺序放入背包中。**

<img src="../../../ZJW-Summary/assets/1621335242057.png" alt="1621335242057" style="zoom:80%;" />

```java
public boolean wordBreak(String s, List<String> wordDict) {
    int n = s.length();					 //背包解法
    boolean[] dp = new boolean[n + 1];
    dp[0] = true;
    for (int i = 1; i <= n; i++) {		//外循环：背包	
        for (String word : wordDict) {	//内循环：物品
            int len = word.length();
            if (len <= i && word.equals(s.substring(i - len, i))) 
                dp[i] = dp[i] || dp[i - len];
        }								//自己写字符串判断函数会快一些
    }
    return dp[n];
}
```

 其他解法：[「手画图解」剖析三种解法: DFS, BFS, 动态规划 |139.单词拆分 - 单词拆分 ](https://leetcode-cn.com/problems/word-break/solution/shou-hui-tu-jie-san-chong-fang-fa-dfs-bfs-dong-tai/) 

 [字典树+DFS实现，击败90% - 单词拆分 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/word-break/solution/zi-dian-shu-dfsshi-xian-ji-bai-90-by-kua-48j6/) 

### 7. 组合总和

中等：[377. 组合总和 Ⅳ](https://leetcode-cn.com/problems/combination-sum-iv/)

```js
输入：nums = [1,2,3], target = 4	输出：7	解释：(1, 1, 1, 1)、(1, 1, 2)、(1, 2, 1)、(1, 3)、(2, 1, 1)、(2, 2)、(3, 1)，请注意，顺序不同的序列被视作不同的组合。nums中的所有元素互不相同。
```

题目中 target 的范围是最小值是1，而 f[0] = 1; 没有任何实际意义，为的是 f[i] += f[i - u];  仅是为推导递推公式。 

**如果求组合数就是外层for循环遍历物品，内层for遍历背包**。对比： [动态规划：518.零钱兑换II](https://mp.weixin.qq.com/s/PlowDsI4WMBOzf3q80AksQ)  是求的组合

**如果求排列数就是外层for遍历背包，内层for循环遍历物品**。本题是求的排列

如果把遍历nums（物品）放在外循环，遍历target的作为内循环的话，举一个例子：计算dp[4]的时候，结果集只有 {1,3} 这样的集合，不会有{3,1}这样的集合，因为nums遍历放在外层，3只能出现在1后面！

 [「代码随想录」377. 组合总和 Ⅳ【动态规划】详解 - 组合总和 Ⅳ - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/combination-sum-iv/solution/dai-ma-sui-xiang-lu-377-zu-he-zong-he-iv-pj9s/) 

```java
public int combinationSum4(int[] nums, int tar) {
    int[] f = new int[tar + 1];
    f[0] = 1;
    for (int i = 1; i <= tar; i++) 
        for (int u : nums) 
            if (i >= u) f[i] += f[i - u];
    return f[tar];
}
```

