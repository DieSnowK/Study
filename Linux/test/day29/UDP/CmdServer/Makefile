.PHONY:all
all:cmdClient cmdServer

cmdClient:cmdClient.cc
	g++ -o $@ $^ -std=c++11
cmdServer:cmdServer.cc
	g++ -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -f cmdClient cmdServer