#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head=NULL;
void addfirst(int no)
{
    struct node* newnode;
    struct node* tail=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        newnode->data=no;
        newnode->prev=NULL;
        newnode->next=NULL;
        head=newnode;
        tail=newnode;
        printf("First Node inserted\n");
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        printf("Inserted\n");
    }
    
}


void print(struct node* head)
{
    while(head!=NULL)
    {
        printf("%d-->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
int main()
{
   int val,choice,no;
   while(1)
   {
        printf("1.Insert at beginning\n 2.Insert at last\n 3.Insert at nth location\n 4.Insert after element\n 5.Insert before element\n 6.exit\n Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
            {
                case 1:
                    printf("Enter the element to be added:");
                    scanf("%d",&val);
                    addfirst(val);
                    print(head);
                    break;
                // case 2:
                //     printf("Enter the element to be added at last:");
                //     scanf("%d",&val);
                //     addlast(val);
                //     print(head);
                //     break;
                // case 3:
                //      printf("Enter the value to be inserted:");
                //      scanf("%d",&no);
          
                //     printf("Enter the nth position to add:");
                //     scanf("%d",&val);
                //     addat(no,val);
                //     print(head);
                //     break;
                // case 4:
                //  printf("Enter the value to be inserted:");
                //      scanf("%d",&no);
          
                //     printf("Enter the element after to be added:");
                //     scanf("%d",&val);
                //     addafter(no,val);
                //     print(head);
                //     break;
                //     case 5:
                //     printf("Enter the value to be inserted:");
                //     scanf("%d",&no);
                //     printf("Enter the element to be added before:");
                //     scanf("%d",&val);
                //     insert_before(no,val);
                //     print(head);
                //     break;
                    case 6:
                    exit(0);
                    break;
                default:
                    printf("Wrong choice\n");
            }
   }
    return 0;
}