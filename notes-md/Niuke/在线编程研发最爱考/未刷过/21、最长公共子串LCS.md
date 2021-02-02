牛客原题：https://www.nowcoder.com/practice/f33f5adc55f444baa0e0ca87ad8a6aac?tpId=117&&tqId=35268&rp=1&ru=/activity/oj&qru=/ta/job-code-high/question-ranking





给定两个字符串s和s,输出两个字符串的最长公共子串，如果最长公共子串为空，输出-1。

示例1

## 输入

```
"1AB2345CD","12345EF"
```

## 输出

```
"2345"
```



本题和力扣经典 LCS 类似，不妨显卡看下下边的 LCS 。

和LCS问题唯一不同的地方在于当A[i] != B[j]时，res\[i][j] 就直接等于0了，因为子串必须连续，**且res\[i][j] 表示的是以A[i]，B[j]截尾的公共子串的长度**。 

参考：

https://blog.csdn.net/u013309870/article/details/69479488

https://www.nowcoder.com/questionTerminal/f33f5adc55f444baa0e0ca87ad8a6aac

````java
import java.util.*;

public class Solution {
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    public String LCS (String str1, String str2) {
       if(str1 == null || str2 == null || str1.equals("") || str2.equals("")){
           return "-1";
       } 
        int indexMax = 0;
        int maxLen = 0;
        int m = str1.length();
        int n = str2.length();

        //dp[i][j]代表 str1[0~i-1]和str2[0~j-1] 的最长公共子串的长度  
        int[][] dp = new int[m][n];
        for(int i = 0; i < m; ++ i){
            for(int j = 0; j < n; ++j){
                if(str1.charAt(i) == str2.charAt(j)){
                    if(i == 0 || j == 0){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                }//else 是str1[i]!=str2[j]的情况,这种情况下dp[i][j]=0,由于初始化已经将其设置为0,所以这里不再写。
                
                 //处理完dp[i][j]之后,查看一下是否需要记录下来
                if(maxLen < dp[i][j]){
                    maxLen = dp[i][j]; //记录下最长公共子串的长度
                    indexMax = i; //记录下出现“最长公共子串”时的末尾字符的位置
                }
            }
        }
        if(maxLen == 0) return "-1";
        //字符串截取的长度有(end-start+1) = maxLen, 那么start = indexMax +1-maxLen
        // maxLen即为所截取的字符串的长度。
        return str1.substring(indexMax - maxLen  + 1 , indexMax + 1);
    }
}
````







## 力扣经典 LCS 

（Longest Common Subsequence，简称 LCS） 

 [1143.最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence) 



## 方法：动态规划

![1611728890062](../../../assets/1611728890062.png)



````java
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length(), n = text2.length();
        int[][] dp = new int[m + 1][n + 1];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 获取两个串字符
                char c1 = text1.charAt(i), c2 = text2.charAt(j);
                if (c1 == c2) {
                    // 去找它们前面各退一格的值加1即可
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    //要么是text1往前退一格，要么是text2往前退一格，两个的最大值
                    //左上角的值dp[i - 1][j - 1]必是最小所以不参与比较，延续。
                    dp[i + 1][j + 1] = Math.max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[m][n];
    }
}

作者：yijiaoqian
链接：https://leetcode-cn.com/problems/longest-common-subsequence/solution/dong-tai-gui-hua-tu-wen-jie-xi-by-yijiaoqian/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
````





