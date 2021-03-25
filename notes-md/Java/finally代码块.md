## 深度解析 Finally 执行顺序

直接从案例3开始看吧。

一、 首先在大家的印象中，无论程序是否出现异常，Finally 代码块是一定会执行的。这个观点可能会让大家有些失望了，答案是否定的。接下来就让我来详细的给大家讲解一下吧。

#### 案例 1：

```java


public class Main {
    public static void main(String[] args) {
        System.out.println("main 代码块中的执行结果为：" + myMethod());
    }
    public static int myMethod() {
        int i = 0;
        int[] num = {1, 2, 3};
        
        System.out.println(num[3]);
        
        try {
            System.out.println("try 代码块被执行！");
            return 0;
        } catch (Exception e) {
            System.out.println("catch 代码块被执行！");
            return 0;
        } finally {
            System.out.println("finally 代码块被执行！");
        }
    }
}
```

其执行结果为：  

```java
Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: 3	at com.test.Main.myMethod(Main.java:15)	at com.test.Main.main(Main.java:7)
```

可以看到结果显示 数组**下标越界**，没有下标为 3 的这个索引，我们可以看到**并没有执行 finally 代码块中的打印语句**

 

#### 案例 2：

```java


public class Main {
    public static void main(String[] args) {
        System.out.println("main 代码块中的执行结果为：" + myMethod());
    }
    public static int myMethod() {
        int i = 0;
        int[] num = {1, 2, 3};
        if (i == 0) {
            return 0;
        }
        
        System.out.println(num[3]);
        
        try {
            System.out.println("try 代码块被执行！");
            return 0;
        } catch (Exception e) {
            System.out.println("catch 代码块被执行！");
            return 0;
        } finally {
            System.out.println("finally 代码块被执行！");
        }
    }
}
```

另外，当我们在 myMethod () 方法中添加如下这段

```java
if (i == 0) {    return 0;}
```

在运行代码，其结果如下，也没有执行 finally 代码块中的打印语句

```html
main 代码块中的执行结果为：0
```

 

通过以上例子可以看出，finally 代码块中的打印语句都没有被执行，这是为什么呢？

这是因为这两个例子都在 try 代码块之前就结束了 myMethod () 方法，try 代码块并没有得到执行，所以 finally 中的代码块也不会得到相应的执行。只有在 try 代码块得到执行的情况下，finally 代码块才会得到执行。

 

二、那么问题又来了，是不是只要 try 代码块得到执行了，finally 代码块才一定会执行呢？可能又会让你们失望了，答案是不一定会执行，这是为什么呢，请看如下的案例 3：

```java


public class Main {
    public static void main(String[] args) {
        System.out.println("main 代码块中的执行结果为：" + myMethod());
    }

    public static int myMethod() {
        try {
            System.out.println("try 代码块被执行！");
            System.exit(0);
            return 0;
        } catch (Exception e) {
            System.out.println("catch 代码块被执行！");
            return 0;
        } finally {
            System.out.println("finally 代码块被执行！");
        }
    }
}
```

执行结果为：

```html
try 代码块被执行！
```

可以看到只打印了 try 代码块中的语句，finally 代码块中的语句并没有打印，这是因为 System.exit (0)，它表示退出当前 Java 虚拟机，一旦退出 Java 虚拟机，任何代码都不会再执行。

#### 案例 3：

三、你们会说，写程序一般都不会写 **System.exit (0)；来退出 Java 虚拟机**，那么是不是不写 System.exit (0)；finally 代码块就一定会得到执行呢？

可能还是会让你们失望了，答案时不一定的，这又是为什么？来看这段文字，估计你应该会明白一些。

如果当一个线程在执行 try 语句块或者 catch 语句块时被打断（interrupted）或者被终止（killed），与其相对应的 finally 语句块可能不会执行。还有更极端的情况，就是在线程运行 try 语句块或者 catch 语句块时，**突然死机或者断电，finally 语句块肯定不会执行了。**

#### 案例 4：

四、下面来让我们讲解一下，再排除以上 finally 代码块得不到执行的情况外，finally 代码块与 try 代码块和 catch 代码块的执行顺序，**当 try 和 catch 代码块中有 return 语句时**，又是一个什么样的情况。请看如下的案例 4：

```java


public class Main {
    public static void main(String[] args) {
        System.out.println("main 代码块中的执行结果为：" + myMethod());
    }

    public static int myMethod() {
        int i = 6;
        try {
            System.out.println("try 代码块被执行！");
            //i = i / 0;
            return 1;
        } catch (Exception e) {
            System.out.println("catch 代码块被执行！");
            return 2;
        } finally {
            System.out.println("finally 代码块被执行！");
        }
    }
}
```

