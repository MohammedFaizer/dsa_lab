#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max],n,front=-1,rear=-1;
void enqueue()
{
    int val;
    if(rear==max-1)
    {
        printf("Queue overflow\n");
    }
    else
    {
        if((front==-1)&&(rear==-1))
        {
            front+=1;
            printf("Enter the value to inserted:");
            scanf("%d",&val);
            rear+=1;
            queue[rear]=val;
            printf("First value inserted\n");
        }
        else
        {
            printf("Enter the value to inserted:");
            scanf("%d",&val);
            rear+=1;
            queue[rear]=val;
            printf("Value inserted\n");
        }
    }
}
void dequeue()
{
     if((front==-1)||(front>rear))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Element deleted:%d",queue[front]);
        front+=1;
    }

}
void search()
{
    int no,flag=0,pos=1;
    printf("Enter the element to be searched:");
    scanf("%d",&no);
     if((front==-1)||(front>rear))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            if(queue[i]==no)
            {
            printf("Element found at index:%d",pos);
            flag=1;
            }  
            pos++; 
        }
        if(flag==0)
        {
        printf("Element not found\n");
        }
    }
}
void peek()
{
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Top element in queue:%d",queue[front]);
        
    }
}
void display()
{
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Elements in queue\n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);

            
        }
    }
}
int main()
{
    int choice;
    while(1)
    {
    printf("\n\tQueue Operations using Array\n");
    printf("\t------------------------------\n");
    printf("\t 1.Enqueue \t 2.Dequeue \t3.Display\t4.Search\t5.peek\t6.Exit\n");
    printf("Enter your Choice\n");
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
        peek();
        break;
        case 6:
        exit(0);
        break;
        default:
        printf("Wrong choice\n");

    }
    }
    return 0;
}