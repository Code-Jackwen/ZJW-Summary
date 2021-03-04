## Xml 映射⽂件标签

<resultMap>、<parameterMap>、<sql>、<include>、<selectKey>

动态 sql 的 9个标签，trim | **where** | set | **foreach** | **if** | choose | **when** | otherwise | bind等。

其中为 sql ⽚段标签，通过<include>标签引⼊ sql ⽚段，<selectKey>为不⽀持⾃增的主键⽣成策略标签。

## 动态 sql 是做什么的？都有哪些动态 sql？执⾏原理？

动态 sql 的 9个标签，trim | **where** | set | **foreach** | **if** | choose | **when** | otherwise | bind等。

使⽤ **OGNL** 从 sql 参数对象中计算表达式的值，根据表达式的值动态拼接 sql，以此来完成动态 sql 的功能。

## Dao 接⼝⾥的⽅法，参数不同时，⽅法能重载吗？

Dao 接⼝，就是⼈们常说的Mapper接⼝，接⼝的全限名，就是映射⽂件中的 **namespace**的值。

接⼝的⽅法名，就是映射⽂件中MappedStatement的 id 值。

接⼝⽅法内的参数，就是传递给 sql 的参数。

Mapper接⼝是没有实现类的，当调⽤接⼝⽅法时，**接⼝全限名+⽅法名拼接字符串作为 key 值，可唯⼀定位⼀个MappedStatement**。

举例：

com.mybatis3.mappers.StudentDao.findStudentById，可以唯⼀找到 namespace为

com.mybatis3.mappers.StudentDao下⾯id = findStudentById的MappedStatement。

在 Mybatis中，每⼀个<select>、<insert>、<update>、<delete>标签，都会被解析为⼀个

**MappedStatement**对象。

Dao 接⼝⾥的⽅法，是**不能重载的**，**因为是全限名+⽅法名的保存和寻找策略**。

Dao 接⼝的⼯作原理是 **JDK 动态代理**，Mybatis 运⾏时会使⽤ JDK 动态代理**为 Dao 接⼝⽣成代理 proxy 对象**

，代理对象 proxy 会拦截接⼝⽅法，转⽽执⾏MappedStatement所代表的 sql，然后将 sql 执⾏结果返回。

## Mybatis 是如何将 sql 执⾏结果封装为⽬标对象，有哪些映射形式？

第⼀种是使**⽤<resultMap>标签**，逐⼀定义列名和对象属性名之间的映射关系。



第⼆种是使⽤ sql 列的别名功能，将列别名书写为对象属性名，⽐如 T_NAME AS NAME，对象属性名⼀般是 **name**，⼩写，但是列名不区分⼤⼩写，Mybatis 会忽略列名⼤⼩写，智能找到与之对应对象属性名，你甚⾄可以写成 **T_NAME AS NaMe**，Mybatis ⼀样可以正常⼯作。



有了列名与属性名的映射关系后，**Mybatis 通过反射创建对象，同时使⽤反射给对象的属性逐⼀赋值并返回**，那些**找不到映射关系的属性，是⽆法完成赋值的**。



## Mybatis的⼀对⼀、⼀对多的关联查询吗？都有哪些实现⽅式，以及它们之间的区别。

多对⼀查询，其实就是⼀对⼀查询，只需要把selectOne()修改为selectList()即可

多对多查询，其实就是⼀对多查询，只需要把selectOne()修改为selectList()即可

## Mybatis 是否⽀持延迟加载

Mybatis 仅⽀持 association 关联对象和 collection 关联集合对象的延迟加载，association 指的就是**⼀对⼀**，collection 指的就是**⼀对多**查询。

在 Mybatis **配置⽂件**中，可以配置是否启⽤延迟加载lazyLoadingEnabled=true|false



原理：

使⽤**CGLIB创建⽬标对象的代理对象**，当调⽤⽬标⽅法时，进⼊拦截器⽅法，⽐如调⽤

