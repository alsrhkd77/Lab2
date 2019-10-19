/*assert.c*/
#include <stdio.h>
#include <stdlib.h>
#include <features.h>

#define __MY_ASSERT_VOID_CAST (void)


#ifdef	NDEBUG
#define my_assert(expr)	(__MY_ASSERT_VOID_CAST (0))
#else

# if !defined __GNUC__ || defined __STRICT_ANSI__

#  define my_assert(expr)                                                        \
    ((expr)                                                                \
     ? __MY_ASSERT_VOID_CAST (0)                                                \
     : __assert_fail (#expr, __FILE__, __LINE__, __MY_ASSERT_FUNCTION))

# else

#  define my_assert(expr)                                                        \
  ((void) sizeof ((expr) ? 1 : 0), __extension__ ({                        \
      if (expr)                                                                \
        ; /* empty */                                                        \
      else                                                                \
        __assert_fail (#expr, __FILE__, __LINE__, __MY_ASSERT_FUNCTION);        \
    }))

# endif /*__GNUC__ || __STRICT_ANSI__	*/

#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L
#define __MY_ASSERT_FUNCTION	__func__
#else
#define __MY_ASSERT_FUNCTION	((const char *) 0)
#endif

#endif /* NDEBUG.  */

void foo(int num){
	my_assert(((num >= 0) && (num <= 100)));
	printf("foo: num = %d\n", num);
}

int main(int argc, char *argv[]){
	int num;

	if(argc<2){
		fprintf(stderr, "Usage: assert_test a Number\n(0<=Number<=100)\n");
		exit(1);
	}

	num = atoi(argv[1]);
	foo(num);
	return 0;
}
