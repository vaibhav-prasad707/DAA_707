#include <stdio.h>
#include <string.h>

void compute_lps_array(char *patt,int m,int *lps){
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while(i<m){
        if (patt[i] == patt[len]){
            len++;
            lps[i] = len;
            i++;
        } else{
            if (len!=0){
                len = lps[len-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp_search(char *string,char *patt){
    int n = strlen(string);
    int m = strlen(patt);
    int lps[m];
    compute_lps_array(patt,m,lps);
    int shifts = 0;
    int i = 0;
    int j = 0;
    while(i<n){
        if(patt[j] == string[i]){
            j++;
            i++;
            if(j==m){
                printf("Pattern is found in the string\n");
                j=lps[j-1];
            }
        }else{
            if(j!=0){
                j = lps[j-1];
            }else{
                i++;
            }
            shifts++;
        }
    }
    printf("Number of Shifts needed is %d\n",shifts);
}

int main(){
    char string[] = "bacbabababacaab";
    char pattern[] = "ababaca";
    kmp_search(string,pattern);
    return 0;
}