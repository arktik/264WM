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
 *
 * \file transform8x8.h
 *
 * \brief
 *    prototypes of 8x8 transform functions
 *
 * \date
 *    9. October 2003
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *    Yuri Vatis
 **************************************************************************/

#ifndef _TRANSFORM8X8_H_
#define _TRANSFORM8X8_H_
extern int     mode_decision_for_I8x8_MB               (Macroblock *currMB, int lambda, distblk *min_cost);
extern int     mode_decision_for_I8x8_blocks_JM_Low    (Macroblock *currMB, int b8, int lambda, distblk *min_cost);
extern int     mode_decision_for_I8x8_blocks_JM_High   (Macroblock *currMB, int b8, int lambda, distblk *min_cost);
extern int     mode_decision_for_I8x8_blocks_JM_Low444 (Macroblock *currMB, int b8, int lambda, distblk *min_cost);
extern int     mode_decision_for_I8x8_blocks_JM_High444(Macroblock *currMB, int b8, int lambda, distblk *min_cost);

extern distblk rdcost_for_8x8_intra_blocks             (Macroblock *currMB, int *c_nz, int b8, int ipmode, int lambda, distblk min_rdcost, int mostProbableMode);
extern distblk rdcost_for_8x8_intra_blocks_444         (Macroblock *currMB, int *c_nz, int b8, int ipmode, int lambda, distblk min_rdcost, int mostProbableMode);
extern distblk compute_satd8x8_cost                    (VideoParameters *p_Vid, imgpel **cur_img, imgpel **mpr8x8, int pic_opix_x, distblk min_cost);
extern distblk compute_sse8x8_cost                     (VideoParameters *p_Vid, imgpel **cur_img, imgpel **mpr8x8, int pic_opix_x, distblk min_cost);
extern distblk compute_sad8x8_cost                     (VideoParameters *p_Vid, imgpel **cur_img, imgpel **mpr8x8, int pic_opix_x, distblk min_cost);
extern distblk compute_comp8x8_cost                    (VideoParameters *p_Vid, imgpel **cur_img, imgpel **mpr8x8, int pic_opix_x, distblk min_cost);

extern int     residual_transform_quant_luma_8x8       (Macroblock *currMB, ColorPlane pl, int b8, int *coeff_cost, int intra);
extern int     residual_transform_quant_luma_8x8_cavlc (Macroblock *currMB, ColorPlane pl, int b8, int *coeff_cost, int intra);
extern int     residual_transform_quant_luma_8x8_ls    (Macroblock *currMB, ColorPlane pl, int b8, int *coeff_cost, int intra);

#endif //_TRANSFORM8X8_H_
