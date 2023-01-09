#include<stdio.h>
#include<stdlib.h>
#define size 10
#define coprime 5
int arr[size];
void init()
{
    for(int i=0;i<size;i++)
    {
        arr[i]=-1;
    }
}
void insert(int value)
{
    for(int i=0;i<size;i++)
    {
        int key=value % 11;
        if(arr[key]==-1)
        {
            arr[key]=value;
            printf("%d inserted at arr[%d]\n",value,key);
            break;
            
        }
        else
        {
            for(int i=0;i<size;i++)
            {
                int key1=value % coprime;
                int key_final=key+i*key1;
                if(arr[key_final]==-1)
                {
                    arr[key_final]=value;
                    printf("%d inserted at arr[%d]\n",value,key_final);
                    break;
                }
            }
        }
    }
}
void print()
{
    for(int i=0;i<size;i++)
    {
        printf("arr[%d]=%d\n",i,arr[i]);
    }
}
int main()
{
    init();
    int choice,val;
    while(1)
    {
        printf("1.Insert\t 2.Display \t3.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the value:");
                scanf("%d",&val);
                insert(val);
            break;
            case 2: print();
            break;
            case 3:exit(0);
            break;
            default:printf("Invalid choice\n");
        }
    }
    return 0;
}