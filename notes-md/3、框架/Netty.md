## Netty是什么？

相⽐于直接使⽤ JDK ⾃带的 NIO 相关的 API 来说更加易⽤。

1、Netty 是⼀个基于 **NIO的 client-server(**客户端服务器)框架，使⽤它可以快速简单地开发⽹络应⽤程序。

2、它极⼤地**简化并优化了 TCP 和 UDP** 套接字服务器等⽹络编程,并且性能以及安全性等很多⽅⾯甚⾄都要更好。

3、**⽀持多种协议如 FTP，SMTP，HTTP** 以及各种⼆进制和基于⽂本的传统协议。



常⽤的 Dubbo、RocketMQ、Elasticsearch、gRPC 等等都⽤到了 Netty。

## 为什么要⽤ Netty？

统⼀的 API，⽀持多种传输类型，阻塞和⾮阻塞的。

安全性不错，有完整的 SSL/TLS 以及 StartTLS ⽀持。

## 应用场景

实现⼀个即时通讯系统

RPC 框架的⽹络通信⼯具

实现消息推送系统

HTTP 服务器



## Netty 核⼼组件类

EventLoop的主要作⽤实际就是负责监听⽹络事件并调⽤事件处理器进⾏相关 I/O 操作的处理。

