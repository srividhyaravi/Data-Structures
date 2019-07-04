#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *next;
    struct node *prev;
    int data;
}*head=NULL,*tail=NULL,*newnode=NULL,*searchptr=NULL,*ptr,*after,*before;


 void print()
 {
     if(head==NULL)
     {
         printf("no node to print\n");
     }
     else
     {
         ptr=head;
         while(ptr!=NULL)
         {
             printf("data:%d\n",ptr->data);
             ptr=ptr->next;
         }
     }
 }

 void createnode()
 {
     newnode=(struct node *)malloc(sizeof(struct node));
     int data;
     newnode->prev=NULL;
     newnode->next=NULL;
     printf("enter data\n");
     scanf("%d",&data);
     newnode->data=data;
 }
 void insertbegin()
 {
    if(head==NULL)
    {
        createnode();
        head=newnode;
        tail=head;
    }
    else
        {
            createnode();
           newnode->next=head;
           head->prev=newnode;
           head=newnode;
        }
 }

 void insertend()
 {
     if(head==NULL)
     {  createnode();
        head=newnode;
        tail=head;
     }
     else
     {    createnode();
         tail->next=newnode;
         newnode->prev=tail;
         tail=newnode;
     }
 }

 struct node * searchpointer(int data)
 {
   if(head==NULL)
        printf("no node to print");
   else
    {
        searchptr=head;
        while(searchptr!=NULL)
        {
            if(searchptr->data==data)
                return searchptr;
            else
                searchptr=searchptr->next;
        }
    }
 }

 void insertafter()
 {
     if(searchptr==tail)
        insertend();
     else
     {   before=searchptr->next;
         createnode();
         searchptr->next=newnode;
         newnode->prev=searchptr;
         newnode->next=before;
         before->prev=newnode;
     }
 }

 void insertbefore()
 {
     if(searchptr==head)
        insertbegin();
     else
        {
            createnode();
            after=searchptr->prev;
            after->next=newnode;
            newnode->prev=after;
            newnode->next=searchptr;
            searchptr->prev=newnode;
        }
 }

 void deleteanywhere()
 {
     if(searchptr==head)
     {
         head=head->next;
         head->prev=NULL;
         free(searchptr);
     }

  else if(searchptr==tail)
     {
         tail=tail->prev;
         tail->next=NULL;
         free(searchptr);
     }

     else
     {
         before=searchptr->next;
         after=searchptr->prev;
         after->next=before;
         before->prev=after;
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


































