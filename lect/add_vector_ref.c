#include "dsp_lecture.h"

void add_vector_ref(int_fast16_t n, int16_t * dst, int16_t * src1, int16_t * src2)
{
	int_fast16_t i;
	assert(0<=i && i<N_MAX);
	for (i=0; i<n; i++)
		dst[i] = src1[i] + src2[i];
}
