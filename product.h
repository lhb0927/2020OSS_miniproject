//2020OSS_miniproject
//product.h
#include <stdio.h>
#include <string.h>

typedef struct{
	char m_name[30];	//메뉴 이름
	int price;	//메뉴 가격
	char size;	//small/medium/large (S/M/L)
	char type;	//ICE/HOT
}MENU;

int cafemenu();	//사용할 옵션을 선택하는 함수
int addmenu(MENU *t);	//새로운 메뉴를 등록하는 함수
void readmenu(MENU t);	//메뉴를 조회하는 함수
int updatemenu(MENU *t);	//메뉴를 수정하는 함수
int select_data_no(MENU *t, int count);	//메뉴 리스트에서 특정 메뉴를 선택하는 함수
int deletemenu(MENU *t);	//메뉴 삭제를 삭제하는 함수
void savefile(MENU *t, int count);	//등록된 메뉴를 저장하는 함수
int loadfile(MENU *t);	//저장된 메뉴 파일을 불러오는 함수
void searchmenu(MENU *t, int count);	//검색하는 함수


