import socket
import threading


def recv(sock, addr):
    global name
    sock.sendto(name.encode("UTF-8"), addr)  # win下应先打开端口
    global enable
    while enable:
        data = sock.recv(1024)
        print(data.decode("UTF-8"))


def send(sock, addr):
    global name
    global enable
    while True:
        message = input()
        if message == "退出":
            sock.sendto(message.encode("UTF-8"), addr)
            enable = False
            break
        else:
            sock.sendto((name + ": " + message).encode("UTF-8"), addr)


def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    saddr = input("请输入服务器地址:")
    sport = input("请输入服务器端口:")
    server = (saddr, int(sport))

    global name
    name = input("请输入你的昵称:")
    print("%s, 欢迎来到聊天室(%s:%s), 退出聊天室请输入'退出'!" % (name, server[0], server[1]))

    tr = threading.Thread(target=recv, args=(s, server), daemon=True)
    ts = threading.Thread(target=send, args=(s, server))
    tr.start()
    ts.start()
    ts.join()
    s.close()


name = "Nobody"
enable = True
if __name__ == "__main__":
    main()
