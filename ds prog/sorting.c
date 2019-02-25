#include<stdio.h>
void swap(int *a,int *b);
void display(int arr[],int len);
void merge(int start,int end,int mid,int arr[]);
void mergesort(int start,int end,int arr[]);
void isort(int arr[],int len);
void ssort(int arr[],int len);

void mergesort(int start,int end,int arr[])
{
    if(start!=end)
    {
        int mid = (start+end)/2;
        mergesort(start,mid,arr);
        mergesort(mid+1,end,arr);
        merge(start,end,mid,arr);
    }
    else return;
}
void merge(int start,int end,int mid,int arr[])
{
    int i,j,count,len;
    i= start;count = 0;j = mid+1;
    len = end-start+1;
    int temp[len];
    for(int f=0;f<len;f++)
    {
        temp[f]=0;
    }
    while(i<=mid && j<=end)
    {
        if(arr[i]>arr[j])
            temp[count++]=arr[j++];
        else
            temp[count++]=arr[i++];
    }
    while(i<=mid)
        temp[count++]=arr[i++];
    while(j<=end)
        temp[count++]=arr[j++];
    count = 0;
    for(i=start;i<=end;i++)
    {
        arr[i]=temp[count++];
    }
}
display(int arr[],int len)
{
    int i ;
    for(i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
}
void qsort(int start, int end,int arr[])
{
    if(start<end)
    {   int pivot = arr[start];
        int i=start,j=end+1;
        while(i<j)
        {
            do i++;
            while(arr[i]<pivot && i<=end);
            do j--;
            while(arr[j]>pivot);
            if(i<j)
                swap(&arr[i],&arr[j]);
        }
        swap(&arr[j],&arr[start]);
        qsort(start,j-1,arr);
        qsort(j+1,end,arr);
    }
    else
        return;
}
void swap(int *a,int *b)
{
    int temp = *a;
    *a  = *b;
    *b = temp;
}
void isort(int arr[],int len)
{
    int i=1;
    while(i<len)
    {
        int j=i-1;
        int val = arr[i];
        while((arr[j] >val) && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=val;
        i++;
    }
    return;
}
void ssort(int arr[],int len)
{
    for(int i=0;i<len-1;i++)
    {
        int index = i;
        int j = i+1;
        while(j<len && arr[j]<arr[index])
        {
            index = j;
            j++;
        }
        swap(&arr[i],&arr[index]);
    }
}


int main()
{
    int num_ele,method;
    printf("Enter the number of elements\n");
    scanf("%d",&num_ele);
    int i,arr[num_ele];
    for(i=0;i<num_ele;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Select the sorting algo\n");
    printf("1. selection sort\n");
    printf("2. insertion sort\n");
    printf("3. merge sort\n");
    printf("4. quick sort\n");
    scanf("%d", &method);
    switch(method)
    {
        case 1:
            ssort(arr,num_ele);
            printf("\nsorted by selection sort\n");
            break;
        case 2:
            isort(arr, num_ele);
            printf("\nsorted by insertion sort\n");
            break;
        case 3:
            mergesort(0, num_ele-1, arr);
            printf("\nsorted by merge sort\n");
            break;
        case 4:
            qsort(0, num_ele-1, arr);
            printf("\nsorted by quick sort\n");
            break;
    }
    display(arr,num_ele);
}
