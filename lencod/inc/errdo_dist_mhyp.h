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
 **************************************************************************
 *  \file errdo_dist_mhyp.h
 *  \brief  
 *    Header file for distortion estimation with multiple decoder based method
 *
 *  \author 
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *    - Zhifeng Chen                     <zzchen@dolby.com>
 *
 **************************************************************************
 */

#ifndef _ERRDO_DIST_MHYP_H_
#define _ERRDO_DIST_MHYP_H_

extern void errdo_store_best_block_multihyp  (InputParameters *p_Inp, imgpel*** mbY, imgpel*** dec_img, int block, int img_i, int img_j, int block_size);
extern void errdo_get_best_block_multihyp    (Macroblock *currMB, imgpel*** dec_img, imgpel*** mbY, int block, int block_size);
extern distblk errdo_distortion_estimation_multihyp(Macroblock *currMB, int block, int block_size, short mode, short pdir, distblk min_rdcost);
extern void copy_conceal_picture    (VideoParameters *p_Vid, StorablePicture *enc_pic, int decoder);
#endif
