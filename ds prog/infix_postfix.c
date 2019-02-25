#include<stdio.h>
#define MAX 50
void display();
int pres(char ope);
void infix_postfix(char str[]);
void push(char elem);
char pop();

int top = -1;
char stack[MAX];
int pres(char ope)
{
    if(ope=='&')
        return 0;
    else if(ope=='(')
        return 1;
    else if(ope==')')
        return 2;
    else if(ope=='+' || ope=='-')
        return 3;
    else
        return 4;
}
void infix_postfix(char str[])
{
    int k=0;
    char ope;
    push('&');
    int len = strlen(str);
    char t_str[len];
    for(int i=0;i<len;i++)
    {
        if(str[i]>=48 && str[i]<=57)
            t_str[k++]=str[i];
        else if(pres(stack[top]) < pres(str[i]) || str[i]=='(')
            push(str[i]);
        else
        {
            while((pres(stack[top]) >= pres(str[i])) && stack[top]!='&')
                t_str[k++] = pop();
            if(str[i]==')')
                ope = pop();
            else
                push(str[i]);
        }

    }
    while(stack[top]!='&')
    {
        t_str[k++]=pop();
    }
    t_str[k]='\0';
    for(int i=0;i<k;i++)
    {
        printf("%c",t_str[i]);
    }
}
void push(char elem)
{
    if(top<MAX-1)
    {
        stack[++top] = elem;
    }
    else
        printf("stack is full\n");
}
char pop()
{
    if(top>-1)
    {
        return stack[top--];
    }
    else
    {
        printf("\nstack is empty");
        return '&';
    }
}

void display()
{
    printf("\nstack is.....\n");
    for(int i=0;i<=top;i++)
    {
        printf("%c ",stack[top]);
    }
}

int main()
{
    int check;
    char str[10];
    while(1)
    {
    printf("press 1 to convert and 2 to exit\n");
    scanf("%d",&check);
    if(check == 2)
        break;
    scanf("%s",str);
    infix_postfix(str);
    }
}
