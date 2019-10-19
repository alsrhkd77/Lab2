dynamic : dltest.c shared
	gcc -g -rdynamic -o dynamic dltest.c -ldl -pg
shared : main.c static
	cd lib;make shared;cd ..;gcc -g -I./lib -L./lib -o shared main.c -Wl,--rpath=./lib -ltest -pg
static : main.c
	cd lib;make static;cd ..;gcc -g -I./lib -L./lib -o static main.c -ltest -pg
clean :
	rm -f mtrace.log gmon.out dynamic shared static; cd lib;make clean;cd ..
