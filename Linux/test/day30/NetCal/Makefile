.PHONY:all
all:CalClient CalServer

CalClient:CalClient.cc
	g++ -o $@ $^ -std=c++11 -ljsoncpp

CalServer:CalServer.cc
	g++ -o $@ $^ -std=c++11 -ljsoncpp

.PHONY:clean
clean:
	rm -f CalServer CalClient