#
# Makefile
#
# Computer Science 50
# Problem Set 4
##-Wall -Werror -Wno-unused-variable

tictactoe: tictactoe.c Makefile
	clang -ggdb3 -Ispl/include -O0 -std=c99  -o tictactoe tictactoe.c -Lspl/lib -lcs -lm

clean:
	rm -f *.o core tictactoe
