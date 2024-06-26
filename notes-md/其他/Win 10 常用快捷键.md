## cmd 其他命令

##### 打开cmd

windows+R

##### 列出所有端口情况

netstat -ano
本机地址冒号后面的就是端口号

查看被占用端口对应的PID：
netstat -aon|findstr "端口号"
netstat -ano|findstr "端口号"

继续输入
tasklist|findstr "PID"   查看那个进程或者程序 占用了。显示的名字 xxx.exe

也可任务管理器  找到PID 结束进程，也可再敲cmd 命令



##### 测试ip 链接是否正常

Ping 测试 5 次：ping ip/域名 -n 5



##### 查看本机 ip地址：

win：ipconfig
linux： ifconfig、ip addr

##### cmd 下登录 mysql

进入mysql：

myslq -uroot -pxxx

##### cmd 下的 MongoDB

测试MongoDB path变量
net start MongoDB



默认端口27017



客户端连接服务端
mongo ip		默认不写ip就是本机



客户端退出
exit





## 文件操作

##### 复制内容

ctrl ＋c
粘贴内容就是 鼠标右键就可

##### 切换磁盘

d:或者D: 都可以  切磁盘不需要写cd

或者：

- 切换磁盘和目录：cd /d d:/test（进入 d 盘 test 文件夹）
- 进入文件夹：cd \test1\test2（进入 test2 文件夹）



##### 进入目录

cd:  目录名称  带不带\都可以  刚进磁盘进下层也不用 带cd d:\再写下层目录名字
/\ 不区分

##### 返回上目录

cd ..

##### 返回根目录

cd \

##### 创建文件夹

md d:\data  

##### 显示目录中文件列表

dir

##### 显示当前目录位置

cd

asdads

##### 清屏

cls

linux：clear 

##### 帮助命令

help

##### 删除文件 

//这个是专门删除文件的，不能删除文件夹 del 文件名 

del 文件名 

## Windows 快捷键

##### 打开资源管器

也就是我的电脑

win+E 



##### 调出运行命令窗口

WINDOWS+R           

  

##### 临时查看桌面

Windows 键+,



##### 虚拟桌面 

创建一个新的虚拟桌面 

Win键+Tab 点击加号新建桌面或者Win键+Ctrl+D

切换虚拟桌面 

 Win键+Tab

 Win键+Ctrl+左/右：



##### 窗口操作 Windows + 箭头

最大化窗口(与 Metro 应用无关)

Windows 键+ ↑

最小化窗口(与 Metro 应用无关)

Windows 键+ ↓

最大化窗口到左侧的屏幕上(与 Metro 应用无关)

Windows 键 + ←

最大化窗口到右侧的屏幕上(与 Metro 应用无关)

Windows 键 + →

垂直拉伸窗口，宽度不变(与 Metro 应用无关)

Windows 键+ SHIFT +↑

垂直缩小窗口，宽度不变(与 Metro 应用无关)

Windows 键+ SHIFT +↓



##### 录制视频或截屏栏等等

 Win键+G

##### 激活Cortana 

 Win键+C



##### 打开设置栏

Windows 键+I：



##### 打开蓝牙

Windows 键+K



##### 打开语音输入

Windows 键+H：



##### 打开应用搜索面板

Windows 键+Q：



##### 快捷菜单

Windows 键+X：



##### 外链接显示屏栏目显示

Windows 键+ P



##### 打开“运行”对话框

Windows 键+R：



##### 任务页

Windows 键+Tab

会显示历史打开的应用



##### 打开任务管理器

ctrl+shift+Esc 



##### 查找

ctrl+F                  

可用于文件或者网页，退出一般按ESC。



##### 上下扩展选择文字 

Ctrl+Shift+上下左右箭头



获取帮助信息

F1

想得到 Windows 帮助，则需要按下 Win+F1。

按下 Shift+F1，会出现 "What's This?" 的帮助信息 



##### 重命名该文件

F2



##### 搜索该文件目录下的文件

F3



##### 关闭当前窗口

Alt + F4 或者 ctrl + w          



##### 刷新

F5



##### 快速选中资源管理器、IE 中的地址栏

 F6



##### 资源管理器或 IE 变为全屏显示

 F11



##### 最小化当前窗口

ALT+Esc 

备用：Alt + 空格 + N 最小化当前窗口 (和浏览器的最小化一样) 

ALT+TAB  切换窗口，也可以认为是恢复刚才缩小后的当前窗口



##### 最小化所有窗口（再按恢复）

Win+D 

也可以是显示桌面





##### 备用：最小化所有窗口

Windows 键+M

Windows+Shift+M：还原最小化的窗口。 



##### 显示电脑配置信息

Win + SL（→列最上边的按键）



##### 彻底删除文件，

SHIFT + DEL 



##### 备用：开始菜单 WIN 键

 CTRL+ESC 

相当于按了开始菜单 WIN 键



##### 创建该文件的快捷方式

点住一个文件按 CTRL+SHIFT，拖到该文件就可以。 



##### 关机

win + x 打开系统菜单

win + x + u + u 关机

或者 

Win+D 切换桌面，再按 Alt + F4 关机 + 回车

 

##### 锁机

win+L      