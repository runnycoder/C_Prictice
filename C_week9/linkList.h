//
//  linkList.h
//  C_week9
//
//  Created by runny on 2020/6/1.
//  Copyright © 2020 runny. All rights reserved.
//

#ifndef linkList_h
#define linkList_h

#include <stdio.h>
typedef  struct _node {
    int value;
    struct _node *next;
}Node;

typedef struct _list{
    Node * head;
//    Node * tail;  思考一下拥有头尾指针的链表该怎么定义 头插法 尾插法
}List;
void list_add(List* pList,int number);
void list_print(List *pList);
Node * list_search(List *pList,int number);
#endif /* linkList_h */
