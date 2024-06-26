其他未参考：

高分：https://blog.csdn.net/qq_40164190/article/details/81917208



##### nextInt () 

只读取数值，剩下 "\n" 还没有读取，并将 cursor 放在本行中

##### next () 

next () 方法遇见第一个有效字符（非空格，非换行符）时，开始扫描，当遇见第一个分隔符或结束符 (**空格**或**换行符**) 时，**结束**扫描，获取扫描到的内容，即**获得第一个扫描到的不含空格、换行符的单个字符串。** 

##### nextLine () 

可以扫描到一行内容并作为一个字符串而被获取到。 



##### nextLine () 的吞并现象

````java
public class NextTest{  
    public static void main(String[] args) {  
        String s1,s2;  
        Scanner sc=new Scanner(System.in);  
        System.out.print("请输入第一个字符串：");  
        s1=sc.nextLine();  
        System.out.print("请输入第二个字符串：");  
        s2=sc.next();  
        System.out.println("输入的字符串是："+s1+" "+s2);  
    }  
}  
//结果
请输入第一个字符串：home
请输入第二个字符串：work
输入的字符串是：home work
````

可以看到，nextLine () 自动读取了被 next () 去掉的 Enter 作为他的结束符，所以没办法给 s2 从键盘输入值。

经过验证，我发现其他的 next 的方法，如 double nextDouble () ， float nextFloat () ， int nextInt () 等与 nextLine () 连用时都存在这个问题。

解决的办法是：

在每一个 next ()、nextDouble () 、 nextFloat ()、nextInt () 等语句之后**加一个 nextLine () 语句，将被 next () 去掉的 Enter 结束符过滤掉**。 

````java
public class NextTest{  
    public static void main(String[] args) {  
        String s1,s2;  
        Scanner sc=new Scanner(System.in);  
        System.out.print("请输入第一个字符串：");  
        s1=sc.next();  
        sc.nextLine();
        System.out.print("请输入第二个字符串：");  
        s2=sc.nextLine();  
        System.out.println("输入的字符串是："+s1+" "+s2);  
    }  
}  
//此时的顺序是
s1=sc.next();  
sc.nextLine();
s2=sc.nextLine();
//看似多了 sc.nextLine(); 但却是正确的期待写法。

//结果：
请输入第一个字符串：home
请输入第二个字符串：work
输入的字符串是：home work
````

改版

````java
把上面的程序两行的顺序修改一下：
s1=sc.next();  
s2=sc.nextLine();  
运行结果：
请输入第一个字符串：home
请输入第二个字符串：输入的字符串是：home
````

##### Demo1

````java
public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    // 一个while就是一个测试用例，没结束。。。。
    while(in.hasNext()){
        int n = in.nextInt(); // 该测试用例后续接收的参数个数
        long[] array = new long[n];
        String[] arrayStr = new String[n];
        for(int i=0; i<n; i++){
            arrayStr[i] = in.next();
        }
        for(int i=0; i<n; i++){
            array[i] = in.nextLong();// 取下一个元素转换成long类型
        }
        System.out.println(Arrays.toString(arrayStr)+" "+ Arrays.toString(array));
    }
}
````

````
//正常
2
112 21 11 21
[112, 21] [11, 21]
2
31 23 32 11
[31, 23] [32, 11]
````

````
//故意不正常输入
2
112 21 11 21 3
[112, 21] [11, 21]
31 23 32 11 22 111 1 1
[31, 23, 32] [11, 22, 111]
3 4
[1] [3]
````

##### Demo2

````java
public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    while (in.hasNext()) {
        int n = in.nextInt();
        /* nextLine()是扫描器执行当前行，并返回跳过的输入信息，特别需要注意！！！
			如果没有该行，则执行第一个in.nextLine()命令时的返回值是int n = in.nextInt()的值*/
        in.nextLine();//让它读了 上边int n = in.nextInt()的值，但是不存。
        HashSet<String> set = new HashSet<String>();
        for (int i = 0; i < n; i++) {
            String line = in.nextLine();
            String[] arr = line.split(" ");
            for (int j = 0; j < arr.length; j++) {
                set.add(arr[j]);
            }
        }
        System.out.println("sum:" + set.size());
    }
}
````

````
//输出
1
a s s
sum:2
3
a aa bb
c d ee
f wq at
sum:9

//其他
输入：
3
a b c
d e f
a b c
输出：
6
````

一般情况下，通过 Scanner 类的 next () 与 nextLine () 方法获取输入的字符串
但是在读取前我们一般需要 使用 hasNext 与 hasNextLine 判断是否还有输入的数据

##### hasNext() 与 next()小Demo

