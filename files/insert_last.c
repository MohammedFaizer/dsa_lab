#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void addLast(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    if(head == NULL)
    {
         head = newNode;
         printf("This is the fisrt element inserted");
    }
    else
    {
        struct node *lastNode = head;
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }

}

void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n1.INSERT At END\n 2.EXIT\n ");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
           printf("Enter the element to be inserted at last:");
           scanf("%d",&value);
           addFirst(value);
           printList(head);
           break;
        case 2:
            exit(0);
        default:
            printf("wrong choice\n");
            
        }
    }
    //  addFirst(&head,10);
    //  addFirst(&head,20);
    //  addFirst(&head,30);
    // printList(head);
    return 0;
}