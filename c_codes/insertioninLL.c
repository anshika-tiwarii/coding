#include <stdio.h>
#include <stdlib.h>
struct node{
        int data;
        struct node *next;
    };
    struct node *head,*newnode,*temp;
void insertatbeginning(struct node **head){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data ");
    scanf("%d",&newnode->data);
    newnode->next=*head;
    *head=newnode;
    temp=*head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void insertatend(struct node **head ){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    temp=*head;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=newnode;
    temp=*head;
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void insertaftergivenpos(struct node **head){
    int i=1;
    newnode=(struct node*)malloc(sizeof(struct node));
    int pos;
    printf("enter position ");
    scanf("%d",&pos);
    temp=*head;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    printf("enter data ");
    scanf("%d",&newnode->data);
    newnode->next=temp->next;
    temp->next=newnode;
    temp=*head;
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    head=NULL;
    
    
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
    do{
    temp=head;
    count=0;
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
        count++;
    }
    printf("\ntotal number of nodes in the LL are: %d",count);
    printf("do you want to add more nodes to the list?(0 or 1): ");
    scanf("%d",&choice);
    if(choice){
        int choice2;
        do{
            printf("choose where you want to insert the node\n");
            printf("1.at the beginning\n");
            printf("2.at the end\n");
            printf("3.after a position given by you\n");
            printf("4.Kam hogaya? Ab nahi dalna kuch -_- ? \n");
            scanf("%d",&choice2);
            switch(choice2){
                case 1:
                {
                    insertatbeginning(&head);
                    break;
                }
                case 2:
                {
                    insertatend(&head);
                    break;
                }
                case 3:
                {
                    insertaftergivenpos(&head);
                    break;
                }
                case 4:
                {
                    printf("ok byeeee!\n");
                    break;
                }
                default:
                printf("Invalid choice!Please try again.\n");
                

            }

        }while(choice);

    }
    }while(choice);
    return 0;

}
    













