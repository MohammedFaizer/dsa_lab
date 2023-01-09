#include<stdio.h>
struct student
{
    int rollno,tot;
    char name[25];
    int mark[100];
}temp;
void display(struct student s[],int n);
int main()
{
    struct student s1[5];
    int i,n,j;
    printf("Enter the number of students:");
    scanf("%d",&n);
    printf("\t *Students Records*\n");
    for(i=0;i<n;i++)
    {
        printf("\n Enter student roll number:");
        scanf("%d",&s1[i].rollno);
        printf("\n Enter student name:");
        scanf("%s",s1[i].name);
        printf("\n Enter student 3 subject's marks:");
        for(j=0;j<3;j++)
        scanf("%d",&s1[i].mark[j]);
    }
    display(s1,n);
    return 0;
}
void display(struct student s[],int n)
{
    printf("\t *Students Rank list* \n");
    for(int i=0;i<n;i++)
    {
        s[i].tot=0;
        for(int j=0;j<3;j++)
        {
            s[i].tot=s[i].tot+s[i].mark[j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(s[j].tot<s[j+1].tot)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        int k=i+1;
        printf("\n Rank:%d",k);
        printf("\n Student's Roll no-%d",s[i].rollno);
        printf("\n Student's Name-%s",s[i].name);
        printf("\n Student's Total Marks-%d",s[i].tot);
    }
}