all: clear compile_run1 compile_run2 clean 

clear:
	@clear

compile_run1:
	@g++ driver1.cpp tetromino.cpp tetris.cpp
	@./a.out
	@echo "DRIVER 2 BEGINS"


compile_run2:
	@g++ driver2.cpp tetromino.cpp tetris.cpp
	@./a.out


clean:
	@rm -rf a.out
