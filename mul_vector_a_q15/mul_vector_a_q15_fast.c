#include "../dsp_lecture.h"

void mul_vector_a_q15_fast(int n, int32_t * dst, int16_t * src1, int16_t * src2) {
    int vect_4_N_div = n - (n % 4);
    int16x4_t buf1, buf2;
    int32x4_t mul;
    for (int vect_4_index = 0; vect_4_index < vect_4_N_div; vect_4_index += 4) {
        buf1 = vld1_s16(&src1[vect_4_index]);
        buf2 = vld1_s16(&src2[vect_4_index]);
        mul = vmull_s16(buf1, buf2);
        vst1q_s32(&dst[vect_4_index], mul);
    }

    for (int i = vect_4_N_div; i < n; i++) {
        dst[i] = (int32_t)src1[i] * (int32_t)src2[i];
    }
}
