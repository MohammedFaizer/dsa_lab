#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* front=0;
struct node* rear=0;
void enqueue()
{
    int num;
    printf("Enter the value to be inserted:");
    scanf("%d",&num);
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=0;
    if(rear==0)
    {
        front=rear=newnode;
        rear->next=front;
        printf("First value inserted\n");
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
        printf("Inserted\n");
    }
}
void dequeue()
{
    struct node* temp;
    temp=front;
    if(front==0)
    {
        printf("No elements to delete\n");
    }
    else
    {
        if(front==rear)
        {
        front=rear=0;
        free(temp);
        printf("Emptied\n");
        }
        else
        {
        printf("Deleted element:%d",temp->data);
        front=front->next;
        rear->next=front;
        free(temp);
         }
    }
    
    
    
}
void search()
{
    int search_no,index=0,flag=0;
    struct node* temp=front;
    printf("Enter the element to be searched:");
    scanf("%d",&search_no);
    if(front==0 && rear==0)
    {
        printf("Underflow\n");
    }
    else
    {
        while(temp->next!=front)
        {
            index+=1;
            if(temp->data==search_no)
            {
                printf("Element found at index:%d\n",index);
                
                flag=1;
            }
           
            temp=temp->next;
        }
        if(temp->data==search_no)
            {
                printf("Element found at index:%d\n",index+1);
                flag=1;
                
            }
        if(flag==0)
        {
        printf("Not found\n");
        }
    }
}
void ins_after()
{
    if(front==0 && rear==0)
    {
        printf("Empty\n");
        enqueue();
    }
    else
    {
        int num,after;
        printf("Enter the element after to be inserted:");
        scanf("%d",&after);
        printf("Enter the element to be inserted:");
        scanf("%d",&num);
        struct node *ptr,*preptr,*newnode,*p;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        ptr=front;
        preptr=ptr;
         if(front->data==after)
            {
                p=front->next;
                front->next=newnode;
                newnode->next=p;
                printf("added success\n");
            }
            else
            {
        while(preptr->data!=after)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
       
            preptr->next=newnode;
            newnode->next=ptr;
            printf("value added\n");
           
            }

    }

}
void ins_before()
{
    if(front==0 && rear==0)
    {
        printf("Empty\n");
        
    }
    else
    {
        int num,before;
        printf("Enter the element before to be inserted:");
        scanf("%d",&before);
        printf("Enter the element to be inserted:");
        scanf("%d",&num);
        struct node *ptr,*preptr,*newnode,*p,*temp;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        ptr=front;
        preptr=ptr;
        
        while(ptr->data!=before)
            {
                preptr=ptr;
                ptr=ptr->next;
            }
        
                preptr->next=newnode;
                newnode->next=ptr;
                printf("value added\n");
       
       
            
                
    }
   
}
void display()
{
    struct node* temp;
    temp=front;
    if(front==0 && rear==0)
    {
        printf("Empty\n");
    }
    else
    {
        printf("Elements present are:\n");
        while(temp->next!=front)
        {
            printf("Address of node:%p\t",temp); 
            printf("%d\t",temp->data);    
            printf("Address of next:%p",temp->next); 
            printf("\n");      
            temp=temp->next;
        }
             printf("Address of node:%p\t",temp); 
            printf("%d\t",temp->data);
            printf("Address of next:%p",temp->next);   
            printf("\n");    
    }
}
int main()
{
    int choice;
    printf("\n1.Enqueue\t2.Dequeue\t3.Display\t4.Search\t5.Insert after element\t6.Insert before element\t7.exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        enqueue();
        break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        case 4:
        search();
        break;
        case 5:
        ins_after();
        break;
        case 6:
        ins_before();
        break;
        case 7:
        exit(0);
        break;
        default:
        printf("Invalid Choice");
    }
    main();
    return 0;
}