#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tagListNode
{
    int value;
    struct tagListNode *next;
}ListNode;

void list_insert(ListNode **head,ListNode **tail,ListNode *p)
{
    if((*head)==NULL){
        *head=p;
		*tail=p;
        return;
    }

	(*tail)->next=p;
	*tail=(*tail)->next;
}

bool ifloop(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;

    while(fast) {
        if(fast == slow){
            return true;
        }

        if(fast->next){
            fast=fast->next->next;
            slow = slow->next;
        } else {
            return false;
        }
    }

    return false;
}

void list_print(ListNode *head)
{
    ListNode *p=head;
    while(p){
        printf("%d\t",p->value);
        p=p->next;
    }
    printf("\n");
    return;
}

int main()
{
    int a[]={1,2,3,4,5,6,7};
    int len= sizeof(a)/ sizeof(int);
    ListNode *head=NULL,*tail=NULL;

    for(int i=0;i<len;i++){
        ListNode *p=(ListNode *)malloc(sizeof(ListNode));
        p->value=a[i];
        p->next=NULL;
        list_insert(&head,&tail,p);
    }
    list_print(head);

    bool flag = false;
    flag = ifloop(head);
    if(flag) {
        printf("loop exists\n");
    }
    else {
        printf("No loop\n");
    }

    /* create a loop */
    tail->next=head;
    flag = false;
    flag = ifloop(head);
    if(flag) {
        printf("loop exists\n");
    }
    else {
        printf("No loop\n");
    }

    tail->next=head;

	
	return 0;
}
