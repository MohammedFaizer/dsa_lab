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
void delfirst()
{
if (head==NULL)
{
    printf("Underflow");
}
else
{
    struct node* ptr;
    ptr=head;
    head=head->next;
    free(ptr);
    
}
}
void dellast()
{
if (head==NULL)
{
    printf("Underflow");
}
else
{
    struct node* ptr;
    struct node* preptr;
    ptr=head;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    
}
}
// void del_before(int before)
// {
//      if(head==NULL)
//     {
//         printf("Can't be done\n");
//     }
//     else
//     {
//             struct node * ptr;
//                 struct node * preptr;
//                 struct node * temp;
//               ptr=head;
//         preptr=ptr;
//         while(ptr->data!=before)
//         {
//             preptr=ptr;
//             ptr=ptr->next;
//         }
//         temp=ptr;
//         preptr->next=ptr;
//         free(temp);
//     }
// }
void del_before(int before) 
{ 
	struct node *t,*t2,*t3; 
	t=head; 
	if(before==head->data) 
	{ 
		printf("node cannot be deleted\n"); 
	} 
	else 
	{ 
		if(before==head->next->data) 
		{ 
			t3=head; 
			head=head->next; 
			free(t3); 
		} 
		else 
		{ 
			while(t->next->next->data!=before && t->next->next!=NULL) 
			{ 
				t=t->next; 
			} 
			if(t->next->next->data==before) 
			{ 
				t2=t->next; 
				t->next=t->next->next; 
				free(t2); 
			} 
		} 
	} 
} 

void delafter(int after)
{
    if(head==NULL)
    {
        printf("Can't be done\n");
    }
    else
    {
            struct node * ptr;
                struct node * preptr;
                struct node * temp;
        
        ptr=head;
        preptr=ptr;
        while(preptr->data!=after)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        temp=ptr;
        preptr->next=ptr->next;
        free(temp);
    }
}
void delat(int p)
{
 struct node* temp=head;
 struct node* temp2;
 if ((p==1)&&(temp!=NULL))
 {
   struct node* temp=head;

    if(head == NULL)
        printf("Stack is Empty\n");
    else
    {
        temp =head;
        head=head->next;
        free(temp);
    }
 }
 else{
    for (int i = 1; i < p-1; i++)
    {
        temp=temp->next;
    }
    if (temp!=NULL)
    {
      temp2=temp->next;
      temp->next=temp2->next;
      free(temp2);
       printf("value is deleted .\n");
    }
    else
    {
        printf("Sorry desired position is not present\n");
    }
    
 }
 
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
        printf("\n0.Insert\n 1.Delete at beginning\n 2.Delete at last\n 3.Delete at nth location\n 4.Delete after element\n 5.Delete before element\n 6.exit\n Enter the choice:");
        scanf("%d",&choice);
        switch(choice)
            {
                case 0:
                 printf("Enter the element to be added:");
                    scanf("%d",&val);
                    addfirst(val);
                    print(head);
                break;
                case 1:
                    delfirst();
                    print(head);
                   break;
                case 2:
                    dellast();
                     print(head);
                  break;
                 case 3:
                  printf("Enter the nth position to delete:");
                  scanf("%d",&val);
                delat(val);
                  print(head);
                   break;
                 case 4:
          
                     printf("Enter the element after to be deleted:");
                     scanf("%d",&val);
                     delafter(val);
                     print(head);
                     break;
                 case 5:
                    printf("Enter the element to be  deleted before:");
                     scanf("%d",&val);
                     del_before(val);
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