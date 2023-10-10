.PHONY:all
all:exec myfile

exec:exec.c
	gcc -o $@ $^

myfile:myfile.c
	gcc -o $@ $^


.PHONY:clean
clean:
	rm -f exec
