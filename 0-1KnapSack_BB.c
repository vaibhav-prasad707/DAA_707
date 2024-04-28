#include <stdio.h>

#define NUM_ITEMS 4

int maxProfit = 0;
int bestSet[NUM_ITEMS];

void branchAndBound(int idx, int profit, int weight, int set[], int profitArr[], int weightArr[], int capacity) {
    if (weight > capacity)
        return;
    if (idx >= NUM_ITEMS) {
        if (profit > maxProfit) {
            maxProfit = profit;
            for (int i = 0; i < NUM_ITEMS; i++)
                bestSet[i] = set[i];
        }
        return;
    }

    
    set[idx] = 1;
    branchAndBound(idx + 1, profit + profitArr[idx], weight + weightArr[idx], set, profitArr, weightArr, capacity);
    set[idx] = 0;
    branchAndBound(idx + 1, profit, weight, set, profitArr, weightArr, capacity);
}

int main() {
    int M = 15;
    int profit[NUM_ITEMS] = {10, 10, 12, 18};
    int weight[NUM_ITEMS] = {2, 4, 6, 9};
    int set[NUM_ITEMS] = {0};
    
    branchAndBound(0, 0, 0, set, profit, weight, M);
    
    printf("Profit =%d\n", maxProfit);
    printf("solution = {");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("%d", bestSet[i]);
        if (i < NUM_ITEMS - 1)
            printf(",");
    }
    printf("}\n");
    
    return 0;
}
