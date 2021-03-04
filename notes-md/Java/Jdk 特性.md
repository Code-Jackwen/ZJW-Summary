## jdk7

**1、switch中使用String**
**2、try-with-resources**
**3、捕获多个异常||||||**
**4、泛型实例化类型自动推断**
**5、数字增加二进制表示 多进制表示赋值**
6、数字中可添加分隔符

参考

- https://blog.csdn.net/u014209205/article/details/79718689

## jdk8

**1、接口的默认方法、静态方法**
**2、Lambda 表达式**
**3、函数式接口**
**4、方法与构造函数引用**
**5、Date API**
**6、Optional 类**
**7、Stream**


参考

- 菜鸟教程
- https://www.jianshu.com/p/0bf8fe0f153b
- https://blog.csdn.net/sun_promise/article/details/51383618

## jdk9

1、集合加强 of
2、**私有接口方法**，作为通用方法放在默认方法中调用
3、**jdk9把G1作为默认的垃圾收集器实现**，替换了jdk7和jdk8的默认垃圾收集器实现：Parallel Scavenge（新生代）+Parallel Old（老年代）。
**4、I/O流加强，增加方法，readAllBytes等等**
**5、JShell工具**
**6、String存储结构变更**
7、Deprecated废弃不少API 标注Since
**8、增加stream API 方法**
        1、takeWhile
        2、dropWhile
        3、ofNullable(T t): t可以为null
        4、等等
**9、对try with resource的进一步优化**
**10、全新的HTTP客户端API**

参考

- https://yq.aliyun.com/articles/652719

## jdk10	

**1、局部变量类型推断 var**
2、**G1**已经作为缺省的垃圾收集器了。
**3、Optional API增强**，orElseThrow（）....

参考

- https://zhuanlan.zhihu.com/p/97767518

## jdk11

**1、Lambda表达式中Local Var**
**2、HttpClient 在11中完全可用，是对java9 最终版**
**3、对Files类增加了writeString和readString两个静态方法**
**4、String新增了strip()方法，和trim()相比，strip()可以去掉Unicode空格**
5、优秀的**ZGC**（目前只在 Linux/x64 上可用）：
	可伸缩低延迟垃圾收集器，并发收集器， -Xmx 是 ZGC 收集器中最重要的调优选项
	比g1颗粒度更细
	并行回收、增量回收、在程序运行期间回收（并发回收）

参考

- https://www.liaoxuefeng.com/article/1248336382261824
- https://developer.ibm.com/zh/articles/the-new-features-of-java-11/	

## jdk12

1、String中新增方法indent()缩进、transform()字符串函数式转换、
2、Files.mismatch(Path, Path)文件相同比较、
**3、Unicode 万国码更多的支持以及 emoji**
**4、Switch Expressions(Preview) 表达式输出、 ->**
5、Compact Number Formatting (紧凑的数据格式)

6、Shenandoah GC 色男都啊   测试中的**GC算法**、旨在保证低延迟（10 - 500 ms的下限）无论堆的大小如何都是这个值			
7、G1归还不使用的内存
8、G1的可中断 mixed GC 功能的支持

- https://zhuanlan.zhihu.com/p/107117568

## jdk13

1、Switch Expressions(Preview) 表达式输出、 -> 基于jdk12（**标签简化**）的更加优化，可以方法内部直接 当参数传递，比如syso

**2、switch多了跳出switch块的关键字，yield 返回值形式，那就是yield、区别return一个跳出方法，一个跳出switch**

**Switch 表达式（返回值）应该使用 yield，而 Switch 语句（不返回值）应该使用 break**
目前处于预览状态。

3、字符串 """ 多行的字符串，不需要进行任何转义，不出现\n + 什么的
4、Java 13 中对 ZGC 的改进，主要体现在下面几点：				

ZGC原来java11的测试gC，可伸缩、低延迟的垃圾收集器。

- **释放未使用内存给操作系统**
- **支持最大堆大小为 16TB**
- **添加参数：-XX:SoftMaxHeapSize 来软限制堆大小**

5、Socket API 重构

参考

- https://developer.ibm.com/zh/articles/the-new-features-of-Java-13/

## jdk14

1、垃圾回收相关：

**1）删除cms垃圾收集器**
**2）弃用 ParallelScavenge + SerialOld GC 的垃圾回收算法组合**
**3）zgc 垃圾回收器 移植到 macOS 和 windows 平台** 

2、switch优化变更为最终版
	预览版：该功能在当前版本可以使用，如果效果不是很好的话，可能以后的其他版本就会删去该功能。
	最终版：该功能在之前版本效果很好，之后的每个版本中都会存在该功能。

3、数值读取优化，NumberFormat

4、删除了安全库java.security.acl API

参考

- https://blog.csdn.net/m0_38001814/article/details/88831037?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.edu_weight&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.edu_weight#jdk12%E6%96%B0%E7%89%B9%E6%80%A7

# 参考

JDK 15 新特性讲解：https://my.oschina.net/u/4262150/blog/4656149

JDK 15 ：https://www.cnblogs.com/flydean/p/jdk15-release-new-features.html

JDK 下载官网：https://www.oracle.com/java/technologies/javase-downloads.html

https://download.oracle.com/otn/java/jdk/11.0.9+7/eec35ebefb3f4133bd045b891f05db94/jdk-11.0.9_windows-x64_bin.zip?AuthParam=1611062540_6cf57dcae1242c0342cd3b3b044c7696