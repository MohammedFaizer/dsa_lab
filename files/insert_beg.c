#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void addFirst( int val)
{    
      if(head==NULL)
      {
        struct node *newNode = malloc(sizeof(struct node));
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        printf("This is first element inserted\n");
      }
      else
      {
        struct node *newNode = malloc(sizeof(struct node));
        newNode->data = val;
        newNode->next = head;
        head = newNode;
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
    printf("\nLinked List- Insertion at beginning\n");
    while (1)
    {
        printf("1.INSERT\n 2.EXIT\n ");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
           printf("Enter the element to be inserted:");
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