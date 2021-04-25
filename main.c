#include <stdio.h>
#include <ctype.h>
#include <string.h>


int check = 0;
int count = 0;

struct goods
{
    int no;
    char id[10];
    char name[50];
    char type[30];
    double price;
};

void mainmenu();


void manager_menu(struct goods item[]);
void see_itme(struct goods item[], int amount);
void add_item(struct goods item[]);


void guest_menu();


void check_item();



int main(){
    printf("    menu\n");
    printf("    1.guest\n");
    printf("    2.manager\n");
    struct goods item[count];


    int i;
    scanf("%d", &i);
    if(i == 1){
        guest_menu();
    }
     else if (i == 2){
        manager_menu(item);
    }
}


void manager_menu(struct goods item[]){
    int i;
    printf("    Welcome Manager\n");
    printf("    1.ดูสินค้าทั้งหมด\n");
    printf("    2.เพิ่มสินค้า\n");
    printf("    3.แก้ไขสินค้า\n");
    printf("    4.ค้นหาสินค้า\n");


    scanf("%d", &i);
    if(i == 1){
        see_itme(item, count);
    }
    else if (i == 2){
        add_item(item);
    }
    

}



void add_item(struct goods item[]){
    int i;
    char t[50];
    double p;
    printf("    กรุณาป้อนจำนวนสินค้าที่เพิ่ม\n");
    scanf("%d", &count);
    for(int j=0; j<count; j++){
        printf("item No.%d", j+1);
        item[j].no = j+1;

        printf("\nID:  ");
        scanf("%s", t);
        stpcpy(item[j].id, t);

        printf("Name:  ");
        scanf("%s", t);
        stpcpy(item[j].name, t);

        printf("Type:  ");
        scanf("%s", t);
        stpcpy(item[j].type, t);

        printf("Price:  ");
        scanf("%lf", &item[j].price);
    }
    printf("ป้อนข้อมูลสำเร็จ !!!!!\n");
    check = 1;
    printf("0.ย้อนกลับ\n");
    scanf("%d", &i);
    if(i == 0){
        manager_menu(item);
    }

    
}


void see_itme(struct goods item[], int amount){
    int i;
    check_item();
    for(int j=0; j<amount; j++){
        if(j == 0){
            printf("\tNo\t\tID\t\tName\t\tType\t\tPrice\n");
        }
        printf("\t%d\t\t", item[j].no);
        printf("%s\t\t", item[j].id);
        printf("%s\t\t", item[j].name);
        printf("%s\t\t", item[j].type);
        printf("%.2lf\n", item[j].price);
    }
    printf("0.ย้อนกลับ\n");
    scanf("%d", &i);
    if(i == 0){
        manager_menu(item);
    }
}


void guest_menu(){
    printf("    Welcome To Shop\n");
}

void check_item(){
    if(check == 0){
        printf("    ไม่มีสินค้า\n");
    }
}
