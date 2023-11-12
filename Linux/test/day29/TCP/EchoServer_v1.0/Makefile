.PHONY:all
all:echoClient echoServer

echoClient:echoClient.cc
	g++ -o $@ $^ -std=c++11
echoServer:echoServer.cc
	g++ -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -f echoClient echoServer