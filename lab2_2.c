#include <stdio.h>
#include <string.h>
typedef struct{
    char name[100];
    char size[20];
    int price;
} Pizza;


int addMenu(Pizza *s);
void readMenu(Pizza s);
int updateMenu(Pizza *s);
int deleteMenu(Pizza*s);
int selectMenu(){
    int menu;
    printf("\n*** PizzaYaho ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("0. 종료\n");
    printf(">> ");
    scanf("%d", &menu);
    return menu;
}

//main function
int main(void){
    Pizza s;
    int count = 0, menu;
    int result = 0;
    while (1){
        result = 0;
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1 || menu == 3 || menu == 4){
            if (count == 0) continue;
        }
        if (menu == 1){
            readMenu(s);
            count = 1;
        }
        if (menu == 2){
            result = addMenu(&s);
            count += 1;
        }
        if (menu == 3){
            result = updateMenu(&s);
            if (result==1) printf("=> 수정성공!\n");
        }
        if (menu == 4){
            result = deleteMenu(&s);
            count = 0;
            if (result==1) printf("=> 삭제됨!\n");
        }
    }
    printf("종료됨!\n");
    return 0;
}
//Create
int addMenu(Pizza *s){
    printf("메뉴명은? ");
    getchar();  
    fgets(s->name, 100, stdin);
    printf("메뉴종류(P/S/R)? ");
    scanf("%s", s->size);
    printf("가격은? ");
    scanf("%d", &s->price);
    return 1;
}
//Read
void readMenu(Pizza s){
    printf("*****************\n");
    printf("1       %d %s  %s", s.price, s.size, s.name);
}
//Update
int updateMenu(Pizza *s){
    printf("새 메뉴명은? ");
    getchar();  
    fgets(s->name, 20, stdin);
    printf("새 메뉴종류(P/S/R)? ");
    scanf("%s", s->size);
    printf("새 가격은? ");
    scanf("%d", &s->price);
    return 1;
}
//Delete
int deleteMenu(Pizza *s){
    strcpy(s->name, "nothing");
    strcpy(s->size, "nothing");
    s->price = 0;
    return 1;
}
