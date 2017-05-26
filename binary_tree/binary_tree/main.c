//
//  main.c
//  binary_tree
//
//  Created by 顾浩 on 23/5/17.
//  Copyright © 2017 顾浩. All rights reserved.
//

#include <stdio.h>
#include "binary_tree.h"

int main(int argc, const char * argv[])
{
    ElemType aName[] = {"grace", "hao", "shawn", "alice", "cindy", "luna", "ray"};
    //ElemType aName[] = {5, 4, 2, 10, 6, 9, 3};
    Node *root = NULL;
    
    for(unsigned long iLoop = 0; iLoop < sizeof(aName)/sizeof(ElemType); iLoop++)
    {
        Add_Node(&root, aName[iLoop]);
    }
    
    Preorder(root);
    printf("\n");
    Inorder(root);
    printf("\n");
    Postorder(root);
    
	int depth = 0;

	depth = get_tree_depth(root);
	printf("%d\n",depth);
    return 0;
}
