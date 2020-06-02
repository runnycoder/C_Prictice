//
//  main.c
//  C_week9
//
//  Created by runny on 2020/6/1.
//  Copyright © 2020 runny. All rights reserved.
//  可变类型数组定义

#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "linkList.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    //array define test
//    Array arr = array_create(100);
//    int number=0;
//    int cnt=0;
//    printf("请录入数据 -1代表终止!\n");
//    while (number!=-1) {
//        scanf("%d",&number);
//        if(number!=-1){
//            array_set(&arr, cnt++, number);
//        }
//    }
//    arr.size=cnt;
//    printf("arr size = %d\n",arr.size);
//    for (int i =0; i<arr.size; i++) {
//        printf("arr[%d] = %d\n",i,array_get(&arr, i));
//    }
//    array_free(&arr);
    
    //linked_list define test
    
    List list;
    list.head = NULL;
    
    int number = 0;
    int cnt=0;
    printf("请录入数据 -1代表终止!\n");
    while (number!=-1) {
            scanf("%d",&number);
            if(number!=-1){
                 list_add(&list, number);
                
            }
    }
//    list_print(&list);
    Node * distNode = list_search(&list,2);
    printf("search node value=%d\n",distNode->value);
        return 0;
}
//链表删除操作
void list_destroy(List *pList){
    Node *p = pList->head;
    Node *q = NULL;
    for (; p; p=q) {
        q=p->next;
        free(p);
    }
    
}

//删除指定数值的链表节点
void list_nodeDelete(List *pList,int number){
    Node *p;
    Node *temp;
    //初始化temp->null
    for (temp=NULL,p=pList->head; p; temp=p,p=p->next) {
        if(p->value==number){
            if(temp){
                temp->next=p->next;
            }else{
                pList->head=p->next;
            }
            free(p);
            break;
        }
        
    }

}

Node * list_search(List *pList,int number){
    Node *p;
    for (p=pList->head; p; p=p->next) {
        if(p->value==number){
            printf("Node value=%d\n",p->value);
            break;
        }
        
    }
    return p;
}

void list_print(List *pList){
    Node *p;
    for (p=pList->head; p; p=p->next) {
        printf("Node value=%d\n",p->value);
    }

}

void list_add(List* pList,int number){
       Node *p = (Node *)malloc(sizeof(Node));
       p->value=number;
       p->next=NULL;
       
       Node *last = pList->head;
       if(last){
           while(last->next){
               last = last->next;
           }
           last->next=p;
       }else{
           pList->head = p;
       }
}




