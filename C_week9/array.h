//
//  array.h
//  C_Prictice
//
//  Created by runny on 2020/6/1.
//  Copyright © 2020 runny. All rights reserved.
//

#ifndef array_h
#define array_h
typedef struct {
    int *array;
    int size;
}Array;

Array array_create(int init_size);
void array_free(Array *arr);
int array_size(const Array *arr);
int* array_at(Array *arr,int index);
void array_set(Array *arr,int index,int number);
int array_get(const Array *arr,int index);
void array_inflate(Array *arr,int more_size);

#endif /* array_h */
