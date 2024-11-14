#include "dsp_lecture.h"

void 
add_vector(int_fast16_t n, int16_t * dst, int16_t * src1, int16_t * src2)
{
	int_fast16_t i;
	int_fast16_t error_i;
	int error_p;
	
	int16_t * dst_ref = (int16_t *) malloc (n * sizeof(int16_t));
	add_vector_ref(n,dst_ref,src1,src2);
	
	/* homework: read cycle timer on Raspberry Pi */
	int start_time = READ_CYCLE_TIMER;	
	add_vector_fast(n,dst,src1,src2);
	int end_time = READ_CYCLE_TIMER;
	int elapsed_time = end_time - start_time;

	error_p = FALSE;
	for (i=0; i<n; i++)
		if (dst_ref[i] != dst[i]) {
			error_p = TRUE;
			error_i = i;
			break;
		}
	if (error_p) {
		fprintf(stderr, "ERROR: the function add_vector_fast did not compute correctly!\n");
		fprintf(stderr, "ERROR: i=%d, ref: dst[i]=0x%8.8x, result: dst[i]=0x%8.8x\n",
			i, dst_ref[i], dst[i]);
	}
	
	free(dst_ref);	
}
