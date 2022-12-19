all: clear hw4 cat clean

clear:
	@clear

hw4:
	@echo "Compiling hw4.cpp..."
	@g++ -g -O1 -o hw4 main.cpp hw4.cpp
	@echo "Running hw4..."
	@./hw4

cat:
	@echo "Showing output.txt"
	@cat output.txt

clean:
	@echo "Cleaning up..."
	@rm -f hw4
