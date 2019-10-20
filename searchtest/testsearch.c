/*testsearch.c*/
#include <search.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	char *name;
	int middle;
	int last;
};

struct node *root = NULL;

//노드간 비교방법 정의
int compare(const void *cp1, const void *cp2){
	return strcmp(((struct node *)cp1)->name, ((struct node *)cp2)->name);
}

//노드 출력
void print_node(const void *nodeptr, VISIT order, int level){
	if(order == preorder || order == leaf){
		printf("이름 = %-20s, 중간 = %d점, 기말 = %d점\n",
				(*(struct node **)nodeptr)->name,
				(*(struct node **)nodeptr)->middle,
				(*(struct node **)nodeptr)->last);
	}
}

int main(void){
	
	int count;
	char *nametable;
	struct node *nodetable;

	printf("학생수를 입력하세요: ");
	scanf("%d", &count);
	
	//nametable 메모리 할당	
	nametable = (char *)malloc((count)*(sizeof(char))*20);
	if(nametable == NULL){
		printf("nametable의 메모리를 할당하지 못했습니다.");
		exit(-1);
	}
	
	//nodetable 메모리 할당
	nodetable = (struct node *)malloc((count)*(sizeof(struct node)));
	if(nodetable == NULL){
		printf("nodetable의 메모리를 할당하지 못했습니다.");
		exit(-1);
	}

	char *nameptr = nametable;
	struct node *nodeptr = nodetable;
	struct node **ret;
	int i=0;

	while(i++<count){

		printf("%d번째 학생 이름을 입력하세요: ", i);
		scanf("%s", nameptr);
		printf("%d번째 학생 중간 점수를 입력하세요: ", i);
		scanf("%d", &nodeptr->middle);
		printf("%d번째 학생 기말 점수를 입력하세요: ", i);
		scanf("%d", &nodeptr->last);

		nodeptr->name = nameptr;

		//트리에 넣기
		ret = (struct node **)tsearch((void *)nodeptr, (void **)&root, compare);

		printf("\"%s\"님이 ", (*ret)->name);
		if(*ret == nodeptr){
			nameptr += strlen(nameptr) + 1;
			nodeptr++;
			printf("트리에 추가되었습니다.\n\n");
		}
		else{
			i--;
			printf("트리에 이미 존재합니다.\n\n");
		}
	}
	twalk((void *)root, print_node);

	free(nametable);
	free(nodetable);

	return 0;
}
