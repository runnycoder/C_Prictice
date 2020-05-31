//
//  main.c
//  C_week7
//
//  Created by runny on 2020/5/31.
//  Copyright © 2020 runny. All rights reserved.
//
//二进制文件的读写
#include <stdio.h>
#include "student.h"
#include <string.h>

void getStudentList(Student students[],int studentNum);
void readFile(FILE *fr ,int index);
int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("请输入学生的数量!\n");
//    int num;
//    scanf("%d",&num);
//    Student stu[num];
//    getStudentList(stu, num);
//    if(save(stu, num)){
//        printf("读入数据保存成功!\n");
//    }else{
//        printf("读入数据保存失败!\n");
//    }
//    
    //读取报文的文本数据
//    FILE * fr = fopen("student.data",   "rs");
//    if(fr){
//        fseek(fr, 0L, SEEK_END);
//        long fileSize = ftell(fr);
//        int readNum =  fileSize/sizeof(Student);
//        int index = 0;
//        printf("文件中共有%d个Student结构体数据,你想看第几个?\n",readNum);
//        scanf("%d",&index);
//        readFile(fr, index-1);
//        fclose(fr);
//
//    }    
    
    return 0;
}

//根据输入的数量读取结构体数据
void getStudentList(Student students[],int studentNum){
    char nameStr[NAME_STR_LENGTH];
    sprintf(nameStr,"%%%ds",NAME_STR_LENGTH-1);
    int i;
    for (i=0; i<studentNum; i++) {
        printf("请输入第%d个学生的信息!",i+1);
        printf("\t姓名:\n");
        scanf(nameStr,students[i].name);
        printf("\t性别:\n");
        scanf("%d",&students[i].gender);
        printf("\t年龄:\n");
        scanf("%d",&students[i].age);
    }
}
//保存读取的结构体信息到文件中
int save(Student stu[],int number){
    int ret = -1;
    FILE * fw = fopen("student.data",   "w");
    if(fw){
        ret = fwrite(stu, sizeof(Student), number, fw);
        fclose(fw);
    }
    return ret==number;
}
//根据指定的位置读取保存的结构体数据
void readFile(FILE *fr ,int index){
    fseek(fr, index*sizeof(Student), SEEK_SET);
    Student stu;
    if(fread(&stu, sizeof(Student), 1, fr)==1){
        printf("第%d个学生",index+1);
        printf("\t姓名:%s\n",stu.name);
        printf("\t性别:%d\n",stu.gender);
        printf("\t年龄:%d\n",stu.age);
    }
}
