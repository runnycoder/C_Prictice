//
//  main.c
//  C_week1
//
//  Created by runny on 2020/5/22.
//  Copyright © 2020 runny. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("Hello, World!\n");
    void timeCalculate();
    timeCalculate();
    return 0;
}

//时间计算
void timeCalculate(){
    /* code */
    int currentTime;
    int minute;
    printf("请输入时间和分钟数!");
    scanf("%d %d",&currentTime,&minute);
    int currentHour = currentTime/100;
    int currentMinute = currentTime%100;
    int nextHour = currentHour+minute/60;
    int nextMinute = currentMinute+minute%60;

    printf("计算后新的时间为:%d\n",nextHour*100+nextMinute);
}
