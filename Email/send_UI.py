'''
@Written:薛沛元
@NO:2023303226
@Date:2024-12-4
'''
import ssl
import socket
import base64
import customtkinter as ctk
from tkinter import messagebox


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

        server.send(b"QUIT\r\n")
        print(server.recv(1024).decode())

        server.close()
        print("邮件发送成功！")
        messagebox.showinfo("成功", "邮件发送成功！")
    except Exception as e:
        print("发送邮件失败：", e)
        messagebox.showerror("错误", f"发送邮件失败：{e}")


# 创建 UI 界面
def create_ui():
    def send_email():
        smtp_server = smtp_server_entry.get().strip()
        smtp_port = int(smtp_port_entry.get().strip())
        sender_email = sender_email_entry.get().strip()
        sender_password = sender_password_entry.get().strip()
        recipient_email = recipient_email_entry.get().strip()
        subject = subject_entry.get().strip()
        body = body_text.get("1.0", "end").strip()

        if not smtp_server or not smtp_port or not sender_email or not sender_password or not recipient_email or not subject or not body:
            messagebox.showwarning("警告", "请填写所有字段！")
            return

        send_email_smtp(smtp_server, smtp_port, sender_email,
                        sender_password, recipient_email, subject, body)

    app = ctk.CTk()
    app.title("邮件发送器")
    app.geometry("600x500")

    # SMTP 服务器地址
    ctk.CTkLabel(app, text="SMTP 服务器地址：").grid(
        row=0, column=0, padx=10, pady=10, sticky="w")
    smtp_server_entry = ctk.CTkEntry(app, width=400)
    smtp_server_entry.grid(row=0, column=1, padx=10, pady=10)

    # SMTP 端口号
    ctk.CTkLabel(app, text="SMTP 端口号：").grid(
        row=1, column=0, padx=10, pady=10, sticky="w")
    smtp_port_entry = ctk.CTkEntry(app, width=400)
    smtp_port_entry.grid(row=1, column=1, padx=10, pady=10)

    # 发件人邮箱
    ctk.CTkLabel(app, text="发件人邮箱：").grid(
        row=2, column=0, padx=10, pady=10, sticky="w")
    sender_email_entry = ctk.CTkEntry(app, width=400)
    sender_email_entry.grid(row=2, column=1, padx=10, pady=10)

    # 发件人授权码
    ctk.CTkLabel(app, text="发件人授权码：").grid(
        row=3, column=0, padx=10, pady=10, sticky="w")
    sender_password_entry = ctk.CTkEntry(app, width=400, show="*")
    sender_password_entry.grid(row=3, column=1, padx=10, pady=10)

    # 收件人邮箱
    ctk.CTkLabel(app, text="收件人邮箱：").grid(
        row=4, column=0, padx=10, pady=10, sticky="w")
    recipient_email_entry = ctk.CTkEntry(app, width=400)
    recipient_email_entry.grid(row=4, column=1, padx=10, pady=10)

    # 邮件主题
    ctk.CTkLabel(app, text="邮件主题：").grid(
        row=5, column=0, padx=10, pady=10, sticky="w")
    subject_entry = ctk.CTkEntry(app, width=400)
    subject_entry.grid(row=5, column=1, padx=10, pady=10)

    # 邮件正文
    ctk.CTkLabel(app, text="邮件正文：").grid(
        row=6, column=0, padx=10, pady=10, sticky="nw")
    body_text = ctk.CTkTextbox(app, width=400, height=150)
    body_text.grid(row=6, column=1, padx=10, pady=10)
    send_button = ctk.CTkButton(app, text="发送邮件", command=send_email)
    send_button.grid(row=7, column=1, padx=10, pady=20, sticky="e")

    app.mainloop()


if __name__ == "__main__":
    create_ui()
