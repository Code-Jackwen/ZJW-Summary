比如：

终端窗口报错

fatal: unable to access 'https://github.com/Jack-wen-Java/ZJW-Summary.git/': OpenSSL SSL_connect: SSL_ERROR_SYSCALL in connection to github.com:443



```
git config --global http.sslBackend "openssl"
```

```
git config --global http.sslCAInfo "E:\Git\Git\mingw64\ssl\cert.pem"
```

