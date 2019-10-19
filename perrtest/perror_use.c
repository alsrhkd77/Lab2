/*perror_use.c*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

void my_perror(const char *s){
	char buf[1024];
	char* err;

	err = strerror_r(errno, buf, sizeof buf);

	if(s == NULL || *s== '\0'){
		printf("error code:%d  %s\n", errno, buf);
	}
	else{
		printf("error code:%d  %s:%s\n",errno, s, buf);
	}

}

int main(int argc, char *argv[]){
	FILE *f;

	if(argc<2){
		printf("Usage: perror_use nofilename\n");
		exit(1);
	}

	if((f = fopen(argv[1], "r")) == NULL){
		my_perror("fopen");
		exit(1);
	}

	printf("Open a file \"%s\".\n", argv[1]);
	fclose(f);

	return 0;
}
