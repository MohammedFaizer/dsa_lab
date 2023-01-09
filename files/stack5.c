#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int stack[5];
int top=-1;
void push()
{
    char ch;
    printf("Enter a character:\n");
    scanf(" %c",&ch);
    if((isalpha(ch)==0))
    {
        printf("not a character\n");
    }
    else
    {
        top++;
        stack[top]=ch;
        for(int i=top;i>=0;i--)
        {
            printf("%c-->",stack[i]);
        }
    }
}
void pop()
{
    printf("popped element:%c",stack[top]);
    top--;
    printf("after pop\n");
    for(int i=top;i>=0;i--)
        {
            printf("%c-->",stack[i]);
        }

}
int main()
{
    int choice;
    push();
    while(1)
    {
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 2:pop();break;
    }
    }
return 0;
}