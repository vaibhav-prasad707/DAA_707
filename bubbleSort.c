#include <stdio.h>

void Bubble(int A[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(A[i]>A[j]){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

int main(){
    int A[] = {3,7,9,10,6,12,4,1};
    int n = 8;
    Bubble(A,n);
    for(int i=0;i<n;i++){
        printf("%d",A[i]);
    }
    return 0;


}