import socket

# Create UDP socket using socket() - SOCK_DGRAM for UDP
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind to address using bind()
server_socket.bind(('127.0.0.1', 8080))

print("UDP Server listening on port 8080...")

while True:
    # Receive message using recvfrom() - returns data and client address
    data, addr = server_socket.recvfrom(1024)
    print("Received:", data.decode(), "from", addr)

    # Send response using sendto() - sends to specific address
    server_socket.sendto(data, addr)