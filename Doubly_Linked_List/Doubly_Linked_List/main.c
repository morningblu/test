//
//  main.c
//  Doubly_Linked_List
//
//  Created by 顾浩 on 25/5/17.
//  Copyright © 2017 顾浩. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int main()
{
    ElemType data[] = {3,5,1,2,4,10,6};
    List *lList = NULL;
    unsigned long uLoop = 0;    //counter for loop
    unsigned long length = sizeof(data)/sizeof(ElemType);
    
    lList = (List *)malloc(sizeof(List));
    if(!lList) {
        return 1;   //malloc failed
    }
    else {
        init_list(lList);
    }
    
    while(uLoop < length) {
        Node *pNew = init_node(data[uLoop]);
        insert_node(lList, pNew);
        uLoop++;
    }
    
    traverse_list(lList);
    
    /*
    Node *pNew = lList->head;
    ElemType del_elem = data[1];    //delete a node owning data[1]
    int flag = DELETE_FAILED;
    
    for(uLoop = 0; uLoop < length; uLoop++) {
        //delete a node owning data[1]
        if(pNew->elem != del_elem) {
            pNew = pNew->pNext;
        }
        else {
            //Found The Node
            delete_node(lList, pNew);
            flag = DELETE_SUCCESSED;
            break;
        }
    }
    
    if(flag == DELETE_SUCCESSED) {
        printf("Found the Node\n");
        traverse_list(lList);
        return DELETE_SUCCESSED;
    }
    else {
        return DELETE_FAILED;
    }
    */
    reverse_list(lList);
    traverse_list(lList);
    
    return 0;
}
