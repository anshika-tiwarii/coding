#include <stdio.h>
#include <stdlib.h>
int main(){
    struct node{
        int data;
        struct node *next;
    };
    struct node *head,*newnode,*temp;
    head=0;
    int choice=1,count=0;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            temp=head=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("do you want to create another node?(0 or 1):  ");
        scanf("%d",&choice);
    }
    temp=head;
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
        count++;
    }
    printf("\ntotal number of nodes in the LL are: %d",count);

    }
    













