/*
카페 관리 프로그램을 위한 메인 프로그램
사용자에게 메뉴를 보여주고
원하는 메뉴를 입력받아 함수를 실행한다.
*/

#include "manager.h"

int main(void){
	introduction();	//프로그램에 대한 간단한 설명
	int menu;
	int count=0, curcount=0;
	MENU *mlist[SIZE];
	int searchNum = 0;

	count = loadData(mlist);
	curcount = count;

	while(1){
		menu=cafemenu();
		if(menu==0) break;
		else if(menu==1){
			if(count>0)
				listmenu(mlist, curcount);
			else
				printf("등록된 메뉴가 없습니다\n");
		} 
		else if(menu==2){
			mlist[curcount]= (MENU*)malloc(sizeof(MENU));	
			count+= addmenu(mlist[curcount]);
			curcount++;

		} 
		else if(menu==3){
			if(count>0){
				int no= select_data_no(mlist, curcount);
				if(no==0){
					printf("=> 취소됨\n");
					continue;
				}
				else 
					updatemenu(mlist[no-1]);	
			}
			else
				printf("등록된 메뉴가 없습니다\n");
			
		} 
		else if(menu==4){
			if(count>0){
				int no=select_data_no(mlist, curcount);
				int check;
				if(no==0){
					printf("=> 취소됨\n");
					continue;
				}
				printf("=> 정말로 삭제하시겠습니까? (삭제:1) ");
				scanf("%d", &check);
					if(check==1){
						if(mlist[no-1]) 
							free(mlist[no-1]);
						mlist[no-1]=NULL;
						printf("=> 삭제됨\n");
						count--;
					}
					else{
						printf("=>  취소됨\n");
						continue;
					}		
			}		
			else
				printf("등록된 메뉴가 없습니다\n");

		} 
		else if(menu==5){
			if(count==0)
				printf("저장할 정보가 없습니다\n");
			else
				saveData(mlist,curcount);
		} 
		else if(menu==6){
			printf("\n1. 메뉴 이름 검색\n");
			printf("2. 메뉴 가격 검색\n");
			printf("3. 메뉴 사이즈 검색\n");
			printf("4. 메뉴 타입 검색\n");
			printf("\n=> 번호를 고르세요 : ");
			scanf("%d",&searchNum);
			
			if(searchNum==1)searchMenu(mlist,curcount);
			else if(searchNum==2)searchPrice(mlist,curcount);
			else if(searchNum==3)searchSize(mlist,curcount);
			else if(searchNum==4)searchType(mlist,curcount);
			else printf("잘못 골랐습니다..\n");
		} 
	}
	printf("=> 프로그램 종료됨\n");
	return 0;
}
