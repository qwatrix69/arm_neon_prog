#ifndef DSP_LECTURE_H
#define DSP_LECTURE_H

#include <stdint.h>
#include <arm_neon.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <assert.h>

#define N_MAX 65535
#define INITIAL_VECTOR_SIZE 100000
#define TRUE 1
#define FALSE 0

/* ANSI-C */
void add_vector(int_fast16_t n, int16_t * dst, int16_t * src1, int16_t * src2);
void add_vector_ref(int_fast16_t n, int16_t * dst, int16_t * src1, int16_t * src2);
void add_vector_fast(int_fast16_t n, int16_t * dst, int16_t * src1, int16_t * src2);

/* 1 */
void add_vector_q15(int n, int16_t * dst, int16_t * src1, int16_t * src2);
void add_vector_q15_ref(int n, int16_t * dst, int16_t * src1, int16_t * src2);
void add_vector_q15_fast(int n, int16_t * dst, int16_t * src1, int16_t * src2);
void add_vector_q15_tb(int seed, int n);

/* 2 */
void add_vector_s0_q15(int n, int16_t * dst, int16_t * src1, int16_t * src2);
void add_vector_s0_q15_ref(int n, int16_t * dst, int16_t * src1, int16_t * src2);
void add_vector_s0_q15_fast(int n, int16_t * dst, int16_t * src1, int16_t * src2);
void add_vector_s0_q15_tb(int seed, int n);

/* 3 */
void mul_vector_s0_q15(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_s0_q15_ref(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_s0_q15_fast(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_s0_q15_tb(int seed, int n);

/* 4 */
void add_vector_s1_q15(int n, int16_t * dst, int16_t * src1, int16_t * src2);
void add_vector_s1_q15_ref(int n, int16_t * dst, int16_t * src1, int16_t * src2);
void add_vector_s1_q15_fast(int n, int16_t * dst, int16_t * src1, int16_t * src2);
void add_vector_s1_q15_tb(int seed, int n);

/* 5 */
void mul_vector_s15_q15(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_s15_q15_ref(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_s15_q15_fast(int n, int16_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_s15_q15_tb(int seed, int n);

/* 6 */
void mul_vector_a_q15(int n, int32_t *dst, int16_t *src1, int16_t *src2);
void mul_vector_a_q15_ref(int n, int32_t * dst, int16_t * src1, int16_t * src2);
void mul_vector_a_q15_fast(int n, int32_t * dst, int16_t * src1, int16_t * src2);
void mul_vector_a_q15_tb(int seed, int num_tests);

/* Свёртка */
// void convolution (int_fast16_t m, int_fast16_t n, int16_t * dst, int16_t * src1, int16_t * src2);

void random_vector(int_fast16_t n, int16_t * v);
void copy_vector(int n, int16_t *src, int16_t *dst);

extern clock_t total_time_ref;
extern clock_t total_time_fast;
extern int total_errors;

#endif /* DSP_LECTURE_H */
