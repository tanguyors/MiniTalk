# MiniTalk

```
  __  __ _       _ _____     _ _
 |  \/  (_)_ __ (_)_   _|_ _| | | __
 | |\/| | | '_ \| | | |/ _` | | |/ /
 | |  | | | | | | | | | (_| | |   <
 |_|  |_|_|_| |_|_| |_|\__,_|_|_|\_\
```

> *Talking between processes â one bit at a time, using nothing but UNIX signals.*

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat-square&logo=42&logoColor=white)](https://42.fr)
![C](https://img.shields.io/badge/C-99-blue?style=flat-square&logo=c&logoColor=white)
![Stars](https://img.shields.io/github/stars/tanguyors/MiniTalk?style=flat-square)

---

## About

**MiniTalk** is a client-server communication program that exchanges data using only **UNIX signals** (`SIGUSR1` and `SIGUSR2`). The client encodes each character of a string into its binary representation and sends it bit by bit to the server process.

This project teaches **inter-process communication (IPC)**, **bitwise operations**, **signal handling**, and the fundamentals of how data can be transmitted at the lowest level.

## How It Works

```
 CLIENT                              SERVER
 ââââââ                              ââââââ
 "Hi!" âââº 01001000                  PID: 12345
            ââââââââ                     â
            ââââââââ   SIGUSR1 = 0       â
            ââââââââ   SIGUSR2 = 1       â
            ââââââââ                     â
            âââ´â´â´â´â´â´âââââââââââââââââââº  â
            â  signal by signal          â
            â                        reconstruct
            â                        âââº "Hi!"
            ââââââââââââââââââââââââââââââ
```

## Features

- Bit-by-bit string transmission via `SIGUSR1` / `SIGUSR2`
- Server displays its PID on launch and waits for messages
- Client sends a string to the server using the server's PID
- Handles Unicode characters
- Server acknowledgement system

## Build

```bash
make        # Build client and server
make clean  # Remove object files
make fclean # Full clean
make re     # Rebuild
```

## Usage

**Terminal 1 â Start the server:**
```bash
./server
# Output: Server PID: 12345
```

**Terminal 2 â Send a message:**
```bash
./client 12345 "Hello from MiniTalk!"
```

**Server output:**
```
Hello from MiniTalk!
```

## Project Structure

```
MiniTalk/
âââ client.c
âââ server.c
âââ libft/
âââ Makefile
âââ README.md
```

---

*Bit by bit, signal by signal. â 42 School*
