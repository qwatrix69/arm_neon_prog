#include "../dsp_lecture.h"

void mul_vector_a_q15_ref(int n, int32_t * dst, int16_t * src1, int16_t * src2) { 
    int i;
    for (i=0; i<n; i++) {
        dst[i] = (int32_t)src1[i] * (int32_t)src2[i];
    }
}
