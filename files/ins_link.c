#include<stdio.h>
#include<stdlib.h>
int pos;
struct node
{
    int data;
    struct node* next;
};
struct node* head=NULL;
void addfirst(int no)
{
    struct node* new;
    new=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        new->data=no;
        new->next=head;
        head=new;
        printf("First Node inserted\n");
    }
    else
    {
        new->data=no;
        new->next=head;
        head=new;
        printf("Inserted\n");
    }
    
}

void addlast(int no)
{
    struct node* last;
    last=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        last->data=no;
        last->next=head;
        head=last;
        printf("First Node inserted---\n");
    }
    else
    {
        struct node* temp;
        last->data=no;
        last->next=NULL;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=last;
        printf("Inserted at last\n");
    }
}
void addafter(int value,int after)
{
    if(head==NULL)
    {
        printf("Can't be done\n");
    }
    else
    {
            struct node * ptr;
                struct node * preptr;
        struct node * new_node;
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data=value;
        ptr=head;
        preptr=ptr;
        while(preptr->data!=after)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=new_node;
        new_node->next=ptr;
    }
// struct node * new_node;
//    struct node *tmp = head;
//    while(tmp) {
//       if(tmp->data == after) { /*found the node*/
//          new_node = (struct node *)malloc(sizeof(struct node));
//          if (head == NULL) {
//             printf("Out of memory");
//             return;
//          }
//          new_node->data = value;
//          new_node->next = tmp->next;
//          tmp->next = new_node;
//          //printf("success");
//       }
//       tmp = tmp->next;
//    }
}

void insert_before(int value, int before){
     if(head==NULL)
    {
        printf("Can't be done\n");
    }
    else
    {
            struct node * ptr;
                struct node * preptr;
        struct node * new_node;
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data=value;
        ptr=head;
        preptr=ptr;
        while(ptr->data!=before)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=new_node;
        new_node->next=ptr;
    }
//    struct node * new_node = NULL;
//    struct node * tmp = head;
//    new_node = (struct node *)malloc(sizeof(struct node));
//    if (head == NULL){
//       printf("Out of memory");
//       return;
      
//    }
//    new_node->data= value;
//    if(head->data == before){
//       new_node->next = head;
//       head = new_node;
      
//    }
//    while(tmp && tmp->next) {
//       if(tmp->next->data == before) {
//          new_node->next = tmp->next;
//          tmp->next = new_node;
      
//       }
//       tmp = tmp->next;
//    }
//    /*Before node not found*/
//    free(new_node);
}

void addat(int n,int pos)
{
    
 struct node* temp;
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  temp=head;
 if ((pos==1)&&(temp!=NULL))
 {
    newnode->data=n;
    newnode->next=head;
    head=newnode;
    printf("value is inserted and it is the first element.\n");
 }
 else{
    for (int i = 1; i < pos-1; i++)
    {
        temp=temp->next;
    }
    if (temp!=NULL)
    {
        newnode->next=temp->next;
        newnode->data=n;
        temp->next=newnode;
         printf("value is inserted .\n");
    }
    else
    {
        printf("not available\n");
    }
    
 }

        // int count=0,i=1;
        // while(head!=NULL)
        // {
        //    count++;
        //     head=head->next;
        // }
        // if(pos>count||pos<0)
        // {
        //     printf("Invalid Position\n");
        // }
        // else
        // {
        //     struct node* temp;
        //     struct node* new;
        //     temp=(struct node*)malloc(sizeof(struct node));
        //     new=(struct node*)malloc(sizeof(struct node));
        //     temp=head;
        //     while(i<pos)
        //     {
        //         i++;
        //         temp=temp->next;
                
        //     }
        // printf("%d",temp->data);
        // printf("Enter the data:");
        // scanf("%d",&new->data);
        // new->next=temp->next;
        // temp->next=new;
        // printf("Inserted at given location\n");
        // while(head!=NULL)
        // {
        //     printf("%d-->",head->data);
        //     head=head->next;
        // }
        // printf("NULL\n");
        //   }

}
void print(struct node* head)
{
    while(head!=NULL)
    {
        printf("%d-->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
int main()
{
   int val,choice,no;
   while(1)
   {
        printf("1.Insert at beginning\n 2.Insert at last\n 3.Insert at nth location\n 4.Insert after element\n 5.Insert before element\n 6.exit\n Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
            {
                case 1:
                    printf("Enter the element to be added:");
                    scanf("%d",&val);
                    addfirst(val);
                    print(head);
                    break;
                case 2:
                    printf("Enter the element to be added at last:");
                    scanf("%d",&val);
                    addlast(val);
                    print(head);
                    break;
                case 3:
                     printf("Enter the value to be inserted:");
                     scanf("%d",&no);
          
                    printf("Enter the nth position to add:");
                    scanf("%d",&val);
                    addat(no,val);
                    print(head);
                    break;
                case 4:
                 printf("Enter the value to be inserted:");
                     scanf("%d",&no);
          
                    printf("Enter the element after to be added:");
                    scanf("%d",&val);
                    addafter(no,val);
                    print(head);
                    break;
                    case 5:
                    printf("Enter the value to be inserted:");
                    scanf("%d",&no);
                    printf("Enter the element to be added before:");
                    scanf("%d",&val);
                    insert_before(no,val);
                    print(head);
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