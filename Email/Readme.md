## 计算机网络第五次作业
> 电子邮件收发系统 薛沛元 2023303226
### 功能
- 本程序设计的内容和功能包括：
1. 设定本地服务器为电子邮件系统的支持服务器
2. 为客户端提供：（发送邮件、查看邮件、退出）的功能
3. 为客户端设置UI界面，方便用户进行可视化操作

### 编程语言与技术
- 编程语言：Python
- 网络通信：socket库
- UI界面：customtkinter库

### 运行环境
- python3
- socket库
- customtkinter库
- 其他python需要的程序和功能，如：基础编译和开发环境等

### 程序说明
- user.py:通过25端口进行telnet协议的使用，进行电子邮件的收发。
- send.py:使用465端口和SSL加密验证进行电子邮件的收发。
- send_UI.py:使用UI界面进行功能的开发，可视化程度更高。

### 运行方法
此时即可在相关的命令行界面看到程序的回显和输出。

```
欢迎使用命令行邮件工具！
请输入 SMTP 服务器地址（如 smtp.qq.com）：smtp.qq.com         
请输入 SMTP 端口号（如 465）：465
请输入发件邮箱地址：2700084947@qq.com   
请输入发件邮箱的 SMTP 授权码：cesandkzhqbedhdd    
请输入收件邮箱地址：18793583913@163.com
请输入邮件主题：test
请输入邮件正文内容：test mail
220 newxmesmtplogicsvrszb20-0.qq.com XMail Esmtp QQ Mail Server.

250-newxmesmtplogicsvrszb20-0.qq.com
250-PIPELINING
250-SIZE 73400320
250-AUTH LOGIN PLAIN XOAUTH XOAUTH2
250-AUTH=LOGIN
250-MAILCOMPRESS
250-SMTPUTF8
250 8BITMIME

334 VXNlcm5hbWU6

334 UGFzc3dvcmQ6

235 Authentication successful

250 OK

250 OK

354 End data with <CR><LF>.<CR><LF>.

250 OK: queued as.


221 Bye.

邮件发送成功！
PS D:\VScode_Workplace\Email> python .\send.py
快来愉快地发送邮件吧！
请输入 SMTP 服务器地址（如 smtp.qq.com）：smtp.qq.com         
请输入 SMTP 端口号（如 465）：465
请输入发件邮箱地址：2700084947@qq.com
请输入发件邮箱的 SMTP 授权码：cesandkzhqbedhdd
请输入收件邮箱地址：18793583913@163.com
请输入邮件主题：test02
请输入邮件正文内容：test02——1
220 newxmesmtplogicsvrszb21-0.qq.com XMail Esmtp QQ Mail Server.

250-newxmesmtplogicsvrszb21-0.qq.com
250-PIPELINING
250-SIZE 73400320
250-AUTH LOGIN PLAIN XOAUTH XOAUTH2
250-AUTH=LOGIN
250-MAILCOMPRESS
250-SMTPUTF8
250 8BITMIME

334 VXNlcm5hbWU6
334 UGFzc3dvcmQ6
235 Authentication successful
250 OK
250 OK
354 End data with <CR><LF>.<CR><LF>.
250 OK: queued as.
221 Bye.
邮件发送成功！
```