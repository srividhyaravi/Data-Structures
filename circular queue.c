#include<stdio.h>
#define SIZE 2
int front=-1;
int rear=-1;
int q[SIZE];
void insert(int ele)
{
    if(rear==SIZE-1&&front==0||front==rear+1)
    {
        printf("queue is full");

    }
    else
    {    if(rear==SIZE-1&&front!=0)
            {
                rear=-1;
            }
        if (front==-1)
        front=0;
        q[++rear]=ele;
    }
}
void delette()
{    int del;
    if(front==-1&&rear==-1)
    {
        printf("queue is empty");
    }
    else
        {
            del=q[front++];
            printf("delete ele:%d\n",del);
           if(front==rear+1)
           front= rear=-1;

            if(front==SIZE)
            {
                front=0;
            }

        }
}

void display()
{
    if(front==-1&&rear==-1)
    {
        printf("queue is empty");
    }

    else
    {   if(front<=rear){
        for(int i=front;i<=rear;i++)
        {
            printf("%d\n",q[i]);

        }
    }
    else
        {
            for(int i=front;i<SIZE;i++)
                printf("display ele:%d",q[i]);
            for(int i=0;i<=rear;i++)

               printf("display ele:%d",q[i]);


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

