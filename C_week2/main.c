//
//  main.c
//  C_week2
//
//  Created by runny on 2020/5/23.
//  Copyright © 2020 runny. All rights reserved.
//

#include <stdio.h>
#include<math.h>

int main(int argc, const char * argv[]) {
    // insert code here...
//    void calculateNarcissusNumber();
//    calculateNarcissusNumber();
    
//    void printNinetyNineMultiplication();
//    printNinetyNineMultiplication();
    
    void calculateSequence();
    calculateSequence();
    return 0;
}

//计算水仙花数，它的每个位上的数字的N次幂之和等于它本身 例如153=1的3次幂+5的3次幂+3的3次幂
void calculateNarcissusNumber(){
    int n;
    printf("请输入需要计算的水仙花数的位数\n");
    scanf("%d",&n);
    int firstNum=1;
    int loop=1;
    //算出循环开始的第一个数字 比如三位数就是从100开始 四位数从1000开始
    while (loop<n) {
        firstNum*=10;
        loop++;
    }
    printf("firstNum=%d\n",firstNum);
    
    int i ;
    i=firstNum;
    //三位数计算范围是 100-999 四位数为1000-9999
    while (i<firstNum*10) {
        int k = i;
        int sum = 0;
        //判断i是否为水仙花数
        while(k>0){
            int digit = k%10;
            k/=10;
            sum+=pow(digit,n);
        }
        if(i==sum){
            printf("%d为水仙花数\n",i);
        }
        i++;
    }
}

//打印99乘法表
void printNinetyNineMultiplication(){
    int i ;
    int j ;
    for (i=1; i<=9; i++) {
        for (j=1; j<=i; j++) {
            printf("%d*%d=%d\t",j,i,j*i);
        }
        printf("\n");
    }
}

//求序列的前n项和 从第二项开始 分子为前一项的分子+分母 分母为前一项的分子
// 2/1+3/2+5/3+8/5+13/8...
void calculateSequence(){
    int numerator=2;
    int denominator=1;
    int n;
    double sum = 0.0;
    printf("请输入表达式的项数!\n");
    scanf("%d",&n);
    
    for (int i = 1; i<=n; i++) {
        sum+=(numerator*1.0/denominator);
        int temp = numerator;
        numerator = numerator+denominator;
        denominator = temp;
    }
    printf("%d项多项式子计算结果为:%f\n",n,sum);
}
