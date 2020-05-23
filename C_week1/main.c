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
//    void timeCalculate();
//    timeCalculate();
    
//    void  loopTest();
//    loopTest();
    void reverseIntNum();
    reverseIntNum();
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

//循环读入输入整数 负数输入表示结束 求正整数平均数
void loopTest(){
    int readInt;
    int totalNum=0;
    int readCount=0;
    printf("请输入想要求平均数的整数序列!\n");
    scanf("%d",&readInt);
    while (readInt>=0) {
        totalNum+=readInt;
        readCount++;
        scanf("%d",&readInt);
    }
    printf("输入参数个数为%d个,平均数为%f\n",readCount,1.0*totalNum/readCount);
}

//输入任意一个合法正整数对整数进行逆序
void reverseIntNum(){
    int readIntNum=0;
    int digit = 0;
    int reverseNum = 0;
    
    printf("请输入想要逆序排列的整数!\n");
    scanf("%d",&readIntNum);
    
    while (readIntNum>0)
    {
        digit = readIntNum % 10;
        readIntNum/=10;
        reverseNum=reverseNum*10+digit;
        printf("readIntNum=%d,digit=%d,reverseNum=%d\n",readIntNum,digit,reverseNum);
        
    }
    
    printf("逆序完成的整数为%d\n",reverseNum);
       
    
}
