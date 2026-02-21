import socket

# Simple echo server
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(('localhost', 8080))
server_socket.listen(1)

conn, addr = server_socket.accept()
data = conn.recv(1024)
print("Received:", data.decode())
conn.send(data)

conn.close()
server_socket.close()