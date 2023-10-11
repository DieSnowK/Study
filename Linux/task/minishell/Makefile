.PHONY:all
all:minishell myfile

minishell:minishell.c
	gcc -o $@ $^

myfile:myfile.c
	gcc -o $@ $^


.PHONY:clean
clean:
	rm -f minishell myfile
