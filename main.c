#include "dessert.h"
#include <stdio.h>
#include <stdlib.h>
 
int main(void){
        Cafe d[20];
        int menu;
        int user;
        int index=0; //음료의 리스크를 순서대로 보기 위함과 반복문을 구현할 때 범위의 기준을 잡기 위해 선언.
        int count=0;

        user = selectUser();
        while(1)
        {
                
                if(user==1)//판매자일 때
                {

                  menu = selectMenu();

                  if(menu == 0) break;
                  if(menu == 1)
                  {
                        count += createDessert(&d[index++]);
                  }
                  else if(menu == 2) listDessert(d,index);
                  else if(menu == 3) updataDessert(d);
                  else if(menu == 4)
                  {
                        int no = selectDateNo(d, index);
          
                        if(no==0)
                        {
                                printf("=> 취소됨!\n");
                                continue;
                        }
                        int deleteok; //삭제를 원하는지 사용자에게 물어보는 변수
                        printf("정말로 삭제하시겠습니까? (삭제 :1)");
                        scanf("%d",&deleteok);
                        if(deleteok==1)
                        {
                                if(deleteDessert(&d[no-1])) count--;
                        }  

                  }
                  else if(menu == 5) SaveDate(d);
                  else if(menu == 6) LoadDate(d); 
                  
                }
                if(user == 2)
                {
                    break;//구매자일 때
                }
                
        }
        printf("종료됨");
        return 0;
}
    

