# Linux中ctrl-c, ctrl-z, ctrl-d 区别

**ctrl-c:** ( kill foreground process ) 发送 SIG INT 信号给前台进程组中的所有进程，**强制终止程序的执行**。

户按下 Ctrl-C，这个键盘输入产生一个**硬件中断**。

如果CPU当前正在执行这个进程的代码，则该进程的用户空间代码暂停执行，CPU从**用户态切换到内核态处理硬件中断。**终端发送了一个SIGINT信号给进程。

**ctrl-z:** ( suspend foreground process ) 发送 SIG TSTP 信号给前台进程组中的所有进程，常用于**挂起一个进程**，而并非结束进程，用户可以使用使用 fg/bg 操作**恢复执行前台或后台的进程**。

fg 命令在前台**恢复**执行被挂起的进程，此时可以使用ctrl-z再次挂起该进程。

bg命令在后台**恢复**执行被挂起的进程，而此时将无法使用 ctrl-z 再次挂起该进程。

使用例子类似于 Windows 的Alt ＋Tab：

正在使用 vi 编辑一个文件时，需要执行 shell 命令查询一些需要的信息，可以使用 ctrl-z 挂起 vi，等执行完shell命令后再使用**fg**恢复vi继续编辑你的文件（当然，也可以在vi中使用！command方式执行shell命令，但是没有该方法方便）。

**ctrl-d:** ( Terminate input, or exit shell ) 一个特殊的二进制值，表示 EOF，作用相当于在终端中输入**exit后回车**；

其他拓展：

**ctrl-/**   发送 SIG QUIT 信号给前台进程组中的所有进程，**终止前台进程并生成 core 文件**。

**ctrl-s**  中断控制台输出

**ctrl-q**  恢复控制台输出

**ctrl-l**   清屏

其实，控制字符都是可以通过stty命令更改的，可在终端中输入命令"stty -a"查看终端配置

