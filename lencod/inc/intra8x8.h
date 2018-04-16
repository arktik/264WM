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
 * \file intra8x8.h
 *
 * \brief
*    prototypes of 8x8 intra prediction
  *
 * \date
 *    5. February 2009
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *    Alexis Michael Tourapis
 **************************************************************************/

#ifndef _INTRA8X8_H_
#define _INTRA8X8_H_

extern void set_intrapred_8x8_mbaff (Macroblock *currMB, ColorPlane pl, int img_x,int img_y, int *left_available, int *up_available, int *up_left_available);
extern void set_intrapred_8x8       (Macroblock *currMB, ColorPlane pl, int img_x,int img_y, int *left_available, int *up_available, int *up_left_available);
extern void get_intrapred_8x8       (Macroblock *currMB, ColorPlane pl, int i8x8_mode, int left_available, int up_available);
extern void LowPassForIntra8x8Pred  (imgpel *PredPel, int block_up_left, int block_up, int block_left);

extern void generate_pred_error_8x8 (imgpel **cur_img, imgpel **prd_img, imgpel **cur_prd, int **mb_rres, int pic_opix_x, int block_x);

#endif //_TRANSFORM8X8_H_
