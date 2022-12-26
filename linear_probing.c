#include<stdio.h>
#include<stdlib.h>
#define size 10
int arr[size];
void init()
{   
    int i;
    for(i = 0; i < size; i++)
    {
        arr[i] = -1;
    }
}
void insert(int value)
{   
    for(int i=0;i<size;i++)
        {
        
        int val=value%10;
            
        int key = (val+i)% size;
        if(arr[key]==-1)
        {
            arr[key]=value;
            printf("Success\n");
            break;
        }
        printf("collision occurred %d\n",i);
        }
         
        
}

void del(int value)
{
    int flag=0;
         for(int i = 0; i < size; i++)
        {
            int key = (value+i)% size;
            if(arr[key] == value)
            {   
                arr[key] = -1;
                flag=1;
                printf("Deleted\n");
                break;
            }
            
            
        }
        if(flag==0)
        {
            printf("Not present in table\n");
        }
    
}

void search(int value)
{
    int flag=0;
         for(int i = 0; i < size; i++)
        {
            int key = (value+i)% size;
            if(arr[key] == value)
            {   
                printf("Search Found at index %d\n",key);
                flag=1;
                break;
            }
            
            
        }
        if(flag==0)
        {
            printf("Not found\n");
        }
    // int key = value % size;
    // if(arr[key] == value)
    //     printf("Search Found\n");
    // else
    //     printf("Search Not Found\n");
}

void print()
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n",i,arr[i]);
    }
}

int main()
{
    init();
    int choice,val;
    while(1)
    {
        printf("1.Insert\t2.Delete\t3.Display\t4.Search\t5.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the value to be inserted:");
            scanf("%d",&val);
            insert(val);
            break;
            case 2:
            printf("Enter the value to be deleted:");
            scanf("%d",&val);
            del(val);
            break;
            case 3:
            print();
            break;
            case 4:
            printf("Enter the value to be searched:");
            scanf("%d",&val);
            search(val);
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}
