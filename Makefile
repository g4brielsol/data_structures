all: criptografia2.o
	@gcc criptografia2.o -o exemplo
criptografia2.o:
	@gcc -c criptografia2.c
run:
	@./exemplo