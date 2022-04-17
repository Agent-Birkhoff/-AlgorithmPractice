import socket
import threading


def handler(sock, addr):
    global user
    lock.acquire()
    if not sock in user:
        try:
            data = sock.recv(1024)
        except:
            print("连接出现错误!")
        name = data.decode("UTF-8")
        for s in user:
            if name == user[s][1]:  # 重名处理
                name += "(%s)" % addr[0]
                break
        print("%s 进入了聊天室" % name)
        try:
            for s in user:
                s.send(("%s 进入了聊天室" % name).encode("UTF-8"))
        except:
            print("与%s的连接出现错误!" % user[s][1])
        user[sock] = (addr, name)
    lock.release()

    while True:
        try:
            data = sock.recv(1024)
        except:
            lock.acquire()
            print("与%s的连接出现错误!" % user[sock][1])
            lock.release()
            break
        if "退出" == data.decode("UTF-8"):
            lock.acquire()
            name = user[sock][1]
            user.pop(sock)
            print("%s 离开了聊天室" % name)
            try:
                for s in user:
                    s.send(("%s 离开了聊天室" % name).encode("UTF-8"))
            except:
                print("与%s的连接出现错误!" % user[s][1])
            lock.release()
            break
        else:
            lock.acquire()
            addr = user[sock][0]
            print("%s (来自%s:%s)" % (data.decode("UTF-8"), addr[0], addr[1]))
            try:
                for s in user:
                    if s != sock:
                        s.send(data)
            except:
                print("与%s的连接出现错误!" % user[s][1])
            lock.release()


def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    saddr = ("127.0.0.1", 2333)
    s.bind(saddr)
    s.listen(10)  # 最大10个客户端

    print("TCP聊天室服务器在%s:%s上启动, 使用ctrl+c退出!" % (saddr[0], saddr[1]))

    while True:
        try:
            newS, addr = s.accept()
            newT = threading.Thread(target=handler, args=(newS, addr), daemon=True)
            newT.start()
        except ConnectionResetError:
            print("初始化连接出现错误!")
        except KeyboardInterrupt:
            s.close()
            lock.acquire()
            for sock in user:
                sock.close()
            lock.release()
            break


lock = threading.Lock()
user = {}  # {socket:(addr,name)}
if __name__ == "__main__":
    main()
