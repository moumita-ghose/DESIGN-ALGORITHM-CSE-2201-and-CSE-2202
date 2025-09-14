#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertionSort(float bucket[],int n)
{
    for(int i=1;i<n;i++){
        float key =bucket[i];
        int j=i-1;
        while(j>=0 && bucket[j]>key){
            bucket[j+1]=bucket[j];
            j--;
        }
        bucket[j+1]=key;
    }
}

void bucketSort(float a[],int n)
{
    int i,j,k;
    int bucketCount=10;
    float buckets[10][10];
    int bucketSize[10]={0};

    for(i=0;i<n;i++){
        int bi = a[i]*bucketCount;
        buckets[bi][bucketSize[bi]++]=a[i];
    }

    for(i=0;i<bucketCount;i++){
        if(bucketSize[i]>0){
            insertionSort(buckets[i],bucketSize[i]);
        }
    }
    k=0;
    for(i=0;i<bucketCount;i++){
        for(j=0;j<bucketSize[i];j++){
            a[k++]=buckets[i][j];
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    float a[n];
    for(int i=0;i<n;i++){
        scanf("%f",&a[i]);
    }

    bucketSort(a,n);

    for(int i=0;i<n;i++){
        printf("%.2f ",a[i]);
    }
    printf("\n");
    return 0;
}