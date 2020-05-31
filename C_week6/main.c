//
//  main.c
//  C_week6
//
//  Created by runny on 2020/5/29.
//  Copyright © 2020 runny. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "max.h"
#define cube(x)((x)*(x))
#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))

int globalVariable = 10;

int main(int argc, const char * argv[]) {
    // insert code here...
//    void fuc(void);
//    fuc();
//    fuc();
//    fuc();
//    printf("cube(%d)=%d\n",5,cube(5));
    
//    char chr[100];
//    strcpy(chr, "abcd");
//    int i = 0;
//    ++i;
//    printf("%d\n",i);
//    char a = TOUPPER(chr[++i]);
// 替换之后会变成 ('a'<=(char[++i])&&(char[++i])<='z'?(chr[++i])-'a'+'A':(chr[++i]))
//    putchar(TOUPPER(chr[++i]));
    
    int a1 = 2;
    int a2 = 4;
    
    int rs = max(a1, a2);
    printf("max=%d\n",rs);
    return 0;
}

void fuc(){
    int localVariable = 10;
    //静态本地变量的生命周期是全局的但是作用域是本地的
    static int staticLocalVariable = 10;
    printf("in %s globalVariable        is %d\n",__func__,globalVariable);
    printf("in %s localVariable         is %d\n",__func__,localVariable);
    printf("in %s staticLocalVariable   is %d\n",__func__,staticLocalVariable);
    
    printf("in %s globalVariable address        is %p\n",__func__,&globalVariable);
    printf("in %s localVariable address         is %p\n",__func__,&localVariable);
    printf("in %s staticLocalVariable address   is %p\n",__func__,&staticLocalVariable);
    globalVariable++;
    localVariable++;
    staticLocalVariable++;
}
