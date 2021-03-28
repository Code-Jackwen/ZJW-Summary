# Socket
<!-- GFM-TOC -->

* [Socket](#socket)
    * [一、I/O 模型](#一io-模型)
        * [阻塞式 I/O](#阻塞式-io)
        * [非阻塞式 I/O](#非阻塞式-io)
        * [I/O 复用](#io-复用)
        * [信号驱动 I/O](#信号驱动-io)
        * [异步 I/O](#异步-io)
        * [五大 I/O 模型比较](#五大-io-模型比较)
    * [二、I/O 复用](#二io-复用)
        * [select](#select)
        * [poll](#poll)
        * [比较](#比较)
        * [epoll](#epoll)
        * [工作模式](#工作模式)
        * [应用场景](#应用场景)
    * [参考资料](#参考资料)
<!-- GFM-TOC -->

## 一、I/O 模型

I/O：例如通过从磁盘驱动器读取数据，就会被认为是 I/O；

交互机制（消息通信机制），或理解为协作机制：

- **同步**：调用者会主动等待调用结果。按照“调用者”线程在等待调用结果时的状态可分为：
  - 阻塞：线程被操作系统挂起。
  - 非阻塞：线程不被操作系统挂起，可以处理其他事情。
- **异步**：调用者发起一个异步调用，然后立即返回去做别的事。**“被调用者”**通过状态、**通知**、**回调函数**等手段来**通知“调用者”**。**异步IO不是FIFO有序的**，例如进程A与进程B先后对一个端口发起了异步读操作，有可能是进程B先得到读操作的结果。

参考：

https://zh.wikipedia.org/wiki/I/O

## 用户空间与内核空间

现在操作系统都是采用虚拟存储器，那么对32位操作系统而言，它的寻址空间（虚拟存储空间）为4G（2的32次方）。

操作系统的核心是内核，独立于普通的应用程序，可以访问受保护的内存空间，也有访问**底层硬件设备的所有权限**。

为了保证用户**进程**不能直接操作内核（kernel），保证内核的安全，操心系统将虚拟空间划分为两部分，一部分为**内核空间**，一部分为**用户空间**。

Linux操作系统而言，将最高的1G字节（从虚拟地址0xC0000000到0xFFFFFFFF），供内核使用，称为内核空间。

而将较低的3G字节（从虚拟地址0x00000000到0xBFFFFFFF），供各个进程使用，称为用户空间。

## 进程切换

为了控制进程的执行，**内核挂起**正在CPU上运行的进程，并**恢复**以前挂起的某个进程的执行。这种行为被称为**进程切**换。因此可以说，任何进程都是在操作系统内核的支持下运行的，是与内核紧密相关的。

从一个进程的运行转到另一个进程上运行，这个过程中经过下面这些变化：

1、保存处理机上下文，包括**程序计数器和其他寄存器**。
2、更新PCB信息。
3、把进程的PCB移入相应的队列，如就绪、在某事件阻塞等队列。
4、选择另一个进程执行，并更新其PCB。
5、更新内存管理的数据结构。
6、恢复处理机上下文。

注：**总而言之就是很耗资源**，具体的可以参考这篇文章：[进程切换](http://guojing.me/linux-kernel-architecture/posts/process-switch/)

## 进程的阻塞

正在执行的进程，由于期待的某些事件未发生，如请求系统资源失败、等待某种操作的完成、新数据尚未到达或无新工作做等，则由系统自动执行阻塞原语(Block)，使自己由运行状态变为阻塞状态。

可见，进程的阻塞是进程自身的一种**主动行为**，也因此只有处于运行态的进程（获得CPU），才可能将其转为阻塞状态。**当进程进入阻塞状态，是不占用CPU资源的**。

## 文件描述符 

文件描述符（File descriptor），简写 **fd** 是计算机科学中的一个术语，是一个用于表述指向**文件的引用**的抽象化概念。

文件描述符在形式上是一个非负整数。实际上，它是一个索引值，指向内核为每一个进程所维护的该进程打开文件的记录表。**当程序打开一个现有文件或者创建一个新文件时**，**内核向进程返回一个文件描述符**。

## 缓存 I/O

**缓存 I/O** 又被称作**标准 I/O**，大多数**文件系统**的默认 I/O 操作都是缓存 I/O。在 Linux 的缓存 I/O 机制中，操作系统会将 I/O 的数据缓存在文件系统的页缓存（ page cache ）中，

也就是说，数据会先被拷贝到操作系统**内核的缓冲区**中，然后才会从操作系统内核的缓冲区拷贝到**应用程序的地址空间**。

**缓存 I/O 的缺点：**

数据在传输过程中需要在应用程序地址空间和内核进行**多次数据拷贝**操作，这些数据拷贝操作所带来的 CPU 以及内存开销是非常大的。



一个输入操作通常包括两个阶段：

- 等待数据准备好
- 从内核向进程复制数据

对于一个**套接字上的输入**操作，**第一步通常涉及等待数据从网络中到达**。当所等待数据到达时，它被**复制到内核**中的某个**缓冲区**。第二步就是把数据从**内核缓冲区**复制到**应用进程缓冲区**。

Unix 有五种 I/O 模型：

- 阻塞式 I/O
- 非阻塞式 I/O
- I/O 复用（select 和 poll）
- 信号驱动式 I/O（SIGIO）
- 异步 I/O（AIO）

### 阻塞式 I/O

**应用进程被阻塞，直到数据从内核缓冲区复制到应用进程缓冲区中才返回**。

应该注意到，在阻塞的过程中，**其它应用进程还可以执行**，因此阻塞不意味着整个操作系统都被阻塞。因为其它应用进程还可以执行，所以不消耗 CPU 时间，**这种模型的 CPU 利用率会比较高**。

下图中，recvfrom() 用于**接收 Socket 传来的数据**，并复制到**应用进程的缓冲区 buf** 中。这里把 recvfrom() 当成**系统调用**。

```c
ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);
```

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/1492928416812_4.png"/> </div><br>
**在linux中，默认情况下所有的socket都是blocking**，一个典型的读操作流程大概是这样： 

当用户进程调用了recvfrom这个系统调用，kernel就开始了IO的第一个阶段：准备数据（对于网络IO来说，很多时候数据在一开始还没有到达。比如，还没有收到一个完整的UDP包。这个时候kernel就要等待足够的数据到来）。这个过程需要等待，也就是说数据被拷贝到操作系统内核的缓冲区中是需要一个过程的。而在用户进程这边，整个进程会被阻塞（当然，是进程自己选择的阻塞）。当kernel一直等到数据准备好了，它就会将数据从kernel中拷贝到用户内存，然后kernel返回结果，用户进程才解除block的状态，重新运行起来。

> 所以，blocking IO的特点就是在IO执行的两个阶段都被block了。

### 非阻塞式 I/O

应用进程执行系统调用之后，内核返回一个错误码。**应用进程可以继续执行**，但是需要不断的执行**系统调用来获知 I/O 是否完成**，这种方式称为**轮询**（polling）。

由于 CPU 要处理更多的系统调用，因此这种模型的 **CPU 利用率比较低**。

linux下，可以通过设置socket使其变为non-blocking。当对一个non-blocking socket执行读操作时，流程是这个样子： 

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/1492929000361_5.png"/> </div><br>
当用户进程发出read操作时，如果kernel中的数据还没有准备好，那么它并不会block用户进程，而是立刻返回一个error。从用户进程角度讲 ，它发起一个read操作后，并不需要等待，而是马上就得到了一个结果。用户进程判断结果是一个error时，它就知道数据还没有准备好，于是它可以再次发送read操作。一旦kernel中的数据准备好了，并且又再次收到了用户进程的system call，那么它马上就将数据拷贝到了用户内存，然后返回。

> 所以，nonblocking IO的特点是用户进程需要**不断的主动询问**kernel数据好了没有。

### I/O 复用

使用 **select 或者 poll 等待数据**，并且可以**等待多个套接字中的任何一个变为可读**。这一过程会被**阻塞**，当某一个套接字可读时返回，之后再使用 recvfrom 把数据从内核复制到进程中。

它可以**让单个进程具有处理多个 I/O 事件的能力**。又被称为 Event Driven I/O，即**事件驱动 I/O**。

如果一个 Web 服务器没有 I/O 复用，那么每一个 Socket 连接都需要创建一个线程去处理。如果同时有**几万个连接**，那么就需要创建相同数量的**线程**。相比于多进程和多线程技术，**I/O 复用不需要进程线程创建和切换的开销，系统开销更小**。

**扩展：**

IO multiplexing就是我们说的select，poll，epoll，有些地方也称这种IO方式为event driven IO。

**select/epoll的好处就在于单个process就可以同时处理多个网络连接的IO**。

基本原理就是select，poll，epoll这个function会**不断的轮询所负责的所有socket**，**当某个socket有数据到达了，就通知用户进程**。 

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/1492929444818_6.png"/> </div><br>
当用户进程调用了select，那么整个进程会被block，而同时，kernel会“监视”所有select负责的socket，当任何一个socket中的**数据准备好了**，**select就会返回**。这个时候**用户进程再调用read操作**，将数据从kernel**拷贝**到用户进程。

> 所以，I/O 多路复用的特点是通过一种机制一个进程能同时等待多个文件描述符，而这些文件描述符（套接字描述符）其中的任意一个进入读就绪状态，select()函数就可以返回。

这个图和blocking IO的图其实并没有太大的不同，事实上，还更差一些。因为这里需要使用两个system call (select 和 recvfrom)，而blocking IO只调用了一个system call (recvfrom)。但是，**用select的优势在于它可以同时处理多个connection**。

所以，如果处理的**连接数不是很高**的话，使用**select/epoll**的web server不一定比使用**multi-threading + blocking IO**的web server性能更好，可能延迟还更大。

**select/epoll**的**优势**并不是对于单个连接能处理得更快，而是**在于能处理更多的连接**。）

在**IO multiplexing Model**中，实际中，对于每一个socket，一般都设置成为**non-blocking**，但是，如上图所示，**整个用户的process其实是一直被block的**。只不过**process是被select这个函数block，而不是被socket IO给block**。

### 信号驱动 I/O

应用进程使用 **sigaction** 系统调用，**内核立即返回**，**应用进程可以继续执行**，也就是说**等待数据阶段**应用进程是**非阻塞**的。内核在数据到达时向应用进程发送 **SIGIO** 信号，应用进程收到之后在信号处理程序中调用 recvfrom 将数据从内核复制到应用进程中。

相比于**非阻塞式 I/O 的轮询方式**，信号驱动 I/O 的 CPU **利用率更高**。

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/1492929553651_7.png"/> </div><br>
### 异步 I/O

应用进程执行 **aio_read** 系统调用会**立即返回**，**应用进程可以继续执行**，**不会被阻塞**，**内核会在所有操作完成之后向应用进程发送信号**。

异步 I/O 与信号驱动 I/O 的区别在于，**异步 I/O** 的信号是通知应用进程 **I/O 完成**，而**信号驱动 I/O** 的信号是通知应用进程**可以开始 I/O**。

Linux下的asynchronous IO其实用得很少。先看一下它的流程： 

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/1492930243286_8.png"/> </div><br>
用户进程发起read操作之后，立刻就可以开始去做其它的事。而另一方面，从kernel的角度，当它受到一个asynchronous read之后，首先它会**立刻返回**，所以不会对用户进程产生任何block。然后，kernel会等待数据准备完成，然后将数据拷贝到用户内存，当这一切都**完成之后**，kernel会给用户进程发送一个signal，告诉它read操作完成了。 



### blocking和non-blocking的区别

调用blocking IO会一直block住对应的进程直到操作完成，而non-blocking IO在**kernel还准备数据**的情况下会立刻返回。

### synchronous IO和asynchronous IO的区别

在说明synchronous IO和asynchronous IO的区别之前，需要先给出两者的定义。POSIX的定义是这样子的：
\- A synchronous I/O operation causes the requesting process to be blocked until that I/O operation completes;
\- An asynchronous I/O operation does not cause the requesting process to be blocked;

两者的区别就在于**synchronous IO做”IO operation”的时候会将process阻塞**。按照这个定义，之前所述的blocking IO，non-blocking IO，IO multiplexing都属于synchronous IO。

有人会说，non-blocking IO并没有被block啊。这里有个非常“狡猾”的地方，定义中所指的”IO operation”是指真实的IO操作，就是例子中的recvfrom这个system call。

**non-blocking IO**在执行recvfrom这个system call的时候，如果kernel的**数据没有准备好**，这时候**不会block**进程。但是，当kernel中数据准备好的时候，recvfrom会将数据**从kernel拷贝到用户内存中，这个时候进程是被block了**，在这段时间内，进程是被block的。

**asynchronous IO**则不一样，当进程发起IO 操作之后，就直接返回再也不理睬了，直到kernel发送一个信号，告诉进程说IO完成。在这整个过程中，**进程完全没有被block**。



### 五大 I/O 模型比较

- 同步 I/O：**将数据从内核缓冲区复制到应用进程缓冲区的阶段（第二阶段），应用进程会阻塞。**
- 异步 I/O：**第二阶段应用进程不会阻塞。**

同步 I/O 包括阻塞式 I/O、非阻塞式 I/O、I/O 复用和信号驱动 I/O ，它们的主要区别在第一个阶段。

非阻塞式 I/O 、信号驱动 I/O 和异步 I/O 在第一阶段不会阻塞。

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/1492928105791_3.png"/> </div><br>
通过上面的图片，可以发现**non-blocking IO和asynchronous IO的区别**还是很明显的。

在non-blocking IO中，虽然进程大部分时间都不会被block，但是它仍然**要求进程去主动的check**，并且当数据准备完成以后，也需要进程主动的再次调用recvfrom来将数据拷贝到用户内存。

而asynchronous IO则完全不同。它就像是用户进程将**整个IO操作交给了他人（kernel）完成**，然后他人做完后发信号通知。在此期间，用户进程**不需要去检查**IO操作的状态，也**不需要主动的去拷贝**数据。 

## 二、I/O 复用

select/poll/epoll 都是 I/O 多路复用的具体实现，select 出现的最早，之后是 poll，再是 epoll。

select，poll，epoll本质上都是同步I/O，因为他们都需要在读写事件就绪后**自己负责进行读写**，也就是说**这个读写过程是阻塞的**。而异步I/O则无需自己负责进行读写，异步I/O的实现会负责把数据从内核拷贝到用户空间。

### select

```c
int select(int n, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
```

**调用后select函数会阻塞，直到有描述副就绪**（有数据 可读、可写、或者有except），或者超时（timeout指定等待时间，如果立即返回设为null即可），函数返回。当select函数返回后，可以 通过遍历fdset，来找到就绪的描述符。

select目前几乎在所有的平台上支持，其**良好跨平台**支持也是它的一个优点。

select的一 个缺点在于**单个进程能够监视的文件描述符的数量存在最大限制**，在**Linux**上**一般为1024**，可以通过修改宏定义甚至重新编译内核的方式提升这一限制，但是这样也会造成效率的降低。

select **允许应用程序监视**一组文件描述符，**等待一个或者多**个描述符成为**就绪状态**，从而完成 I/O 操作。

- fd_set 使用数组实现，数组大小使用 FD_SETSIZE 定义，所以只能监听少于 FD_SETSIZE 数量的描述符。有三种类型的描述符类型：readset、writeset、exceptset，分别对应读、写、异常条件的描述符集合。
- timeout 为超时参数，调用 select 会一直阻塞直到有描述符的事件到达或者等待的时间超过 timeout。
- 成功调用返回结果大于 0，出错返回结果为 -1，超时返回结果为 0。

```c
fd_set fd_in, fd_out;
struct timeval tv;

// Reset the sets
FD_ZERO( &fd_in );
FD_ZERO( &fd_out );

// Monitor sock1 for input events
FD_SET( sock1, &fd_in );

// Monitor sock2 for output events
FD_SET( sock2, &fd_out );

// Find out which socket has the largest numeric value as select requires it
int largest_sock = sock1 > sock2 ? sock1 : sock2;

// Wait up to 10 seconds
tv.tv_sec = 10;
tv.tv_usec = 0;

// Call the select
int ret = select( largest_sock + 1, &fd_in, &fd_out, NULL, &tv );

// Check if select actually succeed
if ( ret == -1 )
    // report error and abort
else if ( ret == 0 )
    // timeout; no event detected
else
{
    if ( FD_ISSET( sock1, &fd_in ) )
        // input event on sock1

    if ( FD_ISSET( sock2, &fd_out ) )
        // output event on sock2
}
```

### poll

**poll 的功能与 select 类似，也是等待一组描述符中的一个成为就绪状态**。

```c
int poll(struct pollfd *fds, unsigned int nfds, int timeout);
```

不同与select使用三个位图来表示三个fdset的方式，poll使用一个 pollfd的指针实现。

pollfd结构包含了要监视的event和发生的event，不再使用select“参数-值”传递的方式。

同时，pollfd并**没有最大数量限制**（**但是数量过大后性能也是会下降**）。

和**select函数一样，poll返回后，需要轮询pollfd来获取就绪的描述符。**

> 从上面看，select和poll都需要在返回后，通过遍历文件描述符来获取已经就绪的socket。
>
> 事实上，同时连接的大量客户端在一时刻可能只有很少的处于就绪状态，因此**随着监视的描述符数量的增长，其效率也会线性下降。**

poll 中的描述符是 pollfd 类型的数组，pollfd 的定义如下：

```c
struct pollfd {
               int   fd;         /* file descriptor */
               short events;     /* requested events */
               short revents;    /* returned events */
           };
```


```c
// The structure for two events
struct pollfd fds[2];

// Monitor sock1 for input
fds[0].fd = sock1;
fds[0].events = POLLIN;

// Monitor sock2 for output
fds[1].fd = sock2;
fds[1].events = POLLOUT;

// Wait 10 seconds
int ret = poll( &fds, 2, 10000 );
// Check if poll actually succeed
if ( ret == -1 )
    // report error and abort
else if ( ret == 0 )
    // timeout; no event detected
else
{
    // If we detect the event, zero it out so we can reuse the structure
    if ( fds[0].revents & POLLIN )
        fds[0].revents = 0;
        // input event on sock1

    if ( fds[1].revents & POLLOUT )
        fds[1].revents = 0;
        // output event on sock2
}
```

### select 和 poll 比较

#### 1. 功能

select 和 poll 的功能基本相同。

**poll 的功能与 select 类似，也是等待一组描述符中的一个成为就绪状态**。

**select函数一样，poll返回后，需要轮询pollfd来获取就绪的描述符。**

不过在一些实现细节上有所不同。

- **select 会修改描述符，而 poll 不会**；
- **select** 的描述符类型使用**数组实现**，FD_SETSIZE 大小默认为 **1024**，因此默认只能监听少于 1024 个描述符。如果要监听更多描述符的话，需要修改 FD_SETSIZE 之后重新编译；而 **poll 没有描述符数量的限制**；
- poll 提供了更多的**事件类型**，并且对描述符的**重复利用率**上比 select 高。
- 如果一个线程对某个描述符调用了 select 或者 poll，另一个线程关闭了该描述符，会导致调用结果不确定。

#### 2. 速度

select 和 poll 速度都比较慢，每次调用都需要将**全部描述符**从**应用进程缓冲区**复制到**内核缓冲区**。

#### 3. 可移植性

**几乎所有的系统都支持 select，但是只有比较新的系统支持 poll。**

#### 4、时间精度

### epoll

```c
int epoll_create(int size);//创建一个epoll的句柄，size用来告诉内核这个监听的数目一共有多大
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event)；
int epoll_wait(int epfd, struct epoll_event * events, int maxevents, int timeout);
```

**1. int epoll_create(int size);**
创建一个epoll的句柄，size用来告诉内核这个监听的数目一共有多大，这个参数不同于select()中的第一个参数，给出最大监听的fd+1的值，参数**size**并不是限制了epoll所能监听的描述符最大个数，**只是对内核初始分配内部数据结构的一个建议**。
当创建好epoll句柄后，它就会占用一个fd值，在linux下如果查看/proc/进程id/fd/，是能够看到这个fd的，所以在使用完epoll后，必须调用close()关闭，否则可能导致fd被耗尽。

**2. int epoll_ctl(int epfd, int op, int fd, struct epoll_event \*event)；**
函数是对指定描述符fd执行op操作。
\- epfd：是epoll_create()的返回值。
\- op：表示op操作，用三个宏来表示：添加EPOLL_CTL_ADD，删除EPOLL_CTL_DEL，修改EPOLL_CTL_MOD。分别添加、删除和修改对fd的监听事件。
\- fd：是需要监听的fd（文件描述符）
\- epoll_event：是告诉内核需要监听什么事，struct epoll_event结构如下：

```
struct epoll_event {
  __uint32_t events;  /* Epoll events */
  epoll_data_t data;  /* User data variable */
};

//events可以是以下几个宏的集合：
EPOLLIN ：表示对应的文件描述符可以读（包括对端SOCKET正常关闭）；
EPOLLOUT：表示对应的文件描述符可以写；
EPOLLPRI：表示对应的文件描述符有紧急的数据可读（这里应该表示有带外数据到来）；
EPOLLERR：表示对应的文件描述符发生错误；
EPOLLHUP：表示对应的文件描述符被挂断；
EPOLLET： 将EPOLL设为边缘触发(Edge Triggered)模式，这是相对于水平触发(Level Triggered)来说的。
EPOLLONESHOT：只监听一次事件，当监听完这次事件之后，如果还需要继续监听这个socket的话，需要再次把这个socket加入到EPOLL队列里
```

**3. int epoll_wait(int epfd, struct epoll_event \* events, int maxevents, int timeout);**
等待epfd上的io事件，最多返回maxevents个事件。
参数events用来从内核得到事件的集合，maxevents告之内核这个events有多大，这个maxevents的值不能大于创建epoll_create()时的size，参数timeout是超时时间（毫秒，0会立即返回，-1将不确定，也有说法说是永久阻塞）。该函数返回需要处理的事件数目，如返回0表示已超时。

**解释：**

**epoll_ctl()** 用于向内核注册新的描述符或者是改变某个文件描述符的状态。

已注册的描述符在内核中会被维护在一棵**红黑树**上，**通过回调函数内核会将 I/O 准备好的描述符加入到一个链表中管理，进程调用 epoll_wait() 便可以得到事件完成的描述符**。

从上面的描述可以看出，**epoll 只需要将描述符从进程缓冲区向内核缓冲区拷贝一次**，并且**进程不需要通过轮询**来获得事件完成的描述符。

**epoll 仅适用于 Linux OS。**

epoll 比 select 和 poll 更加灵活而且**没有描述符数量限制**。

epoll 对**多线程编程更有友好**，一个线程调用了 epoll_wait() 另一个线程关闭了同一个描述符也不会产生像 select 和 poll 的不确定情况。



### epoll总结

**epoll的优点主要是一下几个方面：**

1、在 select/poll中，进程只有在调用一定的方法后，内核才对所有监视的文件描述符进行**扫描**。

**而epoll事先通过epoll_ctl()来注册一 个文件描述符，一旦基于某个文件描述符就绪时，内核会采用类似callback的回调机制，迅速激活这个文件描述符，当进程调用epoll_wait() 时便得到通知。**

此处**去掉了遍历文件描述符**，而是通过**监听回调的的机制**。这正是epoll的魅力所在。

2、**监视的描述符数量不受限制**，它所支持的FD上限是最大可以打开文件的数目，这个数字一般远大于2048。

举个例子,在1GB内存的机器上大约是10万左 右，具体数目可以cat /proc/sys/fs/file-max察看,一般来说这个数目和系统内存关系很大。

**select的最大缺点就是进程打开的fd是有数量限制的**。这对 于连接数量**比较大的服务器来说根本不能满足**。

虽然也可以选择**多进程**的解决方案( Apache就是这样实现的)，不过虽然linux上面创建进程的代价比较小，但仍旧是不可忽视的，加上进程间数据同步远比不上线程间同步的高效，所以也不是一种完美的方案。

3、**IO的效率不会随着监视fd的数量的增长而下降**。**epoll不同于select和poll轮询**的方式，而是**通过每个fd定义的回调函数来实现的**。**只有就绪的fd才会执行回调函数**。

如果没有大量的idle -connection(空闲连接)或者dead-connection，epoll的效率并不会比select/poll高很多，但是**当遇到大量的idle- connection，就会发现epoll的效率大大高于select/poll**。




### 工作模式

epoll 的描述符事件有两种触发模式：LT（level trigger）(默认)和 ET（edge trigger）。

#### 1. LT 模式

当 epoll_wait() 检测到描述符事件到达时，将此事件通知进程，**进程可以不立即处理该事件**，下次调用 epoll_wait() **会再次通知进程**。是**默认的一种模式**，并且同时支持 **Blocking 和 No-Blocking**。

#### 2. ET 模式

和 LT 模式不同的是，**通知之后进程必须立即处理事件**，下次再调用 epoll_wait() 时**不会再得到事件到达的通知**。

很大程度上减少了 epoll 事件被重复触发的次数，因此**效率要比 LT 模式高**。**只支持 No-Blocking**，以避免由于一个文件句柄的阻塞读/阻塞写操作把处理多个文件描述符的任务饿死。

### 应用场景

很容易产生一种错觉认为只要用 epoll 就可以了，select 和 poll 都已经过时了，其实它们都有各自的使用场景。

#### 1. select 应用场景

**select** 的 **timeout** 参数精度为**微秒**，而 poll 和 epoll 为**毫秒**，因此 select 更加适用于**实时性要求比较高**的场景，比如**核反应堆的控制**。支持最多数量和系统硬件有很大关系，32位的1024、64位一般2048

**select** **可移植性更好**，几乎被所有主流平台所支持。

#### 2. poll 应用场景

**poll 没有最大描述符数量的限制**，如果平台支持并且对实时性要求不高，应该使用 poll 而不是 select。

#### 3. epoll 应用场景

**只需要运行在 Linux 平台上**，有**大量**的描述符需要同时轮询，并且这些**连接最好是长连接**。

需要同时监控小于 1000 个描述符，就没有必要使用 epoll，因为这个应用场景下并不能体现 epoll 的优势。

**需要监控的描述符状态变化多，而且都是非常短暂的，也没有必要使用 epoll**。因为 epoll 中的**所有描述符都存储在内核中**，造成每次需要对**描述符的状态改变**都需要通过 **epoll_ctl()** 进行**系统调用**，**频繁系统调用降低效率**。并且 **epoll 的描述符存储在内核**，**不容易调试**。



面试之区别再整理：

select、poll、epoll之间的区别：https://xzchsia.github.io/2021/02/24/select-poll-epoll/

## 参考资料

- Stevens W R, Fenner B, Rudoff A M. UNIX network programming[M]. Addison-Wesley Professional, 2004.
- http://man7.org/linux/man-pages/man2/select.2.html
- http://man7.org/linux/man-pages/man2/poll.2.html
- [Boost application performance using asynchronous I/O](https://www.ibm.com/developerworks/linux/library/l-async/)
- [Synchronous and Asynchronous I/O](https://msdn.microsoft.com/en-us/library/windows/desktop/aa365683(v=vs.85).aspx)
- [Linux IO 模式及 select、poll、epoll 详解](https://segmentfault.com/a/1190000003063859)
- [poll vs select vs event-based](https://daniel.haxx.se/docs/poll-vs-select.html)
- [select / poll / epoll: practical difference for system architects](http://www.ulduzsoft.com/2014/01/select-poll-epoll-practical-difference-for-system-architects/)
- [Browse the source code of userspace/glibc/sysdeps/unix/sysv/linux/ online](https://code.woboq.org/userspace/glibc/sysdeps/unix/sysv/linux/)

其他参考：

[用户空间与内核空间，进程上下文与中断上下文总结](http://www.cnblogs.com/Anker/p/3269106.html)
[进程切换](http://guojing.me/linux-kernel-architecture/posts/process-switch/)
[维基百科-文件描述符](https://zh.wikipedia.org/wiki/文件描述符)
[Linux 中直接 I/O 机制的介绍](http://www.ibm.com/developerworks/cn/linux/l-cn-directio/)
[IO - 同步，异步，阻塞，非阻塞 （亡羊补牢篇）](http://blog.csdn.net/historyasamirror/article/details/5778378)
[Linux中select poll和epoll的区别](http://www.cnblogs.com/bigwangdi/p/3182958.html)
[IO多路复用之select总结](http://www.cnblogs.com/Anker/archive/2013/08/14/3258674.html)
[IO多路复用之poll总结](http://www.cnblogs.com/Anker/archive/2013/08/15/3261006.html)
[IO多路复用之epoll总结](http://www.cnblogs.com/Anker/archive/2013/08/17/3263780.html) 