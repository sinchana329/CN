
import socket

# Create a UDP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind to IP and port
server_socket.bind(('127.0.0.1', 65432))
print("UDP Server is listening on port 65432...")

while True:
    # Receive message and client address
    data, addr = server_socket.recvfrom(1024)
    print(f"Received message from {addr}: {data.decode()}")

    # Send reply
    server_socket.sendto(b"Message received!", addr)
