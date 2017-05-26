//
//  doubly_linked_list.c
//  Doubly_Linked_List
//
//  Created by 顾浩 on 26/5/17.
//  Copyright © 2017 顾浩. All rights reserved.
//

#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

//Initialzie A List
void init_list(List *lList)
{
    lList->head = lList->tail = NULL;
    lList->length = 0;
}

//Initialzie A New Node
Node *init_node(ElemType elem)
{
    Node *pNew = (Node *)malloc(sizeof(Node));
    
    if(!pNew) {
        return NULL;
    }
    
    pNew->elem = elem;
    pNew->pNext = NULL;
    pNew->pPrev = NULL;
    
    return pNew;
}

//insert a node
void insert_node(List *lList, Node *pNew)
{
    if(lList->length == 0) {
        lList->head = lList->tail = pNew;
        lList->head->pNext = pNew;
        lList->head->pPrev = pNew;
        lList->tail->pNext = pNew;
        lList->tail->pPrev = pNew;
        lList->length++;
        return;
    }
    
    pNew->pNext = lList->head;
    pNew->pPrev = lList->tail;
    lList->head->pPrev = pNew;
    lList->tail->pNext = pNew;
    lList->head = pNew;
    lList->length++;
    return;
}

//delete a node
void delete_node(List *lList, Node *pNew)
{
    pNew->pPrev->pNext = pNew->pNext;
    pNew->pNext->pPrev = pNew->pPrev;
    lList->length--;
    
    if(pNew == lList->head) {
        lList->head = pNew->pNext;
    }
    else if(lList->tail == pNew) {
        lList->tail = pNew->pPrev;
    }
    
    free(pNew);
}

//reverse a linked list
void reverse_list(List *lList)
{
    Node *pNew = lList->head;
    Node *pTmp = NULL;
    unsigned long length = lList->length;
    
    //exchange pointers of pre with next
    while(length > 0) {
        pTmp = pNew->pNext;
        pNew->pNext = pNew->pPrev;
        pNew->pPrev = pTmp;
        pNew = pNew->pNext;
        length--;
    }
    
    //exchange head with tail
    lList->head = pNew->pNext;
    lList->tail = pNew->pPrev;
}

static void swap_node(Node *p1, Node *p2)
{
    p1->pNext = p2->pNext;
    p2->pPrev = p1->pPrev;
    p1->pPrev->pNext = p2;
    p2->pNext->pPrev = p1;
}

//Sort A Linked List
void bubble_sort_list(List *lList)
{
    
}

//Traverse A Linked List
void traverse_list(List *lList)
{
    Node *pNew = lList->head;
    unsigned long length = lList->length;
    
    while(length > 0) {
        printf("%d\n", pNew->elem);
        pNew = pNew->pNext;
        length--;
    }
}

