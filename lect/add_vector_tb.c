#include "dsp_lecture.h"

void add_vector_tb (int seed, int num_runs)
{
	int i;
	int_fast16_t n;
	
	int16_t * dst = NULL;
	int16_t * src1 = NULL;
	int16_t * src2 = NULL;
	
	srand (seed); /* homework: use srand48 instead! */

	for (i=0; i<num_runs; i++) {
		n = rand() % N_MAX;
		
		dst =(int16_t *) realloc (dst, n * sizeof(int16_t));
		src1 =(int16_t *) realloc (src1, n * sizeof(int16_t));
		src2 =(int16_t *) realloc (src2, n * sizeof(int16_t));
		
		random_vector(n, src1);
		random_vector(n, src2);
		
		add_vector(n, dst, src1, src2);
	}
	
	free(dst);
	free(src1);
	free(src2);
}

int
main()
{
	add_vector_tb (5, 1000);
	return 0;
}
