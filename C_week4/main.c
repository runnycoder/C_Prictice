//
//  main.c
//  C_week4
//
//  Created by runny on 2020/5/27.
//  Copyright © 2020 runny. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
//    char * const s = "hello!";
    int myStrLength(char const *s);
//    myStrLength(s);
    
    char s1[10] = "abc";
    char s2[4] = "abb";
    
    
//    int myStrCmp(const char *s1,const char *s2);
//    int interval =  myStrCmp(s1,s2);
//    printf("s1,s2相差%d\n",interval);
//
//    int myStrCmp2(const char *s1,const char *s2);
//    int interval2 = myStrCmp2(s1,s2);
//    printf("s1,s2相差%d\n",interval2);
    
    char* myStrCat(char *dst,const char *src);
    char* temp =  myStrCat(s1,s2);
    printf("temp length=%d,temp=%s\n",myStrLength(temp),temp);
    
    return 0;
}

//自定义字符串处理方法2 计算字符串长度
int myStrLength(char const *s){
    int cnt = 0 ;
    while(s[cnt]!='\0'){
        cnt++;
    }
    printf("字符串长度为%d\n",cnt);
    return cnt;
}
//自定义字符串处理方法 比较两字符串的大小 相等返回0
int myStrCmp(const char *s1,const char *s2){
    int index=0;
    printf("s1[%d]=%d,s2[%d]=%d\n",index,s1[index],index,s2[index]);

    while(s1[index]==s2[index]&&s1[index]!='\0'){
        printf("s1[%d]=%d,s2[%d]=%d\n",index,s1[index],index,s2[index]);
        index++;
    }
    return s1[index]-s2[index];
}

//自定义字符串处理方法 比较两字符串的大小 相等返回0
int myStrCmp2(const char *s1,const char *s2){
    
    
    while(*s1==*s2&&*s1!='\0'){
        printf("s1=%d,s2=%d\n",*s1,*s2);
        s1++;
        s2++;
    }
    return *s1-*s2;
}

//字符串copy src->dst 数组版本
char* myStrCpy(char *dst,const char *src){
    int index = 0;
    while (src[index]!='\0') {
        dst[index]=src[index];
        index++;
    }
    dst[index]='\0';
    return dst;
}

//字符串copy src->dst 指针版本
char* myStrCpy2(char *dst,const char *src){
    
    char *ret = dst;//记录目标指针初始位置
    while (*src) {
        *dst++=*src++;
    }
    *dst='\0';
    return ret;
}

//字符串链接
char* myStrCat(char *dst,const char *src){
    int srcLength =  myStrLength(src);
    while (*src!='\0'){
        dst[srcLength]=*src++;
        srcLength ++;
    }
    dst[srcLength]='\0';
    return dst;
}





