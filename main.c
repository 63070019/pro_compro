#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


int count_item = 0;
int count_user = 0;

struct goods
{
    int no;
    char id[10];
    char name[50];
    char type[30];
    double price;
    int quantity;
};


struct person
{
    double result_b;

};


void main_menu(struct goods item[], struct person user[]);


void manager_menu(struct goods item[], struct person user[]);
void check_item();
void see_itme(struct goods item[], struct person user[]);
void add_item(struct goods item[], struct person user[]);
void stock(struct goods item[]);
void change(struct goods item[], struct person user[]);
void edit_item(struct goods item[], struct person user[]);
void delete_item(struct goods item[], struct person user[]);
void search_item(struct goods item[], struct person user[]);


void guest_menu(struct goods item[], struct person user[]);

void cal_user(struct goods item[], struct person user[]);
void select_item(struct goods item[], struct person user[]);



int main(){
    struct goods item[count_item];
    struct person user[count_user];
    main_menu(item, user);
}

void main_menu(struct goods item[], struct person user[]){
    printf("\tmenu\n");
    printf("\t1.guest\n");
    printf("\t2.manager\n");



    int i;
    scanf("%d", &i);
    if(i == 1){
        guest_menu(item, user);
    }
     else if (i == 2){
        manager_menu(item, user);
    }
}


void manager_menu(struct goods item[], struct person user[]){
    int state;
    printf("\tWelcome Manager\n");
    printf("\t1.ดูสินค้าทั้งหมด\n");
    printf("\t2.เพิ่มสินค้า\n");
    printf("\t3.แก้ไขสินค้า\n");
    printf("\t4.ค้นหาสินค้า\n");
    printf("\t0.ย้แนกลับ\n");


    scanf("%d", &state);
    if(state == 1){
        see_itme(item, user);
    }
    else if (state == 2){
        add_item(item, user);
    }
    else if (state == 3){
        edit_item(item, user);
    }
    else if (state == 4){
        search_item(item, user);
    }
    else if (state == 0){
        main_menu(item, user);
    }
    

}



void add_item(struct goods item[], struct person user[]){
    int i;
    int get;
    char t[50];
    printf("\tกรุณาป้อนจำนวนสินค้าที่เพิ่ม:  ");
    scanf("%d", &get);
    for(int j=count_item; j<count_item+get; j++){
        printf("\n\titem No.%d", j+1);
        item[j].no = j+1;

        printf("\n\tID:\t");
        scanf("%s", t);
        stpcpy(item[j].id, t);

        printf("\tName:\t");
        scanf("%s", t);
        stpcpy(item[j].name, t);

        printf("\tType:\t");
        scanf("%s", t);
        stpcpy(item[j].type, t);

        printf("\tPrice:\t");
        scanf("%lf", &item[j].price);

        printf("\tQuantity:\t");
        scanf("%d", &item[j].quantity);
    }
    count_item += get;
    printf("\n\tป้อนข้อมูลสำเร็จ !!!!!\n");
    printf("\t0.ย้อนกลับ\n");
    scanf("%d", &i);
    if(i == 0){
        manager_menu(item, user);
    }
    
}


void check_item(){
    if(count_item == 0){
        printf("\tNo\t\tID\t\tName\t\tType\t\tPrice\n");
        printf("\n\n\t\t\t\t\tไม่มีสินค้า\n\n");
    }
}



void stock(struct goods item[]){
    check_item();
    for(int j=0; j<count_item; j++){
        if(j == 0){
            printf("\tNo\t\tID\t\tName\t\tType\t\tPrice\t\tQuantity\n");
        }
        printf("\t%d\t\t", item[j].no);
        printf("%s\t\t", item[j].id);
        printf("%s\t\t", item[j].name);
        printf("%s\t\t", item[j].type);
        printf("%.2lf\t\t", item[j].price);
        printf("%d\n", item[j].quantity);
    }
}

void see_itme(struct goods item[], struct person user[]){
    int i;
    stock(item);
    printf("\t0.ย้อนกลับ\n");
    scanf("%d", &i);
    if(i == 0){
        manager_menu(item, user);
    }
}


void edit_item(struct goods item[], struct person user[]){
    int state;
    stock(item);
    printf("\n\t1.ต้องการเปลี่ยนข้อมูล\n");
    printf("\t2.ต้องการลบข้อมูล\n");
    printf("\t0.ย้อนกลับ\n");

    scanf("%d", &state);
    if(state == 1){
        change(item, user);
    }
    else if(state == 2){
        delete_item(item, user);
    }
    else if(state == 0){
        manager_menu(item, user);
    }
}

