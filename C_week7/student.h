//
//  student.h
//  C_Prictice
//
//  Created by runny on 2020/5/31.
//  Copyright © 2020 runny. All rights reserved.
//

#ifndef student_h
#define student_h
const int NAME_STR_LENGTH=20;
typedef struct student{
    char name[NAME_STR_LENGTH];
    int gender;
    int age;
}Student;

#endif /* student_h */
