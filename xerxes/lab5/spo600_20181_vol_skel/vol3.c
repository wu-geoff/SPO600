#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include "vol.h"

int main() {

	// Allocate memory for large in and out arrays
	int16_t*	in;
	int16_t*	out;
	in = (int16_t*) calloc(SAMPLES, sizeof(int16_t));
	out = (int16_t*) calloc(SAMPLES, sizeof(int16_t));

	int		x;
	int		ttl;

	// Seed the pseudo-random number generator
	srand(-1);

	// Fill the array with random data
	for (x = 0; x < SAMPLES; x++) {
		in[x] = (rand()%65536)-32768;
	}

	clock_t begin = clock();

	//Convert the volume factor 0.75 to a fix-point integer 0b100000000 (256 in decimal) represent 1.00
	int shift = 0b100000000 * 0.75;
	// ######################################
	// This is the interesting part!
	// Scale the volume of all of the samples
	for (x = 0; x < SAMPLES; x++) {
		//out[x] = scale_sample(in[x], 0.75);
		out[x] = in[x] * shift >> 8; //shift result to the right by 8, since I am using 256 as the multiplier
	}
	// ######################################
	clock_t end = clock();
	double total = (double)(end-begin)/CLOCKS_PER_SEC;

	// Sum up the data
	for (x = 0; x < SAMPLES; x++) {
		ttl = (ttl+out[x])%1000;
	}

	// Print the sum
	printf("Result: %d\nTime spent: %f\n", ttl, total);

	return 0;

}

