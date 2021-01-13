#include<stdio.h>
#include<conio.h>
void quickprocedure(int a[],int n,int beg,int end,int*loc)
{
    int left,right,temp;
    left=beg;
    right=end;
    *loc=beg;
    step2:
        {
            while(a[*loc]<=a[right]&&*loc!=right)
                right=right-1;
            if(*loc==right)
                return;
            if(a[*loc]>a[right])
            {
                temp=a[*loc];
                a[*loc]=a[right];
                a[right]=temp;
                *loc=right;
            }
            goto step3;
        }
        step3:
            {
                while(a[*loc]>=a[left]&&*loc!=left)
                    left=left+1;
                if(*loc==left)
                    return;
                if(a[*loc]<a[left])
                {
                    temp=a[*loc];
                    a[*loc]=a[left];
                    a[left]=temp;
                    *loc=left;
                    goto step2;
                }
            }
}
void quicksort(int arr[],int n)
{
    int lower[10],upper[10],beg,end,top,*loc;
    top=-1;
    if(n>1)
        top=top+1;lower[top]=0;upper[top]=n-1;
    while(top!=-1)
    {
        beg=lower[top];
        end=upper[top];
        top=top-1;
        quickprocedure(arr,n,beg,end,loc);
        if(beg<*loc-1)
        {
            top=top+1;
            lower[top]=beg;
            upper[top]=*loc-1;
        }
        if(*loc+1<end)
        {
            top=top+1;
            lower[top]=*loc+1;
            upper[top]=end;
        }
    }
}
void printarray(int arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d\t",arr[i]);
}
int main()
{
    int arr[20],i,size;
    printf("Enter size of array:");
    scanf("%d",&size);
    printf("Enter %d array elements:\n",size);
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("array before sorting:\n");
    printarray(arr,size);
    quicksort(arr,size);
    printf("\narray after sorting:\n");
    printarray(arr,size);
    getch();
    return(0);
}
