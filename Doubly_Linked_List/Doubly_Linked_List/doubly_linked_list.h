//
//  doubly_linked_list.h
//  Doubly_Linked_List
//
//  Created by 顾浩 on 26/5/17.
//  Copyright © 2017 顾浩. All rights reserved.
//

#ifndef doubly_linked_list_h
#define doubly_linked_list_h

#include <stdio.h>

#define DELETE_SUCCESSED    10
#define DELETE_FAILED       5

typedef int ElemType;

typedef struct node{
    struct node *pPrev;
    struct node *pNext;
    ElemType elem;
}Node;

typedef struct list{
    Node *head;
    Node *tail;
    unsigned long length;
}List;

//Initialzie A List
void init_list(List *lList);

//Initialzie A New Node
Node *init_node(ElemType elem);

//insert a node
void insert_node(List *lList, Node *pNew);

//delete a node
void delete_node(List *lList, Node *pNew);

//reverse a linked list
void reverse_list(List *lList);

//Sort A Linked List
void bubble_sort_list(List *lList);

//Traverse A Linked List
void traverse_list(List *lList);

#endif /* doubly_linked_list_h */
