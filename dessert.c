#include "dessert.h"
#include <string.h>
#include <stdlib.h>
int selectUser()
{
    int user;
    printf("\n  <<<<<판매자 및 구매자 음료 등록 서비스 >>>>>\n");
    printf("당신은 어떤 서비스를 원합니까?\n");
    printf("1. 판매자\n");
    printf("2. 구매자\n");
    printf("=> 원하는 메뉴는?\n");
    scanf("%d",&user);
    return user;
}
int selectMenu()
{
        int menu;
        printf("\n *** 판매자 음료 등록 서비스 ***\n");
        printf("0. 종료\n");
        printf("1. 음료 추가\n");
        printf("2. 음료 리스트 확인\n");
        printf("3. 음료 리스트 수정\n");
        printf("4. 음료 리스트 삭제\n");
        printf("5. 음료 리스트 데이터 저장\n");
        printf("6. 음료 리스트 데이터로딩\n");
        printf("=> 원하는 메뉴는?\n");
        scanf("%d",&menu);

        return menu;
}

int createDessert(Cafe *p)
{
        printf("음료명은 무엇입니까??  ");
        scanf("%s",p->name);

        printf("음료의 가격  ");
        scanf("%d",&p->price);

        printf("스탬프의 갯수// 도장 개수(10개되면 음료 한잔)  ");
        scanf("%d",&p->point);

        printf("takeout여부(1:takeout, 2:매장)  ");
        scanf("%d",&p->takeout);

        getchar();
        printf("음료 상세 설명  ");
        fgets(p->explain,100,stdin);

        printf("\n");
        return 1;

} 
void listDessert(Cafe *p,int count)
{
        printf("\n");
        printf("\n");
        printf("-------------------------\n");
        printf(" <<<음료 목록>>>\n");
        printf("-------------------------\n");

        for(int i=0; i<count; i++)
        {
            if(p->price != -1)
            {
                printf("%d.",i+1);
                readDessert(p[i]);
            }

                
        }

} 
int readDessert(Cafe p)
{
    printf("음료명: %s 음료 가격: %d원 스탬프 갯수: %d개 취식방법: %d번\n",p.name,p.price,p.point,p.takeout);
    printf("음료 설명: %s",p.explain);
    printf("\n");
    return 1;
    

}
int deleteDessert(Cafe *p)
{
        p->price=-1;
        p->point=-1;
    
        printf("삭제됨!!\n");

        printf("\n");
        return 1;

}
int updataDessert(Cafe *p)
{
        printf("음료명은 무엇입니까??");
        scanf("%s",p->name);

        getchar();
        printf("음료 상세 설명");
        fgets(p->explain,100,stdin);

        printf("음료의 가격");
        scanf("%d",&p->price);

        printf("스탬프의 갯수// 도장 개수(10개되면 음료 한잔)");
        scanf("%d",&p->point);

        printf("takeout여부(1:takeout, 2:매장)");
        scanf("%d",&p->takeout);

        printf("수정 성공\n");

        printf("\n");
        return 1;


}

int loadProduct(Cafe *p[]){
    int i=0;
    char str[200];
    char *prt;
    FILE *fp;
    if(fp=fopen("dessert.txt","rt")){
while(fgets(str,200,fp)!=NULL){
     p[i]=(Cafe *)malloc(sizeof(Cafe));
     prt=strtok(str,";");
     strcpy(p[i]->name,prt);
     prt=strtok(NULL,";");
     strcpy(p[i]->explain,prt);
     prt=strtok(NULL,";");
    p[i]->price=atoi((strtok(NULL,";")));
    p[i]->point=atoi((strtok(NULL,";")));
    p[i]->takeout=atoi((strtok(NULL,";")));
    i++;
}
fclose(fp);
}
else printf("파일 없음\n"); return i;
}//파일 데이터 불러오기

void saveProduct(Cafe *p[], int count){
    FILE *fp;
    fp=fopen("dessert.txt","wt");
    for(int i=0;i<count;i++){
fprintf(fp,"%s; %s; %d; %d; %d;\n",p[i]->name,p[i]- >explain,p[i]->price,p[i]->point,p[i]->takeout);
    }
    fclose(fp);
printf("저장 됨!\n");
}//데이터 저장하기
