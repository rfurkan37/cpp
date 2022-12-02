all: clear compile run clean

clear:
	@clear

compile:
	@g++ -c tetromino.cpp
	@g++ -c tetris.cpp
	@g++ -c main.cpp
	@g++ main.o tetromino.o tetris.o

run:
	@./a.out

clean:
	@rm -rf a.out
	@rm -rf main.o
	@rm -rf tetromino.o
	@rm -rf tetris.o

