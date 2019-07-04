#include<stdio.h>
int binsch(int a[],int low,int high,int m)
{ int mid;
 if(low>high)
    return -1;

         mid=(low+high)/2;
     if(a[mid]==m)
        return mid;
    else if (a[mid]>m)
     return binsch(a,low,mid-1,m);
        else
        return binsch(a,mid+1,high,m);
    }

void main()
{
    int a[10],i,j,n,x,flag;
    printf("enter the size of array\n");
    scanf("%d",&n);
    printf("enter the elements of array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
     for(i=0;i<n;i++)
        for(j=0;j<n-1-i;j++)
        if(a[j]>a[j+1])
     {
         int temp=a[j];
         a[j]=a[j+1];
         a[j+1]=temp;
     }
     printf("enter the elemnt to be searched\n");
     scanf("%d",&x);
     flag=binsch(a,0,n,x);
     if(flag==-1)
        printf("elemnt not found\n");
     else
        printf("element found at %d\n",flag+1);
}
