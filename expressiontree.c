#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef struct node
{
  char info;
  struct node* llink;
  struct node* rlink;
}node;

/*void display(node * root,int spaces)
{
    if(root!=NULL)
    {
    int i;
    display(root->rlink, spaces );
    for( i = 0; i < spaces; i++ )
    printf(" ");
    printf("%c\n",root->info);
    display(root->llink, spaces  );
    return;
    }
}*/
void inorder(node *tree)
{
if(tree!=NULL)
{
inorder(tree->llink);
printf("%c\t",tree->info);
inorder(tree->rlink);
}
}
node * create_tree(char postfix[])
{
  node * st[20];
  int i,k;
  for(i=k=0;postfix[i]!='\0';i++)
  {
    node * nn=(node *)malloc(sizeof( node));
    nn->rlink=nn->llink=NULL;
    nn->info=postfix[i];
    if(isdigit(postfix[i]))
    {
      st[k++]=nn;
    }
    else
    {
      nn->rlink=st[--k];
      nn->llink=st[--k];
      st[k++]=nn;
    }
  }
  return st[--k];
}
int eval(node * root)
{
  int num;
  switch(root->info)
  {
    case '+':return eval(root->llink) + eval(root->rlink);
    case '-':return eval(root->llink) - eval(root->rlink);
    case '*':return eval(root->llink) * eval(root->rlink);
    case '/':return eval(root->llink) / eval(root->rlink);
    case '$':return pow(eval(root->llink),eval(root->rlink));
    case '^':return pow(eval(root->llink),eval(root->rlink));
    default:
     /* if(isalpha(root->info))
      {
        printf("%c=",root->info);
        scanf("%d",&num);
        return num;
      }
      else
      {*/
        return root->info-'0';
      }
  }
//}
int main()
{
  char postfix[40];
  int res;
  node * root=NULL;
  printf("enter the postfix expression\n");
  scanf("%s",postfix);
  root=create_tree(postfix);
  printf("the expression tree is \n");
  //display(root,1);
  inorder(root);
  printf(" \n");
  res=eval(root);
  printf("result:%d\n",res);
}
