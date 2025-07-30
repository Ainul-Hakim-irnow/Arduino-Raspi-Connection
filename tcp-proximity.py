import socket
import os
import time

PI_IP = '0.0.1.1'
INTERFACE = 'eno1'
PORT = 8888

print(f"Setting IP address for {INTERFACE} to {PI_IP}...")
os.system(f'sudo ip addr flush dev {INTERFACE}')
os.system(f'sudo ip addr add {PI_IP}/24 dev {INTERFACE}')
time.sleep(2)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    
    print(f"Server starting on {PI_IP}:{PORT}")
    s.bind((PI_IP, PORT))
    s.listen()
    
    print("Waiting for a connection...")
    conn, addr = s.accept()
    
    with conn:
        print(f"Connected by {addr}")
        object_count = 0
        while True:
            try:
                data = conn.recv(1024)
                if not data:
                    print("Client disconnected.")
                    break 

                message = data.decode('utf-8').strip()

                if message == "DETECT":
                    object_count += 1
                    print(f"Object detected! Total count: {object_count}")

                    response = f"Count: {object_count}\n".encode('utf-8')
                    conn.sendall(response)

            except Exception as e:
                print(f"An error occurred: {e}")
                break

print("Connection closed.")