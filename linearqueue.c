#include<stdio.h>
#define SIZE 5
int front=-1;
int rear=-1;
int q[SIZE];
void insert(int ele)
{
    if(rear==SIZE-1)
    {
        printf("q is full\n");
    }
    else
    {
    if(front==-1)
        front=0;

    q[++rear]=ele;

}
}
void delette()
{int del;
    if((front==-1&&rear==-1)||(front>rear))
        printf("q is empty\n");
      else
    {
        del=q[front++];
        printf("deleted element is:%d\n",del);

    if(front==rear+1)
    {
        front=-1;
        rear=-1;
    }
}}
 void display()
 {
      if((front==-1&&rear==-1)||(front>rear))
        printf("q is empty\n");
      else
      {
          for(int i=front;i<=rear;i++)
          {
              printf("ele=%d\n",q[i]);
          }
      }
 }
 void main()
 {
     int choice;
     int element;
     while(1)
     {
       printf("1 for insert,2 for delete,3 for display\n");
     printf("enter choice\n");
     scanf("%d",&choice);
     switch(choice)
     {
         case 1: printf("enter ele\n");
         scanf("%d",&element);
         insert(element);
         break;
         case 2: delette();
         break;
         case 3: display();
         break;
     }
 }
 }










