//
//  main.c
//  C_week5
//
//  Created by runny on 2020/5/28.
//  Copyright © 2020 runny. All rights reserved.
//

#include <stdio.h>

//联合 以占用内存最大的变量分配内存空间 比如CHI分配的内存空间就是int的字节数=4
typedef union {
    int i;
    char ch[sizeof(int)];
} CHI;

typedef struct car{
    int speed;
    int wheel;
} Car;

struct date{
    int year;
    int month;
    int day;
};
void getStruct(struct date *p);
void outStruct(struct date p);

int main(int argc, const char * argv[]) {
    // insert code here...
//    struct date today;
//    today.year=2020;
//    today.month=5;
//    today.day=28;
//    printf("date=%d-%d-%d\n",today.year,today.month,today.day);
//
//    today =(struct date){2019,6,29};
//    struct date * todayPoint = &today;
//    printf("date=%d-%d-%d\n",today.year,today.month,today.day);
//    printf("today *p=%p\n",todayPoint);

//    struct date today = {2020,5,29};
//    struct date *temp=&today;
//    getStruct(temp);
//    outStruct(today);
//    outStruct(*temp);
    
//    Car bmw = {500,4};
//    printf("bmw speed=%d,wheel=%d\n",bmw.speed,bmw.wheel);
    
    CHI chi ;
    int i;
    chi.i = 1234; //16进制表示为000004D2 x86cpu在内存存储数值的时候是低为在前的所以正好反过来
    for (i=0; i<sizeof(int); i++) {
        printf("%02hhX",chi.ch[i]);
    }
    printf("\n");

    return 0;
}
//只有传入指针才能真正改变外部结构体 传入参数只是在调用函数的空间 temp copy to p
void getStruct(struct date *p){
    printf("请输入dd mm yy格式的日期\n");

    scanf("%d",&((*p).day));
    scanf("%d",&((*p).month));
    scanf("%d",&((*p).year));
    
    //or
//    scanf("%d",&p->day);
//    scanf("%d",&p->month);
//    scanf("%d",&p->year);
    
}

void outStruct(struct date p){
    printf("date=%d-%d-%d\n",p.year,p.month,p.day);
};
