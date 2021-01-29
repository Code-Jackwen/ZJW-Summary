https://www.nowcoder.com/practice/9cf027bf54714ad889d4f30ff0ae5481?tpId=117&&tqId=35013&rp=1&ru=/activity/oj&qru=/ta/job-code-high/question-ranking



分类：二分、动态规划



示例1

## 输入

```
[2,1,5,3,6,4,8,9,7]
```

## 返回值

```
[1,3,4,8,9]
```

示例2

## 输入

```
[1,2,8,6,4]
```

## 返回值

```
[1,2,4]
```

## 说明

```
其最长递增子序列有3个，（1，2，8）、（1，2，6）、（1，2，4）其中第三个字典序最小，故答案为（1，2，4）
```

## 备注:

```
n≤10^5
1<=arr[i]<=10^9
```



牛客要返回具体的数字，且多个结果返回字典序列最小的。

````java
public class Solution {
    /**
     * retrun the longest increasing subsequence
     * @param arr int整型一维数组 the array
     * @return int整型一维数组
     */
    public int[] LIS (int[] arr) {
        // write code here
    }
}
````



力扣中等

#### [300. 最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)

力扣只是输出序列长度。



解法：动归 + 二分。

时间：Nlogn

空间：On

如果全动归时间是On方，过不去。

````java
// Dynamic programming + Dichotomy.
class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] tails = new int[nums.length];
        int res = 0;
        for(int num : nums) {
            int i = 0, j = res;
            while(i < j) {
                int m = (i + j) / 2;
                if(tails[m] < num) i = m + 1;
                else j = m;
            }
            tails[i] = num;
            if(res == j) res++;
        }
        return res;
    }
}

作者：jyd
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-dong-tai-gui-hua-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
````



