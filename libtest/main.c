/*main.c*/
#include <stdio.h>
#include <mcheck.h>
#include "testlib.h"

int main(void){
	mtrace();
	printf("add(1,2) = %d\n", add(1,2));
	printf("substract(1,2) = %d\n", substract(1,2));
	printf("multiply(1,2) = %d\n", multiply(1,2));
	printf("divide(2,4) = %d\n", divide(2,4));
	muntrace();
	return 0;
}
