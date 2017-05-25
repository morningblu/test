//
//  single_link.h
//  Single_Link
//
//  Created by 顾浩 on 21/5/17.
//  Copyright © 2017 顾浩. All rights reserved.
//

#ifndef single_link_h
#define single_link_h

#define MALLOC_FAILED 10

//Node structure
typedef struct node{
    struct node *pNext;
    int Elem;
}Node;

//initialize a link
void Init_Link(Node **head);

//initialize a node
Node *Init_Node(int elem);

//add a new node from head
void Add_Node(Node *head, Node *pNew);

//add a New Node from Rear
void Add_Node_Tail(Node *pRear, Node *pNew);

//print elements of the link
void Print_Link(Node *head);

#endif /* single_link_h */
