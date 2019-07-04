#include<stdio.h>
int g(int n1,int n2);
void main()
{

    int a,b,lcm;
    int n1,n2;
    printf("enter two numbers\n");
    scanf("%d%d",&n1,&n2);
    printf("gcd is %d:\n",g(n1,n2));
    a=n1;
    b=n2;
    lcm=(a*b)/g(n1,n2);
    printf("lcm is %d:\n",lcm);
}
int g(int n1,int n2)
{
    if(n2 ==0)
    return n1;
    else
        return g(n2,n1%n2);
}






