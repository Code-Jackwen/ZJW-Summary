## 股票交易

### 1. 交易一次

简单：[剑指 Offer 63. 股票的最大利润](https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/) 

```js
输入: [7,1,5,3,6,4]	输出: 5	解释: 最大利润 = 6-1 = 5 。
```

```java
public int maxProfit(int[] prices) {
    if (prices == null || prices.length == 0) return 0;
    int min = Integer.MAX_VALUE;
    int max = 0;
    for(int cur : prices) {
        min = Math.min(min, cur);			//找最小值
        max = Math.max(max, cur - min);		//找最大差值
    }
    return max;
}
```

### 2. 交易多次

简单：[122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)

```java
public int maxProfit(int[] prices) {
    int profit = 0;
    for (int i = 1; i < prices.length; i++) {
        if (prices[i] > prices[i - 1]) {			//计算所有递增两数的差的和
            profit += (prices[i] - prices[i - 1]);
        }
    }
    return profit;
}
```

### 3. 交易两次

困难：[123. 买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)

一个巧妙的解法，以每一天作为分界线，前后分别进行最大售卖的最大值比较。

f[i]记录以0 ~ i中的最低价MIN买入，当前价prices[i]卖出的利润

再从右到左扫一遍，求出i ~ n-1区间内最大利润，再次遍历求两次利润的和。



<img src="../../../ZJW-Summary/assets/1621413985149.png" alt="1621413985149" style="zoom: 67%;" />

```java
public int maxProfit(int[] prices) {
    if (prices == null || prices.length == 0) return 0;
    int len = prices.length;
    int min = prices[0];            // 初始化的前半部分最小买入价格
    int max = prices[len - 1];      // 初始化的后半部分最大卖出价格
    int maxPftL = 0;                // 前半部分的每天最大利润
    int maxPftR = 0;                // 后半部分的每天最大利润
    int[] pftL = new int[len];      // 前半部分的利润表
    int[] pftR = new int[len];      // 后半部分的利润表
    for (int i = 0; i < len; i++) {
        if (prices[i] <= min) min = prices[i];   	  //计算 从前往后 的利润
        maxPftL = Math.max(maxPftL, prices[i] - min); //这可以加上else效率会更高
        pftL[i] = maxPftL;

        if (prices[len - 1 - i] >= max) max = prices[len - 1 - i];//计算 从后往前 的利润
        maxPftR = Math.max(maxPftR, max - prices[len - 1 - i]);   //这加上else效率会更高
        pftR[len - i - 1] = maxPftR;
    }
    int ret = Integer.MIN_VALUE;             		   //计算利润和最大值
    for (int i = 0; i < len; i++) {
        ret = Math.max(ret, pftL[i] + pftR[i]);
    }
    return ret;
}
```

```java
public int maxProfit(int[] prices) {					//联系实际
    int firstBuy = Integer.MIN_VALUE, firstSell = 0;
    int secondBuy = Integer.MIN_VALUE, secondSell = 0;
    for (int curPrice : prices) {
        if (firstBuy < -curPrice)				 firstBuy = -curPrice;
        if (firstSell < firstBuy + curPrice)  	 firstSell = firstBuy + curPrice;
        if (secondBuy < firstSell - curPrice)	 secondBuy = firstSell - curPrice;
        if (secondSell < secondBuy + curPrice)   secondSell = secondBuy + curPrice;
    }
    return secondSell;
}
```

```txt
{3, 3, 5, 0, 3, 1, 4}
 3, 3, 3, 0, 0, 0, 0		//找最小值
 0, 0, 2, 2, 3, 3, 4		//和交易一次的一样
-3,-3,-3, 2, 2, 2, 2		//这不一样了，第一次和第二次关联到一块计算最大值
 0, 0, 2, 2, 5, 5, 6		//这不一样了
```

联系实际，换一种写法  [「代码随想录」买卖股票的最佳时机 III )](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/123-mai-mai-gu-piao-de-zui-jia-shi-ji-ii-zfh9/) 

```c++
int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) return 0;
    vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
    dp[0][1] = -prices[0];
    dp[0][3] = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
        dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }
    return dp[prices.size() - 1][4];
}
```

