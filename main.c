#include "product.h"

int main(void){
	int menu, count=0, curcount=0;
	MENU *mlist[SIZE];
	while(1){
		menu=cafemenu();
		if(menu==0) break;
		else if(menu==1){

		} 
		else if(menu==2){
			mlist[curcount]= (MENU*)malloc(sizeof(MENU));	
			count+= addmenu(mlist[curcount]);
			curcount++;

		} 
		else if(menu==3){

		} 
		else if(menu==4){

		} 
		else if(menu==5){

		} 
		else if(menu==6){

		} 
	}
	printf("=> 프로그램 종료됨\n");
	return 0;
}
