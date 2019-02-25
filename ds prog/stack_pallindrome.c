#include<stdio.h>
#define MAX 10
void pallin(char str[]);
void push(char elem);
char pop();
char stack[MAX];
int top = -1;

void push(char elem)
{
    if(top<MAX-1)
    {
        stack[++top]=elem;
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
        printf("\nstack is empty\n");
    return 1;
}
void pallin(char str[])
{
    int len = strlen(str);
    int i;
    for(i=0;i<len/2;i++)
    {
        push(str[i]);
    }
    for(i=0;i<len/2;i++)
    {
        if(stack[top]==str[len-(len/2)+i])
            pop();
        else
            return printf("\nNot pallindrome");
    }
    return
        printf("\nPallindrome\n");
}
int main()
{
    printf("enter the string : ");
    char str[ 2*MAX];
    scanf("%s",str);
    pallin(str);


}