```c++
int maxProfit(vector<int>& prices) {		//简化后
    if (prices.size() == 0) return 0;
    vector<int> dp(5, 0);
    dp[1] = -prices[0];
    dp[3] = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
        dp[1] = max(dp[1], dp[0] - prices[i]);
        dp[2] = max(dp[2], dp[1] + prices[i]);
        dp[3] = max(dp[3], dp[2] - prices[i]);
        dp[4] = max(dp[4], dp[3] + prices[i]);
    }
    return dp[4];
}
```

### 4. 交易 K 次

困难：[188. 买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)

```c++
int maxProfit(int k, vector<int>& prices) {			//123题的进阶，图还可以参考123
    if (prices.empty()) return 0;
    int n = prices.size();
    k = min(k, n / 2);
    vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
    for (int j = 1; j < 2 * k; j += 2) {			//对奇数项赋值
        dp[0][j] = -prices[0];
    }
    for (int i = 1;i < prices.size(); i++) {
        for (int j = 0; j < 2 * k - 1; j += 2) { 	//dp[i][0] = dp[i - 1][0];直接省掉了
            dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
            dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
        }
    }
    return dp[prices.size() - 1][2 * k];
}
```

```java
if (k >= n / 2) {   // 这种情况下该问题退化为普通的股票交易问题
    int maxProfit = 0;
    for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1]) {
            maxProfit += prices[i] - prices[i - 1];
        }
    }
    return maxProfit;
}
```

### 5. 需要交易费用

