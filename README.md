*This project was created as part of the 42 curriculum by **dabdulla**.*

### Description

Minitalk is a communication program consisting of a client and a server. The objective of this project is to send text messages from the client program to the server program using only UNIX signals (`SIGUSR1` and `SIGUSR2`). The server continually listens for these signals, decodes the binary data back into characters, and prints the received message to the standard output.

### Instructions

To compile the program, navigate to the root directory and run `make`. To compile with bonus features, run `make bonus`.

**1. Start the Server**
Open a terminal and execute the server program:

```bash
./server

```

*The server will launch and print its Process ID (PID) to the terminal. Keep this terminal open.*

**2. Run the Client**
Copy the PID provided by the server. Open a **new** terminal window and run the client program, passing the server's PID and your message as arguments:

```bash
./client <SERVER_PID> "Message you want to send"

```

*The client will transmit the message bit by bit. Once the transmission is complete, the client will print a confirmation message upon receiving an acknowledgment signal from the server.*

### Resources

Building this project required a deep dive into UNIX signals and process communication. Key resources and concepts used include:

* **UNIX Manual Pages:** Extensive reading of `man 2 kill` and `man 2 sigaction` to understand how to send, receive, and properly handle signals.
* **Bitwise Operations:** Utilizing bitwise operators was essential, as the project requires breaking down each character into its constituent bits (0s and 1s) to transmit them via the two available signals.
* **Peer Collaboration:** Discussing the architecture with peers was invaluable. It specifically helped with brainstorming robust error-handling strategies, ensuring data synchronization between processes, and properly managing `-1` error responses from system calls like `sigaction` and `kill`.