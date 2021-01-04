这里的前提是有 node.js 环境，本地安装过 git 。



Hexo 博客的好处：

- 用户多，解决方案多。
- 不需要买服务器，不需要买域名。



我的电脑是 win10 下边开始命令操作。

node版本

node -v

v12.13.1



包管理器的版本

npm -v

6.12.1



某宝镜像有了后可以用cnpm命令



cnpm install -g hexo-cli



hexo -v

hexo-cli: 4.2.0



IOS：sudo hexo init

Win：hexo init



就 hexo init 这一步一直失败，且慢，这里直接从 git 上拉下来复制到目录，不用这个破命令。

就是这个 git 仓库：https://github.com/hexojs/hexo-starter

试过配置 git 代理，不靠谱。



拷贝完，执行启动命令。一般这个命令用来写完博客后预览用

hexo s 或者 hexo server

然后又报错，这时候按照错误执行了 cnpm install --force 之后 又执行 hexo s 后才出现 http://localhost:4000/

访问成功出现默认带的 HelloWorld 文章代表基本架子成功。



接下来自己写一篇文章试试。



