import socket
import threading


def recv():
    global name, failure
    sock.send(name.encode("UTF-8"))  # win下应先打开端口
    while True:
        try:
            data = sock.recv(1024)
            print(data.decode("UTF-8"))
        except:
            print("连接出现错误!")
            failure = True
            break


def send():
    global name, failure
    while not failure:
        message = input()
        if message == "退出":
            try:
                sock.send(message.encode("UTF-8"))
            except:
                print("连接出现错误!")
            break
        else:
            try:
                sock.send((name + ": " + message).encode("UTF-8"))
            except:
                print("连接出现错误!")


def main():
    saddr = input("请输入服务器地址:")
    sport = input("请输入服务器端口:")
    server = (saddr, int(sport))
    try:
        sock.connect(server)
    except:
        print("无法连接!")

    global name
    name = input("请输入你的昵称:")
    print("%s, 欢迎来到聊天室(%s:%s), 退出聊天室请输入'退出'!" % (name, server[0], server[1]))

    tr = threading.Thread(target=recv, daemon=True)
    ts = threading.Thread(target=send)
    tr.start()
    ts.start()
    ts.join()
    sock.close()


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
name = "Nobody"
failure = False
if __name__ == "__main__":
    main()
