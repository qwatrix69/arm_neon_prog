#include "dsp_lecture.h"

void random_vector(int_fast16_t n, int16_t * v)
{
	int_fast16_t i;
	for (i=0; i<n; i++)
		v[i] = rand();
}
