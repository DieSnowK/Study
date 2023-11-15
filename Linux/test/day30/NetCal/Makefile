.PHONY:all
all:CalClient CalServer

CalClient:CalClient.cc
	g++ -o $@ $^ -std=c++11

CalServer:CalServer.cc
	g++ -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -f CalServer CalClient