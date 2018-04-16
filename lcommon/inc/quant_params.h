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
 ***************************************************************************
 * \file
 *    quant_params.h
 *
 * \author
 *    Alexis Michael Tourapis
 *
 * \brief
 *    Headerfile for Quantization parameters
 **************************************************************************
 */

#ifndef _QUANT_PARAMS_H_
#define _QUANT_PARAMS_H_

typedef struct level_quant_params {
  int   OffsetComp;
  int    ScaleComp;
  int InvScaleComp;
} LevelQuantParams;

typedef struct quant_params {
  int AdaptRndWeight;
  int AdaptRndCrWeight;

  LevelQuantParams *****q_params_4x4;
  LevelQuantParams *****q_params_8x8;

  int *qp_per_matrix;
  int *qp_rem_matrix;

  short **OffsetList4x4input;
  short **OffsetList8x8input;
  short ***OffsetList4x4;
  short ***OffsetList8x8;
} QuantParameters;

typedef struct quant_methods {
  int   block_y; 
  int   block_x;
  int   qp; 
  int*  ACLevel;
  int*  ACRun;
  int **fadjust; 
  LevelQuantParams **q_params;
  int *coeff_cost;
  const byte (*pos_scan)[2];
  const byte *c_cost;
  char type;
} QuantMethods;

#endif

