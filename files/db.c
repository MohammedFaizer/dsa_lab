#include<stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10
#define PRIME 5
int arr[TABLE_SIZE];
void init()
{
    for(int i=0;i<TABLE_SIZE;i++)
    {
        arr[i]=-1;
    }
}
int h1(int key) {
  return (key % TABLE_SIZE);
}

int h2(int key) {
  return (PRIME - (key % PRIME));
}

void insert(int key) {
  if (size == TABLE_SIZE)
    return;

  int idx = h1(key);

  if (hash_table[idx] != -1) {
    int idx2 = h2(key);
    int i = 1;
    while (1) {
      int newidx = (idx + i * idx2) % TABLE_SIZE;

      if (hash_table[newidx] == -1) {
        hash_table[newidx] = key;
        break;
      }
      i++;
    }
  } else
    hash_table[idx] = key;
  size++;
}
void print()
{
for(int i=0;i<TABLE_SIZE;i++)
    {
        printf("arr[%d]=%d\n",i,arr[i]);
    }
}

int main() {
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
            for (int i = 0; i < 10; i++) {
             scanf("%d",&val);
                insert(val);
                 }
                
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