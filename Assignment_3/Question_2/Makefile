SOCKET:
	gcc P1_SOCKET.c -o P1_SOCKET -lpthread -lrt
	gcc P2_SOCKET.c -o P2_SOCKET -lpthread -lrt

FIFO:
	gcc P1_FIFO.c -o P1_FIFO -lpthread -lrt
	gcc P2_FIFO.c -o P2_FIFO -lpthread -lrt

SHM:
	gcc P1_SHM.c -o P1_SHM -lpthread -lrt
	gcc P2_SHM.c -o P2_SHM -lpthread -lrt

SOCKET_run_P1:
	./P1_SOCKET

SOCKET_run_P2:
	./P2_SOCKET

FIFO_run_P1:
	./P1_FIFO
	
FIFO_run_P2:
	./P2_FIFO

SHM_run_P1:
	./P1_SHM

SHM_run_P2:
	./P2_SHM

clean:
	rm -v P1_SOCKET P2_SOCKET SOCKET P1_FIFO P2_FIFO FIFO P1_SHM P2_SHM