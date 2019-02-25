#include<stdio.h>
int lin_search(int arr[],int len,int elem);
int b_search(int arr[],int len,int elem);
int b_search_rec(int arr[],int start,int end,int elem);

int lin_search(int arr[],int len,int elem)
{
    for(int i=0;i<len;i++)
    {
        if(arr[i]==elem)
            return i;
    }
    return -1;
}
int b_search(int arr[],int len,int elem)
{
    int start = 0;
    int end = len;
    int mid;
    while(start<end)
    {
        mid = (start+end)/2;
       // printf("start: %d end: %d mid: %d\n", start, end, mid);
        if(arr[mid]==elem)
            return mid;
        else if(arr[mid]>elem)
            end = mid;
        else if(arr[mid]<elem)
            start = mid;
    }

    return -1;
}
int b_search_rec(int arr[],int start,int end,int elem)
{
    if(start<end)
    {
        int mid = (start+end)/2;
        if(arr[mid]==elem)
            return mid;
        else if(arr[mid]>elem)
            return b_search_rec(arr,start,mid,elem);
        else if(arr[mid]<elem)
            return b_search_rec(arr,mid+1,end,elem);
    }
    else
        return -1;

}
int main()
{   int len,check;
    printf("enter the number of element\n");
    scanf("%d",&len);
    int arr[len],elem,method,index;
    for(int i=0;i<len;i++)
    {
        scanf("%d",&arr[i]);
    }
    int count = 1;
    while(count)
    {
        printf("Enter the element you want to find: ");
        scanf("%d",&elem);
        printf("\nSelect method of searching:");
        printf("\n1 for linear search\n");
        printf("\n2 for binary search\n");
        printf("\n3 for binary search recursive\n");
        scanf("%d",&method);

        switch(method)
        {
            case 1:
                index =lin_search(arr,len,elem);
                break;
            case 2:
                index = b_search(arr,len,elem);
                break;
            case 3:
                index = b_search_rec(arr,0,len,elem);
                break;
        }
        if(index>=0)
        {
            printf("Element is found at position %d\n",index+1);
        }
        else
            printf("Not found");

        printf("press 0 to exit and 1 to do again");
        scanf("%d",&check);
        count = check;
    }
}