执行结果为：

```html
try 代码块被执行！
finally 代码块被执行！
main 代码块中的执行结果为：1		//注意
```

**可以看到 finally 代码块中的打印语句在 try 代码块中的 return 1; 语句之前被执行**



### 我的改编1：

```java
public class Main {
    public static void main(String[] args) {
        System.out.println("main 代码块中的执行结果为：" + myMethod());
    }

    public static int myMethod() {
        int i = 6;
        try {
            System.out.println("try 代码块被执行！");
            i = i / 0;
            return 1;
        } catch (Exception e) {
            System.out.println("catch 代码块被执行！");
            return 2;
        } finally {
            System.out.println("finally 代码块被执行！");
            return 3;
        }
    }
}
```

输出：

```
try 代码块被执行！
catch 代码块被执行！
finally 代码块被执行！
main 代码块中的执行结果为：3
```

参考下边这个案例， 改编1里面的 try 的 return 1; 是不再执行的了。

return 2; 之前要执行 finally 

然后 finally 的 return 3; 执行后，catch 的 return 2; 就不执行了。

### 我的改编2：

```java
public class Main {
    public static void main(String[] args) {
        System.out.println("main 代码块中的执行结果为：" + myMethod());
    }

    public static int myMethod() {
        int i = 6;
        try {
            i = i / 0;
            System.out.println("try 代码块被执行！");

            return 1;
        } catch (Exception e) {
            System.out.println("catch 代码块被执行！");
            return 2;
        } finally {
            System.out.println("finally 代码块被执行！");
            return 3;
        }
    }
}
```

输出：

```
catch 代码块被执行！
finally 代码块被执行！
main 代码块中的执行结果为：3
```

 try  下边报错后的代码就不执行了

catch 里面的 return  也要让步于 finally 的  return 3;

### **这个案例有意义**

catch 有 return
finally 没有 return

当把 i = i/0; 前面的注释符去掉之后，其执行结果为：

```html
try 代码块被执行！
catch 代码块被执行！
finally 代码块被执行！
main 代码块中的执行结果为：2		//注意
```

可以看到 finally 代码块在 catch 代码块中的 return 2; 语句之前被执行

#### 案例 5：

五、 通过以上案例，是不是觉得自己对 finally 已经掌握颇深了呢？别急，还有一些是你不了解的，请听我来给你详细的讲解一下。请看如下的案例 5：

```java


public class Main {
    public static void main(String[] args) {
        System.out.println("main 代码块中的执行结果为：" + myMethod());
    }

    @SuppressWarnings("finally")
    public static int myMethod() {
        try {
            System.out.println("try 代码块被执行！");
            return 1;
        } catch (Exception e) {
            System.out.println("catch 代码块被执行！");
            return 2;
        } finally {
            System.out.println("finally 代码块被执行！");
            return 3;
        }
    }
}
```

其执行结果为：

```html
try 代码块被执行！
finally 代码块被执行！
main 代码块中的执行结果为：3
```

想必看了执行结果应该很容易理解，**因为 finally 代码块要在 try 代码块中的 return 1; 语句之前执行**，所以当执行到 finally 代码块中的 return 3; 语句时，myMethod () 方法就结束了，并返回一个 3。

**就把 try 里的 return 给省去不执行了。**

#### 案例 6：

六、再来看一个案例，大家可以先不看执行结果，想一下它的执行结果会是什么样子的，请看如下的案例 6：

```java
public class Main {
    public static void main(String[] args) {
        System.out.println("main 代码块中的执行结果为：" + myMethod());
    }

    public static int myMethod() {
        int i = 1;
        try {
            System.out.println("try 代码块被执行！");
            return i;
        } finally {
            ++i;
            System.out.println("finally 代码块被执行！");
            System.out.println("finally 代码块中的i = " + i);
            //return i;
        }
    }
}
```

执行结果为：

```html
try 代码块被执行！
finally 代码块被执行！
finally 代码块中的i = 2			//注意这一行
main 代码块中的执行结果为：1		//注意这一行
```

是不是觉得结果有点出乎意料，最后一句输出语句的执行结果应该为 2，可为什么是 1 呢？而且 finally 代码块中的 ++i 语句也的确在 try 代码块中的 return i; 语句之前得到执行了，finally 代码块中的 i 也确实变成了 2，可是为什么 main 函数打印出来的结果却是 1 呢？

