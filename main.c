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
    int dis_count;
};





int main_menu(struct goods item[]);

void manager_menu(struct goods item[]);
void check_item();
void see_itme(struct goods item[]);
void add_products(struct goods item[]);
void stock(struct goods item[]);
void change(struct goods item[]);
void edit_item(struct goods item[]);
void delete_item(struct goods item[]);
void search_item(struct goods item[]);





void guest_menu(struct goods item[]);

void select_item(struct goods item[], double result);
void view_item(struct goods item[]);
void add_item(struct goods item[], double result);
void reduce_item(struct goods item[], double result);
void check_discout(struct goods item[]);
void bill(struct goods item[], double result);
void reset_discount(struct goods item[]);



int main(){
    struct goods item[count_item];
    main_menu(item);
}

int main_menu(struct goods item[]){
    int state;
    printf("\n\n\t\t\t\tmenu\n\n");
    printf("\t1.guest\n");
    printf("\t2.manager\n");
    scanf("%d", &state);
    while (state != 1 && state != 2)
    {
        printf("\n\n\t\t\t\tmenu\n\n");
        printf("\t1.guest\n");
        printf("\t2.manager\n");
        scanf("%d", &state);
        if(state == 1 || state == 2){
            break;
        }
    }
    
    if(state == 1){
        guest_menu(item);
    }
    else if (state == 2){
        manager_menu(item);
    }
}


void manager_menu(struct goods item[]){
    int state;
    printf("\n\n\t\t\t\tWelcome Manager\n\n");
    printf("\t1.ดูสินค้าทั้งหมด\n");
    printf("\t2.เพิ่มสินค้า\n");
    printf("\t3.แก้ไขสินค้า\n");
    printf("\t4.ค้นหาสินค้า\n");
    printf("\t0.ย้อนกลับ\n");


    scanf("%d", &state);
    if(state == 1){
        see_itme(item);
    }
    else if (state == 2){
        add_products(item);
    }
    else if (state == 3){
        edit_item(item);
    }
    else if (state == 4){
        search_item(item);
    }
    else if (state == 0){
        main_menu(item);
    }
    

}



void add_products(struct goods item[]){
    int i;
    int get;
    char t[50];
    printf("\n\n\t\t\t\tเพิ่มสินค้า\n\n");
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

        item[j].dis_count = 0;
    }
    count_item += get;
    printf("\n\n\t\t\t\tป้อนข้อมูลสำเร็จ !!!!!\n\n");
    printf("\n\t0.ย้อนกลับ\n");
    scanf("%d", &i);
    if(i == 0){
        manager_menu(item);
    }
    
}


void check_item(){
    if(count_item == 0){
        printf("\n\n\tNo\t\tID\t\tName\t\tType\t\tPrice\n\n");
        printf("\n\n\t\t\t\t\tไม่มีสินค้า\n\n");
    }
}



void stock(struct goods item[]){
    check_item();
    for(int j=0; j<count_item; j++){
        if(j == 0){
            printf("\n\n\tNo\t\tID\t\tName\t\tType\t\tPrice\t\tQuantity\n\n");
        }
        printf("\t%d\t\t", item[j].no);
        printf("%s\t\t", item[j].id);
        printf("%s\t\t", item[j].name);
        printf("%s\t\t", item[j].type);
        printf("%.2lf\t\t", item[j].price);
        printf("%d\n", item[j].quantity);
    }
}

void see_itme(struct goods item[]){
    int i;
    stock(item);
    printf("\t0.ย้อนกลับ\n");
    scanf("%d", &i);
    if(i == 0){
        manager_menu(item);
    }
}


void edit_item(struct goods item[]){
    int state;
    printf("\n\n\t\t\t\tแก้ไขสินค้า\n\n");
    stock(item);
    printf("\n\n\n\t1.ต้องการเปลี่ยนข้อมูล\n");
    printf("\t2.ต้องการลบข้อมูล\n");
    printf("\t0.ย้อนกลับ\n");

    scanf("%d", &state);
    if(state == 1){
        change(item);
    }
    else if(state == 2){
        delete_item(item);
    }
    else if(state == 0){
        manager_menu(item);
    }
}

