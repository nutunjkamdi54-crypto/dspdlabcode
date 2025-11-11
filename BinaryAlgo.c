#include<stdio.h>
int main(){
    int n,i,arr[50],search,start=0,high,mid,found=0;
    printf("Enter the no. of elemenyts in the array:");
    scanf("%d",&n);
    high=n-1;
    printf("Enter %d sorted elements:\n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to search:");
    scanf("%d",&search);

    while(start<=high){
        mid=(start+high)/2;
        printf("start=%d,high=%d,mid=%d\n",start,high,mid);
        if(arr[mid]==search){
            printf("The element %d is located at the position %d\n",search,mid+1);
            found=1;
            break;
        }
        else if(search<arr[mid]){
            high=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    if(!found)
    printf("The elment %d is not present in the array\n",search);
    return 0;
    

}