a.getB().getName()，拦截器invoke()⽅法发现a.getB()是 null 值，那么就会单独发送事先保存好的查询关联 B 对

象的 sql，把 B 查询上来，然后调⽤ a.setB(b)，于是 a 的对象 b 属性就有值了，接着完成a.getB().getName()⽅法

的调⽤。这就是延迟加载的基本原理。



## 不同的 Xml 映射⽂件，id 是否可以重复？

不同的 Xml 映射⽂件，如果配置了 namespace，那么 id 可以重复；如果没有配置namespace，那么 id 不能重复

原因就是 namespace+id 是作为Map<String, MappedStatement>的 key 使⽤。

## Mybatis 中如何执⾏批处理？

使⽤ BatchExecutor 完成批处理。

## Mybatis 都有哪些 Executor 执⾏器？它们之间的区别是什么？

 有三种基本的 Executor 执⾏器，SimpleExecutor、ReuseExecutor、BatchExecutor。



SimpleExecutor：每执⾏⼀次 update 或 select，就开启⼀个 Statement 对象，⽤完⽴刻关闭Statement 对象。



`ReuseExecutor：执⾏ update 或 select，以 sql 作为 key 查找 Statement 对象，存在就使⽤，不存在就创建，⽤完后，不关闭 Statement 对象，⽽是放置于 Map<String, Statement>内，供下⼀次使⽤。简⾔之，就是重复使⽤ Statement 对象。



BatchExecutor：执⾏ update（没有 select，JDBC 批处理不⽀持 select），将所有 sql 都添加到批处理中（addBatch()），等待统⼀执⾏（executeBatch()），它缓存了多个 Statement 对象，每个 Statement 对象都是 addBatch()完毕后，等待逐⼀执⾏ executeBatch()批处理。与JDBC 批处理相同。



作⽤范围：Executor 的这些特点，都严格限制在 SqlSession ⽣命周期范围内。

##  Mybatis 中如何指定使⽤哪⼀种 Executor 执⾏器？

**配置⽂件**中，可以指定默认的 **ExecutorType 执⾏器类型**，也可以⼿动给DefaultSqlSessionFactory的**创建 SqlSession 的⽅法传递 ExecutorType 类型参数**。

## Mybatis 是否可以映射 Enum 枚举类？

Mybatis 可以映射任何对象到表的⼀列上。

映射⽅式为**⾃定义⼀个TypeHandler**，**实现**TypeHandler的**setParameter()和getResult()接⼝⽅法**。

TypeHandler有两个作⽤，⼀是完成从 **javaType** ⾄ **jdbcType** 的转换，⼆是完成jdbcType ⾄ javaType 的转换，

**体现为setParameter()和getResult()两个⽅法**，分别代表设置sql **问号占位符**参数和**获取列查询结果**。

## Mybatis 映射⽂件中，能否引用定义在本标签后的标签内容？

可以。虽然 Mybatis 解析 Xml 映射⽂件是按照顺序解析的，Mybatis 会将 后边的标签标记为**未解析状态**，然后继续解析余下的标签，Mybatis 会**重新解析**那些被标记为未解析的标签。

## Mybatis 的 Xml 解析与映射封装？

Mybatis 将所有 **Xml 配置信息**都封装到 All-In-One 重量级对象 **Configuration 内部**。

在 Xml映射⽂件中，<parameterMap>标签会被解析为**ParameterMap**对象，其每个**⼦元素**会被解析为**ParameterMapping** 对象。

<resultMap>标签会被解析为**ResultMap**对象，其每个⼦元素会被解析为**ResultMapping**对象。

每⼀个<select><insert><update><delete>**标签**均会被解析为**MappedStatement**对象，标签内的 **sql** 会被解析为 **BoundSql** 对象。



## todo

MyBatis执行一个Select查询的流程？

有哪些Executor

插件原理

二级缓存机制？