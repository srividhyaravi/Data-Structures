#include<stdio.h>
#include<ctype.h>
#define SIZE 20
int s[SIZE];
int top=-1;
void push(int ele)
{
    if(top==(SIZE-1))
    {
        printf("stack overflow\n");
    }
    else
        {
            top=top+1;
    s[top]=ele;

    }
}
int pop()
{
    if(top==-1)
    {
        printf("stack underflow\n");
    }
    else{
    return s[top--];
    }
}

void main()
{
    char postfix[SIZE];
    int op1,op2;
    char ch;
    printf("entr postfix expr\n");
    scanf("%s",postfix);
    for(int i=0;postfix[i]!='\0';i++)
    {
        ch=postfix[i];
        if(isdigit(ch))
        {
            push(ch-48);
        }
        else
            {
                op2=pop();
        op1=pop();
        switch(ch)
        {
            case '+': push(op1+op2);
            break;
            case '-':push(op1-op2);
            break;
            case '*':push(op1*op2);
            break;
            case '/':if(op2==0)
            {
                printf("division by zero error\n");
            }
            else
                {
                    push(op1/op2);
                }
                break;
        }
            }
    }
    printf("valu is:%d",s[top]);
}