````java
public static void main(String[] args) {
    Scanner s = new Scanner(System.in); // 从键盘接收数据
    // next方式接收字符串
    System.out.println("next方式接收：");
    // 判断是否还有输入
    if (s.hasNext()) {
        String str1 = s.next();
        System.out.println("输入的数据为：" + str1);
    }
    s.close
}
````

````txt
//输出：
next方式接收：
hello world
输入的数据为：hello

next方式接收：
1 2
输入的数据为：1

next方式接收：
    1 2 
输入的数据为：1

next方式接收：
   123 321 
输入的数据为：123
````

##### next () 和 nextLine() 区别

next ()：
1、一定要读取到有效字符后才可以结束输入。
2、对输入有效字符之前遇到的空白，next () 方法会自动将其去掉。
3、只有输入有效字符后才将其后面输入的空白作为分隔符或者结束符。
**next () 不能得到带有空格的字符串。**

空格就可以结束它，且得到值永远不会有空格。

nextLine()：

- 1、以 Enter 为结束符，也就是说 nextLine () 方法返回的是输入回车之前的所有字符。
- 2、可以获得空白。

##### nextInt() 小Demo

````java
public static void main(String[] args) {
    Scanner s = new Scanner(System.in); // 从键盘接收数据
    System.out.println("nextInt()方式接收：");
    int str1 = s.nextInt();
    System.out.println("输入的数据为：" + str1);
}
````

````java
//输出
nextInt()方式接收：
   123  321   
输入的数据为：123
````

##### hasNextLine() 与 nextLine() 小Demo

````java
import java.util.Scanner;
public class scannertest2 {
	
	public static void main(String[] args) {
        Scanner s = new Scanner(System.in); // 从键盘接收数据
        // next方式接收字符串
        System.out.println("nextLine方式接收：");
        // 判断是否还有输入
        if (s.hasNextLine()) {
            String str2 = s.nextLine();
            System.out.println("输入的数据为：" + str2);
        }
        s.close();
    }
}
````

````
nextLine方式接收：
		hello world 2018	
输入的数据为：		hello world 2018	
````

总结

nextLine () 

1、以 Enter 为结束符 , 也就是说 nextLine () 方法返回的是输入回车之前的所有字符；

2、前后都可以获得空白，都会读入，空格等均会被识别；

注意：如果要输入 int 或 float 类型的数据，在 Scanner 类中也有支持，但是在输入之前最好先使用 hasNextXxx() 方法进行验证，再使用 nextXxx() 来读取。

##### hasNextDouble() 与 nextDouble()小Demo 以及终止

下面实现的功能是可以输入多个数字，并求其总和与平均数。**hasNextDouble（）**，**每输入一个数字用回车确认**，通过输入非数字来结束输入并输出执行结果：

```java
public static void main(String[] args) {
    System.out.println("请输入数字：");
    Scanner scan = new Scanner(System.in);
    double sum = 0;
    int m = 0;
    while (scan.hasNextDouble()) {
        double x = scan.nextDouble();
        m = m + 1;
        sum = sum + x;
    }
    System.out.println(m + "个数的和为" + sum);
    System.out.println(m + "个数的平均值是" + (sum / m));
}
请输入数字： 
20.0
30.0
40.0
end
3个数的和为90.0
3个数的平均值是30.0 	//然后程序结束
    
请输入数字：
1 2 3 
1 2 3
1 2 3
end
9个数的和为18.0
9个数的平均值是2.0
```
总结：

输入end算结束

参考：

https://blog.csdn.net/weixin_30363263/article/details/79700588



##### 终止：while(!sc.hasNext("#"))

Demo1

```java
 public static void main(String[] args)
 {
     System.out.println("请输入若干单词，以空格作为分隔");//回车代表结束
     Scanner sc = new Scanner(System.in);
     while(sc.hasNext())//对sc 哪一行 以空格 分开，像是数组
     {
         System.out.println("键盘输入的内容是："
                            + sc.next());//每个sc.next() 是数组 中每个位置的结果
     }//循环会一直 扫描缓冲区  再次写到缓冲区再次执行
     System.out.println("执行吗?  结果没执行");
 }
```

Demo2

````java
public static void main(String[] args)
{
    System.out.println("请输入若干单词，以空格作为分隔");
    Scanner sc = new Scanner(System.in);
    while(!sc.hasNext("#"))  //匹配#返回true,然后取非运算。即以#为结束符号
    {
        System.out.println("键盘输入的内容是："  + sc.next());
    }
    System.out.println("会执行的");
}
````

参考：

Scanner 的 hasNext () 方法：https://blog.csdn.net/gao_zhennan/article/details/80562548