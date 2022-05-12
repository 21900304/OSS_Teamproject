#include <stdio.h>

typedef struct{
    char name[50]; //제품 이름
    char explain[100]; // 설명
    int price; // 가격
}Cafe;

int selectUser(); // 판매자와 구매자를 선택하는 함수
int selectMenu(); // 판매자를 선택시 메뉴를 선택하는 함수
int createDessert(); //판매자가 디저트 품목을 만드는 함수
void listDessert(); // 어떤 디저트가 있는 확인할 수 있는 함수
int readDessert();// 디저트품목을 읽어오는 함수

int deleteDessert();//디저트 품목을 삭제하는 함수
int selectDateNo(); // 사용자가 디저트 품목을 삭제하고 싶을 때 몇 번째 데이터를 삭제하는 확인하는 함수


int updataDessert();//디저트 품목을 수정하는 함수
void SaveDate();//데이터를 파일에 저장하는 함수
int LoadDate();//데이터를 파일에서 로딩하는 함수
void listConsumer();//소비자가 디저트 품목을 확인하고 구매를 하는 함수
void decaffeine();// 소비자가 구매를 할 때 디카페인, 당도 등 자신의 취향을 결정하게 도와주는 함수
int pointStemp();//소비자에게 스탬프를 찍어, 몇 회 이상 방문하였는지 확인할 수 있는 함수
int takeOut();// 소비자가 매장 내에서 음료를 마실지, 포장할 지 정해주는 함수
