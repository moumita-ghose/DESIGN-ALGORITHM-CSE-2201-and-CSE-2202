#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int max = -100000008;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>=max){
            max=a[i];
        }
    }
    // printf("%d\n",mx);
    int range=max;
    int count[range+1];
    for(int i=0;i<=range;i++){
        count[i]=0;
    }

    for(int i=0;i<n;i++){
        count[a[i]]++;
    }


    // for(int i=0;i<=range;i++){
    //     printf("%d -> %d\n",i,count[i]);
    // }
    // printf("\n\n");
    
    for(int i=1;i<=range;i++){
        count[i]=count[i]+count[i-1];
    }
    

    int output[n];
    for(int i=n-1;i>=0;i--){
        int index= --count[a[i]];
        output[index]=a[i];
    }

    for(int i=0;i<n;i++){
        a[i]=output[i];
    }

    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}