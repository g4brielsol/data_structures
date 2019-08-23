all: criptografia2.o
	@gcc criptografia2.o -o exemplo
run:
	@./exemplo