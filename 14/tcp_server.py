import socket

# Create a TCP socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind to IP and port
server_socket.bind(('127.0.0.1', 65432))

# Listen for incoming connections
server_socket.listen()

print("Server is listening on port 65432...")

# Accept a client connection
conn, addr = server_socket.accept()
print(f"Connected by {addr}")

while True:
    data = conn.recv(1024)  # Receive data from client
    if not data:
        break  # Connection closed by client
    print("Client says:", data.decode())
    conn.sendall(b"Message received!")  # Send response back

conn.close()
server_socket.close()
