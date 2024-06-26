## 保留 n 位小数

### 1、返回double型的

**能四舍五入**

可以用 Math.round()  

```java
double d = 114.1455555;						//传入double类型，默认返回long类型。
d = (double) Math.round(d);					//正常的话是四舍五入到小数第1位
System.out.println(d);//114.0

double d = 114.1455555;
d = (double) Math.round(d * 100) / 100;		//操作一下，让返回四舍五入到小数第2位
System.out.println(d);//114.15

double d = 114.1455555;
d = (double) Math.round(d * 1000) / 1000;	//操作一下，让返回四舍五入到小数第3位
System.out.println(d);//114.146

double d = 114.1455555;
d = Math.round(d * 1000) / 1000;	
System.out.println(d);114.0
```

可以用 BigDecimal 

```
BigDecimal.ROUND_HALF_UP表示**四舍五入**

BigDecimal.ROUND_HALF_DOWN是**五舍六入**

BigDecimal.ROUND_UP表示**进位处理**（**就是直接加1**）

BigDecimal.ROUND_DOWN表示**直接去掉尾数**。
```

```java
double d = 114.145;
BigDecimal b = new BigDecimal(d);
d = b.setScale(2, BigDecimal.ROUND_HALF_UP).doubleValue();        
System.out.println(d);//114.14
```

### 2、返回String型的

 **能四舍五入**

String.format("%.3f", x);  第二个参数是边长参数，Object类型。

```java
 public static void main(String[] args) {
     double x = 123456789.987654312;
     float f = 789.98765f;
     String s1 = String.format("%.3f", x);
     System.out.println(s1);
     String s2 = String.format("%.3f", f);
     System.out.println(s2);
 }
```

 \#.00 表示保留后两位，它的处理方式是直接截掉不要的尾数，不四舍五入。 

```java
double d = 114.145;
DecimalFormat df = new DecimalFormat("#.00");
String str = df.format(d);
System.out.println(str);//114.14
```

## 参考

[Java中Double保留后小数位的几种方法](https://www.cnblogs.com/dichuan/p/7769098.html)

