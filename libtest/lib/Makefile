static : add.o substract.o multiply.o divide.o
	ar rcs libtest.a add.o substract.o multiply.o divide.o
shared : add.o substract.o multiply.o divide.o
	gcc -shared -Wl,-soname,libtest.so.1 -o libtest.so.1.0.1 add.o substract.o multiply.o divide.o;
	ln -s libtest.so.1.0.1 libtest.so.1;
	ln -s libtest.so.1.0.1 libtest.so
add.o : add.c
	gcc -c add.c
substract.o : substract.c
	gcc -c substract.c
multiply.o : multiply.c
	gcc -c multiply.c
divide.o : divide.c
	gcc -c divide.c
clean :
	rm -f add.o substract.o multiply.o divide.o libtest.a libtest.so.1.0.1 libtest.so.1 libtest.so
