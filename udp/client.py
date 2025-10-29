import socket

# Create a UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ('127.0.0.1', 65432)

# Send data
message = "Hello, UDP server!"
client_socket.sendto(message.encode(), server_address)

# Receive response
data, server = client_socket.recvfrom(1024)
print("Server says:", data.decode())

client_socket.close()
