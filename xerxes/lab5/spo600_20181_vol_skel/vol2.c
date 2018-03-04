#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "vol.h"

int main() {
	float factor = 0.75;//volume factor

	// Allocate memory for lookup table array
	int16_t*	lookup;
	//int16_t*	out;
	lookup = (int16_t*) calloc(SAMPLES, sizeof(int16_t));
	//out = (int16_t*) calloc(SAMPLES, sizeof(int16_t));

	int		x;
	int		ttl;

	// Seed the pseudo-random number generator
	srand(-1);

	clock_t start = clock();
	// Fill the array with random data and scale the volume of all of the samples
	for (x = 0; x < SAMPLES; x++) {
		lookup[x] = (int16_t)factor*(x%65536)-32768;
	}

	clock_t end = clock();
	double total = (double)(end - start)/CLOCKS_PER_SEC;
	
	// Sum up the data
	for (x = 0; x < SAMPLES; x++) {
		ttl = (ttl+lookup[x])%1000;
	}

	// Print the sum
	//printf("Result: %d\n", ttl);
	printf("Result: %d\nTime spent: %f\n", ttl, total);

	return 0;

}

