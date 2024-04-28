#include<stdio.h>
#include<string.h>

void compute_lps_array(char *patt,int m,int *lps){
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i<m){
        if (patt[i]==patt[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len!=0){
                len = lps[len-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp_search(char *string,char *patt){
    int n1 = strlen(string);
    int n2 = strlen(patt);
    int shifts = 0;
    int lps[n2];
    compute_lps_array(patt,n2,lps);
    int i = 0;
    int j = 0;
    while(i<n1){
        if(patt[j]==string[i]){
            j++;
            i++;
            if(j==n2){
                printf("Pattern found\n");
                i++
            }
        }
    }
    
}