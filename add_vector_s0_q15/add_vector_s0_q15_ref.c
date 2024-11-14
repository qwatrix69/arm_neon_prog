#include "../dsp_lecture.h"

void add_vector_s0_q15_ref(int n, int16_t *dst, int16_t *src1, int16_t *src2) {
    for (int i = 0; i != n; ++i) {
        int32_t sum = (int32_t)src1[i] + (int32_t)src2[i];
        if (sum > INT16_MAX) {
            dst[i] = INT16_MAX;
        } else if (sum < INT16_MIN) {
            dst[i] = INT16_MIN;
        } else {
            dst[i] = (int16_t)sum;
        }
    }
}