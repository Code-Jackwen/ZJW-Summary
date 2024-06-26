1、vue的生命周期，如何实现
2、vue双向绑定的实现原理，为什么要用虚拟dom树 

 vue中对象和数组的区别 

 



遍历array 中的所有元素，设置两个变量：
excl: 不包含前一个元素的最大和
incl: 包含前一个元素的最大和



更新当前元素的 excl 和 incl：
不包含当前元素的最大和 excl = max(incl’， excl’)
包含当前元素的最大和 incl = excl’+current (元素不能相邻)

```
arr[] = 0 {3,  5, 10, 40, 50, 35}

 excl_new = (excl>incl)?excl:incl;
 incl = excl + arr[i];
 excl = excl_new;

1) arr[0] = 3
   incl = 3 
   excl = 0
2) arr[1] = 5
   incl =  (excl + arr[1])  = 5
   			  exc inc
   excl =  max(0, 3) = 3
3) arr[2] = 10
   incl =  (excl + arr[2])  = 15
   excl =  max(3, 5) = 5
4) arr[3] = 40
   incl =  (excl + arr[3])  = 45
   excl =  max(5, 13) = 13
5) arr[4] = 50
   incl =  (excl + arr[4])  = 65
   excl =  max(13, 45) = 45
5) arr[5] = 35
   incl =  (excl + arr[5])  = 80
   excl =  max(45, 63) = 63

answer is max(incl, excl) =  80
```



```java
public class Main {
    public static void main(String[] args) {
        int arr[] = {3,5,10,40,50,35};
        System.out.println(maxSum(arr, arr.length));
    }
    static int maxSum(int[] arr, int size)
    {
        if(size<=0)
            return 0;
        else if(size ==1)
            return arr[0];

        int excl = 0, incl = arr[0];
        int excl_new;
        for(int i = 1; i<size; ++i)
        {
            excl_new = (excl>incl)?excl:incl;
            incl = excl + arr[i];
            excl = excl_new;
        }
        return (incl>excl)?incl:excl;
    }
}
```

