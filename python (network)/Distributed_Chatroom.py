import socket
import threading


def request(cmd, data):
    global local
    if cmd == "LIST":  # Asked for peer's user list
        nlist = []
        sock = data
        sock.send("1LIST".encode("UTF-8"))
        d = sock.recv(1024).decode("UTF-8").split("|")
        if d[0] != "0":
            raise "META EXPECTED!"
        for peer in d[1:]:
            peer = peer.split("@")
            nname = peer[0]
            peer = peer[1].split(":")
            npeer = (peer[0], int(peer[1]))
            if not npeer == local:  # In case of connecting to local
                nlist.append(npeer)
        return nlist
    elif cmd == "CONNECT":
        global user, name
        nlist = data
        for npeer in nlist:
            try:
                new_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                new_sock.connect(npeer)
                new_sock.send(
                    ("0%s@%s:%s" % (name, local[0], local[1])).encode("UTF-8")
                )  # "0name@addr:port"
                nname = new_sock.recv(1024).decode("UTF-8")  # "0name"
                if nname[0] != "0":  # Not meta-info
                    raise "META EXPECTED!"
                lock.acquire()
                user[new_sock] = (npeer, nname[1:])
                lock.release()
            except:
                print("无法连接!")
    else:
        raise "UNKNOWN CMD!"


def recv(sock):
    global user
    while True:
        data = sock.recv(1024).decode("UTF-8")
        if data[0] == "2":  # "2name: message"
            print(data[1:])
        elif data[0] == "1":  # "1cmd"
            if data[1:] == "EXIT":
                lock.acquire()
                print(
                    "%s (%s:%s)离开了聊天室"
                    % (user[sock][1], user[sock][0][0], user[sock][0][1])
                )
                user.pop(sock)
                lock.release()
                break
            elif data[1:] == "LIST":
                d = "0"
                lock.acquire()
                for s in user:
                    d += "|%s@%s:%s" % (
                        user[s][1],
                        user[s][0][0],
                        user[s][0][1],
                    )  # "|name@addr:port"
                lock.release()
                sock.send(d[:].encode("UTF-8"))
            else:
                raise "UNEXPECTED CMD!"
        else:
            raise "UNEXPECTED TYPE!"


def acpt(sock):
    global user, name
    while True:
        try:
            new_sock, npeer = sock.accept()
            data = new_sock.recv(1024).decode("UTF-8")
            new_sock.send(("0" + name).encode("UTF-8"))
            if data[0] != "0":
                raise "META EXPECTED!"
            data = data[1:].split("@")
            nname = data[0]
            data = data[1].split(":")
            npeer = (data[0], int(data[1]))
            lock.acquire()
            user[new_sock] = (npeer, nname)
            rT = threading.Thread(target=recv, args=((new_sock,)), daemon=True)
            rT.start()
            lock.release()
            print("%s (%s:%s)进入了聊天室" % (nname, npeer[0], npeer[1]))
        except:
            print("连接出现错误!")


def main():
    global user, name, local
    main_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    main_sock.bind((laddr, 0))  # Auto select port
    local = main_sock.getsockname()  # (laddr,lport)
    print("本机地址为%s:%s" % (local[0], local[1]))
    main_sock.listen(10)  # 10 passive connections

    while True:
        first = input("是否要创建新聊天室? (输入'是'/'否')")
        if first == "是":
            first = True
            break
        elif first == "否":
            first = False
            break
        else:
            print("输入错误!")
    name = input("请输入昵称:")

    while not first:
        faddr = input("请输入连接地址:")
        fport = input("请输入连接端口:")
        fpeer = (faddr, int(fport))
        try:
            first_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            first_sock.connect(fpeer)
            first_sock.send(
                ("0%s@%s:%s" % (name, local[0], local[1])).encode("UTF-8")
            )  # "0name@addr:port"
            fname = first_sock.recv(1024).decode("UTF-8")  # "0name"
            if fname[0] != "0":  # Not meta-info
                raise "META EXPECTED!"
            user[first_sock] = (fpeer, fname[1:])
            alist = request(cmd="LIST", data=first_sock)
            request(cmd="CONNECT", data=alist)
            break
        except KeyboardInterrupt:
            first = True
            print("改为创建新聊天室!")
        except:
            print("无法连接!")

    print("%s, 欢迎来到聊天室, 使用ctrl+c退出!" % name)
    if not first:
        print("本聊天室中其他成员有:")
        for s in user:
            print("    %s (%s:%s)" % (user[s][1], user[s][0][0], user[s][0][1]))
    print("您现可随意发言, 欢迎!")

    aT = threading.Thread(target=acpt, args=((main_sock,)), daemon=True)
    aT.start()
    for s in user:
        rT = threading.Thread(target=recv, args=((s,)), daemon=True)
        rT.start()

    # Send Func
    while True:
        try:
            message = input()
            lock.acquire()
            for s in user:
                try:
                    s.send(
                        ("2" + name + ": " + message).encode("UTF-8")
                    )  # "2name: message"
                except:
                    print("连接出现错误!")
            lock.release()
        except KeyboardInterrupt:
            main_sock.close()
            lock.acquire()
            for s in user:
                s.send(("1EXIT").encode("UTF-8"))  # "1EXIT"
                s.close()
            lock.release()
            break


laddr = "127.0.0.1"
lock = threading.Lock()
name = "Nobody"
local = (laddr, 2333)
user = {}  # {socket:((addr,port),name)}
if __name__ == "__main__":
    main()
