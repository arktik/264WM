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
 *    wp.h
 *
 * \author
 *    Alexis Michael Tourapis
 *
 * \date
 *    22. February 2008
 *
 * \brief
 *    Headerfile for weighted prediction support
 **************************************************************************
 */

#ifndef _WP_H_
#define _WP_H_

#include "wp_lms.h"
#include "wp_mcprec.h"
#include "wp_mciter.h"
#include "wp_random.h"
#include "wp_periodic.h"

#define DEBUG_WP  0

void InitWP              (VideoParameters *p_Vid, InputParameters *p_Inp, int force_wp_method);
void ResetWP             (VideoParameters *p_Vid, InputParameters *p_Inp);

extern void   EstimateWPBSliceAlg0   (Slice *currSlice);
extern void   EstimateWPPSliceAlg0   (Slice *currSlice, int offset);
extern int    TestWPPSliceAlg0       (Slice *currSlice, int offset);
extern int    TestWPBSliceAlg0       (Slice *currSlice, int method);
extern double ComputeImgSum          (imgpel **CurrentImage, int height, int width);
extern void   ComputeImgSumBlockBased(imgpel **CurrentImage, int height_in_blk, int width_in_blk, int blk_size_y, int blk_size_x, int start_blk, int end_blk, double *dc);
extern int64  ComputeSumBlockBased   (imgpel **CurrentImage, int height_in_blk, int width_in_blk, int blk_size_y, int blk_size_x, int start_blk, int end_blk);

extern void   ComputeImplicitWeights    (Slice *currSlice,
                                         short default_weight[3],
                                         short im_weight[6][MAX_REFERENCE_PICTURES][MAX_REFERENCE_PICTURES][3]);

#endif

