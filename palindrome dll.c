#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *next;
    struct node *prev;
    char c;
}*head=NULL,*tail=NULL,*newnode=NULL,*ptr=NULL;


void print()
 {
     struct node *temp;
      temp=head;
      printf("\n\n\t");
      while(temp != NULL) // traverse list & print volue
      {
           printf("%c",temp->c);
           temp=temp->next;
      }
 }

 void insert(char c)
 {
     struct node *temp;
      temp=head;
      newnode=(struct node*)malloc(sizeof(struct node));  // allocating space node dynamicaly
      newnode->c=c;
      if(head == NULL)
      {
           head=newnode;
           tail=head;
           head->prev=NULL;
           head->next=NULL;
      }
      else
      {
           tail->next=newnode;
           newnode->prev=tail;
           tail=tail->next;
           tail->next=NULL;
      }
 }

 void check(int m) // funtion check our requrement
 {
      struct node *p1,*p2;
      p1=head;
      p2=tail;
      while(m/2 > 0)
      {
           if(p1->c == p2->c)
           {
                p1=p1->next;
                p2=p2->prev;
           }
           else
           {
           printf("\n\n\t not a palidrome :???");
           exit(0);
        }
        m--;
      }
      printf("\n\n\t it is palidrome !!!!");
 }

 void main()
 {
    char arr[20];
      int m,i;
      printf("\n enter string to check :");
      scanf("%s",&arr);
      m=strlen(arr);    // calculating lenghth of string
      printf("\n length of string is %d",m);
      for(i=0;i<m;i++)
      {
           insert(arr[i]); // creating a double ling list with each node containning a single char
      }
      print();
      check(m);
 }




