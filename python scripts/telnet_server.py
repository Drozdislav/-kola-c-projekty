import socket
import time
import threading

# ASCII snimky tancujiciho panacka
frames = [
    r"""
      O  
     /|\  
     / \  
    """,
    r"""
      O  
     <|>  
     < >  
    """,
    r"""
      O  
     \|/  
     / \  
    """
]

# Funkce pro obsluhu klienta
def handle_client(conn, addr):
    conn.sendall(b"\033[2J")  # Vycištění obrazovky
    conn.sendall(b"Zadej svuj nickname: ")
    
    # Cteni nickname
    nickname = ""
    while True:
        char = conn.recv(1).decode('utf-8')
        if char == '\r':  # Kdyz uzivatel stiskne Enter
            break
        elif char:
            nickname += char  # Append characters do nickname

    print(f"Novy klient: {nickname} z IP: {addr[0]}")  # Zobrazi IP a nickname na hostiteli

    # Poslat potvrzeni uzivateli
    conn.sendall(f"\nAhoj, {nickname}! Panacek zacina tancovat!\n".encode())

    try:
        while True:
            for frame in frames:
                conn.sendall(b"\033[H")  # Presun na zacatek obrazovky
                conn.sendall(frame.encode() + b"\n")
                time.sleep(0.5)  # Pockej 0.5 sekundy mezi snimky
    except:
        conn.close()

# Nastaveni Telnet serveru
def start_server():
    host = "0.0.0.0"  # Posloucha na vsech IP adresach
    port = 23  # Telnet port

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((host, port))
    server.listen(5)

    print(f"Telnet server bezi na {host}:{port}")
    print("Pripoj se pomoci: telnet [TVA_IP] 23")

    while True:
        conn, addr = server.accept()
        print(f"Pripojeni z: {addr}")
        threading.Thread(target=handle_client, args=(conn, addr)).start()

# Spusteni serveru
start_server()
