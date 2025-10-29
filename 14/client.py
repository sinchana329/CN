import socket

# Create a TCP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to server
client_socket.connect(('127.0.0.1', 65432))

# Send data
client_socket.sendall(b"Hello, server!")

# Receive response
data = client_socket.recv(1024)
print("Server says:", data.decode())

client_socket.close()
