import socket

# Create UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

msg = "Hello from UDP client"
# Send message using sendto() - sends data to server address
client_socket.sendto(msg.encode(), ('127.0.0.1', 8080))
print("Message sent:", msg)

# Receive response using recvfrom()
response, addr = client_socket.recvfrom(1024)
print("Received:", response.decode(), "from", addr)

client_socket.close()