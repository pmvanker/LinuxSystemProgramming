import socket

# Create TCP socket using socket() - creates socket object
# AF_INET: IPv4, SOCK_STREAM: TCP
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to server using connect() - establishes connection to server
client_socket.connect(('127.0.0.1', 8080))

msg = "Hello from client"
# Send message using send() - transmits data to server
client_socket.send(msg.encode())
print("Message sent:", msg)

# Receive response using recv() - receives data from server
response = client_socket.recv(1024)
print("Received:", response.decode())

# Close socket using close()
client_socket.close()