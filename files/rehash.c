#include<stdio.h>
#include<stdlib.h>
float load=0.0;
float def_load=0.75;
void print(int n,int ptr[])
{
    for (int i = 0; i < n; ++i) 
    {
        printf("key[%d] = %d\n",i,ptr[i]);
    }
}
void rehash(int n,int ptr1[],int ptr[])
{
    int k=n;
    n=2*n;  
    ptr=(int*)realloc(ptr,n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        ptr[i]=-1;
    }
    for(int i=0;i<k;i++)
    {
        if(ptr1[i]!=0)
        {
        // printf("%d\n",ptr1[i]);
        for(int j=0;j<n;j++)
        {
        
            int val = ptr1[i]%n;   
            int key = (val+j)% n;
                if(ptr[key]==-1)
                {
                    ptr[key]=ptr1[i];
                    break;
                }
        }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("key[%d] = %d\n",i,ptr[i]);
    }
    
    
    
}
int main()
{
    int *ptr,*ptr1,n=8,n1=8,i,choice,val;
    int value;
    float load_fac=0.0;
    ptr=(int*)calloc(n,sizeof(int));
    ptr1=(int*)calloc(n,sizeof(int));
    if(ptr==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    else
    {
        for(i=0;i<n;i++)
        {
            ptr[i]=-1;
        }
        while(1)
        {
        printf("1.Insert\t3.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the value to be inserted \n");
            scanf("%d",&value);
            for(int i=0;i<n;i++)
            {
              int val = value%n;   
              int key = (val+i)% n;
                if(ptr[key]==-1)
                {
                    ptr[key]=value;
                    ptr1[key]=value;
                    load=load+1;
                    printf("Success\n");
                    break;
                }
            }
            load_fac=load/n;
            printf("Load =%.2f\n ",load);
            printf("Load factor=%.2f\n",load_fac);
            print(n,ptr);
            if(load_fac>def_load)
            {
                printf("Rehashing will be done...!\n");
                rehash(n,ptr1,ptr);
                // n=2*n;  
                // ptr=(int*)realloc(ptr,n*sizeof(int));
                // for(i=0;i<n;i++)
                // {
                //     ptr[i]=-1;
                // }
                // for(int j=0;j<n;j++)
                // {
                //   for(int i=0;i<n1;i++)
                //   {
                //      if(ptr1[i]!=-1)
                //       {
                //      int val = ptr1[i]%n;   
                //       int key = (val+i)% n;
                //     if(ptr[key]==-1)
                //     {
                //         ptr[key]=ptr1[i];
                    
                //        }
                //        }
                //   }
                // }
          
               
            }
            break;
            case 2:
            print(n,ptr);
            break;
            case 3:
            exit(0);
            break;
            default:
            printf("Invalid Choice\n");
        }
    }
    }
    return 0;
}
