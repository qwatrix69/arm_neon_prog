#include "../dsp_lecture.h"

clock_t total_time_ref = 0;
clock_t total_time_fast = 0;
int total_errors = 0;

void add_vector_s1_q15(int n, int16_t *dst, int16_t *src1, int16_t *src2) {
    int_fast16_t i;
    int_fast16_t error_i;
	int error_p;
    
    clock_t start_ref, end_ref, start_fast, end_fast;

    int16_t * dst_ref = (int16_t *) malloc (n * sizeof(int16_t));

    start_ref = clock();
    add_vector_s1_q15_ref(n, dst_ref, src1, src2);
    end_ref = clock();
    total_time_ref += (end_ref - start_ref);

    start_fast = clock();
    add_vector_s1_q15_fast(n, dst, src1, src2);
    end_fast = clock();
    total_time_fast += (end_fast - start_fast);

    clock_t refTime = end_ref - start_ref;
    clock_t fastTime = end_fast - start_fast;

    error_p = FALSE;
	for (i = 0; i <n; i++)
		if (dst_ref[i] != dst[i]) {
			error_p = TRUE;
			error_i = i;
            total_errors++;
			break;
		}
	if (error_p) {
		fprintf(stderr, "ERROR: the function add_vector_fast_q15 did not compute correctly!\n");
		fprintf(stderr, "ERROR: i=%d, ref: dst[i]=0x%8.8x, result: dst[i]=0x%8.8x\n",
			i, dst_ref[i], dst[i]);
	}

    printf("Length: %d, Reference Time: %ld ms, Fast Time: %ld ms, Time Difference: %ld ms, Time Increase: %.2f%%\n", 
           n, refTime, fastTime, refTime - fastTime, ((float)(refTime - fastTime) / refTime) * 100);

    free(dst_ref);	
}