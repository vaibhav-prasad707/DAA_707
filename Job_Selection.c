#include <stdio.h>
#include <stdlib.h>

int ub = 999999;
int ub_ans = -1;
int c_ans = -1;
int res_ans[] = {0, 0, 0, 0};

void jobSeq(int p[], int d[], int t[], int jobID, int n, int u, int c, int res[]){

    
    u=0;
    c=0;

    res[jobID] = 1;
    for(int j=0; j<n; j++){
        if(res[j]==0){
            if(j<=jobID)
                c+=p[j];
            u+=p[j];
        }
    }
    
    int max = 0, totalTime=0;
    for(int i=0; i<n; i++){
        if(res[i]==1){
            if(d[i]>max)
                max=d[i];
            totalTime+=t[i];
        }
    }
    
    if(u<ub && totalTime<=max){
        // printf("| Max: %d, Total time: %d, UB: %d, U: %d", max, totalTime, ub, u);
        ub = u;
        ub_ans = ub;
        c_ans = c;
        for(int i=0; i<n; i++)
            res_ans[i] = res[i];
    }
    
    
    for(int j=jobID+1; j<n; j++){
        jobSeq(p,d,t,j,n,ub,c,res);
    }
    
//     printf("\n[");
//     for(int i=0; i<n; i++)
//         printf("%d ", res[i]);
//     printf("], %d with %d", ub, c);
//     printf("| %d %d %d %d", max, totalTime, ub, u);
}

int main(){
    int p[] = {5, 10, 6, 3};
    int d[] = {1, 3, 2, 1};
    int t[] = {1, 2, 1, 1};
    int res1[] = {0, 0, 0, 0};
    int res2[] = {0, 0, 0, 0};
    int res3[] = {0, 0, 0, 0};
    int res4[] = {0, 0, 0, 0};
    
    jobSeq(p,d,t,0,4,ub,0,res1);
    // printf("\n");
    jobSeq(p,d,t,1,4,ub,0,res2);
    // printf("\n");
    jobSeq(p,d,t,2,4,ub,0,res3);
    // printf("\n");
    jobSeq(p,d,t,3,4,ub,0,res4);
    
    printf("Cost = %d\nUpper Bound = %d", c_ans, ub_ans);
    printf("\nJobs Completed within deadline are J");
    int count=0;
    for(int i=0; i<4; i++){
        if(res_ans[i] == 1)
            count++;
    }
    
    int currCount = 0;
    for(int i=1; i<=4; i++){
        if(res_ans[i-1] == 1){
            currCount++;
            if(currCount != count)
                printf("%d and J", i);
            else
                printf("%d", i);
        }
    }

    return 0;
}
