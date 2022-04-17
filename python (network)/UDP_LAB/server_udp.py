import socket


def main():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    saddr = ("127.0.0.1", 2333)
    s.bind(saddr)

    print("UDP聊天室服务器在%s:%s上启动, 使用ctrl+c退出!" % (saddr[0], saddr[1]))

    user = {}  # {addr:name}
    while True:
        try:
            data, addr = s.recvfrom(1024)
            if not addr in user:
                name = data.decode("UTF-8")
                for address in user:
                    if name == user[address]:  # 重名处理
                        name += "(%s)" % addr[0]
                    s.sendto(("%s 进入了聊天室" % name).encode("UTF-8"), address)
                print("%s 进入了聊天室" % name)
                user[addr] = name
            elif "退出" == data.decode("UTF-8"):
                name = user[addr]
                user.pop(addr)
                print("%s 离开了聊天室" % name)
                for address in user:
                    s.sendto(("%s 离开了聊天室" % name).encode("UTF-8"), address)
            else:
                print("%s (来自%s:%s)" % (data.decode("UTF-8"), addr[0], addr[1]))
                for address in user:
                    if address != addr:
                        s.sendto(data, address)

        except ConnectionResetError:
            print("连接出现错误!")
        except KeyboardInterrupt:
            s.close()
            break


if __name__ == "__main__":
    main()
