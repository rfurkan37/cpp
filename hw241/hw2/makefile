all:  clear compile run clean

clear:
	@clear

compile:
	@g++ driver1.cpp util.cpp util2.cpp -o driver1
	@g++ driver2.cpp util.cpp util2.cpp -o driver2

run:   
	@echo DRIVER1 RUNS.........
	@./driver1
	@shell bash -c "read -n 1 -r -s -p 'Press enter to continue...'"
	@clear
	@echo DRIVER2 RUNS.........
	@./driver2

clean:
	@rm -f driver1
	@rm -f driver2
