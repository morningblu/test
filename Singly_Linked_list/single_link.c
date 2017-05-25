//
//  single_link.c
//  Single_Link
//
//  Created by 顾浩 on 21/5/17.
//  Copyright © 2017 顾浩. All rights reserved.
//

#include "single_link.h"
#include <stdlib.h>

//initialize a link
void Init_Link(Node **head)
{
    (*head) = (Node *)malloc(sizeof(Node));
    (*head)->pNext = NULL;
}

//Initialize A Node
Node *Init_Node(int elem)
{
    Node *pNew = (Node *)malloc(sizeof(Node));
    
    if(NULL == pNew) {
        exit(MALLOC_FAILED);
    }
    
    pNew->Elem = elem;
    pNew->pNext = NULL;
    
    return pNew;
}

//add a new node from head
void Add_Node(Node *head, Node *pNew)
{
    pNew->pNext = head->pNext;
    head->pNext = pNew;
}

//Add A New Node from Tail
void Add_Node_Tail(Node *pRear, Node *pNew)
{
    pRear->pNext = pNew;
}

//print elements of the link
void Print_Link(Node *head)
{
    Node *p = head->pNext;
    
    while(p){
        printf("%d\t", p->Elem);
        p = p->pNext;
    }
    
}
