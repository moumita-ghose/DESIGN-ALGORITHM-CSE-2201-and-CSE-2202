#include<stdio.h>
#define ll long long int
 
ll max_value(ll a[],int n)
{
    ll max=0;
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    } 
    return max;
}

void countingSort(ll a[],int n,ll position){
    int count[10];
    for(int i=0;i<=9;i++){
        count[i]=0;
    }

    for(int i=0;i<n;i++){
        int digit=(a[i]/position)%10; 
        count[digit]++;
    }

    for(int i=1;i<=9;i++){
        count[i]=count[i-1]+count[i];
    }
    ll output[n];
    for(int i=n-1;i>=0;i--){
        int digit=(a[i]/position)%10;
        int index=--count[digit];
        output[index]=a[i];
    }

    for(int i=0;i<n;i++){
        a[i]=output[i];
    }

    
/*_________________TESTING ______________________________________________*/
    // printf("%d -> ",position);
    // for(int i=0;i<n;i++){
    //     printf("%d ",a[i]);
    // }
    // printf("\n\n");

/*____________________________________________________________________*/

}
void radixSort(ll a[],int n)
{
    ll mx=max_value(a,n);
    for(ll position=1;mx/position>0 ; position*=10){
        countingSort(a,n,position);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    ll a[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }

    radixSort(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    return 0;
}