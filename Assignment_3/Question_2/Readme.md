# IPC Using Sockets , FIFOs , Shared Memory

In All three Programs I firstly generate 50 Random Char Strings. Then I send Strings form Process P1 to Process P2 then read the highest index of the string and send it back to the P1 as a Acknowledgment. After that I send more Strings to P2 and receives back the acknowledgement this process will continue till acknowledgement of all 50 String is received by Process P1.

After that I print the time taken in sending all 50 Strings.



# Compile and Run Commands
    # For Sockets
        Compile: make SOCKET
        Run: make SOCKET_run_P2
        Run: make SOCKET_run_P1

    # For FIFOs
        Compile: make FIFO
        Run: make FIFO_run_P2
        Run: make FIFO_run_P1

    # For Shared Memory
        Compile: make SHM
        Run: make SHM_run_P1
        Run: make SHM_run_P2


# Note
    a) Please run Commands in above mentioned Order. Otherwise you may got unexpected results.
    b) Simultaneously use two Different terminals for two different processes.