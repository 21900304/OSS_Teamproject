#include "dessert.c"
 
int main(void){
	Cafe *menu_list[50]; //포인터 배열로 수정
	int count = 0, menu; int index = 0; //음료의 리스크를 순서대로 보기 위함과 반복문을 구현할 때 범위의 기준을 잡기 위해 선언.
        int user;
	count = LoadDate(menu_list);
    	index = count;
	user = selectUser();
	if(user==1){//판매자일 때
		 while(1){
			menu = selectMenu();
                 	if(menu == 0) break;
                  	if(menu == 1){
			menu_list[index]=(Cafe *)malloc(sizeof(Cafe));
                        count += createDessert(menu_list[index++]);
                 	}
                  	else if(menu == 2) listDessert(menu_list,index);
                  	else if(menu == 3){
			int num;//삭제 음료 번호 선택 변수
                        listDessert(menu_list,index);
                        printf("수정할 음료 번호? ");
                        scanf("%d", &num);       
			createDessert(menu_list[num-1]);
			}
                  	else if(menu == 4){
                        int no = selectDateNo(menu_list, index);
                        if(no==0){
                                printf("=> 취소됨!\n");
                                continue;
                        }
                        int deleteok; //삭제를 원하는지 사용자에게 물어보는 변수
                        printf("정말로 삭제하시겠습니까? (삭제 :1)");
                        scanf("%d",&deleteok);
                        	if(deleteok==1){
                                   if(deleteDessert(menu_list[no-1])) count--;
                        	}  
                  	}
                 	else if(menu == 5) SaveDate(menu_list,index);
                  }//while
	}//user==1
    User *user_info[100]; //손님 정보
    int count_user=0; //포인트 적립에 등록된 손님 수
    count_user=User_LoadDate(user_info);
                if(user == 2){//구매자일 때
		  while(1){
                    menu = selectMenu_User();
                    if(menu == 0) break;
                    else if(menu == 1) {
                        listDessert(menu_list,index);
                    }
                    else if(menu == 2){ //음료 구매->소비자 취향 선택->테이크아웃여부

                        int check=takeOut(); //1번이면 매장, 2번이면 takeout
                        //구현해주세요!
                    }
                    else if(menu == 3){ //도장 적립
                        count_user=pointStemp(user_info,count_user);//이름 넘겨주고 도장 추가
                        User_SaveDate(user_info,count_user);//바로 저장
                    } 
                }
                }
        printf("종료됨");
        return 0;
}
    

