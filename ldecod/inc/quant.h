/*
***********************************************************************
* COPYRIGHT AND WARRANTY INFORMATION
*
* Copyright 2001, International Telecommunications Union, Geneva
*
* DISCLAIMER OF WARRANTY
*
* These software programs are available to the user without any
* license fee or royalty on an "as is" basis. The ITU disclaims
* any and all warranties, whether express, implied, or
* statutory, including any implied warranties of merchantability
* or of fitness for a particular purpose.  In no event shall the
* contributor or the ITU be liable for any incidental, punitive, or
* consequential damages of any kind whatsoever arising from the
* use of these programs.
*
* This disclaimer of warranty extends to the user of these programs
* and user's customers, employees, agents, transferees, successors,
* and assigns.
*
* The ITU does not represent or warrant that the programs furnished
* hereunder are free of infringement of any third-party patents.
* Commercial implementations of ITU-T Recommendations, including
* shareware, may be subject to royalty fees to patent holders.
* Information regarding the ITU-T patent policy is available from
* the ITU Web site at http://www.itu.int.
*
* THIS IS NOT A GRANT OF PATENT RIGHTS - SEE THE ITU-T PATENT POLICY.
************************************************************************
*/


/*!
 ************************************************************************
 * \file quant.h
 *
 * \brief
 *    definitions for quantization functions
 *
 * \author
 *
 ************************************************************************
 */

#ifndef _QUANT_H_
#define _QUANT_H_

// exported variables
static const int dequant_coef8[6][8][8] =
{
  {
    {20,  19, 25, 19, 20, 19, 25, 19},
    {19,  18, 24, 18, 19, 18, 24, 18},
    {25,  24, 32, 24, 25, 24, 32, 24},
    {19,  18, 24, 18, 19, 18, 24, 18},
    {20,  19, 25, 19, 20, 19, 25, 19},
    {19,  18, 24, 18, 19, 18, 24, 18},
    {25,  24, 32, 24, 25, 24, 32, 24},
    {19,  18, 24, 18, 19, 18, 24, 18}
  },
  {
    {22,  21, 28, 21, 22, 21, 28, 21},
    {21,  19, 26, 19, 21, 19, 26, 19},
    {28,  26, 35, 26, 28, 26, 35, 26},
    {21,  19, 26, 19, 21, 19, 26, 19},
    {22,  21, 28, 21, 22, 21, 28, 21},
    {21,  19, 26, 19, 21, 19, 26, 19},
    {28,  26, 35, 26, 28, 26, 35, 26},
    {21,  19, 26, 19, 21, 19, 26, 19}
  },
  {
    {26,  24, 33, 24, 26, 24, 33, 24},
    {24,  23, 31, 23, 24, 23, 31, 23},
    {33,  31, 42, 31, 33, 31, 42, 31},
    {24,  23, 31, 23, 24, 23, 31, 23},
    {26,  24, 33, 24, 26, 24, 33, 24},
    {24,  23, 31, 23, 24, 23, 31, 23},
    {33,  31, 42, 31, 33, 31, 42, 31},
    {24,  23, 31, 23, 24, 23, 31, 23}
  },
  {
    {28,  26, 35, 26, 28, 26, 35, 26},
    {26,  25, 33, 25, 26, 25, 33, 25},
    {35,  33, 45, 33, 35, 33, 45, 33},
    {26,  25, 33, 25, 26, 25, 33, 25},
    {28,  26, 35, 26, 28, 26, 35, 26},
    {26,  25, 33, 25, 26, 25, 33, 25},
    {35,  33, 45, 33, 35, 33, 45, 33},
    {26,  25, 33, 25, 26, 25, 33, 25}
  },
  {
    {32,  30, 40, 30, 32, 30, 40, 30},
    {30,  28, 38, 28, 30, 28, 38, 28},
    {40,  38, 51, 38, 40, 38, 51, 38},
    {30,  28, 38, 28, 30, 28, 38, 28},
    {32,  30, 40, 30, 32, 30, 40, 30},
    {30,  28, 38, 28, 30, 28, 38, 28},
    {40,  38, 51, 38, 40, 38, 51, 38},
    {30,  28, 38, 28, 30, 28, 38, 28}
  },
  {
    {36,  34, 46, 34, 36, 34, 46, 34},
    {34,  32, 43, 32, 34, 32, 43, 32},
    {46,  43, 58, 43, 46, 43, 58, 43},
    {34,  32, 43, 32, 34, 32, 43, 32},
    {36,  34, 46, 34, 36, 34, 46, 34},
    {34,  32, 43, 32, 34, 32, 43, 32},
    {46,  43, 58, 43, 46, 43, 58, 43},
    {34,  32, 43, 32, 34, 32, 43, 32}
  }
};


//! Dequantization coefficients
static const int dequant_coef[6][4][4] = {
  {
    { 10, 13, 10, 13},
    { 13, 16, 13, 16},
    { 10, 13, 10, 13},
    { 13, 16, 13, 16}},
  {
    { 11, 14, 11, 14},
    { 14, 18, 14, 18},
    { 11, 14, 11, 14},
    { 14, 18, 14, 18}},
  {
    { 13, 16, 13, 16},
    { 16, 20, 16, 20},
    { 13, 16, 13, 16},
    { 16, 20, 16, 20}},
  {
    { 14, 18, 14, 18},
    { 18, 23, 18, 23},
    { 14, 18, 14, 18},
    { 18, 23, 18, 23}},
  {
    { 16, 20, 16, 20},
    { 20, 25, 20, 25},
    { 16, 20, 16, 20},
    { 20, 25, 20, 25}},
  {
    { 18, 23, 18, 23},
    { 23, 29, 23, 29},
    { 18, 23, 18, 23},
    { 23, 29, 23, 29}}
};

static const int quant_coef[6][4][4] = {
  {
    { 13107,  8066, 13107,  8066},
    {  8066,  5243,  8066,  5243},
    { 13107,  8066, 13107,  8066},
    {  8066,  5243,  8066,  5243}},
  {
    { 11916,  7490, 11916,  7490},
    {  7490,  4660,  7490,  4660},
    { 11916,  7490, 11916,  7490},
    {  7490,  4660,  7490,  4660}},
  {
    { 10082,  6554, 10082,  6554},
    {  6554,  4194,  6554,  4194},
    { 10082,  6554, 10082,  6554},
    {  6554,  4194,  6554,  4194}},
  {
    {  9362,  5825,  9362,  5825},
    {  5825,  3647,  5825,  3647},
    {  9362,  5825,  9362,  5825},
    {  5825,  3647,  5825,  3647}},
  {
    {  8192,  5243,  8192,  5243},
    {  5243,  3355,  5243,  3355},
    {  8192,  5243,  8192,  5243},
    {  5243,  3355,  5243,  3355}},
  {
    {  7282,  4559,  7282,  4559},
    {  4559,  2893,  4559,  2893},
    {  7282,  4559,  7282,  4559},
    {  4559,  2893,  4559,  2893}}
};

// SP decoding parameter (EQ. 8-425)
static const int A[4][4] = {
  { 16, 20, 16, 20},
  { 20, 25, 20, 25},
  { 16, 20, 16, 20},
  { 20, 25, 20, 25}
};

// exported functions
// quantization initialization
extern void init_qp_process (CodingParameters *cps);
extern void free_qp_matrices(CodingParameters *cps);

// For Q-matrix
extern void assign_quant_params   (Slice *currslice);
extern void CalculateQuant4x4Param(Slice *currslice);
extern void CalculateQuant8x8Param(Slice *currslice);

#endif

