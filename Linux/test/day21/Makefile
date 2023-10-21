.PHONY:all
all:shmClient shmServer

shmClient:shmClient.cc
	g++ -o $@ $^ -std=c++11 #-D DEBUGV
shmServer:shmServer.cc
	g++ -o $@ $^ -std=c++11 #-D DEBUGV

.PHONY:clean
clean:
	rm -f client shmServer shmClient