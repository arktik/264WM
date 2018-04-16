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
 *************************************************************************************
 * \file lln_mc_prediction.h
 *
 * \brief
 *    definitions for motion compensated prediction
 *
 * \author
 *      Main contributors (see contributors.h for copyright, 
 *                         address and affiliation details)
 *      - Alexis Michael Tourapis  <alexismt@ieee.org>
 *      - Modified for use in hypothetical decoders at encoder
 *           by Peshala V. Pahalawatta <pesh@ieee.org>
 *
 *************************************************************************************
 */

#ifndef _LLN_MC_PREDICTION_H_
#define _LLN_MC_PREDICTION_H_

#include "global.h"
#include "mbuffer.h"


extern void get_block_luma  (Macroblock *currMB, int decoder, ColorPlane pl, StorablePicture *dec_picture, StorablePicture *list, int x_pos, int y_pos, int block_size_y, int block_size_x, imgpel block[MB_BLOCK_SIZE][MB_BLOCK_SIZE]);
extern void get_block_chroma(Macroblock *currMb, int decoder, int uv, StorablePicture *dec_picture, StorablePicture *list, int x_pos, int y_pos, int block_size_x, int block_size_y, imgpel block[MB_BLOCK_SIZE][MB_BLOCK_SIZE]);

//extern void intra_cr_decoding(Macroblock *currMB, int yuv, int smb);
//extern void prepare_direct_params(Macroblock *currMB, StorablePicture *dec_picture, MotionVector *pmvl0, MotionVector *pmvl1,char *l0_rFrame, char *l1_rFrame);

extern void perform_mc            (Macroblock* currMB, int decoder, ColorPlane pl, StorablePicture *dec_picture, int pred_dir, int l0_mode, int l1_mode, PicMotionParams **mv_info, int i, int j, int block_size_x, int block_size_y, short bipred_me);
extern void perform_mc_concealment(Macroblock* currMB, int decoder, ColorPlane pl, StorablePicture *dec_picture, int pred_dir, int l0_mode, int l1_mode, PicMotionParams **mv_info, int i, int j, int block_size_x, int block_size_y);

#endif

