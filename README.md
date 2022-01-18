# minitalk (school21)

I created a communication program in the form of a client and a server. 

<img src="https://user-images.githubusercontent.com/71993796/149926609-e225ec03-4954-47c9-85ca-971447ce8d8b.gif" width="800" />

### Requirements
* The server must be started first. After its launch, it has to print its PID.
* The client takes two parameters:
   * The server PID.
   * The string to send.
* The client must send the string passed as a parameter to the server.
Once the string has been received, the server must print it.
* The server has to display the string pretty quickly. 
* Server should be able to receive strings from several clients in a row without
needing to restart.
* The communication between your client and your server has to be done only using
*UNIX signals*
* I can only use these two signals: *SIGUSR1* and *SIGUSR2*.

### Bonuses: 
1. The server acknowledges every message received by sending back a signal to the
client.
2. Unicode characters support!


### Realization
The client divide the symbol into 8 bits and send the signals to server bitwise: 1 - SIGUSR1, 2 - SIGUSR2.

You can view the task [here](https://github.com/Vlad173/school21/blob/master/subjects/minitalk.pdf)
