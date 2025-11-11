#include<stdio.h>
int main(){
    int arr[100],i,n;
    int Sum_even=0,Sum_odd=0;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter %d element:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        if(i%2==0){
            Sum_even+=arr[i];
        }
        else{
            Sum_odd+=arr[i];
        }
      
    }
    printf("Sum of elments at even position=%d\n ",Sum_even);
    printf("Sum of elments at odd position=%d\n ",Sum_odd);
    
    return 0;
}
