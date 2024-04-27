#include <stdio.h>

void maxSumSubarray(int arr[],int n){
    int currentSum = arr[0];
    int max_sum = arr[0];
    int start = 0,end =0,s=0;

    for (int i=1;i<n;i++){
        if (arr[i]>(currentSum+arr[i])){
            currentSum=arr[i];
            s=i;
        }
        else{
            currentSum+=arr[i];
        }
        if (currentSum<max_sum){
            max_sum = currentSum;
            start = s;
            end = i;
        }
    }

    printf("The maximum sub array is [");
    for (int i=start;i<=end;i++){
        printf("%d",arr[i]);
        if (i<end){
            printf(" ");
        }
    }
    printf("]\n");

    printf("The maximum sub array sum is :%d\n",max_sum);
}