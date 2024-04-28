#include<stdio.h>
#include<limits.h>

int matrix_chain(int p[],int i, int j){
    int k;
    int count;
    int min = INT_MAX;
    if (i==j){
        return 0;
    }
    for (k=i;k<j;k++){
        count=matrix_chain(p,i,k)+matrix_chain(p,k+1,j)+p[i-1]*[k]*p[j];
        if(count<min){
            min = count;
        }
    }
    return min;
}

int main(){
    int n;
    scanf("%d",&n);
    int d[n+1];
    scanf("%d",&d[0]);
    int z = 1;
    for(int i =1;i<=2*n;i++){
        if(i%2!=0){
            scanf("%d",&d[z]);
            z++;
        }else{
            scanf("%*d");
        }
    }
    int N = sizeof(d)/sizeof(d[0]);
    printf("Min no of multiplications required is %d",matrix_chain(d,1,N-1));
    getchar();
    return 0;
}