void change(struct goods item[], struct person user[]){
    int num;
    int state;
    char t[50];
    bool ation = true;
    printf("\n\t No.:   ");
    scanf("%d", &num);
    for(int j=0; j<count_item; j++){
        if(j == num-1){
            while (ation)
            {               
                printf("\n\t1.ID:  \n");
                printf("\t2.Name:  \n");
                printf("\t3.Type:  \n");
                printf("\t4.Price:  \n");
                printf("\t5.Quantity:  \n");
                printf("\t0.ย้อนกลับ:  \n");
                scanf("%d", &state);
                if(state == 1){
                    printf("\n\tID:  ");
                    scanf("%s", t);
                    stpcpy(item[j].id, t);
                }
                else if(state == 2){
                    printf("\tName:  ");
                    scanf("%s", t);
                    stpcpy(item[j].name, t);
                }
                else if(state == 3){
                    printf("\tType:  ");
                    scanf("%s", t);
                    stpcpy(item[j].type, t);
                }
                else if(state == 4){
                    printf("\tPrice:  ");
                    scanf("%lf", &item[j].price);
                }
                else if(state == 5){
                    printf("\tQuantity:  ");
                    scanf("%lf", &item[j].quantity);
                }
                else if(state == 0){
                    ation = false;
                }
                if(state !=  0){
                    printf("\tแก้ไขสำเร็จ  !!!\n");
                }
                
            }
        }
    }
    edit_item(item, user);
}

void delete_item(struct goods item[], struct person user[]){
    int num;
    int state;
    printf("\n\t No.:   ");
    scanf("%d", &num);
    for(int j = 0; j<count_item; j++){
        if(j >= num-1){
            item[j].no = item[j+1].no-1;
            stpcpy(item[j].id, item[j+1].id);
            stpcpy(item[j].name, item[j+1].name);
            stpcpy(item[j].type, item[j+1].type);
            item[j].price = item[j+1].price;
            item[j].quantity = item[j+1].quantity;
        }
    }
    count_item--;
    edit_item(item, user);
}

void search_item(struct goods item[], struct person user[]){
    char n_id[10];
    int state;
    printf("\n\t ID:    ");
    scanf("%s", n_id);
    for(int j = 0; j<count_item; j++){
        if(strcmp(n_id, item[j].id) == 0){
            printf("\n\n\tID:\t%s\n", item[j].id);
            printf("\tName:\t%s\n", item[j].name);
            printf("\tType:\t%s\n", item[j].type);
            printf("\tPrice:\t%.2lf\n", item[j].price);
            printf("\tQuantity:\t%d\n", item[j].quantity);
        }
    }
    printf("\n\t0.ย้อนกลับ\n");
    scanf("%d", &state);
    if(state == 0){
        manager_menu(item, user);
    }
}

void guest_menu(struct goods item[], struct person user[]){
    printf("\t\tWelcome To Shop\n");
    cal_user(item, user);

}


void select_item(struct goods item[], struct person user[]){
    bool ation = true;
    double result = 0;
    while (ation)
    {
        stock(item);
        printf("\n\n\tยอมรวม:\t%.2lf\n", result);
        int i;
        int state;
        int num;
        printf("\t1.เลือกซื้อสินค้า\n");
        printf("\t0.ชำระเงิน\n");
        scanf("%d", &state);
        if(state == 1){
            printf("\tป้อนสินค้าที่ต้อง No:\t");
            scanf("%d", &i);
            for(int j=0; j<count_item; j++){
                if(i-1 == j){
                    printf("\t%s\tจำนวน:\t", item[j].name);
                    scanf("%d", &num);
                    while (num>item[j].quantity){
                        printf("\tมีสินค้าไม่เพียงพอกรุณาป้อนใหม่\n\t0.ยกเลิก\n");
                        printf("\t%s\tจำนวน:\t", item[j].name);
                        scanf("%d", &num);
                        if(num == 0){
                            select_item(item, user);
                        }
                    }
                    result += item[j].price*num;
                    item[j].quantity = item[j].quantity - num;
                }
            }
        }
    }

}


void cal_user(struct goods item[], struct person user[]){
    select_item(item, user);
}