中等：[714. 买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

```java
每次交易都要支付一定的费用。输入：[1,3,7,5,10,3]  3  输出：6  解释：是1和9买和卖，不是1和7、5和10。
```

```java
public int maxProfit(int[] prices, int fee) {
    int n = prices.length;
    int[][] dp = new int[n][2];
    dp[0][0] = 0;			//不持有股票
    dp[0][1] = -prices[0];  //持有股票
    for (int i = 1; i < n; i++) {
        //不持有股票 1、昨天都没买延续下来		     2、昨天把股票卖了
        dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee); 
        //持有股票	 1、有股票但昨天没卖延续下来		2、昨天买了股票
        dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[n - 1][0];
}		//实际一维可以直接去掉
```

### 6. 需要一天冷却期

中等：[309. 最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)		单次交易之后需要有一天的冷却时间。

```js
输入: [1,2,3,0,2]	 输出: 3 	解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
```

注意到第 0 天实际上是不存在处于冷冻期的情况的，但我们仍然可以将对应的状态 f\[0][1] 置为零

f\[0][2]的状态就是第0天不买入，很容易理解。而对这句话，我的想法如下:

简单理解： 两种都是不持有，自然收益就是0了

更具体理解：f\[0][1] 其实可以存在，可以理解为当天买入卖出，收益自然也是0。而且会导致下一天"冷冻期”,显然是只有弊端。

结合代码理解： `f[0][1]只影响f[1][2],而f[1][2]又是由f[0][1]和f[0][2]共同决定的`，而`f[0][2]`如上文所说，肯定就是0。 因此`f[1][2]=Math.max(f[0][1], f[0][2]);` ，只要`f[0][1]<=0` 都是不会造成影响的。

因此我认为` f[0][1] = Integer.MIN_VALUE;` 更容易理解，表示只会带来负收益

```java
public int maxProfit(int[] prices) {
    if (prices == null || prices.length == 0) return 0;
    int res = 0;
    int len = prices.length;
    // dp[i][0] : 持有股票
    // dp[i][1] : 不持有股票，本日卖出，下一天为冷冻期
    // dp[i][2] : 不持有股票，本日无卖出，下一天非冷冻期
    int[][] dp = new int[len][3];

    //初始状态:
    // 1: 第一天持有，只有可能是买入
    dp[0][0] = -prices[0];

    // 其实dp[0][1]、dp[0][2] 都不写，默认为0也对
    // 2. 第0天，相当于当天买入卖出，没有收益，并造成下一天冷冻期，减少选择。综合认为是负收益
    dp[0][1] = Integer.MIN_VALUE;

    // 3. 相当于没买入，收益自然为0
    dp[0][2]=0;

    for (int i = 1; i < len; i++) {
        // 持有股票： 1.昨天持有股票 2.本日买入（条件：昨天不持有，且不是卖出）
        dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
        //本日卖出 : (条件:昨天持有)
        dp[i][1] = dp[i - 1][0] + prices[i];
        // 不持有，但也不是卖出 : 1.昨天卖出，不持有  2.昨天没卖出，但也不持有
        dp[i][2] = Math.max(dp[i - 1][1], dp[i - 1][2]);
    }
    // 最后一天还持有股票是没有意义的,肯定是不持有的收益高，不用对比 dp[len-1][0]
    return Math.max(dp[len - 1][1], dp[len - 1][2]);
}
```

```cpp
//思路：
//考虑有多少种状态，每种状态有哪些选择，或者是做了哪些选择后得到哪种状态。
//注意：到底是先选择了才有状态，还是先由状态才能选择。这里是先选择了，才有状态

// 状态类型有2种：天数和是否持有。
//     天数：一共为1-n天
//     是否持有：分为持有状态、没持有状态1、没持有状态2。
//         持有状态：选择 无处理 和 买入 都有可能达到该状态
//         没持有状态1：选择 无处理 后达到该状态。
//         没持有状态2：选择 卖出 后达到该状态。注意，卖出后进入一天的冻结期。
// 注意：这里为什么要分两种没持有状态，这是为了便于后续状态转移，如果不区分这两种状态，状态转移没法确定当天是否可以进行买入操作。

//dp表示的含义：
//dp[i][2] : 第i天为没持有状态2时，此时的最大利润
//dp[i][1] : 第i天为没持有状态1时，此时的最大利润
//dp[i][0] : 第i天为持有状态时，此时的最大利润

//状态转移方程：

//dp[i][0]: 第i天为持有状态时，此时的最大利润
//无处理后到该状态:   dp[i][0] = dp[i-1][0] // 第i天没有处理就持有股票，证明上一天也持有
//买入后达到该状态:   dp[i][0] = dp[i-1][1]-prices[n] // 第i天能买入股票，证明上一天没持有股票，且没进行卖出操作
//所以dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[n]); 
//这里思考个问题，两种情况都能到达这个状态的话，那如何选择？为什么是取他们的max？

//dp[i][1]: 第i天为没持有状态1时，此时的最大利润
//无处理后达到该状态：			dp[i][1] = dp[i-1][1]
//状态1把股票给卖了之后达到该状态： dp[i][1] = dp[i-1][2]
//因此，dp[i][1] = max(dp[i-1][1], dp[i-1][2]) 

//dp[i][2]: 第i天为没持有状态2时，此时的最大利润
//状态1把股票刚给卖了，卖出后达到该状态： dp[i][2] = dp[i-1][0]+prices[i]

// 最后max(dp[n-1][1], dp[n-1][2])就是题目所需答案。即第n-1天没持有股票时的最大收益

// test case: 
// [1,2,3,0,2]
// [1,2,-2,0,33,0,2]
// [1,2,3,0,2,3,9,0,2,4]
// [2,1]
int maxProfit(vector<int>& prices) {
    if(prices.size() <= 1) return 0;
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    dp[0][2] = 0; // 假设默认持有0元股票
    for(int i=1; i<n; ++i){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][2]);
        dp[i][2] = dp[i-1][0] + prices[i];
    }
    return max(dp[n-1][1], dp[n-1][2]);
}
```

还有细分为4种状态的：1持有、2非持有（今天也没售出，两天前就卖出了股票，度过了冷冻期 ）、3非持有（今天售出，后边冷静1天）、4冷静期，实际上2和4可以合并，没4也行。参考： [309.最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/309zui-jia-mai-mai-gu-piao-shi-ji-han-le-byz3/) 

```java
public int maxProfit(int[] prices) {
    int len = prices.length;
    if (len < 2) return 0;
    int[][] dp = new int[len][2];
    dp[0][0] = 0;		   //两种状态买入
    dp[0][1] = -prices[0]; //卖出
    for (int i = 1; i < len; i++) {
        // 卖出状态
        dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        // 买入状态
        if (i < 3) {// 前三天不用考虑冷冻期的问题，因为不可能出现冷冻期
            dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        } else {	// 从第4天开始，买入考虑一天的冷冻期，3-2=1
            dp[i][1] = Math.max(dp[i - 1][1], dp[i - 2][0] - prices[i]);
        }
    }
    return dp[len - 1][0];
}
```





