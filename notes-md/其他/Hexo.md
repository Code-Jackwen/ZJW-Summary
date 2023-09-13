## 一、Hexo 基础搭建

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



#### 与 Git Hub 关联

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





## 二、博客主题相关

下边是更换主题相关的。



主题推荐的专栏博客https://www.bilibili.com/read/cv4499195/



总结：

##### Butterfly 

做技术博客不错，不过分华丽。

仓库：https://github.com/jerryc127/hexo-theme-butterfly	1.8k

Butterfly 作者博客 jerryc：https://jerryc.me/ 

BF的学习文档：https://butterfly.js.org/posts/21cfbf15/



##### Matery 

功能多，复杂点。

https://github.com/blinkfox/hexo-theme-matery   3k		

Matery 作者博客 blinkfox：https://blinkfox.github.io/



作者官方教程：https://github.com/blinkfox/hexo-theme-matery/blob/develop/README_CN.md





##### Next

仓库钝悟，南大硕士 https://dunwu.github.io/blog/tags/  

钝悟仓库：https://github.com/dunwu

来自洪卫 Git  的仓库。仓库里的10年技术化繁为简、**大道至简，知易行难**的博客 





##### 掘金博客

来自 https://juejin.cn/post/6844904074140205069

全部文章都是关于博客搭建的。

博客推荐的三个人。

[闪烁之狐](https://blinkfox.github.io/)	是matery主题原版的作者	作者样板展示：https://blinkfox.github.io/about/	友情链接不错的很多





[洪卫@博客](https://sunhwee.com/)	是matery   	他的仓库，https://github.com/shw2018

推荐的韦阳也是很优秀 https://godweiyang.com/about/





[过客-砺](https://yafine-blog.cn/)

博客里的教程 https://yafine66.gitee.io/categories/Hexo%E5%8D%9A%E5%AE%A2/



##### docsify

制作 Github Pages，一个神奇的文档网站生成器。

docsify仓库： https://docsify.js.org/#/zh-cn/?id=docsify  	16k

案例展示：https://github.com/docsifyjs/awesome-docsify#showcase

中文使用文档：https://docsify.js.org/#/zh-cn/	



功能：[Vuepress-阅读量统计](https://heshiyu1996.github.io/tool/vuepress-stat/#vuepress-阅读量统计) 

Heshiyu前端仓库：https://heshiyu1996.github.io/tool/vuepress-stat/







图床相关：

如何使用七牛云做为图床？：https://www.jianshu.com/p/6dce6094bf61

如何用七牛和picGO设置免费图床：https://www.jianshu.com/p/0997d0d15e55

## 参考

建议参考主题博主的，以及在博主友链里找些做比较成功的做参考。

总结：

##### BF 

sitoi：https://sitoi.cn/

过客-砺 ：https://yafine-blog.cn/

码酱，罗康源：http://luokangyuan.com/

B站专栏写主题推荐博客作者的：http://www.rwyqboy.top/



Email的学习Java的：https://blog.hvnobug.com/	他的友链未看

他的统计github资料的文章，不过有中文社区了 https://blog.hvnobug.com/post/github-learning.html



Sanarous	https://bestzuo.cn/ 菊厂的前端，一级词条很多。



##### MA

洪卫：https://sunhwee.com/

Dot：https://www.a2data.cn/



Mr.wang：https://www.kingcrown.top/ 可以参考样式，不偏技术。

Mx 过客～铭む 	https://mx142.cn/friends/	 二级标签较花。	来自南玖





##### 其他

这人博客挺干净： Powered by [Hux Blog](http://huangxuan.me/) 

https://xzchsia.github.io/2020/03/05/linux-hard-soft-link/



有他qq，让它帮我搭，后放弃。：https://hesifan.top/about/

YFun在校生：https://www.yfun.top/archives/	文章：免费图床推荐、CloudFlare 加速网站

YFun的站点监控：https://www.yfun.top/status/



体育特招生：https://www.a2data.cn/

frankfeekr：https://www.frankfeekr.cn/author/	

南开的阿杜蚂蚁金服非 hexo ：http://www.javaadu.online/



4ark：https://4ark.me/ 本站基于 Hexo + GitHub Page 搭建，采用 [Polar Bear](https://github.com/frostfan/hexo-theme-polarbear) 主题 ，比较简洁。来自星空无限友链

南玖：https://ztongyang.cn/  黑色画风，功能多。内容杂。

[Hugo](https://gohugo.io/) & [Mogege](https://github.com/Mogeko/Mogege) 来自https://todebug.com/posts/  白色背景，比较简洁。



Mashiro：https://2heng.xin/friends/ 样式花，主题好看。来自洪卫友链

codesheep：https://www.codesheep.cn/	来自Sanarous，世界很小。

美团：https://tech.meituan.com/	来自Sanarous



鑫斌网络传媒创始人  刘禹宁99年 ，鑫斌是它品牌 ：https://www.xbwlcm.com/about.html	网站很特别花。



TRHX的博客中**图床搭建**：https://www.itrhx.com/2019/08/01/A27-image-hosting/ 来自韦阳



功能总结：

有首页接广告的：https://www.fivecc.cn/



NlP算法工程师，刘训灼，电子科技大：https://liuxunzhuo.tech/



友链看完的：

星空无限、洪卫





域名的购买： 

套路云买的、 续费是69一年 

良心云也行





记录下这个人的目录功能。博客园的

https://www.cnblogs.com/saoqiang/p/12453743.html



## 换新主题报错---------------

别人新的博客报错重来，在空的博客文件夹下执行

cnpm install -g hexo-cli

cnpm install

显示样式：cnpm install hexo-renderer-pug hexo-renderer-stylus --save





这俩不要安装

cnpm install --save hexo-inject

cnpm install hexo-neat --save





Hexo 七牛插件安装与使用

https://juejin.cn/post/6844903555342532615

七牛云插件配置

chrome-extension://lpdellhjncaloeogibenafbdiaklnhdc/options.html