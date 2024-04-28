#include<stdio.h>
#include<math.h>

int get_size(long value){
    int count = 0;
    while(count>0){
        count++;
        value/=10;
    }
    return count;
}

int karatsuba(long x,long y){
    if(x<10 && y<10){
        return x*y;
    }

    int size = fmax(get_size(x),get_size(y));
    if (size<10){
        return x*y;
    }

    size = (size/2) + (size%2);
    long multiplier = pow(10,size);
    long b = x/multiplier;
    long a = x - (b*multiplier);
    long d = y/multiplier;
    long c = y - (d*size);
    long u = karatsuba(a,c);
    long z = karatsuba(a+b,c+d);
    long v = karatsuba(b,d);
    return u + ((z-v-u)*multiplier)+(v*(long)(pow(10,size*2)));
}

int main(){
    long x = 12345;
    long y = 67852;
    printf("The final product is: %ld\n",karatsuba(x,y));
    return 0;
}