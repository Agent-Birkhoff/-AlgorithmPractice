import socket

tcp_client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcp_client_socket.connect(("127.0.0.1", 2333))
send_data = "Hello World!"
print("Send: ", send_data)
tcp_client_socket.send(send_data.encode("UTF-8"))
tcp_client_socket.close()
