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
* \file quantChroma.h
*
* \brief
*    Quantization process for chroma header file
*
* \author
*    Limin Liu                       <lliu@dolby.com>
*    Alexis Michael Tourapis         <alexismt@ieee.org>                
*
************************************************************************
*/

#ifndef _QUANT_CR_H_
#define _QUANT_CR_H_

extern void init_quant_Chroma(Slice *currSlice);

extern int quant_dc2x2_normal (Macroblock *currMB, int **tblock, int qp, int* DCLevel, int* DCRun, 
                               LevelQuantParams *q_params_4x4, int **fadjust2x2, const byte (*pos_scan)[2]);

extern int quant_dc2x2_around (Macroblock *currMB, int **tblock, int qp, int* DCLevel, int* DCRun, 
                               LevelQuantParams *q_params_4x4, int **fadjust2x2, const byte (*pos_scan)[2]);

extern int quant_dc2x2_trellis(Macroblock *currMB, int **tblock, int qp, int* DCLevel, int* DCRun, 
                               LevelQuantParams *q_params_4x4, int **fadjust, const byte (*pos_scan)[2]);

extern int quant_dc4x2_normal (Macroblock *currMB, int **tblock, int qp, int* DCLevel, int* DCRun, 
                               LevelQuantParams *q_params_4x4, int **fadjust, const byte (*pos_scan)[2]);

extern int quant_dc4x2_around (Macroblock *currMB, int **tblock, int qp, int* DCLevel, int* DCRun, 
                               LevelQuantParams *q_params_4x4,  int **fadjust, const byte (*pos_scan)[2]);

extern int quant_dc4x2_trellis(Macroblock *currMB, int **tblock, int qp, int* DCLevel, int* DCRun, 
                               LevelQuantParams *q_params_4x4, int **fadjust, const byte (*pos_scan)[2]);

extern void rdoq_dc_cr_CAVLC  (Macroblock *currMB, int **tblock, int qp_per, int qp_rem, 
                               LevelQuantParams *q_params_4x4, 
                               const byte (*pos_scan)[2], int levelTrellis[16], int type);

extern void rdoq_dc_cr_CABAC  (Macroblock *currMB, int **tblock, int qp_per, int qp_rem, 
                               LevelQuantParams *q_params_4x4, const byte (*pos_scan)[2], int levelTrellis[16], int type);

#endif

