//Editor    :Lim Hyeongbin
//StudentID :21500612
/*
입력받은 데이터를 저장하고/ 로드하는 함수 및
데이터 내에서 유저의 선택에 따라 정보를 검색하는 함수 구현
*/

#include "manager.h"

//저장된 데이터 불러오기
int loadData(MENU *t[]){
	int i = 0;
	FILE *fp;

	fp = fopen("cafemenu.txt","rt");
	if(fp == NULL){
		printf("=> failed to open file...\n");
		return 0;
	}
	for(;;i++){
		t[i] = (MENU*)malloc(sizeof(MENU));
		fscanf(fp,"%s %d %c %s",t[i]->m_name,&t[i]->price,&t[i]->size,t[i]->type);
		if(feof(fp))break;
	}

	fclose(fp);
	printf("=>success to file open!!\n");
	return i;
}

//입력받은 데이터 저장하기
void saveData(MENU *t[],int count){
	FILE *fp;
	fp = fopen("cafemenu.txt","wt");

	for(int i = 0;i<count;i++){
		if(t[i]->price != -1)
			fprintf(fp,"%s %d %c %s\n",t[i]->m_name,t[i]->price,t[i]->size,t[i]->type);
	}
	printf("=> success to saved!!\n");
	fclose(fp);
}

//메뉴이름 검색하기
void searchMenu(MENU *t[],int count){
	int scount = 0;
	char target[50];

	printf("=> 검색할 메뉴 이름은? ");
	scanf("%s",target);

	printf("\n원하시는 메뉴입니다!!\n");
	printf("\nNo   메뉴이름   가격 사이즈 ICE/HOT\n");
	printf("=========================================\n");
	for(int i = 0;i<count;i++){
		if(t[i]->price != -1){
			if(strstr(t[i]->m_name,target)){
				printf("%-4d",i+1);
				readmenu(*t[i]);
				scount++;
			}
		}
	}
	if(scount==0)printf("=>찾으시는 데이터가 존재하지 않습니다..\n");
}

//메뉴가격 검색하기
void searchPrice(MENU *t[],int count){
	int scount = 0;
	int target = 0;

	printf("=> 검색할 가격은? ");
	scanf("%d",&target);

	printf("\nNo   메뉴이름   가격 사이즈 ICE/HOT\n");
	printf("=========================================\n");
	for(int i = 0;i<count;i++){
		if(t[i]->price != -1){
			if(t[i]->price==target){
				printf("%-4d",i+1);
				readmenu(*t[i]);
				scount++;
			}
		}
	}
	if(scount==0)printf("=>찾으시는 데이터가 존재하지 않습니다..\n");
}


//메뉴 크기 검색하기
void searchSize(MENU *t[],int count){
	int scount = 0;;
	char target;

	getchar();
	printf("=> 검색할 사이즈는? ");
	scanf("%c",&target);

	printf("\nNo   메뉴이름   가격 사이즈 ICE/HOT\n");
	printf("=========================================\n");
	for(int i = 0;i<count;i++){
		if(t[i]->price != -1){
			if(t[i]->size==target){
				printf("%-4d",i+1);
				readmenu(*t[i]);
				scount++;
			}
		}
	}
	if(scount==0)printf("=>찾으시는 데이터가 존재하지 않습니다..\n");
}

//메뉴 타입 검색하기
void searchType(MENU *t[],int count){
	int scount = 0;
	char target[50];

	printf("=> 검색할 타입은? ");
	scanf("%s",target);

	printf("\nNo   메뉴이름   가격 사이즈 ICE/HOT\n");
	printf("=========================================\n");
	for(int i = 0;i<count;i++){
		if(t[i]->price != -1){
			if(strstr(t[i]->type,target)){
				printf("%-4d",i+1);
				readmenu(*t[i]);
				scount++;
			}
		}
	}
	if(scount==0)printf("=>찾으시는 데이터가 존재하지 않습니다..\n");
}
