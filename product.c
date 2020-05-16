/*
카페를 소개하는 함수
메뉴를 호출하는 함수
메뉴를 추가하고 수정하는 함수
*/

#include "product.h"
void introduction(){
	printf("---------------------------------------------------------\n");
	printf("Welcome to OSS_cafe CRUD program :) \n");
	printf("How to use this program: \n\n");
	printf("메뉴이름:\tEnter the name of the menu\n");
	printf("메뉴사이즈:\tEnter the size\n\n");
	printf("\t\tsmall: S\n\t\tmedium: M\n\t\tlarge: L\n\n");
	printf("메뉴타입:\tEnter ICE or HOT\n");
	printf("Search choices: menu name, price, size, and type\n");
	printf("---------------------------------------------------------\n\n");
}

int cafemenu(){
	int menu;
	printf("\n=== 카페 메뉴 목록===\n");
	printf("=====================\n\n");
	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 저장\n");
	printf("6. 검색\n");
	printf("0. 종료\n\n");

	printf("=> 원하는 메뉴번호는? ");
	scanf("%d", &menu);
	return menu;
}
int addmenu(MENU *t){
	printf("메뉴 이름은? ");
	getchar();
	fgets(t->m_name, 100, stdin);
	t->m_name[strlen(t->m_name)-1]='\0';
	printf("메뉴 가격은? ");
	scanf("%d", &t->price);
	printf("메뉴 사이즈(S/M/L)는 ? ");
	getchar();
	scanf("%c", &t->size);
	while(1){
		if(t->size == 'S'||t->size=='M'||t->size=='L') break;
		printf("잘못 입력하셨습니다. S/M/L 중 하나로 입력해주세요.\n");
		printf("메뉴 사이즈(S/M/L)는 ?");
		getchar();
		scanf("%c",&t->size);
	}
	printf("ICE or HOT ? ");
	scanf("%s",t->type);
	while(1){
		if(strcmp(t->type,"ICE")==0||strcmp(t->type,"HOT")==0)break;
		printf("잘못 입력하셨습니다. ICE/HOT 둘 중 하나로 입력해주세요.\n");
		printf("ICE or HOT ?");
		scanf("%s",t->type);
	}
	printf("=> 메뉴 추가됨\n");
	return 1;
}

void readmenu(MENU t){
	printf("%9s\t%-5d %-5c %s\n", t.m_name, t.price, t.size, t.type);
}

void listmenu(MENU *t[], int count){
	printf("\nNo   메뉴이름   가격 사이즈 ICE/HOT\n");
	printf("====================================\n");
	for(int i=0;i<count;i++){
		if(t[i] == NULL)
			continue;
		else{	
			printf("%-4d ", i+1);
			readmenu(*t[i]);
		}
	}
	printf("\n");
}

int updatemenu(MENU *t){
	printf("메뉴 이름은? ");
	getchar();
	fgets(t->m_name, 100, stdin);
	t->m_name[strlen(t->m_name)-1]='\0';
	printf("메뉴 가격은? ");
	scanf("%d", &t->price);
	printf("메뉴 사이즈(S/M/L)는 ? ");
	getchar();
	scanf("%c", &t->size);
	printf("ICE or HOT ? ");
	scanf("%s", t->type);
	printf("=> 메뉴 수정됨\n");
	return 1;
}

int select_data_no(MENU *t[], int count){
	int no;
	listmenu(t, count);
	
	printf("=> 원하는 번호는? (취소: 0) ");
	scanf("%d", &no);
	return no;
}

//int deletemenu(MENU *t){}
