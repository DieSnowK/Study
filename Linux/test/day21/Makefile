.PHONY:all
all:client mutiServer

client:client.cpp
	g++ -o $@ $^ -std=c++11
mutiServer:server.cpp
	g++ -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -f client mutiServer