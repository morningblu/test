//
//  main.c
//  Single_Link
//
//  Created by 顾浩 on 21/5/17.
//  Copyright © 2017 顾浩. All rights reserved.
//

#include <stdio.h>
#include "single_link.h"

int main() {
    int data[] = {1,5,3,10,-6,0,7};
    unsigned long iLoop = 0;
    Node *head = NULL;
    Node *pNew = NULL;
    
    Init_Link(&head);
    
    for(; iLoop < sizeof(data)/sizeof(int); iLoop++) {
        pNew = Init_Node(data[iLoop]);
        Add_Node(head, pNew);
    }
    
    Print_Link(head);
    
    Init_Link(&head);
    Node *pRear = head;
    for(iLoop = 0; iLoop < sizeof(data)/sizeof(int); iLoop++) {
        pNew = Init_Node(data[iLoop]);
        pRear->pNext = pNew;
        pRear = pNew;
    }
    
    Print_Link(head);
    
    return 0;
}
