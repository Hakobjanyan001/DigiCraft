import socket
import json

IP = "127.0.0.1" # hacen (local host)
PORT = 8080 # porty

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)# stexcuma tsp socket
server.bind((IP, PORT))
server.listen(1)

print(f"SERVER is listening on {IP}:{PORT}...")

client_socket, addr = server.accept() # yndunuma kapy agentic
print(f"Connection fron {addr} established")

try:
    while True:
        data = client_socket.recv(1024) # stanumenq tvyalner aravelaguyn 1024 bayt
        if not data:
            break
        decoded_data = data.decode('utf-8') # poxakerpume baytery JSON-i
        metrics = json.loads(decoded_data)

        print(f"[{metrics['time']}] RAM Used: {metrics['used_ram']} / Total: {metrics['total_ram']}")

except Exception as e:
    print(f"Error: {e}")
finally:
    client_socket.close()
    server.close()
