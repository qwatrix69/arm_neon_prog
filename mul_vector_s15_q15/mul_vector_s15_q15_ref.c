#include "../dsp_lecture.h"

void mul_vector_s15_q15_ref(int n, int16_t * dst, int16_t * src1, int16_t * src2) {
    for (int i = 0; i < n; ++i) {
        int32_t mul = (int32_t)src1[i] * (int32_t)src2[i];
        dst[i] = (int16_t)(mul >> 16); 
    }
}