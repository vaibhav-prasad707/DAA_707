#include<stdio.h>

void maxSumSubArray(int Arr[],int n){
    int currsum = Arr[0];
    int maxsum = Arr[0];
    int start = 0;
    int end = 0;
    int s = 0;
    for(int i=1;i<n;i++){
        if(Arr[i]>(currsum+Arr[i])){
            currsum = Arr[i];
            s = i;
        } else{
            currsum+=Arr[i];
        }

        if(currsum>maxsum){
            maxsum = currsum;
            start = s;
            end = i;
        }
    }

    printf("The maximum sub array is [");
    for(int i = start;i<=end;i++){
        printf("%d",Arr[i]);
        if(i<end){
            printf(" ");
        }
    }
    printf("]\n");

    printf("The maximum sub array sum is :%d\n",maxsum);
}

int main(){
    int n;
    scanf("%d",&n);
    int arr1[] = {-2,-5,6,-2,-3,1,5,-6};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    if (n == n1){
        maxSumSubArray(arr1,n1);
    }
}

