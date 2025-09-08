#include<stdio.h>
void swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

int partition(int a[],int l,int h){
    int pivot = a[l];
    int i=l,j=h;
    while(i<j)
    {
        while(a[i]<=pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<j){
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[l],&a[j]);
    return j;
}

void QuickSort(int a[],int l,int h)
{
    if(l<h){
        int j = partition(a,l,h);
        QuickSort(a,l,j-1);
        QuickSort(a,j+1,h);
    } 
}
int main()
{

    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    if(n==1){
        printf("%d",a[0]);
    }else{
        QuickSort(a,0,n-1);
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }

    // int c=2,b=3;
    // swap(&c,&b);
    // printf("%d %d",c,b);

    return 0;
}