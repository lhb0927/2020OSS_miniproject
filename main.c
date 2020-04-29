#include "product.h"

int main(void){
	int menu, count=0, curcount=0;
	MENU *mlist[SIZE];
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

		} 
		else if(menu==6){

		} 
	}
	printf("=> 프로그램 종료됨\n");
	return 0;
}
