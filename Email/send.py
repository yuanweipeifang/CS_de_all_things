'''
@Written:薛沛元
@NO:2023303226
@Date:2024-12-4
'''
import ssl
import socket
import base64

# SMTP 交互函数（使用 SSL确保qq邮箱和163邮箱的安全验证通过）


def send_email_smtp(smtp_server, smtp_port, sender_email, sender_password, recipient_email, subject, body):
    try:
        # 创建 SSL 加密连接
        context = ssl.create_default_context()
        server = socket.create_connection((smtp_server, smtp_port))
        server = context.wrap_socket(server, server_hostname=smtp_server)

        print(server.recv(1024).decode())  # 接收服务器信息

        # 发送 EHLO 命令
        server.send(b"EHLO yourdomain.com\r\n")
        print(server.recv(1024).decode())

        # 登录 AUTH LOGIN
        server.send(b"AUTH LOGIN\r\n")
        print(server.recv(1024).decode())

        # 发送用户名（Base64 编码）
        server.send(base64.b64encode(sender_email.encode()) + b"\r\n")
        print(server.recv(1024).decode())

        # 发送密码（Base64 编码）
        server.send(base64.b64encode(sender_password.encode()) + b"\r\n")
        print(server.recv(1024).decode())

        # 指定发件人
        server.send(f"MAIL FROM:<{sender_email}>\r\n".encode())
        print(server.recv(1024).decode())

        # 指定收件人
        server.send(f"RCPT TO:<{recipient_email}>\r\n".encode())
        print(server.recv(1024).decode())

        # 发送邮件内容
        server.send(b"DATA\r\n")
        print(server.recv(1024).decode())

        # 设置邮件头部和正文
        from_header = f"From: \"发件人名称\" <{sender_email}>\r\n"
        to_header = f"To: <{recipient_email}>\r\n"
        subject_header = f"Subject: {subject}\r\n"
        headers = from_header + to_header + subject_header + "\r\n"
        server.send((headers + body + "\r\n.\r\n").encode())
        print(server.recv(1024).decode())

        # 退出会话
        server.send(b"QUIT\r\n")
        print(server.recv(1024).decode())

        server.close()
        print("邮件发送成功！")
    except Exception as e:
        print("发送邮件失败：", e)


if __name__ == "__main__":
    print("快来愉快地发送邮件吧！")

    smtp_server = input("请输入 SMTP 服务器地址（如 smtp.qq.com）：").strip()
    smtp_port = int(input("请输入 SMTP 端口号（如 465）：").strip())
    sender_email = input("请输入发件邮箱地址：").strip()
    sender_password = input("请输入发件邮箱的 SMTP 授权码：").strip()
    recipient_email = input("请输入收件邮箱地址：").strip()
    subject = input("请输入邮件主题：").strip()
    body = input("请输入邮件正文内容：").strip()

    # 发送邮件
    send_email_smtp(smtp_server, smtp_port, sender_email,
                    sender_password, recipient_email, subject, body)
