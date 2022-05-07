#include "dessert.h"
#include <stdio.h>
#include <stdlib.h>
 
int main(void){
        Cafe d[20];
        int menu;
        int user;
        int index=0;
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
                  else if(menu == 4) deleteDessert(d);
                  //else if(menu == 5) saveProduct(d);
                  //else if(menu == 6) loadProduct(d); 
                  
                }
                if(user == 2)
                {
                    break;//구매자일 때
                }
                
        }
        printf("종료됨");
        return 0;
}
    