通俗的说就是：**先会把 try 或者 catch 代码块中的返回值保留，再来执行 finally 代码块中的语句，等到 finally 代码块执行完毕之后，在把之前保留的返回值给返回出去。**  

请注意，对于前面这条规则（保留返回值），**只适用于 return 和 throw 语句，不适用于 break 和 continue 语句，因为它们根本就没有返回值。**

这样就能够理解为什么打印的是 1，而不是 2 了，这是因为 try 代码块中先会保留 return 返回的 1，然后再去执行 finally 代码块中的 ++i，i 的值虽然变成了 2，可是保留的值还是 1，没有变，所以等到 finally 代码块执行完毕之后，try 代码块就会把保留值 1 给返回出去

 

放开注释	//return i;

输出：

```
try 代码块被执行！
finally 代码块被执行！
finally 代码块中的i = 2
main 代码块中的执行结果为：2
```

**就把 try 里的 return 给省去不执行了。**



变式1：

```java
public class Main {
    public static void main(String[] args) {
        System.out.println("main 代码块中的执行结果为：" + myMethod());
    }

    public static int myMethod() {
        int i = 1;
        try {
            System.out.println("try 代码块被执行！");
            i = i / 0;
            return i;
        } catch (Exception e) {
            return i;
        } finally {
            ++i;
            System.out.println("finally 代码块被执行！");
            System.out.println("finally 代码块中的i = " + i);
            //return i;
        }
    }
}
```

```
try 代码块被执行！
finally 代码块被执行！
finally 代码块中的i = 2
main 代码块中的执行结果为：1
```

放开注释后，答案以 finally 返回的为准。

```
try 代码块被执行！
finally 代码块被执行！
finally 代码块中的i = 2
main 代码块中的执行结果为：2
```







七、有了上面的讲解，我们在来看一下下面的这几个案例

#### 案例 7：

```java


public class Main {
    public static void main(String[] args) {
        System.out.println("main 代码块中的执行结果为：" + myMethod());
    }

    @SuppressWarnings("finally")
    public static int myMethod() {
        int i = 1;
        try {
            System.out.println("try 代码块被执行！");
        } finally {
            ++i;
            System.out.println("finally 代码块被执行！");
            System.out.println("finally 代码块中的i = " + i);
            return i;
        }
    }
}
```

其执行结果为:

```html
try 代码块被执行！
finally 代码块被执行！
finally 代码块中的i = 2
main 代码块中的执行结果为：2
```

 

#### 案例 8：

```java


public class Main {
    public static void main(String[] args) {
        System.out.println("main 代码块中的执行结果为：" + myMethod());
    }

    public static int myMethod() {
        int i = 1;
        try {
            System.out.println("try 代码块被执行！");
            i = 3;
        } finally {
            ++i;
            System.out.println("finally 代码块被执行！");
            System.out.println("finally 代码块中的i = " + i);
        }
        return i;
    }
}
```

 其执行结果为:

```html
try 代码块被执行！
finally 代码块被执行！
finally 代码块中的i = 4
main 代码块中的执行结果为：4
```

 

#### 案例 9

八、以上的两个案例都比较好理解，接下来看一下下面这个案例 9，大家可以先不看执行结果，来想一下它的执行情况

```java


public class Main {
    public static void main(String[] args) {
        System.out.println("main 代码块中的执行结果为：" + myMethod());
    }

    public static int myMethod() {
        try {
            System.out.println("try 代码块被执行！");
            return num();
        } finally {
            System.out.println("finally 代码块被执行！");
            //return 3;
        }
    }

    public static int num() {
        System.out.println("num 代码块被执行！");
        return 2;
    }
}
```

 

其执行结果为:

```html
try 代码块被执行！
num 代码块被执行！
finally 代码块被执行！
main 代码块中的执行结果为：2
```

是不是觉得很奇怪，num () 方法中的打印语句居然在 finally 代码块中的打印语句之前被执行，而 finally 代码块的打印语句又在 num () 方法中的 return 2; 语句之前被打印，这又是为什么呢？

其实  return num ();  等同于下面这段代码

```java
int sum = num();
return sum;
```

所以就会先打印 num () 方法中的语句，后打印 finally 代码块中的语句。



放开 注释后 //return 3;

```
try 代码块被执行！
num 代码块被执行！
finally 代码块被执行！
main 代码块中的执行结果为：3
```





总的来说，try catch 有return 会给 finally 里面的return 让步，因为执行顺序的原因，finally 的return 结果会优先。

而 i++ 类问题，try 会有缓存的意思，不受finally 里面的 i++ 影响。

