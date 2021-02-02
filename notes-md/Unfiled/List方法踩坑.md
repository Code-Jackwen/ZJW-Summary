## ArrayList中add(int index, E element)和set(int index, E element)两个方法的不同以及报错的点。

一般使用List集合，估计都是使用这个ArrayList，很少使用到add(int index, E element)和set(int index, E element)两个方法。

陷阱代码：

````java
public static void main(String[] args) {
    List<String> list = new ArrayList<>(2);
    System.out.println("list大小为：" + list.size());//0
    list.add("12");
    System.out.println("list大小为：" + list.size());//1
    //list.set(1,"sss");
    list.add(1,"第一次放在下标为1的位置");
    list.add("22");
    System.out.println("list大小为：" + list.size());//3
    System.out.println(list.toString());//[12, 第一次放在下标为1的位置, 22]
    list.add(1,"第二次放在下标为1的位置");
    System.out.println("list大小为：" + list.size());//4
    System.out.println(list.toString());//[12, 第二次放在下标为1的位置, 第一次放在下标为1的位置, 22]
}
````

运行结果：如代码后的注释。

如果将 list.set(1,"sss"); 注释放开，运行结果如下：

````
list大小为：0
list大小为：1
报错：数组下标越界
````

解释：

1、虽然 new ArrayList<>(2); 但是 list大小为：0。在底层是新建了个长度为2的数组Object[]，但是size()方法返回的是成员变量 int size。new ArrayList<>(2); 并未改变size的值，因此还是int的默认值0；size 变量源码注释的意思是当前ArrayList中包含的元素数量。

2、set(int index, E element) 为什么就报错了？

函数中会调用如下函数代码：

````java
private void rangeCheck(int index) {
    if (index >= size)
    throw new IndexOutOfBoundsException(outOfBoundsMsg(index));
}
````

此时， index是1，但是size是1，就会报错。

3、 list.add(1,"第一次放在下标为1的位置"); 为什么不报错？

函数中会调用如下函数代码：

````java
private void rangeCheckForAdd(int index) {
    if (index > size || index < 0)
    throw new IndexOutOfBoundsException(outOfBoundsMsg(index));
}
````

此时  index=1 > size=1 不成立，那么就顺利添加了 。

但是，要是在数组刚声明完，直接在下标为1的位置，这么干，就异常了。 也就是声明好 List<String> list = new ArrayList<>(2); 之后也不能用这方法直接操作下标为1的元素。但是可以 add(0,"xxx");

4、 就是你在下标 1 这个位置一直调用add（index ， element）。

这个不仅仅是把index位置的数据给替换，而且把之前这个位置的数据给依次向后移动1个位置。

