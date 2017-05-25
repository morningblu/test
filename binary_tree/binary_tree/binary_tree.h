//
//  binary_tree.h
//  binary_tree
//
//  Created by 顾浩 on 23/5/17.
//  Copyright © 2017 顾浩. All rights reserved.
//

#ifndef binary_tree_h
#define binary_tree_h

#include <stdio.h>

typedef char* ElemType;

typedef struct node{
    struct node *left;
    struct node *right;
    ElemType elem;
}Node;

//Insert A New Node
void Add_Node(Node **root, ElemType elem);

//Preorder A Tree
void Preorder(Node *root);

//Inorder A Tree
void Inorder(Node *root);

//Postorder A Tree
void Postorder(Node *root);

#endif /* binary_tree_h */
