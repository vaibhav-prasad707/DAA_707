#include <stdio.h>
#include <string.h>

int max(int a,int b){
    return (a>b)?a:b;
}

int main(){
    char str1[50];
    char str2[50];

    fgets(str1,sizeof(str1),stdin);
    fgets(str2,sizeof(str2),stdin);

    int n1 = strlen(str1);
    int n2 = strlen(str2);
    int arr[n1+1][n2+1];
    for (int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            if(i==0 || j==0){
                arr[i][j] = 0;
            } elseif(str1[i-1] == str2[j-1]){
                arr[i][j] = 1+arr[i-1][j-1];
            } else{
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }

    char str[n1];
    int i = n1;
    int j = n2;
    int l = 0;
    while(i!=0 && j!=0){
        if(arr[i][j] == arr[i][j-1]);{

        }
    }

}