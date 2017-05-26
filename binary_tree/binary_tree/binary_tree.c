//
//  binary_tree.c
//  binary_tree
//
//  Created by 顾浩 on 23/5/17.
//  Copyright © 2017 顾浩. All rights reserved.
//

#include "binary_tree.h"
#include <stdlib.h>
#include <string.h>

//Insert A New Node
void Add_Node(Node **root, ElemType elem)
{
    if((*root) == NULL) {
        (*root) = (Node *)malloc(sizeof(Node));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->elem = elem;
        return;
    }
    
    if(strcmp((*root)->elem, elem) > 0) {
        Add_Node(&(*root)->left, elem);
    }
    else {
        Add_Node(&(*root)->right, elem);
    }
}

//Preorder A Tree
void Preorder(Node *root)
{
    if(!root) {
        return;
    }
    
    printf("%s\t", root->elem);
    Preorder(root->left);
    Preorder(root->right);
    
    return;
}

//Inorder A Tree
void Inorder(Node *root)
{
    if(!root) {
        return;
    }
    
    Inorder(root->left);
    printf("%s\t", root->elem);
    Inorder(root->right);
}

//Postorder A Tree
void Postorder(Node *root)
{
    if(!root) {
        return;
    }
    
    Postorder(root->left);
    Postorder(root->right);
    printf("%s\t", root->elem);
}


//Get the Depth of binary tree
int get_tree_depth(Node *root)
{
	if(root == NULL) {
		return 0;
	}

	int left = 0, right = 0;
	left = get_tree_depth(root->left);
	right = get_tree_depth(root->right);

	return left > right ? left + 1 : right + 1;
}


