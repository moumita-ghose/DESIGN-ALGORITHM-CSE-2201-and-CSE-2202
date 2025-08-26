#include<stdio.h>

void merge(int a[] ,int st1,int mid,int end){
    int left_size=mid-st1+1;
    int right_size=end-mid;
    int L[left_size],R[right_size];
    int ind=0;
    for(int i=0;i<left_size;i++){
        L[i]=a[st1+i];
    }
     ind=0;
    for(int i=0;i<right_size;i++){
        R[i]=a[i+1+mid];
        // ind++;
    }
    int i=0,j=0;
    ind=st1;
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
        ind++;
        i++;
    }
    while(j<right_size){
        a[ind]=R[j];
        ind++;
        j++;
    }

}

void merge_sort(int a[],int start,int end){
    if(start<end){
        int mid = (start+end)/2;
        merge_sort(a,start,mid);
        merge_sort(a,mid+1,end);
        merge(a,start,mid,end);
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
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);

    return 0;
}