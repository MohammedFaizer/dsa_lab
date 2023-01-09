#include<stdio.h>
#include<string.h>
struct book
{
    int isbn;
    char bookname[20];
    char bookauthr[20];
    int year,copies;
};
struct book b[20];
void issuebook(int n)
{
    int isbn,flag=0,i=0;
    printf("Enter the isbn of the book:\n");
    scanf("%d",&isbn);
    for(i=0;i<n;i++)
    {
        if(b[i].isbn==isbn)
        {
            b[i].copies--;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("wrong isbn no entered\n");
    }
    if(flag==1)
    {
        printf("No of copies has been updated to %d\n",b[i].copies);
    }
}
void returnbook(int n)
{
    int isbn,flag=0,i;
    printf("Enter the isbn of the book:\n");
    scanf("%d",&isbn);
    for(i=0;i<n;i++)
    {
        if(b[i].isbn==isbn)
        {
            b[i].copies++;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Wrong isbn no entered\n");
    }
    if(flag==1)
    {
        printf("No of copies has been updated to %d\n",b[i].copies);
    }
}
void listbook(int n)
{
    int i,year=0,flag=0;
    printf("Enter the year:\n");
    scanf("%d",&year);
    for(i=0;i<n;i++)
    {
        if(b[i].year==year)
        {
            printf("ISBN:%d",b[i].isbn);
            printf("\t Book name:%s",b[i].bookname);
            printf("\t Book Author:%s",b[i].bookauthr);
            printf("\t Copies:%d",b[i].copies);
            printf("\t Year:%d",b[i].year);
            printf("\n");
        }
    }
}
void listallbook(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("ISBN:%d",b[i].isbn);
        printf("\t Book name:%s",b[i].bookname);
        printf("\t Book Author:%s",b[i].bookauthr);
        printf("\t Copies:%d",b[i].copies);
        printf("\t Year:%d",b[i].year);
        printf("\n");
    }
}
void listcopies(int n)
{
    char name[20];
    int i=0,result;
    printf("Enter the name of the book:\n");
    scanf("%s",name);
    for(i=0;i<n;i++)
    {
        result=strcmp(name,b[i].bookname);
        if(result==0)
        {
            printf("Number of copies:%d\n",b[i].copies);
        }
    }
}
int main()
{
    int n,ch;
    printf("Enter number of books to be added to library\n");
    scanf("%d",&n);
    printf("-------------\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter the isbn no of the book \n");
        scanf("%d",&b[i].isbn);
        printf("Enter the name of the book\n");
        scanf("%s",b[i].bookname);
        printf("Enter the name of author\n");
        scanf("%s",b[i].bookauthr);
        printf("Enter the year of publication of book\n");
        scanf("%d",&b[i].year);
        printf("Enter the total no of copies of book\n");
        scanf("%d",&b[i].copies);
    }
    for(int i=0;i<n;i++)
    {
        printf("ISBN:%d",b[i].isbn);
        printf("\t Book name:%s",b[i].bookname);
        printf("\t Book Author:%s",b[i].bookauthr);
        printf("\t Copies:%d",b[i].copies);
        printf("\t Year:%d",b[i].year);
        printf("\n");
    }
    while(ch!=0)
    {
        printf("\n");
        printf("Enter 0 to exit\n");
        printf("Enter 1 to issue a book to a member\n");
        printf("Enter 2 to accept a book from member\n");
        printf("Enter 3 to list books based on year of publication\n");
        printf("Enter 4 to list all the books\n");
        printf("Enter 5 to search copies of a book by name\n");
        scanf("%d",&ch);
        if(ch==0)
        printf("Thank you...!");
        else if(ch==1)
        issuebook(n);
        else if(ch==2)
        returnbook(n);
         else if(ch==3)
        listbook(n);
         else if(ch==4)
        listallbook(n);
         else if(ch==5)
        listcopies(n);
        else
        printf("Enter valid number from above options\n");    
        
    }
}