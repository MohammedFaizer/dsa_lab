#include <stdio.h>
#include <stdlib.h>
#define size 7
#define CO_PRIME 5
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
    int i=0;
        for(i = 0; i < size; i++)
        {
            int key = value% size;
            if(arr[key] == -1)
            {   
                arr[key] = value;
                printf("%d inserted at arr[%d]\n", value,key);
                break;
            }
            else
            {
                for(int i=0;i<size;i++)
                {
                    int key1=value%CO_PRIME;
                    int key_final=key+i*key1;
                    if(arr[key_final]==-1)
                    {
                        arr[key_final] = value;
                        printf("%d inserted at arr[%d]\n", value,key_final);
                        break;
                    }
                }

            }
            
        }
    
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
        printf("1.Insert\t2.Display\t3.Exit\n");
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
            print();
            break;
            
            case 3:
            exit(0);
            break;
            default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}