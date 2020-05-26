//
//  main.c
//  week3
//
//  Created by runny on 2020/5/25.
//  Copyright © 2020 runny. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void printNuber(int a){
    printf("%d\n",a);
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    printNuber(2.4);
//    void calculateNumberAppearTimes();
//    calculateNumberAppearTimes();
    
//    void calculatePrimeNumberByArrays();
//    calculatePrimeNumberByArrays();
//    void calculatePrimeNumberByArrays2();
//    calculatePrimeNumberByArrays2();
    
//    void swap(int *a,int *b);
//
//    int a =5;
//    int b =10;
//    swap(&a, &b);
//    printf("a=%d,b=%d\n",a,b);
//    return 0;
    
    
    //指针测试 数组本身相当于特殊的指针 int a[] = int * const a 指针指向地址不能改变
//    int a[10] = {10};
//    int *p = a;
//    printf("%p\n", a);
//    printf("%p\n", &a[0]);
//    printf("%p\n", p);
//    printf("%p\n", a[0]);
//    printf("%p\n", p[0]);
    
//    void dynamicMemoryDistribute();
//    dynamicMemoryDistribute();
    
    void calculateMaxMallocDynamicMemorySize();
    calculateMaxMallocDynamicMemorySize();
    
}

//输入数量不确定的[0,9]之间的整数，统计每个数字出现的次数，输入-1说明输入结束
void calculateNumberAppearTimes(){
    const int length = 10;
    int arrs[length]={0};
    int readNum;
    
//    for (int i=0; i<length; i++) {
//        arrs[i]=0;
//    }
    
    printf("请输入需要统计的数列\n");
    scanf("%d",&readNum);
    while (readNum!=-1) {
        if(readNum>=0&&readNum<length){
            arrs[readNum]++;
        }
        scanf("%d",&readNum);
    }
    //sizeof(arrs) 求数组占用的字节数
    for (int i = 0; i<sizeof(arrs)/sizeof(arrs[0]); i++) {
        printf("%d:%d\n",i,arrs[i]);
    }
}

int isPrime(int n,int primeArr[],int arrLength){
    int isPrime = 1;
    int i;
    for (i=0; i<arrLength; i++) {
        if(primeArr[i]!=0 &&
           n%primeArr[i]==0){
            isPrime=0;
            break;
        }
    }
    return isPrime;
}

//求给定数量的素数
void calculatePrimeNumberByArrays(){
    const int arrLength = 100;
    int count = 0;
    int primeArr[arrLength]={2};//初始化素数数组
    int i = 3;
    while (count<arrLength) {
        if(isPrime(i, primeArr, arrLength)){
            primeArr[++count]=i;
        }
        i++;
    }
    
    for (int i = 0; i<arrLength; i++) {
        printf("%d\t",primeArr[i]);
        if((i+1)%5==0){
            printf("\n");
        }
    }
}

//求在给定值之内的素数
void calculatePrimeNumberByArrays2(){
    const int maxNumber = 100;
    int primeArr[maxNumber];//构建指定长度的数组，默认初始化每个数字都为素数
    for (int i = 0; i<maxNumber; i++) {
        primeArr[i]=1;
    }
   //从2开始判断数值是否为素数
    for (int i = 2; i<=maxNumber; i++) {
        if(primeArr[i]){//如果i为素数 那么2x 3x 4x .. ax<=100 都不是素数 所以从构建的素数表中删除
            for (int x = 2; x*i<=maxNumber; x++) {
                primeArr[x*i]=0;
            }
        }
    }
    
    int cnt = 1;
     for (int i = 2; i<=maxNumber; i++) {
         if(primeArr[i]){
             printf("%d\t",i);
             if(cnt%5==0){
                        printf("\n");
             }
             cnt++;
         }
    }
    
}
//利用指针类型的数据交换a b 的值
void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

//动态内存分配
void dynamicMemoryDistribute(){
    int arrLength;
    printf("请输入想要构建的数组长度\n");
    scanf("%d",&arrLength);
    int *p = (int *)malloc(arrLength*sizeof(int));
    for (int i = 0; i<arrLength; i++) {
        p[i]=i;
    }
    
    for (int i = 0; i<arrLength; i++) {
        printf("arr[%d]=%d\n",i,p[i]);
    }
    
    //释放malloc虚拟的内存空间 malloc申请的内存空间是以字节为单位的
    free(p);
}

//这个macos执行结果十分巨大 不知道为什么 134209100MB
void calculateMaxMallocDynamicMemorySize(){
    void *p;
    int cnt = 0;
    while ((p=malloc(100*1024*1024))){
        cnt++;
    }
    printf("程序一共申请了%d00M内存\n",cnt);
    
}
