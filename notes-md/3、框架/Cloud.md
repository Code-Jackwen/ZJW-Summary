## 一、基础

## 什么是 RPC?RPC原理是什么?

### **什么是 RPC？**

RPC（Remote Procedure Call）—远程过程调用，它是一种通过网络从远程计算机程序上请求服务，而不需要了解底层网络技术的协议。比如两个不同的服务 A、B 部署在两台不同的机器上，那么服务 A 如果想要调用服务 B 中的某个方法该怎么办呢？使用 HTTP请求 当然可以，但是可能会比较**慢**而且一些**优化做的并不好。** RPC 的出现就是为了解决这个问题。

### **RPC原理是什么？**

我这里这是简单的提一下，详细内容可以查看下面这篇文章：

http://www.importnew.com/22003.html

![RPC原理图](../../../../../项目/Git-md/ZJW-Summary/assets/37345851.jpg)

1. 服务消费方（client）调用以本地调用方式调用服务；
2. **client stub接收到调用后负责将方法、参数等组装成能够进行网络传输的消息体；**
3. client stub找到服务地址，并将消息发送到服务端；
4. server stub收到消息后进行解码；
5. server stub**根据解码结果调用本地的服务**；
6. 本地服务执行并将结果返回给server stub；
7. server stub将返回结果打包成消息并发送至消费方；
8. client stub接收到消息，并进行解码；
9. 服务消费方得到最终结果。

下面再贴一个网上的时序图：

![RPC原理时序图](../../../../../项目/Git-md/ZJW-Summary/assets/32527396.jpg)

### RPC 解决了什么问题？

从上面对 RPC 介绍的内容中，概括来讲RPC 主要解决了：**让分布式或者微服务系统中不同服务之间的调用像本地调用一样简单。**

### 常见的 RPC 框架总结?

- **RMI（JDK自带）：** JDK自带的RPC，有很多局限性，不推荐使用。
- **Dubbo:** Dubbo是 阿里巴巴公司开源的一个高性能优秀的服务框架，使得应用可通过高性能的 RPC 实现服务的输出和输入功能，可以和 Spring框架无缝集成。**目前 Dubbo 已经成为 Spring Cloud Alibaba 中的官方组件。**
- **gRPC** ：gRPC是可以在任何环境中运行的现代开源高性能RPC框架。它可以通过可插拔的支持来有效地连接数据中心内和跨数据中心的服务，以实现负载平衡，跟踪，运行状况检查和身份验证。它也适用于分布式计算的最后一英里，以将设备，移动应用程序和浏览器连接到后端服务。

- **Hessian：** Hessian是一个轻量级的remotingonhttp工具，使用简单的方法提供了RMI的功能。 相比WebService，Hessian更简单、快捷。采用的是二进制RPC协议，因为采用的是二进制协议，所以它很适合于发送二进制数据。
- **Thrift：**  Apache Thrift是Facebook开源的跨语言的RPC通信框架，目前已经捐献给Apache基金会管理，由于其跨语言特性和出色的性能，在很多互联网公司得到应用，有能力的公司甚至会基于thrift研发一套分布式服务框架，增加诸如服务注册、服务发现等功能。

## 既有 HTTP ,为啥用 RPC 进行服务调用?

### RPC 只是一种设计而已

RPC 只是一种**概念**、一种**设计**，就是为了解决 **不同服务之间的调用问题**, 它一般会包含有 **传输协议** 和 **序列化协议** 这两个。

但是，HTTP  是一种**协议**，RPC框架可以使用 HTTP协议作为传输协议或者直接使用TCP作为传输协议，使用不同的协议一般也是为了适应不同的场景。

### HTTP 和 TCP

**可能现在很多对计算机网络不太熟悉的朋友已经被搞蒙了，要想真正搞懂，还需要来简单复习一下计算机网络基础知识：**

