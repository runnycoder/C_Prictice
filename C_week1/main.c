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
//    void reverseIntNum();
//    reverseIntNum();
    
//    void isPrimeNumber();
//    isPrimeNumber();
    
//    void printfFiftyPrimeNuber();
//    printfFiftyPrimeNuber();
    
//    void splitPrintReadNumber();
//    splitPrintReadNumber();
    
//    void splitPrintReadNumber2();
//    splitPrintReadNumber2();
    
    void calculateHighestCommonDivisor();
    calculateHighestCommonDivisor();
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

//判断一个数是否为素数
void isPrimeNumber(){
    int readNumber;
    printf("请输入需要判断的数值!");
    scanf("%d",&readNumber);
    int isPrimeFlag = 1;
    int i ;
    for (i=2; i<readNumber; i++) {
        if(readNumber%i==0){
            isPrimeFlag = 0;
            break;
        }
    }
    if(isPrimeFlag==1&&readNumber!=1){
        printf("输入值%d是素数",readNumber);
    }else{
        printf("输入值%d不是素数",readNumber);
    }
}

//输出前五十个素数
void printfFiftyPrimeNuber(){
    int readNumber=2;
    int loopCount = 0;
    
    while (loopCount<50) {
        int isPrimeFlag = 1;
        int i ;
        for (i=2; i<readNumber; i++) {
            if(readNumber%i==0){
                isPrimeFlag = 0;
                break;
            }
        }
        if(isPrimeFlag==1&&readNumber!=1){
            printf("%d\t",readNumber);
            loopCount++;
            if(loopCount%5==0){
                printf("\n");
            }
        }
       
        readNumber++;
    }
    
}

//12345-> 1 2 3 4 5 但是这种对于含0的整数就会出现异常
void splitPrintReadNumber(){
    int readNum ;
    int reverseNum=0 ;
    int digit;
    printf("请输入合适的正整数!\n");
    scanf("%d",&readNum);
    while (readNum>0) {
         digit = readNum%10;
         reverseNum = reverseNum*10+digit;
         readNum/=10;
    }
    printf("reverseNum=%d\n",reverseNum);
    
    while(reverseNum>0){
        digit = reverseNum%10;
        printf("%d",digit);
        if(reverseNum>=10){
            printf(" ");
        }
        reverseNum/=10;
    }
    printf("\n");
   
}
//12345-> 1 2 3 4 5
void splitPrintReadNumber2(){
    int readNum ;
    int splitNum=0 ;
    int preDigit;
    int maxUnit = 1;
    int divideCount = 0;
    printf("请输入合适的正整数!\n");
    scanf("%d",&readNum);
    splitNum=readNum;
    
    //循环求取最高位数值
    while (readNum>=10) {
        readNum/=10;
        divideCount++;
        maxUnit*=10;
    }
    
    //从高到低输出每一位数值
    while(maxUnit>0){
        preDigit=splitNum/maxUnit;
        splitNum%=maxUnit;
        maxUnit/=10;
        printf("%d\n",preDigit);
    }
    
}

//计算最大公约数
void  calculateHighestCommonDivisor(){
    int a,b;
    int maxCommonDivisor;
    a=35;
    b=41;
    while(a>0){
        int modNum = b%a;
        b=a;
        a=modNum;
        printf("b=%d,a=%d,modNum=%d\n",b,a,modNum);
    }
    printf("最大公约数为:%d\n",b);
}
