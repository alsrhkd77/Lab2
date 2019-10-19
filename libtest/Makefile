dynamic : dltest.c shared
	gcc -rdynamic -o dynamic dltest.c -ldl
shared : main.c static
	cd lib;make shared;cd ..;gcc -I./lib -L./lib -o shared main.c -Wl,--rpath=./lib -ltest
static : main.c
	cd lib;make static;cd ..;gcc -I./lib -L./lib -o static main.c -ltest
clean :
	rm -f dynamic shared static; cd lib;make clean;cd ..
