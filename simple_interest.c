#include<stdio.h>
float simple_int(float p,float r,float t)
{
    float si;
    si=(p*r*t)/100;
    return si;
}
int main()
{
    float a,b,c;
    float interest;
    printf("\n Enter Principal:\t");
    scanf("%f",&a);
    printf("\n Enter the year:\t");
    scanf("%f",&b);
    printf("\n Enter rate:\t");
    scanf("%f",&c);
    interest=simple_int(a,b,c);
    printf("\n Simple Interest=%.2f \n",interest);
    return 0;
}