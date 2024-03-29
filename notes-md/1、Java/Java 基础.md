# Java 基础
<!-- GFM-TOC -->
* [Java 基础](#java-基础)
    * [一、数据类型](#一数据类型)
        * [基本类型](#基本类型)
        * [包装类型](#包装类型)
        * [缓存池](#缓存池)
    * [二、String](#二string)
        * [概览](#概览)
        * [不可变的好处](#不可变的好处)
        * [String, StringBuffer and StringBuilder](#string-stringbuffer-and-stringbuilder	)
        * [String Pool](#string-pool)
        * [new String("abc")](#new-stringabc)
    * [三、运算](#三运算)
        * [参数传递](#参数传递)
        * [float 与 double](#float-与-double)
        * [隐式类型转换](#隐式类型转换)
        * [switch](#switch)
    * [四、关键字](#四关键字)
        * [final](#final)
        * [static](#static)
    * [五、Object 通用方法](#五object-通用方法)
        * [概览](#概览)
        * [equals()](#equals)
        * [hashCode()](#hashcode)
        * [toString()](#tostring)
        * [clone()](#clone)
    * [六、继承](#六继承)
        * [访问权限](#访问权限)
        * [抽象类与接口](#抽象类与接口)
        * [super](#super)
        * [重写与重载](#重写与重载)
    * [七、反射](#七反射)
    * [八、异常](#八异常)
    * [九、泛型](#九泛型)
    * [十、注解](#十注解)
    * [十一、特性](#十一特性)
        * [Java 各版本的新特性](#java-各版本的新特性)
        * [Java 与 C++ 的区别](#java-与-c-的区别)
        * [JRE or JDK](#jre-or-jdk)
    * [参考资料](#参考资料)
    <!-- GFM-TOC -->

## ⾯向对象和⾯向过程的区别

**⾯向过程**：⽐如单⽚机、嵌⼊式开发、Linux/Unix 等⼀般采⽤⾯向过程开发。

⾯向过程性能⽐⾯向对象⾼。⾯向过程没有⾯向对象易维护、易复⽤、易扩展。

**⾯向对象**：⾯向对象易维护、易复⽤、易扩展。因为⾯向对象有封装、继承、多态性的特性，所以可以设计出低耦合的系统，使系统更加灵活、更加易于维护。但是，⾯向对象性能⽐⾯向过程低。



⾯向过程性能好的原因：

⾯向过程语⾔**⼤多**都是直接编译成**机械码**在电脑上执⾏，并且其它⼀些⾯向过程的脚本语⾔性能也并不⼀定⽐ Java 好。**Java 是半编译语⾔**，最终的执⾏代码并**不是可以直接被 CPU 执⾏的⼆进制机械码**。

## Java 语⾔有哪些特点

1、⾯向对象（封装，继承，多态）

2、平台⽆关性（ Java 虚拟机实现平台⽆关性）；

3、⽀持多线程（C++ 语⾔没有内置的多线程机制，因此必须调⽤操作系统的多线程功能来进⾏多线程程序设计）

4、⽀持⽹络编程并且很⽅便（ Java 语⾔诞⽣本身就是为简化⽹络编程设计）

5、⾃动内存管理机制

## JVM、JDK 和 JRE 

Java 虚拟机（JVM）是运⾏ Java 字节码的虚拟机。JVM 可以理解的代码就叫做**字节码**（即扩展名为.class的⽂件）。JVM 有针对不同系统的特定实现（Windows，Linux，macOS），⽬的是使⽤相同的字节码，它们都会给出相同的结果。

Java 程序从源代码到运⾏⼀般有下⾯ 3 步：

![1613391173976](../../../../../项目/Git-md/ZJW-Summary/assets/1613391173976.png)



.class->机器码这⼀步。在这⼀步 **JVM 类加载器**⾸先加载字节码⽂件，然后通过**解释器逐⾏解释执⾏**，这种⽅式的执⾏速度会相对慢。

**JIT 编译器**完成第⼀次编译后，其会将字节码对应的机器码保存下来，运⾏效率肯定是⾼于 Java 解释器。

**HotSpot** 采⽤了**惰性评估**(Lazy Evaluation)的做法，根据⼆⼋定律，消耗⼤部分系统资源的只有那⼀⼩部分的代码（**热点代码**），⽽这也就是 JIT 所需要编译的部分。

## JDK 和 JRE

JDK 是 **Java Development Kit**，它是功能⻬全的 Java SDK。它**拥有 JRE** 所拥有的⼀切，**还有编译器（javac）****和**⼯具（如 javadoc 和 jdb）**。它能够**创建和编译程序**。



JRE 是 Java **运⾏时环境**。包括 Java 虚拟机（**JVM**），Java **类库**，java 命令和其他的⼀些基础构件。但是，它不能⽤于创建新程序。

一般如果只是为了运⾏⼀下 Java 程序的话，那么你只需要安装 JRE 就可以了。

## Java 和 C++的区别

1、都是**⾯向对象**的语⾔，都⽀持**封装、继承和多态**

2、J**ava 不提供指针**来直接访问内存，**程序内存更加安全**

3、Java 的类是单继承的，**C++ ⽀持多重继承**；虽然 Java 的类不可以多继承，但是接⼝可以多继承。

4、Java 有**⾃动内存管理机制**，不需要程序员⼿动释放⽆⽤内存

5、在 C 语⾔中，字符串或字符数组最后都会有⼀个额外的字符‘\0’来表示结束。但是，**Java 语⾔中没有结束符这⼀概念**。



## 重载和重写

重载

**就是同⼀个类中多个同名⽅法根据不同的传参来执⾏不同的逻辑处理。**

发⽣在同⼀个类中，**⽅法名必须相同**，参数类型不同、个数不同、顺序不同，**⽅法返回值和访问修饰符可以不同。**

也就是除了方法名必须相同。可以声明更广的检查异常。只以返回值不同，不能作为重载标准。

重写

发⽣在**运⾏期**，是⼦类对⽗类的允许访问的⽅法的实现过程进⾏重新编写。

1、**返回值类型、⽅法名、参数列表必须相同，抛出的异常范围⼩于等于⽗类，访问修饰符范围⼤于等于⽗类。**

2、**如果⽗类⽅法访问修饰符为private/final/static则⼦类就不能重写该⽅法，但是被 static 修饰的⽅法能够被再次声明。**

3、 **构造⽅法⽆法被重写**

综上：**重写就是⼦类对⽗类⽅法的重新改造，外部样⼦不能改变，内部逻辑可以改变。**

## 封装、继承、多态

封装

把⼀个对象的属性私有化，同时提供⼀些可以被外界访问的属性的⽅法。

继承

1、⼦类拥有⽗类对象所有的属性和⽅法（包括私有属性和私有⽅法），但是⽗类中的私有属性和⽅法⼦类是**⽆法访问，只是拥有**。

2、⼦类可以拥有⾃⼰属性和⽅法，即⼦类可以对⽗类进⾏**扩展**。

多态

**多态就是同一个接口，使用不同的实例而执行不同操作**，即⼀个引⽤**变量到底会指向哪个类的实例对象**，该引⽤变量发出的⽅法**调⽤到底是哪个类中实现的⽅法**，必须在由程序运⾏期间才能决定。

实现多态：

1、继承（多个⼦类对同⼀⽅法的重写）

2、接⼝（实现接⼝并覆盖接⼝中同⼀⽅法）。

- 父类引用指向子类对象：Parent p = new Child();

多态的优点：消除类型之间的耦合，可替换、扩充、灵活。

## 构造函数

Java 程序在执⾏⼦类的构造⽅法之前，**如果没有⽤super()来调⽤⽗类特定的构造⽅法**，则会调⽤⽗类中“没有参数的构造⽅法”。这样是帮助⼦类做初始化⼯作。

因此，如果⽗类中**只定义了有参数的构造⽅法**，⽽在⼦类的构造⽅法中⼜没有⽤super()来调⽤⽗类中特定的构造⽅法，**则编译时将发⽣错误**，因为 Java 程序在⽗类中找不到没有参数的构造⽅法可供执⾏。**解决办法是在⽗类⾥加上⼀个不做事且没有参数的构造⽅法。**

## 接⼝和抽象类的区别

1、接⼝的**⽅法默认是public**，所有⽅法在接⼝中**不能有实现**(Java 8 开始接⼝⽅法可以有默认实现），⽽**抽象类可以有⾮抽象的⽅法**。

2、接⼝中除了**static、final变量**，不能有其他变量，⽽抽象类中则不⼀定。抽象类可以有构造方法。接口不可以。default 不可以修饰抽象类的变量和方法。default 修饰的接口方法必须有函数体。抽象类里面的字段方法都可以protected修饰。抽象类字段也是final的，但还有个小点是抽象类这样只声明不赋值不报错，但在普通类会报错，写了构造方法才不报错。

3、**⼀个类可以实现多个接⼝，但只能实现⼀个抽象类**。**接⼝⾃⼰本身可以通过extends关键字扩展多个接⼝**

4、接⼝⽅法默认修饰符是public，**抽象⽅法可以有public、protected和default这些修饰符**（**抽象⽅法就是为了被重写所以不能使⽤private关键字修饰**！）。

5、从设计层⾯来说，**抽象类是对类的抽象，是⼀种模板设计**，⽽**接⼝是对⾏为的抽象**，是⼀种**⾏为的规范**。

扩展：

1、 **Jdk 9** 在接⼝中引⼊了**私有⽅法和私有静态⽅法。jdk 8** 的时候接⼝可以有**默认⽅法和静态⽅法功能。**

2、在 JDK8 中，接⼝也可以定义**静态⽅法**，可以直接⽤接⼝名调⽤。**实现类和实现是不可以调⽤的。**

如果同时**实现两个接⼝**，接⼝中定义了⼀样的**默认⽅法**，则必须重写，不然会报错。

## 成员变量与局部变量的区别

1、从语法形式上看:成员变量是属于**类**的，⽽局部变量是在⽅法中定义的变量或是**⽅法**的参数；成员变量可以被public,private,static等修饰符所修饰，⽽**局部变量不能被访问控制修饰符及static所修饰**；但是，成员变量和局部变量**都能被final所修饰**。

2、从变量在内存中的存储⽅式来看:如果成员变量是使⽤static修饰的，那么这个成员变量是属于类的，如果没有使⽤static修饰，这个成员变量是属于实例的。对象存于堆内存，如果局部变量类型为基本数据类型，那么存储在**栈内存**，如果为引⽤数据类型，那存放的是指向**堆内存对象的引⽤**或者是**指向常量池中的地址**。

3、从变量在内存中的⽣存时间上看:成员变量是对象的⼀部分，它随着**对象**的创建⽽存在，⽽局部变量随着**⽅法**的调⽤⽽⾃动消失。

4、成员变量如果没有被赋初值:则会⾃动以类型的默认值⽽赋值（⼀种情况例外:**被final修饰的成员变量也必须显式地赋值**），⽽局部变量则不会⾃动赋值。

## 对象实体与对象引⽤

创建⼀个对象⽤ new 运算符，**new 创建对象实例**（对象实例在堆内存中）。对象引⽤指向对象实例（**对象引⽤存放在栈内存中**）。⼀个对象引⽤可以指向 0 个或 1 个对象（⼀根绳⼦可以不系⽓球，也可以系⼀个⽓球）;⼀个对象可以有 n 个引⽤指向它（可以⽤ n 条绳⼦系住⼀个⽓球）。


## 数据类型

### 基本类型

- byte/8
- char/16
- short/16
- int/32
- float/32
- long/64
- double/64
- boolean/\~

boolean 只有两个值：true、false，**可以使用 1 bit 来存储**，但是**具体大小没有明确规定**。**JVM 会在编译时期将 boolean 类型的数据转换为 int，使用 1 来表示 true，0 表示 false。JVM 支持 boolean 数组，但是是通过读写 byte 数组来实现的。**

- [Primitive Data Types](https://docs.oracle.com/javase/tutorial/java/nutsandbolts/datatypes.html)
- [The Java® Virtual Machine Specification](https://docs.oracle.com/javase/specs/jvms/se8/jvms8.pdf)

### 包装类型

基本类型都有对应的包装类型，基本类型与其对应的包装类型之间的赋值使用自动装箱与拆箱完成。

```java
Integer x = 2;     // 装箱 调用了 Integer.valueOf(2)
int y = x;         // 拆箱 调用了 X.intValue()
```

- [Autoboxing and Unboxing](https://docs.oracle.com/javase/tutorial/java/data/autoboxing.html)

### 缓存池

new Integer(123) 与 Integer.valueOf(123) 的区别在于：

- new Integer(123) 每次都会新建一个对象；
- **Integer.valueOf(123) 会使用缓存池中的对象，多次调用会取得同一个对象的引用。**

```java
Integer x = new Integer(123);
Integer y = new Integer(123);
System.out.println(x == y);    // false
Integer z = Integer.valueOf(123);
Integer k = Integer.valueOf(123);
System.out.println(z == k);   // true
```

valueOf() 方法的实现比较简单，就是先判断值是否在缓存池中，如果在的话就直接返回缓存池的内容。

```java
public static Integer valueOf(int i) {
    if (i >= IntegerCache.low && i <= IntegerCache.high)
        return IntegerCache.cache[i + (-IntegerCache.low)];
    return new Integer(i);
}
```

在 Java 8 中，**Integer 缓存池的大小默认为 -128\~127。**

```java
static final int low = -128;
static final int high;
static final Integer cache[];

static {
    // high value may be configured by property
    int h = 127;
    String integerCacheHighPropValue =
        sun.misc.VM.getSavedProperty("java.lang.Integer.IntegerCache.high");
    if (integerCacheHighPropValue != null) {
        try {
            int i = parseInt(integerCacheHighPropValue);
            i = Math.max(i, 127);
            // Maximum array size is Integer.MAX_VALUE
            h = Math.min(i, Integer.MAX_VALUE - (-low) -1);
        } catch( NumberFormatException nfe) {
            // If the property cannot be parsed into an int, ignore it.
        }
    }
    high = h;

    cache = new Integer[(high - low) + 1];
    int j = low;
    for(int k = 0; k < cache.length; k++)
        cache[k] = new Integer(j++);

    // range [-128, 127] must be interned (JLS7 5.1.7)
    assert IntegerCache.high >= 127;
}
```

编译器会在**自动装箱过程调用 valueOf() 方法**，因此多个值相同且值在缓存池范围内的 Integer 实例使用自动装箱来创建，那么就会引用相同的对象。

```java
Integer m = 123;
Integer n = 123;
System.out.println(m == n); // true
```

基本类型对应的缓冲池如下：

- **boolean** values true and false
- all **byte** values
- **short** values between -128 and 127
- **int** values between -128 and 127
- **char** in the range \u0000 to \u007F

在使用这些基本类型对应的包装类型时，**如果该数值范围在缓冲池范围内，就可以直接使用缓冲池中的对象。**

在 jdk 1.8 所有的数值类缓冲池中，**Integer 的缓冲池 IntegerCache 很特殊**，这个缓冲池的下界是 - 128，上界默认是 127，但是这个**上界是可调的**，在启动 jvm 的时候，通过 -XX:AutoBoxCacheMax=&lt;size&gt; 来指定这个缓冲池的大小，该选项在 JVM 初始化的时候会设定一个名为 **java.lang.IntegerCache.high 系统属性**，然后 IntegerCache 初始化的时候就会读取该系统属性来决定上界。

[StackOverflow : Differences between new Integer(123), Integer.valueOf(123) and just 123
](https://stackoverflow.com/questions/9030817/differences-between-new-integer123-integer-valueof123-and-just-123)

## String

### 概览

String 被声明为 final，因此它不可被继承。(Integer 等包装类也不能被继承）

在 Java 8 中，String 内部使用 char 数组存储数据。

```java
public final class String
    implements java.io.Serializable, Comparable<String>, CharSequence {
    /** The value is used for character storage. */
    private final char value[];
}
```

在 Java 9 之后，**String 类的实现改用 byte 数组存储字符串**，同时使用 `coder` 来标识使用了哪种**编码**。

```java
public final class String
    implements java.io.Serializable, Comparable<String>, CharSequence {
    /** The value is used for character storage. */
    private final byte[] value;

    /** The identifier of the encoding used to encode the bytes in {@code value}. */
    private final byte coder;
}
```

value 数组被**声明为 final**，这意味着 value 数组初始化之后就不能再引用其它数组。并且 **String 内部没有改变 value 数组的方法**，因此可以保证 String 不可变。

### 不可变的好处

**1. 可以缓存 hash 值**  

因为 String 的 hash 值经常被使用，例如 String 用做 HashMap 的 key。不可变的特性可以使得 hash 值也不可变，因此只需要进行一次计算。

**2. String Pool 的需要**  

如果一个 String 对象已经被创建过了，那么就会从 String Pool 中取得引用。只有 String 是不可变的，才可能使用 String Pool。

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/image-20191210004132894.png"/> </div><br>
**3. 安全性**  

String 经常作为参数，String 不可变性可以保证参数不可变。例如在作为网络连接参数的情况下如果 String 是可变的，那么在网络连接过程中，String 被改变，改变 String 的那一方以为现在连接的是其它主机，而实际情况却不一定是。

**4. 线程安全**  

String **不可变性天生具备线程安全**，可以在多个线程中安全地使用。

[Program Creek : Why String is immutable in Java?](https://www.programcreek.com/2013/04/why-string-is-immutable-in-java/)

### String, StringBuffer and StringBuilder	

**1. 可变性**  

- String 不可变
- StringBuffer 和 StringBuilder 可变

**2. 线程安全**  

- String 不可变，因此是线程安全的
- StringBuilder 不是线程安全的
- StringBuffer 是线程安全的，内部使用 synchronized 进行同步

[StackOverflow : String, StringBuffer, and StringBuilder](https://stackoverflow.com/questions/2971315/string-stringbuffer-and-stringbuilder)

### String Pool

字符串常量池（String Pool）保存着所有字符串字面量（literal strings），这些字面量在编译时期就确定。不仅如此，还可以使用 **String 的 intern() 方法在运行过程将字符串添加到 String Pool 中。**

当一个字符串调用 intern() 方法时，如果 String Pool 中已经存在一个字符串和该字符串值相等（使用 equals() 方法进行确定），那么就会返回 String Pool 中字符串的引用；**否则，就会在 String Pool 中添加一个新的字符串，并返回这个新字符串的引用。**

下面示例中，s1 和 s2 采用 new String() 的方式新建了两个不同字符串，**而 s3 和 s4 是通过 s1.intern() 和 s2.intern() 方法取得同一个字符串引用。**intern() 首先把 "aaa" 放到 String Pool 中，然后返回这个字符串引用，因此 s3 和 s4 引用的是同一个字符串。

```java
String s1 = new String("aaa");
String s2 = new String("aaa");
System.out.println(s1 == s2);           // false
String s3 = s1.intern();
String s4 = s2.intern();
System.out.println(s3 == s4);           // true
```

**如果是采用 "bbb" 这种字面量的形式创建字符串，会自动地将字符串放入 String Pool 中。**

```java
String s5 = "bbb";
String s6 = "bbb";
System.out.println(s5 == s6);  // true
```

在 Java **7 之前**，String Pool 被放在运行时常量池中，它属于**永久代**。而在 Java 7，String Pool 被移到**堆**中。这是因为永久代的空间有限，在大量使用字符串的场景下会导致 OutOfMemoryError 错误。

- [StackOverflow : What is String interning?](https://stackoverflow.com/questions/10578984/what-is-string-interning)
- [深入解析 String#intern](https://tech.meituan.com/in_depth_understanding_string_intern.html)

### new String("abc")

使用这种方式一共会创建**两个字符串对象**（前提是 String Pool 中还没有 "abc" 字符串对象）。

- "abc" 属于字符串字面量，因此编译时期会在 String Pool 中创建一个字符串对象，指向这个 "abc" 字符串字面量；
- 而使用 new 的方式会在堆中创建一个字符串对象。

创建一个测试类，其 main 方法中使用这种方式来创建字符串对象。

```java
public class NewStringTest {
    public static void main(String[] args) {
        String s = new String("abc");
    }
}
```

使用 javap -verbose 进行反编译，得到以下内容：

```java
// ...
Constant pool:
// ...
   #2 = Class              #18            // java/lang/String
   #3 = String             #19            // abc
// ...
  #18 = Utf8               java/lang/String
  #19 = Utf8               abc
// ...

  public static void main(java.lang.String[]);
    descriptor: ([Ljava/lang/String;)V
    flags: ACC_PUBLIC, ACC_STATIC
    Code:
      stack=3, locals=2, args_size=1
         0: new           #2                  // class java/lang/String
         3: dup
         4: ldc           #3                  // String abc
         6: invokespecial #4                  // Method java/lang/String."<init>":(Ljava/lang/String;)V
         9: astore_1
// ...
```

在 Constant Pool 中，#19 存储这字符串字面量 "abc"，#3 是 String Pool 的字符串对象，它指向 #19 这个字符串字面量。在 main 方法中，0: 行使用 new #2 在堆中创建一个字符串对象，并且使用 ldc #3 将 String Pool 中的字符串对象作为 String 构造函数的参数。

以下是 String 构造函数的源码，可以看到，在将一个字符串对象作为另一个字符串对象的构造函数参数时，并不会完全复制 value 数组内容，而是都会指向同一个 value 数组。

```java
public String(String original) {
    this.value = original.value;
    this.hash = original.hash;
}
```

### String 的最大长度

1.Java中的字符串String最大长度，编译期如果是**javac编译就是65534**。如果绕过javac编译的限制，其最大长度可以达到u2类型变达的最大值65535。

2.Java中的字符串String最大长度运行期大约**4G**。

3.Eclise编译超过65534长度的字符串不报错，是Eclipse有自己的Java编译器。JDT优化为了StringBuilder的append。

4.Eclise使用自己的编译器。主要原因是JDT核心具有渐进式编译的能力（也就是增量编译），这也是Eclipse不需要编译按钮的原因，因为它会在检测到更改时自动编译。但Oracle的JDK不支持增量编译。

String 的长度是有限制的。

- 编译期的限制：字符串的UTF8编码值的字节数不能超过65535，字符串的长度不能超过65534；
- 运行时限制：字符串的长度不能超过2^31-1，占用的内存数不能超过虚拟机能够提供的最大值。

参考

https://www.cnblogs.com/54chensongxia/p/13640352.html

## 运算

### 参数传递

Java 的参数是以**值传递的形式传入方法中**，而**不是引用传递。**

以下代码中 Dog dog 的 dog 是一个指针，存储的是对象的地址。在将一个参数传入一个方法时，**本质上是将对象的地址以值的方式传递到形参中。**

```java
public class Dog {

    String name;

    Dog(String name) {
        this.name = name;
    }

    String getName() {
        return this.name;
    }

    void setName(String name) {
        this.name = name;
    }

    String getObjectAddress() {
        return super.toString();
    }
}
```

在方法中改变对象的字段值会改变原对象该字段值，因为**引用的是同一个对象。**

```java
class PassByValueExample {
    public static void main(String[] args) {
        Dog dog = new Dog("A");
        func(dog);
        System.out.println(dog.getName());          // B
    }

    private static void func(Dog dog) {
        dog.setName("B");
    }
}
```

但是**在方法中将指针引用了其它对象，那么此时方法里和方法外的两个指针指向了不同的对象**，在一个指针改变其所指向对象的内容对另一个指针所指向的对象没有影响。

```java
public class PassByValueExample {
    public static void main(String[] args) {
        Dog dog = new Dog("A");
        System.out.println(dog.getObjectAddress()); // Dog@4554617c
        func(dog);
        System.out.println(dog.getObjectAddress()); // Dog@4554617c
        System.out.println(dog.getName());          // A
    }

    private static void func(Dog dog) {
        System.out.println(dog.getObjectAddress()); // Dog@4554617c
        dog = new Dog("B");
        System.out.println(dog.getObjectAddress()); // Dog@74a14482
        System.out.println(dog.getName());          // B
    }
}
```

[StackOverflow: Is Java “pass-by-reference” or “pass-by-value”?](https://stackoverflow.com/questions/40480/is-java-pass-by-reference-or-pass-by-value)

### float 与 double

Java 不能隐式执行向下转型，因为这会使得精度降低。

1.1 字面量属于 double 类型，不能直接将 1.1 直接赋值给 float 变量，因为这是向下转型。

```java
// float f = 1.1;
```

**1.1f 字面量才是 float 类型。**

```java
float f = 1.1f;
```

### 隐式类型转换

因为字面量 1 是 int 类型，它比 short 类型精度要高，因此不能隐式地将 int 类型向下转型为 short 类型。

```java
short s1 = 1;
// s1 = s1 + 1;
```

但是使用 **+=** 或者 **++** 运算符会**执行隐式类型转换。**

```java
s1 += 1;
s1++;
```

上面的语句相当于将 s1 + 1 的计算结果进行了向下转型：

```java
s1 = (short) (s1 + 1);
```

[StackOverflow : Why don't Java's +=, -=, *=, /= compound assignment operators require casting?](https://stackoverflow.com/questions/8710619/why-dont-javas-compound-assignment-operators-require-casting)

### switch

从 **Java 7** 开始，可以在 switch 条件判断语句中使用 **String** 对象。

```java
String s = "a";
switch (s) {
    case "a":
        System.out.println("aaa");
        break;
    case "b":
        System.out.println("bbb");
        break;
}
```

switch 不支持 **long、float、double**，是因为 switch 的**设计初衷是对那些只有少数几个值的类型进行等值判断**，如果值过于复杂，那么还是用 if 比较合适。

```java
// long x = 111;
// switch (x) { // Incompatible types. Found: 'long', required: 'char, byte, short, int, Character, Byte, Short, Integer, String, or an enum'
//     case 111:
//         System.out.println(111);
//         break;
//     case 222:
//         System.out.println(222);
//         break;
// }
```

[StackOverflow : Why can't your switch statement data type be long, Java?](https://stackoverflow.com/questions/2676210/why-cant-your-switch-statement-data-type-be-long-java)


## 关键字

### final

**1. 数据**  

声明数据为常量，可以是编译时常量，也可以是在运行时被初始化后不能被改变的常量。

- 对于基本类型，final 使数值不变；
- 对于引用类型，final 使引用不变，也就不能引用其它对象，**但是被引用的对象本身是可以修改的。**

```java
final int x = 1;
// x = 2;  // cannot assign value to final variable 'x'
final A y = new A();
y.a = 1;
```

**2. 方法**  

声明方法不能被子类重写。

**private 方法隐式地被指定为 final**，如果在子类中定义的方法和基类中的一个 private 方法签名相同，此时子类的方法**不是重写**基类方法，而是在子类中定义了一个新的方法。

**3. 类**  

声明类不允许被继承。

**参考**：

[final修饰的对象，有几种初始化方式](https://www.cnblogs.com/lwhsummer/p/11148985.html)

这个点见 JVM

对于final域，编译器和处理器要遵守两个重排序规则：

1、**初次读**一个包含final域的对象的引用和**随后初次写**这个final域，**不能重拍序**。

2、在**构造函数内对final域写入**，随后将**构造函数**的引用**赋值**给一个引用变量，**操作不能重排序**。

以上两个规则就限制了**final域的初始化必须在构造函数内**，**不能重拍序到构造函数之外**，普通变量可以。

 JMM对final域的重拍序规则保证了能**安全读取final域时已经在构造函数中被正确的初始化了**。 

具体的操作：

1、java内存模型在final域写入和构造函数返回之前，插入一个**Store内存屏障**，**禁止处理器将final域重拍序到构造函数之外**。

2、java内存模型在初次读final域的对象和读对象内final域之间插入一个**Load内存屏障**。



### static

**1. 静态变量**  

- 静态变量：又称为类变量，也就是说这个变量属于类的，类所有的实例都共享静态变量，可以直接通过类名来访问它。静态变量在内存中只存在一份。
- 实例变量：每创建一个实例就会产生一个实例变量，它与该实例同生共死。

```java
public class A {

    private int x;         // 实例变量
    private static int y;  // 静态变量

    public static void main(String[] args) {
        // int x = A.x;  // Non-static field 'x' cannot be referenced from a static context
        A a = new A();
        int x = a.x;
        int y = A.y;
    }
}
```

**2. 静态方法**  

**静态方法在类加载的时候就存在了**，它**不依赖于任何实例**。所以**静态方法必须有实现**，也就是说**它不能是抽象方法。**

```java
public abstract class A {
    public static void func1(){
    }
    // public abstract static void func2();  // Illegal combination of modifiers: 'abstract' and 'static'
}
```

只能访问所属类的静态字段和静态方法，**方法中不能有 this 和 super 关键字**，因此这两个关键字与具体对象关联。

```java
public class A {

    private static int x;
    private int y;

    public static void func1(){
        int a = x;
        // int b = y;  // Non-static field 'y' cannot be referenced from a static context
        // int b = this.y;     // 'A.this' cannot be referenced from a static context
    }
}
```

**3. 静态语句块**  

**静态语句块在类初始化时运行一次。**

```java
public class A {
    static {
        System.out.println("123");
    }

    public static void main(String[] args) {
        A a1 = new A();
        A a2 = new A();
    }
}
```

```html
123
```

**4. 静态内部类**  

**非静态内部类依赖于外部类的实例，也就是说需要先创建外部类实例，才能用这个实例去创建非静态内部类。而静态内部类不需要。**

```java
public class OuterClass {

    class InnerClass {
    }

    static class StaticInnerClass {
    }

    public static void main(String[] args) {
        // InnerClass innerClass = new InnerClass(); // 'OuterClass.this' cannot be referenced from a static context
        OuterClass outerClass = new OuterClass();
        InnerClass innerClass = outerClass.new InnerClass();
        StaticInnerClass staticInnerClass = new StaticInnerClass();
    }
}
```

**静态内部类不能访问外部类的非静态的变量和方法。**

**5. 静态导包**  

在使用静态变量和方法时**不用再指明 ClassName**，从而简化代码，**但可读性大大降低。**

```java
import static com.xxx.ClassName.*
```

**6. 初始化顺序**  

静态变量和静态语句块**优先于实例变量和普通语句块**，静态变量和静态语句块的**初始化顺序取决于它们在代码中的顺序。**

```java
public static String staticField = "静态变量";
```

```java
static {
    System.out.println("静态语句块");
}
```

```java
public String field = "实例变量";
```

```java
{
    System.out.println("普通语句块");
}
```

**最后才是构造函数的初始化。**

```java
public InitialOrderTest() {
    System.out.println("构造函数");
}
```

存在继承的情况下，初始化顺序为：

- 父类（静态变量、静态语句块）
- 子类（静态变量、静态语句块）
- **父类（实例变量、普通语句块）**
- 父类（构造函数）
- **子类（实例变量、普通语句块）**
- 子类（构造函数）

## Object 通用方法

### 概览

```java

public native int hashCode()

public boolean equals(Object obj)

protected native Object clone() throws CloneNotSupportedException

public String toString()

public final native Class<?> getClass()

protected void finalize() throws Throwable {}

public final native void notify()

public final native void notifyAll()

public final native void wait(long timeout) throws InterruptedException

public final void wait(long timeout, int nanos) throws InterruptedException

public final void wait() throws InterruptedException
```

### equals()

**1. 等价关系**  

两个对象具有等价关系，需要满足以下五个条件：

Ⅰ 自反性

```java
x.equals(x); // true
```

Ⅱ 对称性

```java
x.equals(y) == y.equals(x); // true
```

Ⅲ 传递性

```java
if (x.equals(y) && y.equals(z))
    x.equals(z); // true;
```

Ⅳ 一致性

多次调用 equals() 方法结果不变

```java
x.equals(y) == x.equals(y); // true
```

Ⅴ 与 null 的比较

对任何不是 null 的对象 x 调用 x.equals(null) 结果都为 false

```java
x.equals(null); // false;
```

**2. 等价与相等**  

- 对于**基本类型**，== 判断两个值是否相等，基本类型没有 equals() 方法。
- 对于引用类型，== 判断两个变量是否引用同一个对象，而 equals() 判断引用的对象是否等价。

```java
Integer x = new Integer(1);
Integer y = new Integer(1);
System.out.println(x.equals(y)); // true
System.out.println(x == y);      // false
```

**3. 实现**  

- 检查**是否为同一个对象的引用**，如果是直接返回 true；
- 检查是否是**同一个类型**，如果不是，直接返回 false；
- 将 Object 对象进行**转型**；
- **判断每个关键域**是否相等。

```java
public class EqualExample {

    private int x;
    private int y;
    private int z;

    public EqualExample(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        EqualExample that = (EqualExample) o;

        if (x != that.x) return false;
        if (y != that.y) return false;
        return z == that.z;
    }
}
```

### hashCode()

hashCode() 返回哈希值，而 equals() 是用来判断两个对象是否等价。等价的两个对象**散列值**一定相同，但是散列值相同的两个对象不一定等价，这是因为计算哈希值具有随机性，两个值不同的对象可能计算出相同的哈希值。

**在覆盖 equals() 方法时应当总是覆盖 hashCode() 方法，保证等价的两个对象哈希值也相等。**

**HashSet  和 HashMap** 等集合类使用了 hashCode()  方法来计算对象应该存储的位置，因此要将对象添加到这些集合类中，需要让对应的类实现 hashCode()  方法。

下面的代码中，新建了两个等价的对象，并将它们添加到 HashSet 中。我们希望将这两个对象当成一样的，只在集合中添加一个对象。但是 EqualExample 没有实现 hashCode() 方法，因此这两个对象的哈希值是不同的，最终导致集合添加了两个等价的对象。

```java
EqualExample e1 = new EqualExample(1, 1, 1);
EqualExample e2 = new EqualExample(1, 1, 1);
System.out.println(e1.equals(e2)); // true
HashSet<EqualExample> set = new HashSet<>();
set.add(e1);
set.add(e2);
System.out.println(set.size());   // 2
```

理想的哈希函数应当具有均匀性，即不相等的对象应当均匀分布到所有可能的哈希值上。这就要求了哈希函数要把所有域的值都考虑进来。**可以将每个域都当成 R 进制的某一位**，然后**组成一个 R 进制的整数**。

R 一般取 31，因为它是一个奇素数，如果是偶数的话，当出现乘法溢出，信息就会丢失，因为与 2 相乘相当于向左移一位，最左边的位丢失。并且一个数与 31 相乘可以转换成**移位和减法**：`31*x == (x<<5)-x`，**编译器会自动进行这个优化。**

```java
@Override
public int hashCode() {
    int result = 17;
    result = 31 * result + x;
    result = 31 * result + y;
    result = 31 * result + z;
    return result;
}
```

### toString()

默认返回 ToStringExample@4554617c 这种形式，其中 @ 后面的数值为**散列码的无符号十六进制**表示。

```java
public class ToStringExample {

    private int number;

    public ToStringExample(int number) {
        this.number = number;
    }
}
```

```java
ToStringExample example = new ToStringExample(123);
System.out.println(example.toString());
```

```html
ToStringExample@4554617c
```

### clone()

**1. cloneable**  

clone() 是 Object 的 **protected 方法**，它不是 public，**一个类不显式去重写 clone()，其它类就不能直接去调用该类实例的 clone() 方法。**

```java
public class CloneExample {
    private int a;
    private int b;
}
```

```java
CloneExample e1 = new CloneExample();
// CloneExample e2 = e1.clone(); // 'clone()' has protected access in 'java.lang.Object'
```

重写 clone() 得到以下实现：

```java
public class CloneExample {
    private int a;
    private int b;

    @Override
    public CloneExample clone() throws CloneNotSupportedException {
        return (CloneExample)super.clone();
    }
}
```

```java
CloneExample e1 = new CloneExample();
try {
    CloneExample e2 = e1.clone();
} catch (CloneNotSupportedException e) {
    e.printStackTrace();
}
```

```html
java.lang.CloneNotSupportedException: CloneExample
```

**以上抛出了 CloneNotSupportedException，这是因为 CloneExample 没有实现 Cloneable 接口。**

应该注意的是，**clone() 方法并不是 Cloneable 接口的方法，而是 Object 的一个 protected 方法**。**Cloneable 接口只是规定，如果一个类没有实现 Cloneable 接口又调用了 clone() 方法，就会抛出 CloneNotSupportedException。**

```java
public class CloneExample implements Cloneable {
    private int a;
    private int b;

    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
}
```

**2. 浅拷贝**  

拷贝对象和原始对象的**引用类型引用同一个对象**。

```java
public class ShallowCloneExample implements Cloneable {

    private int[] arr;

    public ShallowCloneExample() {
        arr = new int[10];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = i;
        }
    }

    public void set(int index, int value) {
        arr[index] = value;
    }

    public int get(int index) {
        return arr[index];
    }

    @Override
    protected ShallowCloneExample clone() throws CloneNotSupportedException {
        return (ShallowCloneExample) super.clone();
    }
}
```

```java
ShallowCloneExample e1 = new ShallowCloneExample();
ShallowCloneExample e2 = null;
try {
    e2 = e1.clone();
} catch (CloneNotSupportedException e) {
    e.printStackTrace();
}
e1.set(2, 222);
System.out.println(e2.get(2)); // 222
```

**3. 深拷贝**  

拷贝对象和原始对象的**引用类型引用不同对象。**

```java
public class DeepCloneExample implements Cloneable {

    private int[] arr;

    public DeepCloneExample() {
        arr = new int[10];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = i;
        }
    }

    public void set(int index, int value) {
        arr[index] = value;
    }

    public int get(int index) {
        return arr[index];
    }

    @Override
    protected DeepCloneExample clone() throws CloneNotSupportedException {
        DeepCloneExample result = (DeepCloneExample) super.clone();
        result.arr = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            result.arr[i] = arr[i];
        }
        return result;
    }
}
```

```java
DeepCloneExample e1 = new DeepCloneExample();
DeepCloneExample e2 = null;
try {
    e2 = e1.clone();
} catch (CloneNotSupportedException e) {
    e.printStackTrace();
}
e1.set(2, 222);
System.out.println(e2.get(2)); // 2
```

**4. clone() 的替代方案**  

使用 clone() 方法来拷贝一个对象即复杂又有风险，它会抛出异常，并且还需要类型转换。Effective Java 书上讲到，最好不要去使用 clone()，**可以使用拷贝构造函数或者拷贝工厂**来拷贝一个对象。

```java
public class CloneConstructorExample {

    private int[] arr;

    public CloneConstructorExample() {
        arr = new int[10];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = i;
        }
    }

    public CloneConstructorExample(CloneConstructorExample original) {
        arr = new int[original.arr.length];
        for (int i = 0; i < original.arr.length; i++) {
            arr[i] = original.arr[i];
        }
    }

    public void set(int index, int value) {
        arr[index] = value;
    }

    public int get(int index) {
        return arr[index];
    }
}
```

```java
CloneConstructorExample e1 = new CloneConstructorExample();
CloneConstructorExample e2 = new CloneConstructorExample(e1);
e1.set(2, 222);
System.out.println(e2.get(2)); // 2
```

### java - finalize() 方法

参考：

java - finalize() 方法：https://www.jianshu.com/p/aa7ae747ff25

`System.gc()`方法是通知垃圾收集器该收垃圾了，收不收确定不了。

## 继承

### 访问权限

Java 中有三个访问权限修饰符：private、protected 以及 public，**如果不加访问修饰符，表示包级可见。**

可以对类或类中的成员（字段和方法）加上访问修饰符。

- 类可见表示其它类可以用这个类创建实例对象。
- 成员可见表示其它类可以用这个类的实例对象访问到该成员；

**protected** 用于修饰**成员**，表示**在继承体系中成员对于子类可见**，但是**这个访问修饰符对于类没有意义。**

设计良好的模块会隐藏所有的实现细节，把它的 API 与它的实现清晰地隔离开来。模块之间只通过它们的 API 进行通信，一个模块不需要知道其他模块的内部工作情况，这个概念被称为信息隐藏或封装。因此访问权限应当尽可能地使每个类或者成员不被外界访问。

如果子类的方法重写了父类的方法，那么子类中该方法的访问级别不允许低于父类的访问级别。这是**为了确保可以使用父类实例的地方都可以使用子类实例去代替**，也就是确保满足**里氏替换原则**。

字段决不能是公有的，因为这么做的话就**失去**了对这个字段修改行为的**控制**，客户端可以对其随意修改。例如下面的例子中，AccessExample 拥有 id 公有字段，如果在某个时刻，我们想要使用 int 存储 id 字段，那么就需要修改所有的客户端代码。

```java
public class AccessExample {
    public String id;
}
```

可以使用公有的 getter 和 setter 方法来替换公有字段，这样的话就可以控制对字段的修改行为。

```java
public class AccessExample {

    private int id;

    public String getId() {
        return id + "";
    }

    public void setId(String id) {
        this.id = Integer.valueOf(id);
    }
}
```

但是也有例外，如果是**包级私有的类**或者**私有的嵌套类**，那么直接暴露成员不会有特别大的影响。

```java
public class AccessWithInnerClassExample {

    private class InnerClass {
        int x;
    }

    private InnerClass innerClass;

    public AccessWithInnerClassExample() {
        innerClass = new InnerClass();
    }

    public int getValue() {
        return innerClass.x;  // 直接访问
    }
}
```

### 访问权限补充

参考

java默认修饰符：https://blog.csdn.net/wangluqinglxq/article/details/38944409

### 抽象类与接口

**1. 抽象类**  

**抽象类和抽象方法都使用 abstract 关键字进行声明。**如果一个类中包含抽象方法，那么这个类必须声明为抽象类。

**抽象类和普通类最大的区别是，抽象类不能被实例化，只能被继承。**

```java
public abstract class AbstractClassExample {

    protected int x;
    private int y;

    public abstract void func1();

    public void func2() {
        System.out.println("func2");
    }
}
```

```java
public class AbstractExtendClassExample extends AbstractClassExample {
    @Override
    public void func1() {
        System.out.println("func1");
    }
}
```

```java
// AbstractClassExample ac1 = new AbstractClassExample(); // 'AbstractClassExample' is abstract; cannot be instantiated
AbstractClassExample ac2 = new AbstractExtendClassExample();
ac2.func1();
```

**2. 接口**  

**接口是抽象类的延伸**，在 Java 8 之前，它可以看成是一个完全抽象的类，也就是说它不能有任何的方法实现。

**从 Java 8 开始，接口也可以拥有默认的方法实现**，这是因为不支持默认方法的**接口的维护成本太高**了。在 Java 8 之前，如果一个接口想要添加新的方法，那么要修改所有实现了该接口的类，让它们都**实现新增的方法**。

接口的成员（**字段 + 方法**）默认都是 **public** 的，并且不允许定义为 private 或者 protected。**从 Java 9** 开始，允许将**方法**定义为 **private**，这样就能**定义某些复用的代码**又不会把方法暴露出去。

**接口的字段默认都是 static 和 final 的。**

```java
public interface InterfaceExample {

    void func1();

    default void func2(){
        System.out.println("func2");
    }

    int x = 123;
    // int y;               // Variable 'y' might not have been initialized
    public int z = 0;       // Modifier 'public' is redundant for interface fields
    // private int k = 0;   // Modifier 'private' not allowed here
    // protected int l = 0; // Modifier 'protected' not allowed here
    // private void fun3(); // Modifier 'private' not allowed here
}
```

```java
public class InterfaceImplementExample implements InterfaceExample {
    @Override
    public void func1() {
        System.out.println("func1");
    }
}
```

```java
// InterfaceExample ie1 = new InterfaceExample(); // 'InterfaceExample' is abstract; cannot be instantiated
InterfaceExample ie2 = new InterfaceImplementExample();
ie2.func1();
System.out.println(InterfaceExample.x);
```

**3. 比较**  

- 从设计层面上看，**抽象类**提供了一种 IS-A 关系，需要满足**里式替换原则**，即**子类对象必须能够替换掉所有父类对象。**而接口更像是一种 LIKE-A 关系，它只是提供一种方法实现契约，并不要求接口和实现接口的类具有 IS-A 关系。
- 从使用上来看，**一个类可以实现多个接口，但是不能继承多个抽象类。**
- **接口的字段只能是 static 和 final 类型的**，而抽象类的字段没有这种限制。
- **接口的成员只能是 public 的**，而抽象类的成员可以有多种访问权限。

**4. 使用选择**  

使用接口：

- 需要让不相关的类都实现一个方法，例如不相关的类都可以实现 Comparable 接口中的 compareTo() 方法；
- 需要使用**多重继承。**

使用抽象类：

- **需要在几个相关的类中共享代码。**
- 需要能**控制继承来的成员的访问权限**，而**不是都为 public。**
- 需要继承非静态和非常量字段。

**在很多情况下，接口优先于抽象类。**因为**接口没有抽象类严格的类层次结构要求**，可以**灵活**地为一个类添加行为。并且从 **Java 8** 开始，接口也可以有**默认的方法实现，使得修改接口的成本也变的很低。**

- [Abstract Methods and Classes](https://docs.oracle.com/javase/tutorial/java/IandI/abstract.html)
- [深入理解 abstract class 和 interface](https://www.ibm.com/developerworks/cn/java/l-javainterface-abstract/)
- [When to Use Abstract Class and Interface](https://dzone.com/articles/when-to-use-abstract-class-and-intreface)
- [Java 9 Private Methods in Interfaces](https://www.journaldev.com/12850/java-9-private-methods-interfaces)


### super

- **访问父类的构造函数**：可以使用 **super()** 函数访问父类的构造函数，从而**委托父类完成一些初始化的工作**。应该注意到，**子类一定会调用父类的构造函数来完成初始化工作，一般是调用父类的默认构造函数，如果子类需要调用父类其它构造函数，那么就可以使用 super() 函数。**
- **访问父类的成员**：如果子类**重写**了父类的某个**方法**，可以通过**使用 super 关键字来引用父类的方法实现。**

```java
public class SuperExample {

    protected int x;
    protected int y;

    public SuperExample(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void func() {
        System.out.println("SuperExample.func()");
    }
}
```

```java
public class SuperExtendExample extends SuperExample {

    private int z;

    public SuperExtendExample(int x, int y, int z) {
        super(x, y);
        this.z = z;
    }

    @Override
    public void func() {
        super.func();
        System.out.println("SuperExtendExample.func()");
    }
}
```

```java
SuperExample e = new SuperExtendExample(1, 2, 3);
e.func();
```

```html
SuperExample.func()
SuperExtendExample.func()
```

[Using the Keyword super](https://docs.oracle.com/javase/tutorial/java/IandI/super.html)

### 重写与重载

**1. 重写（Override）**  

存在于继承体系中，指子类实现了一个与父类在方法声明上完全相同的一个方法。

为了满足**里式替换原则**，重写有以下三个限制：

- 子类方法的**访问权限**必须**大于**等于父类方法；
- 子类方法的**返回类型**必须是父类方法返回类型或为其**子类型。**
- 子类方法**抛出的异常**类型必须是父类抛出异常类型或为其**子类型。**

使用 **@Override 注解**，可以让编译器**帮忙检查**是否满足上面的三个限制条件。

下面的示例中，SubClass 为 SuperClass 的子类，SubClass 重写了 SuperClass 的 func() 方法。其中：

- 子类方法访问权限为 public，大于父类的 protected。
- 子类的返回类型为 ArrayList\<Integer\>，是父类返回类型 List\<Integer\> 的子类。
- 子类抛出的异常类型为 Exception，是父类抛出异常 Throwable 的子类。
- 子类重写方法使用 @Override 注解，从而让编译器自动检查是否满足限制条件。

```java
class SuperClass {
    protected List<Integer> func() throws Throwable {
        return new ArrayList<>();
    }
}

class SubClass extends SuperClass {
    @Override
    public ArrayList<Integer> func() throws Exception {
        return new ArrayList<>();
    }
}
```

在**调用一个方法**时，先从**本类**中查找看是否有对应的方法，如果没有再到**父类**中查看，看是否从父类继承来。否则就要对参数进行**转型**，**转成父类之后看是否有对应的方法**。总的来说，方法调用的优先级为：

- this.func(this)
- super.func(this)
- this.func(super)
- super.func(super)


```java
/*
    A
    |
    B
    |
    C
    |
    D
 */


class A {

    public void show(A obj) {
        System.out.println("A.show(A)");
    }

    public void show(C obj) {
        System.out.println("A.show(C)");
    }
}

class B extends A {

    @Override
    public void show(A obj) {
        System.out.println("B.show(A)");
    }
}

class C extends B {
}

class D extends C {
}
```

```java
public static void main(String[] args) {

    A a = new A();
    B b = new B();
    C c = new C();
    D d = new D();

    // 在 A 中存在 show(A obj)，直接调用
    a.show(a); // A.show(A)
    // 在 A 中不存在 show(B obj)，将 B 转型成其父类 A
    a.show(b); // A.show(A)
    // 在 B 中存在从 A 继承来的 show(C obj)，直接调用
    b.show(c); // A.show(C)
    // 在 B 中不存在 show(D obj)，但是存在从 A 继承来的 show(C obj)，将 D 转型成其父类 C
    b.show(d); // A.show(C)

    // 引用的还是 B 对象，所以 ba 和 b 的调用结果一样
    A ba = new B();
    ba.show(c); // A.show(C)
    ba.show(d); // A.show(C)
}
```

**2. 重载（Overload）**  

存在于同一个类中，指一个方法与已经存在的**方法名称上相同**，但是**参数类型、个数、顺序至少有一个不同。**

应该注意的是，**返回值不同，其它都相同不算是重载。**

```java
class OverloadingExample {
    public void show(int x) {
        System.out.println(x);
    }

    public void show(int x, String y) {
        System.out.println(x + " " + y);
    }
}
```

```java
public static void main(String[] args) {
    OverloadingExample example = new OverloadingExample();
    example.show(1);
    example.show(1, "2");
}
```

## 反射

每个类都有一个   **Class**   对象，包含了与类有关的信息。当编译一个新类时，会产生一个同名的 **.class 文件**，该**文件内容保存着 Class 对象。**

类加载相当于 Class 对象的加载，**类在第一次使用时才动态加载到 JVM 中**。也可以使用 `Class.forName("com.mysql.jdbc.Driver")` 这种方式来**控制**类的加载，该方法会返回一个 Class 对象。

**反射可以提供运行时的类信息**，并且这个类可以在运行时才加载进来，**甚至在编译时期该类的 .class 不存在也可以加载进来。**

**获取类对象的三种方式**

1、`Class.forName("com.mysql.jdbc.Driver")` 

2、xxx对象.getClass()

3、xxx类名.class

Class 和 java.lang.reflect 一起对反射提供了支持，java.lang.reflect 类库主要包含了以下三个类：

-  **Field**  ：可以使用 get() 和 set() 方法读取和修改 Field 对象关联的**字段**；
-  **Method**  ：可以使用 invoke() 方法调用与 Method 对象关联的**方法**；
-  **Constructor**  ：可以用 Constructor 的 newInstance() **创建新的对象**。

**反射的优点：**  

-  **可扩展性**   ：应用程序可以利用全限定名创建可扩展对象的实例，来**使用来自外部的用户自定义类。**
-  **类浏览器和可视化开发环境**   ：一个类浏览器需要可以枚举类的成员。可视化**开发环境（如 IDE）**可以从利用反射中可用的类型信息中受益，以帮助程序员编写正确的代码。
-  **调试器和测试工具**   ： 调试器需要能够检查一个类里的私有成员。**测试工具**可以利用反射来自动地调用类里定义的可被发现的 API 定义，以确保一组测试中有较高的代码覆盖率。

**反射的缺点：**  

尽管反射非常强大，但也不能滥用。如果一个功能可以不用反射完成，那么最好就不用。在我们使用反射技术时，下面几条内容应该牢记于心。

-  **性能开销**   ：反射涉及了**动态类型的解析**，所以 **JVM 无法对这些代码进行优化**。因此，反射操作的效率要比那些非反射操作低得多。我们应该避免在经常被执行的代码或对性能要求很高的程序中使用反射。

-  **安全限制**   ：使用反射技术要求程序必须在一个没有**安全限制**的环境中运行。如果一个程序必须在有安全限制的环境中运行，如 Applet，那么这就是个问题了。

-  **内部暴露**   ：由于反射允许代码执行一些在正常情况下不被允许的操作（比如**访问私有的属性和方法**），所以使用反射可能会导致意料之外的副作用，这可能导致代码功能失调并破坏可移植性。反射代码破坏了抽象性，**破坏了原有规则**，因此当平台发生改变的时候，代码的行为就有可能也随着变化。

- [Trail: The Reflection API](https://docs.oracle.com/javase/tutorial/reflect/index.html)
- [深入解析 Java 反射（1）- 基础](http://www.sczyh30.com/posts/Java/java-reflection-1/)

## 异常

Throwable 可以用来表示任何可以作为异常抛出的类，分为两种：  **Error**   和 **Exception**。其中 Error 用来表示 JVM 无法处理的错误，Exception 分为两种：

-   **受检异常**  ：需要用 try...catch... 语句捕获并进行处理，并且可以从异常中恢复；
-   **非受检异常**  ：是程序运行时错误，例如除 0 会引发 Arithmetic Exception，此时程序崩溃并且无法恢复。

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/PPjwP.png" width="600"/> </div><br>
- [Java 入门之异常处理](https://www.cnblogs.com/Blue-Keroro/p/8875898.html)
- [Java Exception Interview Questions and Answers](https://www.journaldev.com/2167/java-exception-interview-questions-and-answersl)

## 泛型

```java
public class Box<T> {
    // T stands for "Type"
    private T t;
    public void set(T t) { this.t = t; }
    public T get() { return t; }
}
```

- [Java 泛型详解](https://www.cnblogs.com/Blue-Keroro/p/8875898.html)
- [10 道 Java 泛型面试题](https://cloud.tencent.com/developer/article/1033693)

未参考：

面试中泛型问题一文搞定：https://www.nowcoder.com/discuss/583890

## 注解

Java 注解是附加在代码中的一些元信息，用于一些工具在编译、运行时进行解析和使用，起到说明、配置的功能。注解不会也不能影响代码的实际逻辑，仅仅起到辅助性的作用。

[注解 Annotation 实现原理与自定义注解例子](https://www.cnblogs.com/acm-bingzi/p/javaAnnotation.html)

## 新特性

### Java 各版本的新特性

**New highlights in Java SE 8**  

1. Lambda Expressions
2. Pipelines and Streams
3. Date and Time API
4. Default Methods
5. Type Annotations
6. Nashhorn JavaScript Engine
7. Concurrent Accumulators
8. Parallel operations
9. PermGen Error Removed

**New highlights in Java SE 7**  

1. Strings in Switch Statement
2. Type Inference for Generic Instance Creation
3. Multiple Exception Handling
4. Support for Dynamic Languages
5. Try with Resources
6. Java nio Package
7. Binary Literals, Underscore in literals
8. Diamond Syntax

- [Difference between Java 1.8 and Java 1.7?](http://www.selfgrowth.com/articles/difference-between-java-18-and-java-17)
- [Java 8 特性](http://www.importnew.com/19345.html)

### Java 与 C++ 的区别

- Java 是纯粹的面向对象语言，所有的对象都继承自 java.lang.Object，C++ 为了兼容 C 即支持面向对象也支持面向过程。
- Java 通过虚拟机从而实现跨平台特性，但是 C++ 依赖于特定的平台。
- Java 没有指针，它的引用可以理解为安全指针，而 C++ 具有和 C 一样的指针。
- Java 支持自动垃圾回收，而 C++ 需要手动回收。
- Java 不支持多重继承，只能通过实现多个接口来达到相同目的，而 C++ 支持多重继承。
- Java 不支持操作符重载，虽然可以对两个 String 对象执行加法运算，但是这是语言内置支持的操作，不属于操作符重载，而 C++ 可以。
- Java 的 goto 是保留字，但是不可用，C++ 可以使用 goto。

[What are the main differences between Java and C++?](http://cs-fundamentals.com/tech-interview/java/differences-between-java-and-cpp.php)

### JRE or JDK

- JRE：Java Runtime Environment，Java 运行环境的简称，为 Java 的运行提供了所需的环境。它是一个 JVM 程序，主要包括了 JVM 的标准实现和一些 Java 基本类库。
- JDK：Java Development Kit，Java 开发工具包，提供了 Java 的开发及运行环境。JDK 是 Java 开发的核心，集成了 JRE 以及一些其它的工具，比如编译 Java 源码的编译器 javac 等。

Lam

## Lambda 原理

（未看）Lambda表达式看这一篇就够了：https://objcoding.com/2019/03/04/lambda/

https://github.com/objcoding?tab=overview&from=2019-12-01&to=2019-12-31

**函数式接口**

字节码上，Lambda表达式生成一个私有的静态函数，注意，在这里说的是生成，而不是等价。

private static void lambda$0(java.lang.String); 私有的静态函数干的就是Lambda表达式里面的内容 

**map和foreach**

```java
list.forEach(s -> {
    System.out.println(args.getClass().getTypeName());
});
```

````java
list.stream().map(s -> {
    Integer a = Integer.parseInt(s);
    a = a+1;
    System.out.println(a.getClass().getTypeName());
    return a;
 }).collect(Collectors.toList());
````

**map对原来的集合操作后返回一个新的集合。此集合和原集合无任何关系，且不会改变原集合的任何东西。**

**foreach操作的是原集合，返回的还是原集合**

参考

java8 lambda表达式之map和foreach的区别：https://blog.csdn.net/EnseHeiKe/article/details/103649676

## JDK8 的时间类

https://www.jianshu.com/p/2949db9c3df5

## 哈希碰撞解决方式

#### **1、拉链法**

1）优点： ①对于记录总数频繁可变的情况，处理的比较好（也就是避免了动态调整的开销） ②由于记录存储在结点中，而结点是动态分配，不会造成内存的浪费，所以尤其适合那种记录本身尺寸（**size）很大的情况，因为此时指针的开销可以忽略不计了** ③**删除快**

2）缺点： ①**查询慢**，存储的记录是随机分布在内存中的，这样在查询记录时，相比结构紧凑的数据类型（比如数组），哈希表的跳转访问会带来额外的时间开销 ②如果所有的 key-value 对是可以提前预知，并之后不会发生变化时（即不允许插入和删除），可以人为创建一个不会产生冲突的完美哈希函数（perfect hash function），此时封闭散列的性能将远高于开放散列 **③由于使用指针，记录不容易进行序列化（serialize）操作**

#### **2、开放定址法**

当发生地址冲突时，按照某种方法**继续探测哈希表中的其他存储单元，直到找到空位置为止。**
用方程来表达的话是这样子， 

> H i ( key ) = ( H ( key )+ d i ) mod m ( i = 1,2,…… ， k ( k ≤ m – 1)) 

m 是哈希表的长度。

举一个实际的例子，
一个哈希函数是 H (key) = key mod 7 ，
哈希表长度为 7，
关键字序列（ 32 ， 13 ， 49 ， 55 ， 22 ， 38 ， 21 ）
如果以线性探测再散列来生成哈希表的话，

过程是这样的 ：

> 32 ％ 7 = 4 ； 13 ％ 7 = 6 ； 49 ％ 7 = 0 ；
> 55 ％ 7 = 6 发生冲突，下一个存储地址（ 6 ＋ 1 ）％ 7 ＝ 0 ，仍然发生冲突，再下一个存储地址：（ 6 ＋ 2 ）％ 7 ＝ 1 未发生冲突，可以存入。
> 22 ％ 7 ＝ 1 发生冲突，下一个存储地址是：（ 1 ＋ 1 ）％ 7 ＝ 2 未发生冲突；
> 38 ％ 7 ＝ 3 ；
> 21 ％ 7 ＝ 0 发生冲突，按照上面方法继续探测直至空间 5 ，不发生冲突 

所得到的哈希表对应存储位置： 

> 下标： 0 1 2 3 4 5 6
> 49 55 22 38 32 21 13  

1）优点： ①**记录更容易进行序列化（serialize）操作** ②如果记录总数可以预知，可以创建完美哈希函数，此时处理数据的效率是非常高的

2）缺点： ①**存储记录的数目不能超过桶数组的长度**，如果超过就需要扩容，而扩容会导致某次操作的时间成本飙升，这在实时或者交互式应用中可能会是一个严重的缺陷 ②使用探测序列，有可能其**计算的时间成本过高**，导致**哈希表的处理性能降低** ③由于记录是存放在桶数组中的，而桶数组必然存在空槽，所以当记录本身尺寸（size）很大并且记录总数规模很大时，**空槽占用的空间会导致明显的内存浪费** ④删除记录时，比较麻烦。比如需要删除记录a，记录b是在a之后插入桶数组的，但是和记录a有冲突，是通过探测序列再次跳转找到的地址，所以如果直接删除a，a的位置变为空槽，而**空槽是查询记录失败的终止条件**，这样会导致记录b在a的位置重新插入数据前不可见，所以不能直接删除a，而是**设置删除标记。这就需要额外的空间和操作。**

#### 3、再哈希法

对于冲突的哈希值再次进行哈希处理，直至没有哈希冲突

#### 4、建立公共溢出区

这种方法的基本思想是：将哈希表分为基本表和溢出表两部分，凡是和基本表发生冲突的元素，一律填入溢出表。

参考：

哈希碰撞是什么，怎么解决：https://segmentfault.com/p/1210000015259218/read

哈希冲突及四种解决方法：https://www.cnblogs.com/higerMan/p/11907117.html

解决hash冲突的三个方法：https://www.cnblogs.com/wuchaodzxx/p/7396599.html

## UTF-8与UTF-16编码

Unicode，译名为万国码，是[计算机科学](https://zh.wikipedia.org/wiki/電腦科學)领域的业界标准。它整理、编码了世界上大部分的[文字系统](https://zh.wikipedia.org/wiki/文字系統)，使得电脑可以用更为简单的方式来呈现和处理文字。 

Unicode为解决既有的传统[字符编码](https://zh.wikipedia.org/wiki/字元編碼)方案的局限而产生，例如[ISO 8859-1](https://zh.wikipedia.org/wiki/ISO/IEC_8859)所定义的字符虽然在不同的国家中广泛地使用，可是在不同国家间却经常出现不兼容的情况。

Unicode至今仍在不断增修，每个新版本都加入更多新的字符，意在达到万国统一。

Unicode的**实现方式**不同于**编码方式**。一个字符的Unicode编码确定。但是在实际传输过程中，由于不同[系统平台](https://zh.wikipedia.org/wiki/系统平台)的设计不一定一致，以及**出于节省空间的目的**，对Unicode编码的实现方式有所不同。Unicode的实现方式称为**Unicode转换格式**（Unicode Transformation Format，万国码传输规整，简称为UTF）。

例如，如果一个**仅包含**基本7位[ASCII](https://zh.wikipedia.org/wiki/ASCII)字符的Unicode文件，如果每个字符都使用**2字节的原Unicode编码传输**，其第一字节的**8位始终为0**。这就造成了比较大的**浪费**。对于这种情况，可以使用**UTF-8编码**，这是**变长编码**，它将基本7位ASCII字符仍用7位编码表示，占用一个字节（首位补0）。而**遇到与其他Unicode字符混合的情况，将按一定算法转换，每个字符使用1-3个字节编码，并利用首位为0或1识别。**这样对以7位ASCII字符为主的西文文档就大幅节省了编码长度（具体方案参见[UTF-8](https://zh.wikipedia.org/wiki/UTF-8)）。

Unicode只是一组字符设定或者说是从数字和字符之间的逻辑映射的概念编码，但是它并没有指定代码点如何在计算机上存储。

其他：

UTF-8就是以8位为单元对UCS进行编码，UTF-16以16位为单元对UCS进行编码。
UTF-8以字节为编码单元，没有字节序的问题。
UTF-16以两个字节为编码单元，在解释一个UTF-16文本前，首先要弄清楚每个编码单元的字节序。
一般默认的情况下是unicode的utf-8，你的编译器与操作系统有关。没有绝对的。 

## 字符串大小估算

醉眼看人间:

100w个 32长度的uuid字符串 存到 String 数组里约 100M

1w个2长度的uuid字符串 存到 String 数组里约 1M

具体1个的大小是  40字节+ 2*len字节

40 包含 16字节的 对象头 和 char 数组等等

参考：[CSDN - 已收藏 Java 基础](https://blog.csdn.net/mafei6827/article/details/87076371?spm=1001.2014.3001.5506)




## 参考资料

- Eckel B. Java 编程思想[M]. 机械工业出版社, 2002.
- Bloch J. Effective java[M]. Addison-Wesley Professional, 2017.
