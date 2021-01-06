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

直接使用本地编辑器就可以，我用的 Typora 。

写好的 md文件放到 博客目录下的 \source\_posts 目录下，这个目录下也是有 hello-world.md 存放的目录



写好之后生成下

hexo g

然后开启服务

hexo s  

然后再次访问 http://localhost:4000/ 就可以看到新文章了。





hexo 常用命令官方文档：https://hexo.io/zh-cn/docs/commands.html





创建 github 仓库名字：

handsome99.github.io

> 要创建一个和你用户名相同的仓库，后面加.[http://github.io，只有这样，将来要部署到`GitHub](http://github.xn--io%2C%2C`github-682v24rcn0bge3bnmb63gnr5n8eybxf3aidf/) page`的时候，才会被识别，也就是http://xxxx.github.io，其中xxx就是你注册`GitHub`的用户名。 



接下来和 github 做关联，在博客目录下安装部署到 github 的工具 ，安装完这工具才能用命令部署到`GitHub`。 

cnpm install --save hexo-deployer-git 



成功之后，在博客目录下找到 _config.yml 文件编辑，内容拉到底部，找到：

````java
deploy:
  type: git
  repo: https://github.com/Jack-wen-Java/Jack-wen-Java.github.io.git
  branch: master
````

改完之后

hexo deploy

hexo d

结果却报错：

````
F:\HexoBlog>hexo d

F:\HexoBlog>"node"  "D:\nodejs\node_global\\node_modules\hexo-cli\bin\hexo" d
INFO  Validating config
INFO  Deploying: git
INFO  Clearing .deploy_git folder...
INFO  Copying files from public folder...
INFO  Copying files from extend dirs...
warning: LF will be replaced by CRLF in 2021/01/03/hello-world/index.html.
The file will have its original line endings in your working directory.
warning: LF will be replaced by CRLF in 2021/01/05/Hexo 搭建/index.html.
The file will have its original line endings in your working directory.
warning: LF will be replaced by CRLF in archives/2021/01/index.html.
The file will have its original line endings in your working directory.
warning: LF will be replaced by CRLF in archives/2021/index.html.
The file will have its original line endings in your working directory.
warning: LF will be replaced by CRLF in archives/index.html.
The file will have its original line endings in your working directory.
warning: LF will be replaced by CRLF in css/fonts/fontawesome-webfont.svg.
The file will have its original line endings in your working directory.
warning: LF will be replaced by CRLF in css/style.css.
The file will have its original line endings in your working directory.
warning: LF will be replaced by CRLF in fancybox/jquery.fancybox.min.js.
The file will have its original line endings in your working directory.
warning: LF will be replaced by CRLF in index.html.
The file will have its original line endings in your working directory.
warning: LF will be replaced by CRLF in js/jquery-3.4.1.min.js.
The file will have its original line endings in your working directory.
warning: LF will be replaced by CRLF in js/script.js.
The file will have its original line endings in your working directory.
On branch master
nothing to commit, working tree clean
fatal: HttpRequestException encountered.
   发送请求时出错。
Everything up-to-date
Branch 'master' set up to track remote branch 'master' from 'https://github.com/Jack-wen-Java/Jack-wen-Java.github.io.git'.
````

我又执行了

hexo clean

然后再 hexo d

````java
Counting objects: 11, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (6/6), done.
Writing objects: 100% (11/11), 902 bytes | 300.00 KiB/s, done.
Total 11 (delta 3), reused 0 (delta 0)
remote: Resolving deltas: 100% (3/3), completed with 3 local objects.
To https://github.com/Jack-wen-Java/Jack-wen-Java.github.io.git
   3736b1d..924b130  HEAD -> master
Branch 'master' set up to track remote branch 'master' from 'https://github.com/Jack-wen-Java/Jack-wen-Java.github.io.git'.
````

访问：https://jack-wen-java.github.io/ 和访问 http://localhost:4000/ 结果一致，代表成功了



Civili-Summary



暂时没用

https://github.com/Jack-wen-Java/ZJW-Summary.git



更换主题

主题推荐的专栏博客https://www.bilibili.com/read/cv4499195/

专栏作者的博客 http://www.rwyqboy.top/

结果：Butterfly 感觉还可以 https://github.com/jerryc127/hexo-theme-butterfly	1.8k

Butterfly 的作者博客，效果图  https://jerryc.me/ 





比较华丽的 matery 

主题matery 3k		功能多，复杂点。

https://github.com/blinkfox/hexo-theme-matery

效果 https://blinkfox.github.io/





掘金博客

来自 https://juejin.cn/post/6844904074140205069

全部文章都是关于博客搭建的。

文章推荐优秀搭建效果人

[闪烁之狐](https://blinkfox.github.io/)	是matery主题原版的作者

[洪卫@博客](https://sunhwee.com/)	是matery   	他的仓库，https://github.com/shw2018

推荐的也是很优秀 https://godweiyang.com/about/

仓库里的10年技术化繁为简、**大道至简，知易行难**的博客 https://dunwu.github.io/blog/tags/ 仓库 钝悟



[过客-砺](https://yafine-blog.cn/)	是 matery 的更改，类似了 Butterfly 	

博客里的教程 https://yafine66.gitee.io/categories/Hexo%E5%8D%9A%E5%AE%A2/

# ---------------------------------------------------------------------







hexo-theme-butterfly 作者基于  [hexo-theme-melody](https://github.com/Molunerfinn/hexo-theme-melody) 主题

hexo-theme-melody 仓库https://github.com/Molunerfinn/hexo-theme-melody 有很多搭建好的参考，不是太合我口味



这俩不要安装

cnpm install --save hexo-inject

cnpm install hexo-neat --save

但是需要下载

cnpm install hexo-renderer-pug hexo-renderer-stylus --save





