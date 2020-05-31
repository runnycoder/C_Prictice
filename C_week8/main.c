//
//  main.c
//  C_week8
//
//  Created by runny on 2020/5/31.
//  Copyright © 2020 runny. All rights reserved.
//  位操作练习

struct U0{
    unsigned int leading : 3;
    unsigned int FLAG1 : 4;
    unsigned int FLAG2 : 4;
    unsigned int trailing : 21;
};

#include <stdio.h>
void printBinaryUnsignedInt(unsigned int s);
int main(int argc, const char * argv[]) {
    // insert code here...
//    unsigned int s = 0xAAAAAAAA;
//    printBinaryUnsignedInt(s);
    struct U0 uu;
    uu.leading = 2;
    uu.FLAG1 = 15;
    uu.FLAG2 = 15;
    uu.trailing = 0;
    printf("sizeof(uu)=%lu\n",sizeof(uu));
    printBinaryUnsignedInt(*(int *)&uu);
    return 0;
}

//用二进制的形式输出无符号int数值
void printBinaryUnsignedInt(unsigned int s){
    unsigned int mask = 1u<<31;
    do {
        printf("%d",s&mask?1:0);
    } while (mask>>=1);
    printf("\n");
   
}
