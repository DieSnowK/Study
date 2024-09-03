main:main.cc
	g++ -std=c++17 -o $@ $^ -l redis++ -l hiredis -l pthread

.PHONY:clean
clean:
	rm main