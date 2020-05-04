//2020OSS_miniproject
//product.h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

typedef struct{
	char m_name[30];	//메뉴 이름
	int price;	//메뉴 가격
	char size;	//small/medium/large (S/M/L)
	char type[10];	//ICE/HOT
}MENU;

int cafemenu();	//사용할 옵션을 선택하는 함수
int addmenu(MENU *t);	//새로운 메뉴를 등록하는 함수
void readmenu(MENU t);	//메뉴를 조회하는 함수
void listmenu(MENU *t[], int count);	//메뉴 리스트를 보여주는 함수
int updatemenu(MENU *t);	//메뉴를 수정하는 함수
int select_data_no(MENU *t[], int count);	//메뉴 리스트에서 특정 메뉴를 선택하는 함수
//int deletemenu(MENU *t);	//메뉴 삭제를 삭제하는 함수
void introduction();
