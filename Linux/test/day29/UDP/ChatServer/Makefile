.PHONY:all
all:chatClient chatServer

chatClient:chatClient.cc
	g++ -o $@ $^ -std=c++11
chatServer:chatServer.cc
	g++ -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -f chatClient chatServer