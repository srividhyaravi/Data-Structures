#include<stdio.h>

 void tower(int n,char source,char temp,char dest)
{
    if(n==1)
    {
        printf("move disk %d from %c to %c\n ",n,source,dest);
    }
    else
    {
        tower(n-1,source,dest,temp);
    printf("move disk %d from %c to %c\n",n,source,dest);

    tower(n-1,temp,source,dest);

}
}
void main()
{
    int n;
    printf("enter the no of disks\n");
    scanf("%d",&n);
    tower(n,'A','B','C');
}