> 我们通常谈计算机网络的五层协议的体系结构是指：应用层、传输层、网络层、数据链路层、物理层。
>
> **应用层(application-layer）的任务是通过应用进程间的交互来完成特定网络应用。**HTTP 属于应用层协议，它会基于TCP/IP通信协议来传递数据（HTML 文件, 图片文件, 查询结果等）。HTTP协议工作于客户端-服务端架构为上。浏览器作为HTTP客户端通过 URL 向HTTP服务端即WEB服务器发送所有请求。Web服务器根据接收到的请求后，向客户端发送响应信息。HTTP协议建立在 TCP 协议之上。
>
> **运输层(transport layer)的主要任务就是负责向两台主机进程之间的通信提供通用的数据传输服务**。TCP是传输层协议，主要解决数据如何在网络中传输。相比于UDP,**TCP** 提供的是**面向连接**的，**可靠的**数据传输服务。

### RPC框架功能更齐全

成熟的 RPC框架还提供好了“服务自动注册与发现”、"智能负载均衡"、“可视化的服务治理和运维”、“运行期流量调度”等等功能，这些也算是选择
RPC 进行服务注册和发现的一方面原因吧！

**相关阅读：**

- http://www.ruanyifeng.com/blog/2016/08/http.html （HTTP 协议入门- 阮一峰）

### 一个常见的错误观点

很多文章中还会提到说 HTTP 协议相较于自定义 TCP 报文协议，增加的开销在于连接的建立与断开，但是这个观点已经被否认，下面截取自知乎中一个回答，原回答地址：https://www.zhihu.com/question/41609070/answer/191965937。

>首先要否认一点 HTTP 协议相较于自定义 TCP 报文协议，增加的开销在于连接的建立与断开。HTTP 协议是支持连接池复用的，也就是建立一定数量的连接不断开，并不会频繁的创建和销毁连接。二一要说的是 HTTP 也可以使用 Protobuf 这种二进制编码协议对内容进行编码，因此二者最大的区别还是在传输协议上。



## 二、FeignClient与RestTemplate的区别

JAVA 项目中接口调用怎么做 ？

- Httpclient
- Okhttp
- Httpurlconnection
- RestTemplate

区别总结：FeignClient简化了请求的编写，且通过动态负载进行选择要使用哪个服务进行消费，而这一切都由Spring动态配置实现，我们不用关心这些，只管使用方法即可。再说，就是**简化了编写**，RestTemplate还需要写上服务器**IP**这些信息等等，而FeignClient则不用。

Feign是一个http请求调用的轻量级框架，可以以Java接口注解的方式调用Http请求。 fegin是spring cloud微服务推荐使用内部调用方式，底层是http调用类似RestTemplate的一个封装，结合cloud的Ribbon组件，是声明式接口调用，方便。

参考：

FeignClient与RestTemplate的区别：https://www.cnblogs.com/EasonJim/p/8321355.html

## 三、Dubbo 与 Feign 远程调用的区别

一、相同点

Dubbo 与 Feign 都依赖注册中心、负载均衡。

二、区别

**1、协议**

Dubbo：

**支持多传输协议**(Dubbo、Rmi、http、redis等等)，可以根据业务场景选择最佳的方式。非常灵活。

**默认的Dubbo协议**：利用Netty，TCP传输，单一、异步、**长连接**，适合数据量小、高并发和服务提供者远远少于消费者的场景（**消费者多**）。

Feign：

**基于Http传输协议，短连接，不适合高并发的访问。**

**2、负载均衡**

Dubbo：

支持4种算法（随机、轮询、活跃度、Hash一致性），而且算法里面引入**权重**的概念。

配置的形式不仅支持代码配置，还支持Dubbo控制台灵活动态配置。

负载均衡的算法可以**精准到**某个服务接口的**某个方法**。

Feign：

只支持N种策略：轮询、随机、ResponseTime加权。

负载均衡算法是**Client级别**的。

3、容错策略

Dubbo：

**支持多种容错策略**：failover、failfast、brodecast、forking等，也引入了**retry**次数、**timeout**等配置参数。

Feign：

利用**熔断机制**来实现容错的，处理的方式不一样。

参考：

远程调用 Dubbo 与 Feign 的区别：https://blog.csdn.net/riemann_/article/details/108762693

## 四、Dubbo和Spring Cloud的区别

定位：Dubbo 专注 RPC 和服务治理；Spirng Cloud 是一个微服务架构生态。

**性能**：Dubbo 强于 SpringCloud(主要是**通信协议**的影响)

**功能范围**：Dubbo 诞生于面向服务架构时代，是一个分布式、高性能、透明化的 RPC 服务框架，提供服务自动注册、自动发现等高效服务治理方案；Spring Cloud 诞生于微服务架构时代，基于 Spring、SpringBoot，关注微服务的方方面面，提供整套的组件支持

**通信协议**：Dubbo 使用 Netty，基于 TCP 协议传输，用 Hession 序列化完成 RPC 通信；SpringCloud 是基于 Http 协议 + Rest 风格接口通信。Http 请求报文更大，占用带宽更多；Rest 比 RPC 灵活

**更新维护**：Dubbo 曾停止更新，2017年重启维护，中文社区文档较为全面；一直保持高速更新，社区活跃
Dubbo 构建的微服务架构像组装电脑，组件选择自由度高、玩不好容易出问题；Spring Cloud 的像品牌机，提供一整套稳定的组件。

参考：

Dubbo和Spring Cloud的区别：https://blog.csdn.net/meism5/article/details/104439082

## 五、feign和http调用的区别

 feign和http调用的区别（feign 基于短连接，不适合高并发访问，有负载均衡，有服务容错） 

## 六、Eureka和ZooKeeper区别

Eureka和ZooKeeper都可以提供服务注册与发现的功能,请说说两个的区别？

1、ZooKeeper保证的是CP,Eureka保证的是AP

ZooKeeper在**选举期**间注册服务**瘫痪**,虽然服务**最终会恢复**,但是选举期间不可用的

Eureka各个**节点是平等关系**,只要有一台Eureka就可以保证服务**可用**,而查询到的**数据并不是最新**的

自我保护机制会导致

Eureka不再从注册列表移除因长时间没收到心跳而应该过期的服务

Eureka仍然能够接受新服务的注册和查询请求,但是不会被同步到其他节点(高可用)

当网络稳定时,当前实例新的注册信息会被同步到其他节点中(最终一致性)

Eureka可以很好的应对因网络故障导致部分节点失去联系的情况,而不会像ZooKeeper一样使得整个注册系统瘫痪



2、ZooKeeper有Leader和Follower角色,Eureka各个节点平等

3、ZooKeeper采用过半数存活原则,Eureka采用自我保护机制解决分区问题

## 七、Ribbon和Feign的区别？

1、启动类**注解不同**，Ribbon是**@RibbonClient**，feign的是**@EnableFeignClients**

2、**服务指定的位置**不同，Ribbon是在**@RibbonClient注解上声明**，Feign则是在定义**抽象方法的接口中使用@FeignClient**声明。

3、调用方式不同，Ribbon需要自己构建http请求，模拟http请求然后使用RestTemplate发送给其他服务，步骤相当繁琐。Feign需要将调用的方法定义成抽象方法即可。