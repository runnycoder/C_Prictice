//
//  main.c
//  C_week10
//
//  Created by runny on 2020/6/6.
//  Copyright © 2020 runny. All rights reserved.
//
void beerCalculate();
int isFunded(const int trace[],int currentTraceNumber,int v);
void insertSortAlgorithm(int arr[],int length);
void selectSortAlgorithm(int arr[],int length);
void bubbleSortAlgorithm(int arr[],int length);
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    // insert code here...
//    printf("Hello, World!\n");
//    void greedyAlgorithm();
//    greedyAlgorithm();
//    beerCalculate();
    int arr[5] = {2,3,1,4,5};
//    insertSortAlgorithm(arr, 5);
//    selectSortAlgorithm(arr,5);
    bubbleSortAlgorithm(arr,5);
    for (int i =0; i<5; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}



//贪心算法计算最优路径
/**
 n个城市 记做 v{v0,v1,v2,v3} 任意vi,vj节点之间的距离记做Dij
 求出一个访问顺序，距离最短，且每个节点只访问一次

 */

void greedyAlgorithm(){
    //构造一个二维数组记录地图节点 几点编号为 0 1 2 3 map[i][j]为i到j的距离
    int map[4][4];
    map[0][1]=2;
    map[0][2]=4;
    map[0][3]=5;

    map[1][0]=2;
    map[1][2]=4;
    map[1][3]=4;

    map[2][0]=4;
    map[2][1]=4;
    map[2][3]=2;
    
    map[3][0]=5;
    map[3][1]=4;
    map[3][2]=2;
    
    //两节点最长路径
    const int MAX_LENGTH=5;
    
    //定义数组记录最短轨迹 从v0开始
    int trace[4];
    trace[0]=1;
    //最短距离
    int minDistance=0;
    //当前已经搜索到的城市数
    int currentTraceNumber = 1;
    //当前节点编号
    int preV = 0;

    int v = 1;
    while(v<4)
    {
        //当前节点与下一个节点的最短距离
        int tempV = 0;
        int distance_prev_v = MAX_LENGTH;
        int i = 0;
        while(i<4){//循环搜索与当前节点最近的节点和距离
            if(isFunded(trace,currentTraceNumber,i)!=1){
                if(map[preV][i]<distance_prev_v){
                    distance_prev_v = map[preV][i];
                    tempV = i;
                }
            }
            i++;
        }
        
        trace[currentTraceNumber]=tempV;
        minDistance+=distance_prev_v;
        currentTraceNumber++;
        preV=tempV;
        v++;
    }
    
    printf("贪心算法计算所得最短路径为: ");
    for (int i = 0; i<4; i++) {
        printf("V%d=%d, ",i,trace[i]);
    }
    printf("\n");
    printf("最短距离minDistance=%d\n",minDistance);
    
    
}
//判断城市编号是否已经在轨迹列表中
int isFunded(const int trace[],int currentTraceNumber,int v){
    int funded = 0;
    for (int i = 0 ;i<currentTraceNumber; i++) {
        if(trace[i]==v){
            funded = 1;
        }
    }
    return funded;
}

//有1000瓶啤酒，每喝完一瓶得到一个空瓶子，每3个空瓶子又能换1瓶啤酒，喝掉以后又得到一个空瓶子。问总共能喝多少瓶啤酒?还剩多少空瓶子”
void beerCalculate(){
    int beerBattle = 0;
    int beerDrink = 0;
    int n = 1000;
    int cnt = 1;
    while(n>0){
        if(cnt%3==0){
            n++;
            beerBattle-=3;
        }
        cnt++;
        beerBattle++;
        beerDrink++;
        n--;
    }
    printf("总共能喝%d瓶啤酒,还剩%d个空瓶子\n",beerDrink,beerBattle);
}

//排序算法练习
//1 插入排序
void insertSortAlgorithm(int arr[],int length){
    int i;
    for (i=1; i<length; i++) {
        int currentNumber = arr[i];
        int j = i-1;
        while (j>=0&&arr[j]>currentNumber) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=currentNumber;
    }
    
}

//2 选择排序
void selectSortAlgorithm(int  arr[],int length){
    int i;
    for (i=0; i<length; i++) {
        
        int k =i;
        for (int j = i+1; j<5; j++) {
            if(arr[j]<arr[i]){
                k=j;
            }
        }
        if(i!=k){
            int temp = arr[i];
            arr[i]=arr[k];
            arr[k]=temp;
        }
    
    }

    
    
}

//3 冒泡排序
void bubbleSortAlgorithm(int  arr[],int length){
    int i;
    for (i=0; i<length; i++) {
        int isChange = 0;
        for (int j = 0; j<length-i; j++) {
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                isChange=1;
            }
        }
        if(isChange==0){
            break;
        }
    }
}
