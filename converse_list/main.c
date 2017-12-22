#include <stdio.h>
#include <stdlib.h>

typedef struct tagListNode
{
    int value;
    struct tagListNode *next;
}ListNode;

void list_insert(ListNode **head,ListNode *p)
{
    if((*head)==NULL){
        *head=p;
        return;
    }

    ListNode *tmp=*head;
    while(tmp->next){
        tmp=tmp->next;
    }
    tmp->next=p;
}

void list_insert2(ListNode **head,ListNode *p)
{
    p->next=*head;
    *head=p;
}

void list_converse(ListNode **head)
{
    ListNode *prev=NULL;

    while(*head){
        ListNode *p=(*head)->next;
        (*head)->next=prev;
        prev=*head;
        *head=p;
    }
    *head=prev;
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
    ListNode *head=NULL,*head2=NULL;

    for(int i=0;i<len;i++){
        ListNode *p=(ListNode *)malloc(sizeof(ListNode));
        p->value=a[i];
        p->next=NULL;
        list_insert(&head,p);
    }
    list_print(head);

    for(int i=0;i<len;i++){
        ListNode *p=(ListNode *)malloc(sizeof(ListNode));
        p->value=a[i];
        p->next=NULL;
        list_insert2(&head2,p);
    }
    list_print(head2);

    list_converse(&head);
    list_print(head);

    return 0;
}