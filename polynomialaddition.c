#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int a,b,c;
     struct node *next;

}node;

node * head,*newnode,*ptr;

node * createnode()
{
    newnode=(node *)malloc(sizeof(node ));
    newnode->next=NULL;
    return newnode;
}

void insert()
{
    newnode=createnode();
    printf("enter polynomial of the form ax^2+ bx +c=0\n");
    printf("enter coefficient of x^2: ");
    scanf("%d",&newnode->a);
    printf("enter coefficient of x: ");
    scanf("%d",&newnode->b);
    printf("enter the constant vale:  ");
    scanf("%d",&newnode->c);

     if(head==NULL)
     {
         head=newnode;
         return;
     }
     ptr=head;
     while(ptr->next!=NULL)
     {
         ptr=ptr->next;
     }
     ptr->next=newnode;
}

void sum()
{
    int a=0,b=0,c=0;
    if(head==NULL)
    {
        printf("no polynomial to print");
        return;
    }
    ptr=head;
    while(ptr!=NULL)
    {
        a+=ptr->a;
        b+=ptr->b;
        c+=ptr->c;
        ptr=ptr->next;
    }
    printf("the expression is :%dx^2 + %dx +%d=0\n",a,b,c);
}

void main()
{
    int ch;
    while(1)
    {
        printf("enter 1.add new expression ,2.display the sum, 3.exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:insert();
            break;
            case 2: sum();
            break;
            case 3:exit(0);
        }

    }

}

































