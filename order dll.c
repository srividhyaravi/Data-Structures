#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node * prev,*next;
}node;
node * head =NULL,*tail = NULL,*temp = NULL,*ptr=NULL,*after = NULL;
void create(int data)
{
  temp = (node *)malloc(sizeof(node));
  temp->prev = NULL;
  temp->next = NULL;
  temp->data = data;
}
void insert(int data)
{
  if(head==NULL)//when there is new node
  {
    create(data);
    head = temp;
    tail = head;
  }
  else if(tail->data<data)//when the data entered is greater than last element.i.e, greatest element compare to all node.Then you must add that element at end
  {
    create(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }
  else if(head->data>data)//smallest element among all must me head
  {
    create(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
  else
  {
    ptr = head;
    while(ptr->data<data)//In between the nodes
     ptr = ptr->next;
    create(data);
    after = ptr->prev;
    after->next = temp;
    temp->prev = after;
    temp->next = ptr;
    ptr->prev = temp;
  }
}
void display()
{
  ptr = head;
  while(ptr!=NULL)
  {
    printf("%d\n",ptr->data);
    ptr = ptr->next;
  }
}
void main()
{
  int ch,data;
  for(;;){
    printf("1.Insert\n");
    printf("2.Display\n");
    printf("3.Exit\n");
    printf("Enter choice\n");
    scanf(" %d",&ch);
    switch(ch)
    {
      case 1:
       printf("Enter data\n");
       //fflush(stdin);
       scanf(" %d",&data);
       insert(data);
       break;
      case 2:
          printf("list is :\n");
        display();
        break;
      case 3:
        exit(0);
      default:
        printf("Wrong choice\n");
    }}
}
