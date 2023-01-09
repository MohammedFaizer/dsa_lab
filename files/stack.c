#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int stack[5],i,choice,n=5,top=-1;
void push()
{
        char val;
        printf("Enter the charcter:\n");
        scanf("%c",&val);
        if(isalpha(val)==0)
        {
             printf("Not a charcater...! please Enter a valid character\n");
        }
        else
        {
            top++;
            stack[top]=val;
            
        }
    
        
    
}
void occurence()
{
    if(top==-1)
    {
        printf("Stack empty");
    }
    else
    {
        for(i=0;i<n;i++)
        {
            
        }
    }
}
void display()
{
    if(top>=0)
    {
        printf("Stack elements:\n");
        for(i=top;i>=0;i++)
        {
            printf("\n%d",stack[i]);
        }
    }
    else
    {
        printf("Stack Empty\n");
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n stack underflow\n");
    }
    else
    {
        printf("Popped Element:%d",stack[top]);
        top--;
    }
}
int main()
{
while(1)
{    printf("1.push\t 2.pop\t 3.count\t 4.Display \t5.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            push();
            break;
        case 2:
        pop();
        break;
        case 3:
        occurence();
        break;
        case 4:
        display();
        break;
        case 5:exit(0);
        break;
        default:printf("Invalid choice");
    }
}
return 0;
}