void change(struct goods item[]){
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
                stock(item);    
                printf("\n\t1.ID\n");
                printf("\t2.Name\n");
                printf("\t3.Type\n");
                printf("\t4.Price\n");
                printf("\t5.Quantity\n");
                printf("\t0.ย้อนกลับ\n");
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
                    printf("\n\tแก้ไขสำเร็จ  !!!\n\n");
                }
                
            }
        }
    }
    edit_item(item);
}

void delete_item(struct goods item[]){
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
    edit_item(item);
}

void search_item(struct goods item[]){
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
        manager_menu(item);
    }
}







void guest_menu(struct goods item[]){
    printf("\n\n\t\t\t\t\t\tWelcome To Shop\n\n\n");
    double result = 0;
    reset_discount(item);
    select_item(item, result);
}


void select_item(struct goods item[], double result){
    bool ation = true;
    while (ation)
    {
        stock(item);
        printf("\n\n\tยอมรวม:\t%.2lf\n", result);
        int state;
        printf("\t1.เพิ่มสินค้า\n");
        printf("\t2.ลดสินค้า\n");
        printf("\t3.ชำระเงิน\n");
        scanf("%d", &state);
        if(state == 1){
            add_item(item, result);
        }
        else if (state == 2){
           reduce_item(item, result);
        }
        else if (state == 3){
           bill(item, result);
        }
    }
}


void view_item(struct goods item[]){
    printf("\n\n\tNo\tสินค้า\tจำนวน\tราคา\n\n");
    for(int j=0; j<count_item; j++){
        if(item[j].dis_count > 0){
            printf("\t%d\t%s\tx%d\t%.2lf\n", item[j].no, item[j].name, item[j].dis_count, item[j].dis_count*item[j].price);
        }
    }
}

void add_item(struct goods item[], double result){
    int i;
    int num;
    printf("\n\tป้อนสินค้าที่ต้องเพิ่ม No:\t");
    scanf("%d", &i);
    for(int j=0; j<count_item; j++){
        if(i == item[j].no){
            printf("\t%s\tจำนวน:\t", item[j].name);
            scanf("%d", &num);
            while (num>item[j].quantity){
                printf("\tมีสินค้าไม่เพียงพอกรุณาป้อนใหม่\n\t0.ยกเลิก\n");
                printf("\t%s\tจำนวน:\t", item[j].name);
                scanf("%d", &num);
                if(num == 0){
                    select_item(item, result);
                }
            }
            result += item[j].price*num;
            item[j].quantity = item[j].quantity - num;
            item[j].dis_count += num;
        }
    }
    select_item(item, result);
}

void check_discout(struct goods item[]){
    int i = 0;
    for(int j=0; j<count_item; j++){
        if(item[j].dis_count == 0){
            i++;
        }
    }
    if(i == count_item){
        printf("\n\t\tไม่มีสินค้า\n\n");
        printf("\n\t0.ย้อนกลับ\n");
    }
}



void reduce_item(struct goods item[], double result){
    int i;
    int num;
    view_item(item);
    check_discout(item);
    printf("\n\tป้อนสินค้าที่ต้องลด No:\t");
    scanf("%d", &i);
    for(int j=0; j<count_item; j++){
        if(i == item[j].no){
            printf("\t%s\tจำนวน:\t", item[j].name);
            scanf("%d", &num);
            while (num>item[j].dis_count){
                printf("\tมีสินค้าไม่เพียงพอกรุณาป้อนใหม่\n\t0.ยกเลิก\n");
                printf("\t%s\tจำนวน:\t", item[j].name);
                scanf("%d", &num);
                if(num == 0){
                    select_item(item, result);
                }
            }
            result -= item[j].price*num;
            item[j].quantity = item[j].quantity + num;
            item[j].dis_count -= num;
        }
    }
    select_item(item, result);
}



void bill(struct goods item[], double result){
    int state;
    view_item(item);
    printf("\n\n\tจำนวนเงินที่ต้องชำระ: %.2lf\n\n", result);
    printf("\t0.กลับไปหน้าแรก\n");
    scanf("%d", &state);
    if(state == 0){
        result = 0;
        main_menu(item);
    }

}

void reset_discount(struct goods item[]){
    for(int j=0; j<count_item; j++){
        item[j].dis_count = 0;
    }
}


