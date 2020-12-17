# LinkedHashMap

##### 概述

LinkedHashMap extends HashMap<K,V>implements Map<K,V>

这里说的版本是1.8版本，实际使用上可以认为是**HashMap+LinkedList**，有序的实现是因为加了双链表。

| **关  注  点**                | **结    论**                 |
| ----------------------------- | ---------------------------- |
| LinkedHashMap是否允许空       | Key和Value都允许空           |
| LinkedHashMap是否允许重复数据 | Key重复会覆盖、Value允许重复 |
| LinkedHashMap是否有序         | **有序**                     |
| LinkedHashMap是否线程安全     | 非线程安全                   |

##### 存储结构

````java
static class Entry<K,V> extends HashMap.Node<K,V> {    
	Entry<K,V> before, after;    
	Entry(int hash, K key, V value, Node<K,V> next) {        
		super(hash, key, value, next);    
	}
}
````

 Entry<K,V> before, after 代表双链表的前后节点，用于迭代。

##### 其他变量

```java
/*The head (eldest) of the doubly linked list. */
transient LinkedHashMap.Entry<K,V> head;
/*The tail (youngest) of the doubly linked list. */
transient LinkedHashMap.Entry<K,V> tail;

final boolean accessOrder;
```

单独维护 head、tail 方便头、尾的操作。

accessOrder：

false，所有的Entry按照插入的顺序排列，也是默认值。这时候可以当做队列使用。

true，所有的Entry按照访问的顺序排列， 这时候可以当做简单的LRU算法实现。

LRU： 缓存算法的概念，LRU即Least Recently Used，最近最少使用，也就是说，当缓存满了，会优先淘汰那些最近最不常访问的数据。

##### 简单LRU功能

accessOrder为true的LinkedHashMap 每次访问一个元素（get或put），被访问的元素都被提到最后面去。

也就是双向链表最头的那个数据就是要淘汰的数据。 举个例子说，依次存了1、3、5 ，然后用了一次 3 ，那么再遍历出的顺序就是1、5、3 。

逻辑实现是这个方法 void recordAccess(HashMap<K,V> m)   逻辑就是先将自己删除了，然后在把自己添加。

##### 五个构造方法： 

````java
// 构造方法1，构造一个指定初始容量和负载因子的、按照插入顺序的LinkedList
public LinkedHashMap(int initialCapacity, float loadFactor) {
    super(initialCapacity, loadFactor);
    accessOrder = false;
}
// 构造方法2，构造一个指定初始容量的LinkedHashMap，取得键值对的顺序是插入顺序
public LinkedHashMap(int initialCapacity) {
    super(initialCapacity);
    accessOrder = false;
}
// 构造方法3，用默认的初始化容量和负载因子创建一个LinkedHashMap，取得键值对的顺序是插入顺序
public LinkedHashMap() {
    super();
    accessOrder = false;
}
// 构造方法4，通过传入的map创建一个LinkedHashMap，容量为默认容量（16）和(map.zise()/DEFAULT_LOAD_FACTORY)+1的较大者，装载因子为默认值
public LinkedHashMap(Map<? extends K, ? extends V> m) {
    super(m);
    accessOrder = false;
}
// 构造方法5，根据指定容量、装载因子和键值对保持顺序创建一个LinkedHashMap
public LinkedHashMap(int initialCapacity,
             float loadFactor,
                         boolean accessOrder) {
    super(initialCapacity, loadFactor);
    this.accessOrder = accessOrder;
}
````

所有构造方法都是通过调用父类的构造方法来创建对象的。重载的参数是初始容量、负载因子、对出入Map类型的适配构造、排序规则（布尔值accessOrder）。



##### 了解更多

LinkedHashMap https://www.cnblogs.com/xiaoxi/p/6170590.html