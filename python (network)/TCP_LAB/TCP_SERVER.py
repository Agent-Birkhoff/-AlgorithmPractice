import socket

tcp_server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcp_server_socket.bind(("0.0.0.0", 2333))
tcp_server_socket.listen(128)  # 128 Connections Max
client_socket, client_addr = tcp_server_socket.accept()
recv_data = client_socket.recv(1024)  # 1KB Max
print("Receive: ", recv_data.decode("UTF-8"))
client_socket.close()
