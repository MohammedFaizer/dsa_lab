#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node *head=NULL;
struct node *tail=NULL;
void ins_que()
{
    int num;
    printf("Enter the element to be inserted:");
    scanf("%d",&num);
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        newnode->data=num;
        newnode->prev=NULL;
        newnode->next=NULL;
        head=newnode;
        tail=newnode;
        printf("First value inserted\n");
    }
    else
    {
        newnode->data=num;
        newnode->prev=tail;
        tail->next=newnode;
        newnode->next=NULL;
        tail=newnode;
        printf("Inserted\n");
    }
}
void del_que()
{
    struct node* temp=head;
    if(head==NULL)
    {
        printf("Empty\n");
    }
    else
    {
        if(head==tail)
        {
            free(head);
            head=NULL;
            tail=NULL;
        }
        else
        {
        printf("Deleted element:%d",temp->data);
        head=head->next;
        head->prev=NULL;
        free(temp);
        }
    }
}
void peek()
{
    if(head==NULL)
    {
        printf("---Underflow---\n");
    }
    else
    {
        printf("Top element:%d",head->data);
    }
}
void search_que()
{
    int search_no,index=0,count=0;
    struct node* temp=head;
    printf("Enter the element to be searched:");
    scanf("%d",&search_no);
    if(head==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        while(temp!=NULL)
        {
            index+=1;
            
            if(temp->data==search_no)
            {
                printf("Element found at index:%d\n",index);
                count+=1;
            }
            temp=temp->next;
        }
        printf("Element found:%d",count);
    }
}
void display()
{
    struct node* temp;
    temp=head;
    if(head==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Elements present:\n");
        while(temp!=NULL)
        {
           
            printf("address of node:%p\n",temp);
            printf("address of previous:%p\n",temp->prev);
            printf("node data:%d\n",temp->data);
            printf("address of next:%p\n",temp->next);
            printf("\n");
            temp=temp->next;
        }
        
    }
    
}
int main()
{
        int choice;
        printf("\nQueue Implementation using Doubly Linked list\n");
        printf("\n1.Insert\t 2.Delete\t 3.Search\t 4.Display\t 5.peek\t 6.Exit\n");
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
            printf("Invalid Choice\n");
        }
        main();
    
    return 0;
}