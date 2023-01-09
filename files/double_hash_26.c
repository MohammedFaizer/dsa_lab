#include<stdio.h>
#include<stdlib.h>
#define size 10
int hash[size];
void initialise()
{
    for(int i=0;i<size;i++)
    {
        hash[i]= -1;
    }

}
void insert()
{
    int value,i;
    printf("Enter a value to be inserted in hash table\n");
    scanf("%d",&value);
    int key=value%11;
    if(hash[key]==-1)
    {
        hash[key]=value;
        printf("Insert success at first instance\n");
        for(i=0;i<size;i++)
        {
            printf("hash[%d] = %d\n",i,hash[i]);
        }
    }
    
    else
    {
        printf("Collision occured\n");    
        int h2=value%5;
        for(int i=0;i<size;i++)
        {
        int key_new=(key+(i*h2))%10;
        if(hash[key_new]==-1)
        {
            hash[key_new]=value;
            printf("Success\n");
            break;
        }
        printf("collision occurred %d\n",i);
        }
        
        

    }

}
void display()
{
    for(int i=0;i<size;i++)
    {
        printf("hash[%d] = %d\n",i,hash[i]);
    }
}
void main()
{
    initialise();
    int choice;
    while(1)
    {
    printf("1.Insert \t 2.Display \t3.Exit\n");
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        insert();
        break;
    case 2:
        display();
        break;
    case 3:
        exit(0);
        break;
    default:
        printf("Enter a valid choice\n");
        break;
    }
    }

}