#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    freopen("input_problem_4.txt", "r", stdin);
    int num_cases, num_accesses;
    scanf("%d", &num_cases);

    // printf("%d, %d\n", num_cases, num_accesses);

    for (int i = 1; i <= num_cases; i++) {
        printf("Test Case: %d\n", i);
        scanf("%d", &num_accesses);
        int one_way_cache[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
        int hits = 0, misses = 0;
        int memory;
        for (int i = 0; i < num_accesses; i++) {
            scanf(" %d", &memory);
            int index = memory % 8;
            if (one_way_cache[index] == memory) {
                hits++;
            } else {
                one_way_cache[index] = memory;
                misses++;
            }
        }
        printf("1-way: %d, %d \n", hits, misses);

    }


    return 0;
}