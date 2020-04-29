#include "product.h"

int cafemenu(){
	int menu;
	printf("\n=== 카페 메뉴 목록===\n");
	printf("=====================\n\n");
	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 저장\n");
	printf("6. 검색\n\n");

	printf("=> 원하는 메뉴번호는? ");
	scanf("%d", &menu);
	return menu;
}
int addmenu(MENU *t){
	printf("메뉴 이름은? ");
	getchar();
	fgets(t->m_name, 100, stdin);
	printf("메뉴 가격은? ");
	scanf("%d", &t->price);
	printf("메뉴 사이즈(S/M/L)는 ? ");
	getchar();
	scanf("%c", &t->size);
	printf("ICE/HOT ? ");
	scanf("%s", t->type);
	printf("=> 메뉴 추가됨\n");
	return 1;
}
