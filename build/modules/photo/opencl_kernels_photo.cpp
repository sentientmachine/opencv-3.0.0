// This file is auto-generated. Do not edit!

#include "precomp.hpp"
#include "opencl_kernels_photo.hpp"

namespace cv
{
namespace ocl
{
namespace photo
{

const struct ProgramEntry nlmeans={"nlmeans",
"#ifdef cl_amd_printf\n"
"#pragma OPENCL_EXTENSION cl_amd_printf:enable\n"
"#endif\n"
"#ifdef DOUBLE_SUPPORT\n"
"#ifdef cl_amd_fp64\n"
"#pragma OPENCL EXTENSION cl_amd_fp64:enable\n"
"#elif defined cl_khr_fp64\n"
"#pragma OPENCL EXTENSION cl_khr_fp64:enable\n"
"#endif\n"
"#endif\n"
"#ifdef OP_CALC_WEIGHTS\n"
"__kernel void calcAlmostDist2Weight(__global int * almostDist2Weight, int almostMaxDist,\n"
"FT almostDist2ActualDistMultiplier, int fixedPointMult,\n"
"FT den, FT WEIGHT_THRESHOLD)\n"
"{\n"
"int almostDist = get_global_id(0);\n"
"if (almostDist < almostMaxDist)\n"
"{\n"
"FT dist = almostDist * almostDist2ActualDistMultiplier;\n"
"int weight = convert_int_sat_rte(fixedPointMult * exp(-dist * den));\n"
"if (weight < WEIGHT_THRESHOLD * fixedPointMult)\n"
"weight = 0;\n"
"almostDist2Weight[almostDist] = weight;\n"
"}\n"
"}\n"
"#elif defined OP_CALC_FASTNLMEANS\n"
"#define noconvert\n"
"#define SEARCH_SIZE_SQ (SEARCH_SIZE * SEARCH_SIZE)\n"
"inline int calcDist(uchar_t a, uchar_t b)\n"
"{\n"
"int_t diff = convert_int_t(a) - convert_int_t(b);\n"
"int_t retval = diff * diff;\n"
"#if cn == 1\n"
"return retval;\n"
"#elif cn == 2\n"
"return retval.x + retval.y;\n"
"#else\n"
"#error \"cn should be either 1 or 2\"\n"
"#endif\n"
"}\n"
"inline int calcDistUpDown(uchar_t down_value, uchar_t down_value_t, uchar_t up_value, uchar_t up_value_t)\n"
"{\n"
"int_t A = convert_int_t(down_value) - convert_int_t(down_value_t);\n"
"int_t B = convert_int_t(up_value) - convert_int_t(up_value_t);\n"
"int_t retval = (A - B) * (A + B);\n"
"#if cn == 1\n"
"return retval;\n"
"#elif cn == 2\n"
"return retval.x + retval.y;\n"
"#else\n"
"#error \"cn should be either 1 or 2\"\n"
"#endif\n"
"}\n"
"#define COND if (x == 0 && y == 0)\n"
"inline void calcFirstElementInRow(__global const uchar * src, int src_step, int src_offset,\n"
"__local int * dists, int y, int x, int id,\n"
"__global int * col_dists, __global int * up_col_dists)\n"
"{\n"
"y -= TEMPLATE_SIZE2;\n"
"int sx = x - SEARCH_SIZE2, sy = y - SEARCH_SIZE2;\n"
"int col_dists_current_private[TEMPLATE_SIZE];\n"
"for (int i = id; i < SEARCH_SIZE_SQ; i += CTA_SIZE)\n"
"{\n"
"int dist = 0, value;\n"
"__global const uchar_t * src_template = (__global const uchar_t *)(src +\n"
"mad24(sy + i / SEARCH_SIZE, src_step, mad24(cn, sx + i % SEARCH_SIZE, src_offset)));\n"
"__global const uchar_t * src_current = (__global const uchar_t *)(src + mad24(y, src_step, mad24(cn, x, src_offset)));\n"
"__global int * col_dists_current = col_dists + i * TEMPLATE_SIZE;\n"
"#pragma unroll\n"
"for (int j = 0; j < TEMPLATE_SIZE; ++j)\n"
"col_dists_current_private[j] = 0;\n"
"for (int ty = 0; ty < TEMPLATE_SIZE; ++ty)\n"
"{\n"
"#pragma unroll\n"
"for (int tx = -TEMPLATE_SIZE2; tx <= TEMPLATE_SIZE2; ++tx)\n"
"{\n"
"value = calcDist(src_template[tx], src_current[tx]);\n"
"col_dists_current_private[tx + TEMPLATE_SIZE2] += value;\n"
"dist += value;\n"
"}\n"
"src_current = (__global const uchar_t *)((__global const uchar *)src_current + src_step);\n"
"src_template = (__global const uchar_t *)((__global const uchar *)src_template + src_step);\n"
"}\n"
"#pragma unroll\n"
"for (int j = 0; j < TEMPLATE_SIZE; ++j)\n"
"col_dists_current[j] = col_dists_current_private[j];\n"
"dists[i] = dist;\n"
"up_col_dists[0 + i] = col_dists[TEMPLATE_SIZE - 1];\n"
"}\n"
"}\n"
"inline void calcElementInFirstRow(__global const uchar * src, int src_step, int src_offset,\n"
"__local int * dists, int y, int x0, int x, int id, int first,\n"
"__global int * col_dists, __global int * up_col_dists)\n"
"{\n"
"x += TEMPLATE_SIZE2;\n"
"y -= TEMPLATE_SIZE2;\n"
"int sx = x - SEARCH_SIZE2, sy = y - SEARCH_SIZE2;\n"
"for (int i = id; i < SEARCH_SIZE_SQ; i += CTA_SIZE)\n"
"{\n"
"__global const uchar_t * src_current = (__global const uchar_t *)(src + mad24(y, src_step, mad24(cn, x, src_offset)));\n"
"__global const uchar_t * src_template = (__global const uchar_t *)(src +\n"
"mad24(sy + i / SEARCH_SIZE, src_step, mad24(cn, sx + i % SEARCH_SIZE, src_offset)));\n"
"__global int * col_dists_current = col_dists + TEMPLATE_SIZE * i;\n"
"int col_dist = 0;\n"
"#pragma unroll\n"
"for (int ty = 0; ty < TEMPLATE_SIZE; ++ty)\n"
"{\n"
"col_dist += calcDist(src_current[0], src_template[0]);\n"
"src_current = (__global const uchar_t *)((__global const uchar *)src_current + src_step);\n"
"src_template = (__global const uchar_t *)((__global const uchar *)src_template + src_step);\n"
"}\n"
"dists[i] += col_dist - col_dists_current[first];\n"
"col_dists_current[first] = col_dist;\n"
"up_col_dists[mad24(x0, SEARCH_SIZE_SQ, i)] = col_dist;\n"
"}\n"
"}\n"
"inline void calcElement(__global const uchar * src, int src_step, int src_offset,\n"
"__local int * dists, int y, int x0, int x, int id, int first,\n"
"__global int * col_dists, __global int * up_col_dists)\n"
"{\n"
"int sx = x + TEMPLATE_SIZE2;\n"
"int sy_up = y - TEMPLATE_SIZE2 - 1;\n"
"int sy_down = y + TEMPLATE_SIZE2;\n"
"uchar_t up_value = *(__global const uchar_t *)(src + mad24(sy_up, src_step, mad24(cn, sx, src_offset)));\n"
"uchar_t down_value = *(__global const uchar_t *)(src + mad24(sy_down, src_step, mad24(cn, sx, src_offset)));\n"
"sx -= SEARCH_SIZE2;\n"
"sy_up -= SEARCH_SIZE2;\n"
"sy_down -= SEARCH_SIZE2;\n"
"for (int i = id; i < SEARCH_SIZE_SQ; i += CTA_SIZE)\n"
"{\n"
"int wx = i % SEARCH_SIZE, wy = i / SEARCH_SIZE;\n"
"uchar_t up_value_t = *(__global const uchar_t *)(src + mad24(sy_up + wy, src_step, mad24(cn, sx + wx, src_offset)));\n"
"uchar_t down_value_t = *(__global const uchar_t *)(src + mad24(sy_down + wy, src_step, mad24(cn, sx + wx, src_offset)));\n"
"__global int * col_dists_current = col_dists + mad24(i, TEMPLATE_SIZE, first);\n"
"__global int * up_col_dists_current = up_col_dists + mad24(x0, SEARCH_SIZE_SQ, i);\n"
"int col_dist = up_col_dists_current[0] + calcDistUpDown(down_value, down_value_t, up_value, up_value_t);\n"
"dists[i] += col_dist - col_dists_current[0];\n"
"col_dists_current[0] = col_dist;\n"
"up_col_dists_current[0] = col_dist;\n"
"}\n"
"}\n"
"inline void convolveWindow(__global const uchar * src, int src_step, int src_offset,\n"
"__local int * dists, __global const int * almostDist2Weight,\n"
"__global uchar * dst, int dst_step, int dst_offset,\n"
"int y, int x, int id, __local int * weights_local,\n"
"__local int_t * weighted_sum_local, int almostTemplateWindowSizeSqBinShift)\n"
"{\n"
"int sx = x - SEARCH_SIZE2, sy = y - SEARCH_SIZE2, weights = 0;\n"
"int_t weighted_sum = (int_t)(0);\n"
"for (int i = id; i < SEARCH_SIZE_SQ; i += CTA_SIZE)\n"
"{\n"
"int src_index = mad24(sy + i / SEARCH_SIZE, src_step, mad24(i % SEARCH_SIZE + sx, cn, src_offset));\n"
"int_t src_value = convert_int_t(*(__global const uchar_t *)(src + src_index));\n"
"int almostAvgDist = dists[i] >> almostTemplateWindowSizeSqBinShift;\n"
"int weight = almostDist2Weight[almostAvgDist];\n"
"weights += weight;\n"
"weighted_sum += (int_t)(weight) * src_value;\n"
"}\n"
"weights_local[id] = weights;\n"
"weighted_sum_local[id] = weighted_sum;\n"
"barrier(CLK_LOCAL_MEM_FENCE);\n"
"for (int lsize = CTA_SIZE >> 1; lsize > 2; lsize >>= 1)\n"
"{\n"
"if (id < lsize)\n"
"{\n"
"int id2 = lsize + id;\n"
"weights_local[id] += weights_local[id2];\n"
"weighted_sum_local[id] += weighted_sum_local[id2];\n"
"}\n"
"barrier(CLK_LOCAL_MEM_FENCE);\n"
"}\n"
"if (id == 0)\n"
"{\n"
"int dst_index = mad24(y, dst_step, mad24(cn, x, dst_offset));\n"
"int_t weighted_sum_local_0 = weighted_sum_local[0] + weighted_sum_local[1] +\n"
"weighted_sum_local[2] + weighted_sum_local[3];\n"
"int weights_local_0 = weights_local[0] + weights_local[1] + weights_local[2] + weights_local[3];\n"
"*(__global uchar_t *)(dst + dst_index) = convert_uchar_t(weighted_sum_local_0 / (int_t)(weights_local_0));\n"
"}\n"
"}\n"
"__kernel void fastNlMeansDenoising(__global const uchar * src, int src_step, int src_offset,\n"
"__global uchar * dst, int dst_step, int dst_offset, int dst_rows, int dst_cols,\n"
"__global const int * almostDist2Weight, __global uchar * buffer,\n"
"int almostTemplateWindowSizeSqBinShift)\n"
"{\n"
"int block_x = get_group_id(0), nblocks_x = get_num_groups(0);\n"
"int block_y = get_group_id(1);\n"
"int id = get_local_id(0), first;\n"
"__local int dists[SEARCH_SIZE_SQ], weights[CTA_SIZE];\n"
"__local int_t weighted_sum[CTA_SIZE];\n"
"int x0 = block_x * BLOCK_COLS, x1 = min(x0 + BLOCK_COLS, dst_cols);\n"
"int y0 = block_y * BLOCK_ROWS, y1 = min(y0 + BLOCK_ROWS, dst_rows);\n"
"int block_data_start = SEARCH_SIZE_SQ * (mad24(block_y, dst_cols, x0) + mad24(block_y, nblocks_x, block_x) * TEMPLATE_SIZE);\n"
"__global int * col_dists = (__global int *)(buffer + block_data_start * sizeof(int));\n"
"__global int * up_col_dists = col_dists + SEARCH_SIZE_SQ * TEMPLATE_SIZE;\n"
"for (int y = y0; y < y1; ++y)\n"
"for (int x = x0; x < x1; ++x)\n"
"{\n"
"if (x == x0)\n"
"{\n"
"calcFirstElementInRow(src, src_step, src_offset, dists, y, x, id, col_dists, up_col_dists);\n"
"first = 0;\n"
"}\n"
"else\n"
"{\n"
"if (y == y0)\n"
"calcElementInFirstRow(src, src_step, src_offset, dists, y, x - x0, x, id, first, col_dists, up_col_dists);\n"
"else\n"
"calcElement(src, src_step, src_offset, dists, y, x - x0, x, id, first, col_dists, up_col_dists);\n"
"first = (first + 1) % TEMPLATE_SIZE;\n"
"}\n"
"convolveWindow(src, src_step, src_offset, dists, almostDist2Weight, dst, dst_step, dst_offset,\n"
"y, x, id, weights, weighted_sum, almostTemplateWindowSizeSqBinShift);\n"
"}\n"
"}\n"
"#endif\n"
, "c6b1fc1036cafc971f6462594875add4"};
ProgramSource nlmeans_oclsrc(nlmeans.programStr);
}
}}
