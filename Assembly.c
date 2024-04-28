#include <stdio.h>

#define MAX_STATIONS 100

int entry[] = {2,4};
int x[] = {3,2 };

int s1[] = {7,9,3,4,8,4};
int s2[] = {8,5,6,4,5,7};

int t1[] = {2,3,1,3,4};
int t2[] = {2,1,2,2,1};


int min(int a, int b) {
    return (a < b) ? a : b;
}

int assemblyTime(int n) {
    int f1[MAX_STATIONS], f2[MAX_STATIONS];
    
    f1[0] = entry[0] + s1[0];
    f2[0] = entry[1] + s2[0];

    for (int j = 1; j < n; j++) {
        f1[j] = min(f1[j - 1] + s1[j], f2[j - 1] + t2[j - 1] + s1[j]);
        f2[j] = min(f2[j - 1] + s2[j], f1[j - 1] + t1[j - 1] + s2[j]);
    }

    return min(f1[n - 1] + x[0], f2[n - 1] + x[1]);
}

void printOptimalPath(int n) {
    int f1[MAX_STATIONS], f2[MAX_STATIONS];
    int path[MAX_STATIONS];

    f1[0] = entry[0] + s1[0];
    f2[0] = entry[1] + s2[0];

    for (int j = 1; j < n; j++) {
        if (f1[j - 1] + s1[j] <= f2[j - 1] + t2[j - 1] + s1[j]) {
            f1[j] = f1[j - 1] + s1[j];
            path[j] = 1; 
        } else {
            f1[j] = f2[j - 1] + t2[j - 1] + s1[j];
            path[j] = 2;  
        }

        if (f2[j - 1] + s2[j] <= f1[j - 1] + t1[j - 1] + s2[j]) {
            f2[j] = f2[j - 1] + s2[j];
            path[j] = 3;
        } else {
            f2[j] = f1[j - 1] + t1[j - 1] + s2[j];
            path[j] = 4;
        }
    }
    int finalLine = (f1[n - 1] + x[0] < f2[n - 1] + x[1]) ? 1 : 2;

    printf("Optimal Path: ");
    for (int j = n - 1; j >= 0; j--) {
        if (finalLine == 1 && path[j] == 1) {
            printf("Line 1, ");
        } else if (finalLine == 1 && path[j] == 2) {
            printf("Transfer from Line 2 to Line 1, ");
        } else if (finalLine == 2 && path[j] == 3) {
            printf("Line 2, ");
        } else if (finalLine == 2 && path[j] == 4) {
            printf("Transfer from Line 1 to Line 2, ");
        }
    }

    printf("x Line %d\n", finalLine);
}

int main() {
    int n=6;
    int totalTime = assemblyTime(n);
    printOptimalPath(n);
    printf("%d\n", totalTime);
    return 0;
}