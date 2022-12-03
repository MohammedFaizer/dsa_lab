#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void ins_que()
{
    int num;
    printf("Enter the element to be inserted:");
    scanf("%d",&num);
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=rear=newnode;
        printf("First value inserted\n");
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        printf("Value is inserted\n");
    }
}
void del_que()
{
    struct node* temp=front;
    if(front==NULL && rear==NULL)
    {
        printf("Sorry..! Queue underflow\n");
    }
    else
    { 
        printf("Deleted Element:%d",front->data);
        front=front->next;
        free(temp);
    }
}
void search_que()
{
     int search_no,index=0;
     struct  node*temp=front;
     printf("Enter the element to be searched:");
     scanf("%d",&search_no);
     if(front==NULL && rear==NULL)
     {
        printf("Queue underflow\n");
     }
     else
     {
        while(temp!=NULL)
        {
            index+=1;
            if(temp->data==search_no)
            {
            printf("Element found at index:%d",index);
            }
            else
            {
                printf("Element not present in queue please enter a valid input\n");
            }
            temp=temp->next;
        }
    
     }
     
}
void display()
{
    struct node* temp=front;
    if(front==NULL && rear==NULL)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Elements present:");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    }
    
}
void peek()
{
    if(front==NULL && rear==NULL)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Top element:%d",front->data);
    }
}
int main()
{
    int choice;
    printf("Queue implementation using linked list\n");
    while(1)
    {
        printf("\n1.Insert\t 2.Delete \t 3.Search \t 4.Display \t 5.Peek\t 6.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            ins_que();
            break;
            case 2:
            del_que();
            break;
            case 3:
            search_que();
            break;
            case 4:
            display();
            break;
            case 5:
            peek();
            break;
            case 6:
            exit(0);
            break;
            default:
            printf("Invalid choice\n");
        }

    }
    return 0;
}