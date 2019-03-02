#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *ptr;
}node;

void display(node *start);
node *create();
int max_val(node *start);

void display(node *start)
{
    node *temp = start;
    printf("data is = \n");
    while((*temp).data != -1)
    {
        printf("%d\n",(*temp).data);
        temp = (*temp).ptr;
    }
}
node *create()
{
    int i=1, val;
    node *temp;
    node *start = (node*)malloc(sizeof(node));
    node prev;
    prev.ptr = start;
    do
    {
        printf("Enter the %d element :",i++);
        scanf("%d",&val);
        ((prev.ptr)->data) = val;
        temp = (node*)malloc(sizeof(node));
        (prev.ptr)->ptr =temp;
        prev.ptr = temp;
    }
    while(val !=-1);
    (*temp).ptr = 0;
    return start;
}
int max_val(node *start)
{
    node *temp = start;
    int max = (*temp).data;
    while((*temp).data!=-1)
    {
        if((*temp).data > max)
            max = (*temp).data;
        temp  = (*temp).ptr;
    }
    return max;
}
void insertafter(node *start, int num,int toinsert)
{
    node *temp = start;
    node *req_ptr;
    while( (temp)->data !=-1)
    {
        if((temp)->data == num)
        {
            req_ptr = temp;
            break;
        }
        else
            temp=(temp)->ptr;

    }
    node* new_node = (node *)malloc(sizeof(node));
    new_node->ptr = ((req_ptr)->ptr);
    new_node->data = toinsert;
    (req_ptr)->ptr = new_node;
}
node* insertbefore(node *start, int num,int toinsert)
{
    node *temp;
    node* new_node = (node *)malloc(sizeof(node));
    node *req_ptr,*pre_ptr;
    while(temp->data !=-1)
    {
        if(temp->data ==num)
        {
            req_ptr = temp;
            if(temp==start)
            {
                new_node->ptr = start;
                new_node->data = toinsert;
                return new_node;
            }
            break;
        }
        else
        {
            temp = temp->ptr;
        }
    }
    pre_ptr = temp;
    new_node->ptr = ((pre_ptr)->ptr);
    new_node->data = toinsert;
    (pre_ptr)->ptr = new_node;
    return start;
}
node *insertatpos(node *start, int pos, int toinsert)
{
    node *temp = (node*)malloc(sizeof(node));
    temp = start;
    int linklen = 0;
    while(temp!=0)
    {
        linklen++;
    }
    temp = start;
    node *new_node;
    int temp_pos;
    if(pos == 1)
    {
        new_node->ptr = start;
        new_node->data = toinsert;
        return new_node;
    }
    else if(pos==linklen+1)
    {
        while(temp->ptr!=0)
            temp = temp->ptr;
        temp->ptr = new_node;
        new_node->data = toinsert;
        new_node->ptr = 0;


    }
    else if(pos<=linklen)
    {

        temp_pos = pos-2;
        while(temp_pos--)
        {
            temp = temp->ptr;
        }
        new_node->ptr = temp->ptr;
        temp->ptr = node_node;
        new_node->data = toinsert;

    }
    else
        printf("ERROR");
    return start;

}
int main()
{
    printf("Enter -1 to stop entering and display");
    node *start = create();
    display(start);
    start = insertatpos(start,3,23);
    display(start);
}
