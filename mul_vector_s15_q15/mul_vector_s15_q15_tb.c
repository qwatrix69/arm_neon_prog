#include "../dsp_lecture.h"

void mul_vector_s15_q15_tb(int seed, int num_tests) {
    clock_t run_time1 = clock();
    int16_t *src1 = malloc(INITIAL_VECTOR_SIZE * sizeof(int16_t));
    int16_t *src2 = malloc(INITIAL_VECTOR_SIZE * sizeof(int16_t));
    int16_t *dst = malloc(INITIAL_VECTOR_SIZE * sizeof(int16_t));


    if (!src1 || !src2 || !dst) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    srand48(seed);

    for (int i = 0; i < num_tests; i++) {
        int len = rand() % INITIAL_VECTOR_SIZE;

        if (len > INITIAL_VECTOR_SIZE) {
            src1 = realloc(src1, len * sizeof(int16_t));
            src2 = realloc(src2, len * sizeof(int16_t));
            dst = realloc(dst, len * sizeof(int16_t));

            if (!src1 || !src2 || !dst) {
                fprintf(stderr, "Memory reallocation failed\n");
                free(src1); free(src2); free(dst);
                return;
            }
        }

        random_vector(len, src1);
        random_vector(len, src2);

        mul_vector_s15_q15(len, src1, src2, dst);

        printf("Test #%d completed\n", i + 1);
    }

    printf("Total Reference Time: %ld ms\n", total_time_ref);
    printf("Total Fast Time: %ld ms\n", total_time_fast);
    printf("Total Time Difference: %ld ms\n", total_time_ref - total_time_fast);
    printf("Overall Speed Increase: %.2f%%\n", 
           ((float)(total_time_ref - total_time_fast) / total_time_ref) * 100);
    printf("Total Errors: %d\n", total_errors);
    clock_t run_time2 = clock();
    printf("Total program execution time: %ld ms\n", run_time2 - run_time1);
    free(src1);
    free(src2);
    free(dst);
}