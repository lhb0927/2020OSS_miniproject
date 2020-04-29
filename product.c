#include "product.h"

int cafemenu(){
	int menu;
	printf("\n===카페 메뉴 목록===\n");
	printf("=======================\n\n");
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
