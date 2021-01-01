打开cmd：
windows+R

列出所有端口情况：
netstat -ano
本机地址冒号后面的就是端口号

查看被占用端口对应的PID：
netstat -aon|findstr "端口号"
netstat -ano|findstr "端口号"

继续输入
tasklist|findstr "PID"   查看那个进程或者程序 占用了。显示的名字 xxx.exe

也可任务管理器  找到PID 结束进程，也可再敲cmd 命令


查看本机 ip地址：
ipconfig
linux下 ifconfig、ip addr

cmd---mysql------------------------------------------------------------------
进入mysql：
myslq -uroot -pxxx

cmd---MongoDB------------------------------------------------------------------


测试MongoDB path变量
net start MongoDB
默认端口27017

客户端连接 服务端
mongo ip		默认不写ip就是本机

客户端退出
exit

详见hbuilder
------------------------------------------------------------------

复制内容
ctrl ＋c
粘贴内容就是 鼠标右键就可

切换磁盘：
d:或者D: 都可以  切磁盘不需要写cd
在别的 磁盘 直接进入别的磁盘的指定目录，一下子进不去，但是还是进去了，需要再加一部切磁盘操作。

进入目录：
cd:  目录名称  带不带\都可以  刚进磁盘进下层也不用 带cd d:\再写下层目录名字
/\ 不区分

返回上目录:
cd ..

创建文件夹：
md d:\data  

测试ip 链接是否正常：
ping  xxx.xxx.xxx