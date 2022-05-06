#include "dessert.h"
#include <string.h>
#include <stdlib.h>

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
