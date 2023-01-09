#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head=NULL;
void dll_beg()
{

}
int main()
{
    int choice;
    printf("Doubly Linked list\n");
    while(1)
    {
        printf("\n1.Insert at beginning \t 2.Display\t 3.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            dll_beg();
            break;
            case 2:
            display();
            break;
            case 3:
            exit(0);
            break;
            default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}