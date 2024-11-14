#include "../dsp_lecture.h"

void mul_vector_s0_q15_fast(int n, int16_t* dst, int16_t* src1, int16_t* src2)
{
    int vect_4_N_div = n - (n % 4);
    int16x4_t buf1, buf2, sumbuf;
    int32x4_t s;
    int32_t tmp;

    for (int vect_4_index = 0; vect_4_index < vect_4_N_div; vect_4_index += 4) {
        buf1 = vld1_s16(&src1[vect_4_index]);
        buf2 = vld1_s16(&src2[vect_4_index]);
        s = vmull_s16(buf1, buf2);
        sumbuf = vqmovn_s32(s);
        vst1_s16(&dst[vect_4_index], sumbuf);
    }

    for (int i = vect_4_N_div; i < n; i++) {
        tmp = (int32_t)src1[i] * (int32_t)src2[i];
        
        if (tmp > INT16_MAX)
            tmp = INT16_MAX;
        if (tmp < INT16_MIN)
            tmp = INT16_MIN;
        
        dst[i] = (int16_t)tmp;
    }
}
