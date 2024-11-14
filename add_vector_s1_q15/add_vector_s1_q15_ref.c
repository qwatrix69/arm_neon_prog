#include "../dsp_lecture.h"

void add_vector_s1_q15_ref(int n, int16_t * dst, int16_t * src1, int16_t * src2) {
    for (int i = 0; i < n; ++i) {
        int32_t sum = (int32_t)src1[i] + (int32_t)src2[i];
        sum >>= 1;
        dst[i] = (int16_t)sum;
    }
}
