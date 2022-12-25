#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
struct node
{
               int data;
               struct node *next;
};
struct node *head[TABLE_SIZE]={NULL},*c;
void insert()
{
    int i,key;
    printf("\nenter a value to insert into hash table\n");
    scanf("%d",&key);
    i=key%TABLE_SIZE;
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->next = NULL;
    if(head[i] == NULL)
        head[i] = newnode;
    else
    {
        c=head[i];
        while(c->next != NULL)
        {
           c=c->next;
        }
        c->next=newnode;
    }
}
void search()
{
    int key,index;
    printf("\nenter the element to be searched\n");
    scanf("%d",&key);
    index=key%TABLE_SIZE;
    if(head[index] == NULL)
        printf("\n Search element not found\n");
    else
    {
        // for(c=head[index];c!=NULL;c=c->next)
        c=head[index];
        while(c!=NULL)
        {
            if(c->data == key)
                {
                    printf("search element found\n");
                    break;
                }
                c=c->next;
        }
        if(c==NULL)
            printf("\n Search element not found\n");
   
    }
}

void display()
{
    int i;
    for(i=0;i<TABLE_SIZE;i++)
          {
           printf("\nentries at index %d\n",i);
               if(head[i] == NULL)
               {
               printf("No Hash Entry");
               
               }
               else
               {
                c=head[i];
                while(c!=NULL)
                {
                    printf("%d->",c->data);
                    c=c->next;
                }
                            //   for(c=head[i];c!=NULL;c=c->next)
                            //   printf("%d->",c->data);
               }
          }
         
}
void main()
{
    int opt,val,i;
    while(1)
    {
        printf("\nPress 1. Insert\t 2. Display \t3. Search \t  \t5.Exit \n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            //     case 4:
            //      printf("Enter the value to be deleted:");
            // scanf("%d",&val);
            // del(val);
                
                // break;
            case 5:exit(0);
            default:
            printf("Invalid choice\n");
                                           
        }
    }
}