#include<stdio.h>
void merge(int a[],int st1,int end1,int size){
    int left_size=end1-st1+1 ,  right_size = size-end1 ;
    int L[left_size],R[right_size];
    for(int i=st1;i<end1;i++){
        L[i]=a[i];
    }
    int ind=0;
    for(int i=end1;i<size;i++){
        R[ind]=a[i];
        ind++;
    }
    int i=0,j=0;
    ind=0;
    while(i<left_size && j<right_size){
        if(L[i]<=R[j]){
            a[ind]=L[i];
            i++;
        }else{
            a[ind]=R[j];
            j++;
        }
        ind++;
    }
    while(i<left_size){
        a[ind]=L[i];
        i++;
        ind++;
    }
    while(j<right_size){
        a[ind]=R[j];
        j++;
        ind++;
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
    merge(a,0,4,n);
    for(int i=0;i<n;i++){
        printf("%d " , a[i]);
    }
    
    return 0;
}