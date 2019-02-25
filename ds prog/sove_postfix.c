#include<stdio.h>
#define MAX 50
int stack[MAX];
int pop();
int solve_postfix(char str[]);
void push(int );
int top = -1;

int pop()
{
    if(top>-1)
    {
        return stack[top--];
    }
    else
    {
        printf("\nstack is empty");
        return '99999';
    }
}

void push(int elem)
{
    if(top<MAX-1)
    {
        stack[++top] = elem;
    }
    else
        printf("stack is full\n");
}

int solve_postfix(char str[])
{
    int res;
    int len = strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]>47 && str[i]<58)
        {
            push(str[i]-48);
        }
        else
        {
            int val2 = pop();
            int val1 = pop();
            switch(str[i])
            {
                case '+':
                    res = val2+val1;
                    break;
                case '-':
                    res = val1 - val2;
                    break;
                case '*':
                    res = val1*val2;
                    break;
                case '/':
                    res = val1/val2;
                    break;
            }
            push(res);
        }
    }
    return pop();
}
int main()
{
    int check;
    char str[50];
    while(1)
    {
        printf("press 1 to solve and 2 to exit\n");
        scanf("%d",&check);
        if(check == 2)
            break;
        printf("\nenter the postfix experssion\n");
        scanf("%s",str);
        int ans = solve_postfix(str);
        printf("result = %d", ans);
    }

}
