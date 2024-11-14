#include "dsp_lecture.h"

void copy_vector(int n, int16_t *src, int16_t *dst) {
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}
