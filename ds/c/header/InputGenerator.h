#ifndef RANDOM_DATA_H
#define RANDOM_DATA_H

#include <stdlib.h>

/**
 * Generate an array of random integers in memory
 * @param size Number of integers to generate
 * @return Pointer to dynamically allocated array 
 */
int* generate_random_array(int size);

/**
 * Free the dynamically allocated random data array
 * @param data Pointer to the array to free
 */
void free_random_data(int* data);

#endif // RANDOM_DATA_H
