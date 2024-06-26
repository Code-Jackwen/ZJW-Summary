### 4.2 Oauth2授权模式介绍

Oauth2有以下授权模式： 

```
1.授权码模式（Authorization Code）
2.隐式授权模式（Implicit） 
3.密码模式（Resource Owner Password Credentials） 
4.客户端模式（Client Credentials） 
```

其中授权码模式和密码模式应用较多，本小节介绍授权码模式。

#### 4.2.1 授权码模式

##### 4.2.1.1 授权码授权流程 

![1614602658185](../../assets/1614602658185.png)



黑马程序员网站使用**微信认证**的过程就是授权码模式，流程如下： 

1、客户端**请求第三方授权** 

2、用户同意给客户端**授权** 

3、客户端获取到**授权码**，**请求认证服务器申请令牌** 

4、认证服务器向客户端**响应令牌** 

5、客户端**请求资源**服务器的资源，资源服务校验令牌合法性，完成授权 

6、资源服务器**返回受保护资源**   



##### 4.2.1.2 申请授权码

请求认证服务获取授权码：

```properties
Get请求：
http://localhost:9200/oauth/authorize?client_id=changgou&response_type=code&scop=app&redirect_uri=http://localhost
```

参数列表如下： 

```properties
client_id：客户端id，和授权配置类中设置的客户端id一致。 
response_type：授权码模式固定为code 
scop：客户端范围，和授权配置类中设置的scop一致。 
redirect_uri：跳转uri，当授权码申请成功后会跳转到此地址，并在后边带上code参数（授权码）
```

 首先跳转到登录页面：**这是因为配置了拦截，正常的话没有这一步。**

![1558181493405](../../assets/1558181493405.png)

输入账号和密码，点击Login。Spring Security接收到请求会调用UserDetailsService接口的loadUserByUsername方法查询用户正确的密码。 当前导入的基础工程中客户端ID为changgou，秘钥也为changgou即可认证通过。 

接下来进入授权页面：

![1558181664387](../../assets/1558181664387.png)   

点击Authorize,接下来**返回授权码**： 认证服务携带授权码跳转 redirect_uri，code=k45iLY 就是返回的授权码, **每一个授权码只能使用一次**

![1558181855325](../../assets/1558181855325.png)



##### 4.2.1.3 申请令牌

拿到授权码后，**申请令牌**。

```properties
Post请求：
http://localhost:9200/oauth/token
```

 参数如下： 

```properties
grant_type：授权类型，填写 authorization_code，表示授权码模式 
code：授权码，就是刚刚获取的授权码，注意：授权码只使用一次就无效了，需要重新申请。 
redirect_uri：申请授权码时的跳转url，一定和申请授权码时用的redirect_uri一致。 
```

此链接需要使用 **http Basic认证。** 

什么是http Basic认证？

​	http协议定义的一种**认证方式**，将客户端id和客户端密码按照“**客户端ID:客户端密码**”的格式**拼接**，并**用 base64编码，放在header中请求服务端**，一个例子： Authorization：Basic WGNXZWJBcHA6WGNXZWJBcHA=WGNXZWJBcHA6WGNXZWJBcHA= 是用户名:密码的base64编码。 认证失败服务端返回 401 Unauthorized。

以上测试使用postman完成： 

http basic认证：    

![1558182132328](../../assets/1558182132328.png)

![1558182177167](../../assets/1558182177167.png)

**客户端Id和客户端密码会匹配数据库 oauth_client_details 表中的客户端id及客户端密码。**    

点击发送： 申请令牌成功    

![1558182272542](../../assets/1558182272542.png)

返回信如下:

```properties
access_token：访问令牌，携带此令牌访问资源 
token_type：有MAC Token与Bearer Token两种类型，两种的校验算法不同，RFC 6750建议Oauth2采用 Bearer Token（http://www.rfcreader.com/#rfc6750）。 
refresh_token：刷新令牌，使用此令牌可以延长访问令牌的过期时间。 
expires_in：过期时间，单位为秒。 
scope：范围，与定义的客户端范围一致。    
jti：当前token的唯一标识
```

##### 4.2.1.4  令牌校验

Spring Security Oauth2提供校验令牌的端点，如下： 

Get: http://localhost:9200/oauth/check_token?token= [access_token]

参数： 

token：令牌

使用postman测试如下:

![1564717713274](../../assets/1564717713274.png)

如果令牌校验失败，会出现如下结果：

![1564717725784](../../assets/1564717725784.png)

如果令牌过期了，会如下如下结果：

![1564717738230](../../assets/1564717738230.png)

##### 4.2.1.5 刷新令牌

刷新令牌是当令牌快过期时重新生成一个令牌，它于授权码授权和密码授权生成令牌不同，刷新令牌不需要授权码 也不需要账号和密码，只需要一个刷新令牌、客户端id和客户端密码。 

测试如下： **Post**：http://localhost:9200/oauth/token

参数：    

**grant_type**： 固定为 **refresh_token**

refresh_token：刷新令牌（注意不是access_token，而是refresh_token）    

![1564717754020](../../assets/1564717754020.png)



#### 4.2.2 密码模式

密码模式（Resource Owner Password Credentials）与授权码模式的区别是申请令牌不再使用授权码，而是直接 通过用户名和密码即可申请令牌。 

##### 4.2.2.1 申请令牌

测试如下：

```properties
Post请求：
http://localhost:9200/oauth/token

携带参数： 
grant_type：密码模式授权填写password 
username：账号 
password：密码 
```



并且此链接需要使用 http Basic认证。    

![1558221388787](../../assets/1558221388787.png)

![1558221423631](../../assets/1558221423631.png)

测试数据如下：

![1558221480009](../../assets/1558221480009.png)



##### 4.2.2.2 校验令牌

Spring Security Oauth2提供校验令牌的端点，如下： 

```properties
Get请求 
http://localhost:9200/oauth/check_token?token=

携带参数：
token：令牌 
```

使用postman测试如下:

![1558221673028](../../assets/1558221673028.png)

返回结果：

```properties
{
    "companyId": null,
    "userpic": null,
    "scope": [
        "app"
    ],
    "name": null,
    "utype": null,
    "active": true,
    "id": null,
    "exp": 1990221534,
    "jti": "5b96666e-436b-4301-91b5-d89f9bbe6edb",
    "client_id": "changgou",
    "username": "szitheima"
}
```

##### 4.2.2.3 刷新令牌

刷新令牌是当令牌快过期时重新生成一个令牌，它于授权码授权和密码授权生成令牌不同，刷新令牌不需要授权码 也不需要账号和密码，只需要一个刷新令牌、客户端id和客户端密码。 

测试如下： 

```properties
Post请求
http://localhost:9200/oauth/token 

携带参数
grant_type： 固定为 refresh_token 

refresh_token：刷新令牌（注意不是access_token，而是refresh_token）    
```

   使用postman测试如下:

![1558221864957](../../assets/1558221864957.png)

刷新令牌成功，会重新生成新的访问令牌和刷新令牌，令牌的有效期也比旧令牌长。 

刷新令牌通常是在令牌快过期时进行刷新 。

