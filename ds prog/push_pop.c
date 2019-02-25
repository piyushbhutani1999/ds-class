#include<stdio.h>
#define MAX 50
int top=-1;
int stack[MAX];
void push(int elem)
{
    if(top<MAX-1)
    {
        stack[++top]=elem;
    }
    else
        printf("stack is full\n");
}
int pop()
{
    if(top>-1)
    {
        return stack[top--];
    }
    else
    {
        printf("/nstack is empty\n");
        return 99999;
    }
}
void display()
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}


int main()
{
    int ope,push_elem,pop_elem,check=1;
    while(check)
    {

        printf("press 1 to push ,2 to pop , 3 to display and 4 to exit\n");
        scanf("%d",&ope);
        switch(ope)
        {
            case 1:
                printf("enter the element to push\n");
                scanf("%d",&push_elem);
                push(push_elem);
                break;
            case 2:
                printf("popping element...");
                pop_elem = pop();
                if(pop_elem!=99999)
                {
                    printf("poped element is %d\n",pop_elem);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                check=0;
                break;

        }
    }
}

