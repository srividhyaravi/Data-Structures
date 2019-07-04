#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node * right;
  struct node * left;
}node;
node * create()
{
  int x;
  printf("Enter the data(-1 for  null)\n");
  scanf("%d",&x);
  if(x==-1)
   return NULL;
  node * p = (node *)malloc(sizeof(node));
  p->data = x;
  p->left = NULL;
  p->right = NULL;
  printf("Enter left child of %d\n",x);
  p->left = create();
  printf("Enter right child of %d\n",x);
  p->right = create();
  return p;
}
void preorder(node * t)
{
  if(t!=NULL)
  {
    printf("%d\t",t->data);
    preorder(t->left);
    preorder(t->right);
  }
}
void inorder(node * t)
{
  if(t!=NULL)
  {
    inorder(t->left);
    printf("%d\t",t->data);
    inorder(t->right);
  }
}
void postorder(node * t)
{
  if(t!=NULL)
  {
    postorder(t->left);
    postorder(t->right);
    printf("%d\t",t->data);
  }
}
node * search(node * t,int x)
{
  node * found = NULL;
  if(t==NULL)
   return NULL;
  if(t->data==x)
    return t;
  found = search(t->left,x);
  if(found)
    return found;
  found = search(t->right,x);
   if(found)
    return found;

    return NULL;
}
void main()
{
  node * root = NULL;
  int ch,key;
  printf("1.insert\n 2.inorder\n 3.preorder\n 4.postorder\n 5,search\n 6.exit");
  while(1){
  printf("\nEnter choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:
     root = create();break;
    case 2:
     inorder(root); break;
    case 3:
      preorder(root);break;
    case 4:
      postorder(root);break;
    case 5:
      printf("Enter element to search\n");
      scanf("%d",&key);
      node * find = search(root,key);
      if(find!=NULL)
        printf("Data found\n");
    else
      printf("Data not found");
      break;
    case 6:
      exit(0);
    default:
      printf("wrong choice\n");
  }
}
}
