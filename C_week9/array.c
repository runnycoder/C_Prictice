//
//  array.c
//  C_week9
//
//  Created by runny on 2020/6/1.
//  Copyright © 2020 runny. All rights reserved.
//

#include "array.h"
#include <stdlib.h>
const int BLOCK_SIZE=20;
//数组创建
Array array_create(int init_size){
    Array arr;
    arr.size=init_size;
    arr.array = (int*)malloc(sizeof(int)*arr.size);
    
    return arr;
}

void array_free(Array *arr){
    free(arr->array);
    arr->array=NULL;
    arr->size=0;
}

int array_size(const Array *arr){
    return arr->size;
}

int* array_at(Array *arr,int index){
    if(index>=arr->size){//每次扩容BLOCK_SIZE长度单位的空间 (102/20+1)*20-100
        array_inflate(arr, (index/BLOCK_SIZE+1)*BLOCK_SIZE-arr->size);
    }
    return &(arr->array[index]);
}

int array_get(const Array *arr,int index){
    return arr->array[index];
}

void array_set(Array *arr,int index,int number){
    arr->array[index]=number;
};

//数组扩充 重新申请新的空间
void array_inflate(Array *arr,int more_size){
    int * temp =malloc(sizeof(int)*(arr->size+more_size));
    int i;
    for (i=0; i<arr->size; i++) {
        temp[i]=arr->array[i];
    }
    free(arr->array);
    arr->array=temp;
    arr->size+=more_size;
}
