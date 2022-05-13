#include "dessert.h"

int selectUser(){
    int user;
    printf("\n  <<<<<판매자 및 구매자 음료 등록 서비스 >>>>>\n");
    printf("당신은 어떤 서비스를 원합니까?\n");
    printf("1. 판매자\n");
    printf("2. 구매자\n");
    printf("=> 원하는 메뉴는?\n");
    scanf("%d",&user);
    return user;
}

int selectMenu(){
        int menu;
        printf("\n *** 판매자 음료 등록 서비스 ***\n");
        printf("0. 종료\n");
        printf("1. 음료 추가\n");
        printf("2. 음료 리스트 확인\n");
        printf("3. 음료 리스트 수정\n");
        printf("4. 음료 리스트 삭제\n");
        printf("5. 음료 리스트 데이터 저장\n");
        printf("=> 원하는 메뉴는?\n");
        scanf("%d",&menu);

        return menu;
}

int createDessert(Cafe *p){
        printf("음료명은 무엇입니까??  ");
        scanf("%s",p->name);

        printf("음료의 가격  ");
        scanf("%d",&p->price);
        getchar();

        printf("음료 상세 설명  ");
        fgets(p->explain,100,stdin);
	p->explain[strlen(p->explain)-1]='\0';

        return 1;
} 

void listDessert(Cafe *p[],int index){
        printf("\n");
        printf("\n");
        printf("-------------------------\n");
        printf(" <<<음료 목록>>>\n");
        printf("-------------------------\n");

        for(int i=0; i<index; i++)
        {
            readDessert(*p[i],i);
        }

} 

int readDessert(Cafe p, int i){
    if(p.price > 0)
    {
        printf("%2d. ",i+1);
        printf("음료명: %s 음료 가격: %d원\n",p.name,p.price);
        printf("음료 설명: %s",p.explain);
        printf("\n");       
    }
    return 1;
}//하나의 제품 출력

int deleteDessert(Cafe *p)
{
        p->price=-1;
        printf("삭제됨!!\n");
        printf("\n");
        return 1;
}

int selectDateNo(Cafe *s[], int index){
    int no;
    listDessert(s,index);
    printf("번호는 (취소 :0)? ");
    scanf("%d",&no);
    return no;
}

int LoadDate(Cafe *p[]){
    int count=0;
    char str[200];
    char *prt;
    int ptr;
    FILE *fp;
    fp=fopen("dessert.txt","rt");
    if(fp==NULL){
        printf("음료 파일 없음\n");
        return 0;
    }
    else{
        if(!feof(fp)){
            for(int i=0;i<50;i++){
                if(feof(fp))break;
                p[i]=(Cafe *)malloc(sizeof(Cafe));
                fscanf(fp,"%s",p[i]->name);
                fscanf(fp,"%d",&p[i]->price);
                fgets(p[i]->explain,100,fp);
                if(p[i]->price>0) count++;
            }
        }
    fclose(fp);
    printf("로딩 완료!\n");
    return count;
}
}//파일 데이터 불러오기

void SaveDate(Cafe *p[], int count){
    FILE *fp;
    fp=fopen("dessert.txt","wt");
    for(int i=0;i<count;i++){
        if(p[i]->price==-1) continue;
        fprintf(fp,"%s %d %s\n",p[i]->name,p[i]->price,p[i]->explain);
    }
    fclose(fp);
    printf("저장 됨!\n");
}//데이터 저장하기


//------이번에 구현한 user버전 함수--------
int selectMenu_User(){
        int menu;
        printf("\n *** 구매자 음료 구매 서비스 ***\n");
        printf("0. 종료\n");
        printf("1. 음료 리스트 확인\n");
        printf("2. 음료 구매\n"); //소비자 취향 선택 여기서 이어지도록 구현
        printf("3. 도장 적립\n"); //자동으로 저장되도록 구현
        printf("=> 원하는 메뉴는?\n");
        scanf("%d",&menu);

        return menu;
}

int pointStemp(User *p[], int count){
    char user_name[10];
    printf("이름을 입력해주세요: ");
    scanf("%s",user_name);
    int no=0;
    FILE *fp;
    fp=fopen("user_info.txt","rt");
    if(fp==NULL){
        count++;
        strcpy(p[0]->username,user_name);
        p[0]->stamp=1;
        printf("%s님 도장이 하나 적립되었습니다. 현재 도장 개수는 %d개 입니다.\n",p[0]->username,p[0]->stamp); 
        return count;
    }
    else if(!feof(fp)){
        for(int i=0;i<count;i++){
            if(p[i]==NULL)continue;
                if(strstr (p[i]->username,user_name)){
                    p[i]->stamp++;
                    printf("%s님 도장이 하나 적립되었습니다. 현재 도장 개수는 %d개 입니다.\n",p[i]->username,p[i]->stamp);
                    no=1;
                    if(p[i]->stamp==10){
                        printf("도장이 10개가 되었으므로 음료 1잔 무료 쿠폰을 드립니다.\n");
                        p[i]->stamp=0;
                        count--;
                    }
                break;
                }
        }
        if(no==0){
            count++;
            printf("count: %d\n",count);//
            strcpy(p[count-1]->username,user_name);
            p[count-1]->stamp=1;
            printf("%s님 도장이 하나 적립되었습니다. 현재 도장 개수는 %d개 입니다.\n",p[count-1]->username,p[count-1]->stamp); 
        }
    }
    fclose(fp);
return count;//사람 수
}//소비자에게 스탬프를 찍어, 몇 회 이상 방문하였는지 확인할 수 있는 함수

int User_LoadDate(User *p[]){
    int count=0;
    char str[200];
    char *prt;
    int ptr;
    FILE *fp;
    fp=fopen("user_info.txt","rt");
    if(fp==NULL){
        printf("손님 정보 없음\n");
        return 0;
    }
    else{
        if(!feof(fp)){
            for(int i=0;i<100;i++){
                if(feof(fp))break;
                p[i]=(User *)malloc(sizeof(User));
                fscanf(fp,"%s",p[i]->username);
                fscanf(fp,"%d",&p[i]->stamp);
                if(p[i]->stamp>0) count++;
            }
        }
    fclose(fp);
    printf("로딩 완료!\n");
    return count;
    }
}//파일 데이터 불러오기

void User_SaveDate(User *p[], int count){
    FILE *fp;
    fp=fopen("user_info.txt","wt");
    for(int i=0;i<count;i++){
        if(p[i]->stamp<=0) continue;
        fprintf(fp,"%s %d\n",p[i]->username,p[i]->stamp);
    }
    fclose(fp);
    printf("저장 됨!\n");
} //데이터 저장하기

int takeOut(){
    int takeout=0;
    printf("매장 취식은 1번, 포장은 2번을 눌러주세요^^ \n");
    scanf("%d",&takeout);
    if(takeout==1){return 1;}//매장 취식
    else if(takeout==2){return 2;}//포장
    return 0; //오류
} // 소비자가 매장 내에서 음료를 마실지, 포장할 지 정해주는 함수
