#include<stdio.h>
int main()
{

    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    if(n==1){
        printf("%d\n",a[0]);
    }else{
        for(int i=1;i<n;i++){
            int tmp=a[i]; 
            int current_index=i-1;
            while(a[current_index]>tmp && current_index>=0){
               a[ current_index + 1]=a[current_index];
                current_index--;
                
            
            }

            a[current_index+1]=tmp;
            // printf("%d -> %d -> %d -> ",i, tmp,current_index+1);
        }
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;

}
