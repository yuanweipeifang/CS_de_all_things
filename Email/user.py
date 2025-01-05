'''
@Written:薛沛元
@NO:2023303226
@Date:2024-12-4
'''
import smtplib
from email.mime.text import MIMEText
from email.header import Header
import base64

# 配置邮箱信息
smtp_server = "smtp.qq.com"  # QQ 邮箱的 SMTP 服务器地址
smtp_port = 25  # SMTP 端口号
username = "2700084947@qq.com"  # 发件人的邮箱地址
password = "cesandkzhqbedhdd"  # 发件人的邮箱授权码

# 收件人信息
sender = "2700084947@qq.com"  # 发件人邮箱
recipient = "18793583913@163.com"  # 收件人邮箱

# 邮件内容
subject = "Enjoy SMTP Protocol Studying"
body = "Enjoy SMTP Protocol Studying"

# 创建 MIMEText 对象
message = MIMEText(body, "plain", "utf-8")
message["From"] = Header(sender, "utf-8")
message["To"] = Header(recipient, "utf-8")
message["Subject"] = Header(subject, "utf-8")

try:
    # 连接到 SMTP 服务器
    print(f"C: telnet {smtp_server} {smtp_port}")
    smtp = smtplib.SMTP(smtp_server, smtp_port)
    smtp.set_debuglevel(1)  # 模拟 Telnet 的交互过程

    # 发送 HELO 命令
    print(f"C: HELO qq.com")
    smtp.helo("qq.com")

    # 登录邮箱
    print(f"C: auth login")
    smtp.docmd("AUTH LOGIN")
    print(f"S: {base64.b64encode(username.encode()).decode()}")
    smtp.docmd(base64.b64encode(username.encode()).decode())
    print(f"S: {base64.b64encode(password.encode()).decode()}")
    smtp.docmd(base64.b64encode(password.encode()).decode())

    # 发送邮件
    print(f"C: MAIL FROM: <{sender}>")
    smtp.mail(sender)
    print(f"C: RCPT TO: <{recipient}>")
    smtp.rcpt(recipient)
    print(f"C: DATA")
    smtp.data(message.as_string())

    # 退出 SMTP 会话
    print(f"C: QUIT")
    smtp.quit()
    print("邮件发送成功！")

except Exception as e:
    print(f"邮件发送失败：{e}")
