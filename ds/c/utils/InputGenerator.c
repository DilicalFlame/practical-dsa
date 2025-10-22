#include "../header/InputGenerator.h"
#include <stdio.h>

int* generate_random_array(int size) {
    // I am using fixed seed = 37
    static int flag_seeded = 0;
    if (!flag_seeded) {
        srand(37);
        flag_seeded = 1;
    }
    
    int* data = (int*)malloc(size * sizeof(int));
    if (data == NULL) {
        fprintf(stderr, "RAM overflow\n");
        exit(1);
    }
    
    for (int i = 0; i < size; i++) {
        data[i] = rand();
    }
    
    return data;
}

void free_random_data(int* data) {
    if (data != NULL) {
        free(data);
    }
}
