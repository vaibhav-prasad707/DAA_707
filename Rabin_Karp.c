#include <stdio.h>
#include<string.h>

#define PRIME 101 //A prime number to reduce collisions

int rabin_karp(char *string1,char *patt){
    int a = strlen(string1);
    int b =strlen(patt);
    int p_hash = 0;
    int t_hash = 0;
    int h = 1;

    for (int i=0;i<b-1;i++){
        h=(h*256)%PRIME;
    }
    for(int i=0;i<b;i++){
        p_hash = (256*p_hash+patt[i])%PRIME;
        t_hash = (256*t_hash+string1[i])%PRIME;
    }
    for(int i=0;i<=a-b;i++){
        if(p_hash==t_hash){
            int j;
            for(j=0;j<b;j++){
                if(string1[i+j]!=patt[j]){
                    break;
                }
            }
            if(j==b){
                return 1; //Pattern found
            }
        }
        if(i<a-b){
            t_hash=(256*(t_hash-string1[i]*h)+string1[i+b])%PRIME;
            if(t_hash<0){
                t_hash+=PRIME;
            }
        }
    }
    return 0;
}

int main(){
    char string[] = "ccaccaaedba";
    char pattern[] = "dba";
    if (rabin_karp(string,pattern)){
        printf("The given pattern is found in the string\n");
    }else{
        printf("The given pattern is not found in the string\n");
    }
    return 0;
}