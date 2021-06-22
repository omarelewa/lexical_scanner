
An assumption is made that comments cannot be multiline

To use on a linux machine follow these commands:
	sudo apt-get update
	sudo apt-get install flex 
	lex myscanner.l
	gcc myscanner.c lex.yy.c -o myscanner
	./myscanner