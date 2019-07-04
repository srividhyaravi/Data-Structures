#include<stdio.h>
#include<ctype.h>
#define SIZE 50
int top=-1;
char s[SIZE];
void push(char ch,int *top,char s[])
{
    if(*top==(SIZE-1))
    {
        printf("stack overflow");
    }
    else
    {
        ++(*top);
    s[*top]=ch;
    }
}

char pop(int *top,char s[])
{ char del;
    if(*top==-1)
    {
        printf("stack underflow\n");

    }


        del=s[*top];
        (*top)--;
        return del;

    }


int priority(char symbol)
{
    switch(symbol)
    {
        case '#': return 0;

        case '(': return 1;

        case '+':
        case '-': return 2;

        case '*':
        case '/':return 3;


    }
}
 void infixtopostfix(char infix[],char postfix[])
 {
     int i=0;
     int j=0;
     char symbol;
     push('#',&top,s);
     while((symbol=infix[i++])!='\0')
     {
         if(symbol=='(')
         {
             push(symbol,&top,s);
         }
        else if(symbol==')')
         {
             while(s[top]!='(')
             postfix[j++]=pop(&top,s);
             pop(&top,s);
         }
       else  if(isalnum(symbol))

       {
           postfix[j++]=symbol;

       }
       else
        {
            while(priority(s[top])>=priority(symbol))
            postfix[j++]=pop(&top,s);
            push(symbol,&top,s);

        }
     }
        while(s[top]!='#')
        {
            postfix[j++]=pop(&top,s);
            postfix[j]='\0';
        }
     }

 void main()
 {
     char infix[SIZE],postfix[SIZE];
     printf("enter valid expression\n");
     scanf("%s",infix);
     infixtopostfix(infix,postfix);
     printf("postfix expr:%s\n",postfix);
 }










