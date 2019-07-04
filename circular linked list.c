#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL,*newnode=NULL,*searchptr=NULL,*ptr;

void print()
{
    if(head==NULL)
    {
        printf("there is no node to print");
    }else
    {   ptr=head;
        while(ptr->next!=head)
        {    printf("data = %d\n",ptr->data);
            ptr=ptr->next;
        }
        printf("data = %d\n",ptr->data);
    }
}
int count=0;
void createnode()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    int data;
    printf("enter data\n");
    scanf("%d",&data);
    newnode->data=data;
    count++;
}

void insertbegin()
{
    if(head==NULL)
    {
        createnode();
        head=newnode;
        newnode->next=head;
    }
    else
    {
        createnode();
        ptr=head;
        while(ptr->next!=head)
            ptr=ptr->next;
       newnode->next=head;
       head=newnode;
       ptr->next=head;
    }
}
void insertend()
{
    if(head==NULL)
    {
        createnode();
        head=newnode;
        newnode->next=head;
    }
    else
    {
        createnode();
        ptr=head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
           ptr->next=newnode;
        newnode->next=head;
    }
}

struct node * searchpointer(int data)
{
     if(head==NULL)
            printf("no node present");
    else
     {     if(head->data==data)
        return head;
         ptr=head->next;
         while(ptr!=head)
         {
             if(ptr->data==data)
                return ptr;
                else
                   ptr=ptr->next;
             }
             return NULL;
    }
}

void insertafter()
{
    if(searchptr->next==head)
        insertend();
    else
    {
       createnode();
       newnode->next=searchptr->next;
       searchptr->next=newnode;
    }
}

void insertbefore()
{
    if(searchptr==head)
        insertbegin();
    else
        {
            ptr=head;
           while(ptr->next!=searchptr)
            ptr=ptr->next;
           createnode();
           ptr->next=newnode;
           newnode->next=searchptr;
        }
}

void deleteanywhere()
{
    if(searchptr==head)
    {
        ptr=head;
        while(ptr->next!=head)
            ptr=ptr->next;
        head=head->next;
        ptr->next=head;
        free(searchptr);
    }
    else
    {
        ptr=head;
        while(ptr->next!=searchptr)
          ptr=ptr->next;
        ptr->next=searchptr->next;
        free(searchptr);
    }
}

void options()
{
    printf("1.insert begin\n");
    printf("2.insert end\n");
    printf("3.insert after\n");
    printf("4.insert before\n");
    printf("5.delete\n");
    printf("6.exit\n");
}
void main()
{
    int ch,data;
    options();

    while(1)
    {
     printf("enter choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: insertbegin();
                print();
                break;
        case 2: insertend();
                print();
                break;
        case 3: printf("enter data to search\n");
                scanf("%d",&data);
                searchptr=searchpointer(data);
                if(searchptr!=NULL)
                    {
                        insertafter();
                        print();
                    }
                else
                    printf("data not found");
                break;

        case 4:  printf("enter data to search\n");
                scanf("%d",&data);
                searchptr=searchpointer(data);
                if(searchptr!=NULL)
                    {
                        insertbefore();
                        print();
                    }
                else
                    printf("data not found");
                break;

         case 5:  printf("enter data to delete\n");
                scanf("%d",&data);
                searchptr=searchpointer(data);
                if(searchptr!=NULL)
                    {
                        deleteanywhere();
                        print();
                    }
                else
                    printf("data not found");
                break;
                case 6: exit(0);
    }
}

}















































































