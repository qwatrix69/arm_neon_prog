#include "../dsp_lecture.h"

void mul_vector_s15_q15_fast(int n, int16_t *dst, int16_t *src1, int16_t *src2) {
    int vect_4_N_div = n - (n % 4);
    int16x4_t buf1, buf2;
    int16x4_t result;

    for (int i = 0; i < vect_4_N_div; i += 4) {
        buf1 = vld1_s16(&src1[i]); 
        buf2 = vld1_s16(&src2[i]);
        result = vqdmulh_s16(buf1, buf2);
        vst1_s16(&dst[i], result);
    }
    for (int i = vect_4_N_div; i < n; i++) {
        int32_t mul = (int32_t)src1[i] * (int32_t)src2[i];
        dst[i] = (int16_t)(mul >> 16);
    }
}
