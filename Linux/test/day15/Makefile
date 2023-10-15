.PHONY:all
all:fdtest market_bits

fdtest:fdtest.c
	gcc -o $@ $^ 

market_bits:market_bits.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -f fdtest market_bits
