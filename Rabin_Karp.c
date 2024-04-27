#include<stdio.h>
#include<string.h>

#define PRIME 101

int rabin_karp(char *string,char *patt){
    int a = strlen(string);
    int b = strlen(patt);
    int p_hash = 0; //Hash value for pattern
    int t_hash = 0; //Hash value for first window of string
    int h = 1;
    for(int i=0;i<b-1;i++){
        h = (h*256)%PRIME;
    }

    for(int i=0;i<b;i++){
        p_hash=(256*p_hash+patt[i])%PRIME;
        t_hash=(256*t_hash+string[i])%PRIME;
    }

    for(int i=0;i<=a-b;i++){
        if(p_hash==t_hash){
            int j;
            for(j=0;j<b;j++){
                if(string[i+j]!=patt[j])
                break;
            }
            if(j==b){
                return 1;
            }
        }
        if(i<a-b){
            t_hash = (256*(t_hash-string[i]*h)+)
        }

        }
    }
}