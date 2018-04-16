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
* \file quant4x4.h
*
* \brief
*    Quantization process header file
*
* \author
*    Limin Liu                       <lliu@dolby.com>
*    Alexis Michael Tourapis         <alexismt@ieee.org>                
*
************************************************************************
*/

#ifndef _QUANT4x4_H_
#define _QUANT4x4_H_

extern void init_quant_4x4  (Slice *currSlice);

extern int quant_4x4_normal (Macroblock *currMB, int **tblock, struct quant_methods *q_method);
extern int quant_4x4_around (Macroblock *currMB, int **tblock, struct quant_methods *q_method);
extern int quant_4x4_trellis(Macroblock *currMB, int **tblock, struct quant_methods *q_method);
extern int quant_dc4x4_normal (Macroblock *currMB, int **tblock, int qp, int* DCLevel, int* DCRun, 
                               LevelQuantParams *q_params_4x4, const byte (*pos_scan)[2]);

extern int quant_dc4x4_around (Macroblock *currMB, int **tblock, int qp, int* DCLevel, int* DCRun, 
                               LevelQuantParams *q_params_4x4, const byte (*pos_scan)[2]);

extern int quant_dc4x4_trellis(Macroblock *currMB, int **tblock, int qp, int* DCLevel, int* DCRun, 
                               LevelQuantParams *q_params_4x4, const byte (*pos_scan)[2]);

extern int quant_ac4x4_normal (Macroblock *currMB, int **tblock, struct quant_methods *q_method);
extern int quant_ac4x4_around (Macroblock *currMB, int **tblock, struct quant_methods *q_method);
extern int quant_ac4x4_trellis(Macroblock *currMB, int **tblock, struct quant_methods *q_method);

extern void rdoq_4x4_CAVLC    (Macroblock *currMB, int **tblock, struct quant_methods *q_method, int levelTrellis[16]);

extern void rdoq_4x4_CABAC    (Macroblock *currMB, int **tblock, struct quant_methods *q_method, int levelTrellis[16]);

extern void rdoq_dc_CAVLC     (Macroblock *currMB, int **tblock, int qp_per, int qp_rem, LevelQuantParams *q_params_4x4, 
                               const byte (*pos_scan)[2], int levelTrellis[16], int type);

extern void rdoq_dc_CABAC     (Macroblock *currMB, int **tblock, int qp_per, int qp_rem, LevelQuantParams *q_params_4x4, 
                               const byte (*pos_scan)[2], int levelTrellis[16], int type);

extern void rdoq_ac4x4_CAVLC  (Macroblock *currMB, int **tblock, struct quant_methods *q_method, int levelTrellis[16]);

extern void rdoq_ac4x4_CABAC  (Macroblock *currMB, int **tblock , struct quant_methods *q_method, int levelTrellis[16]);


#endif

