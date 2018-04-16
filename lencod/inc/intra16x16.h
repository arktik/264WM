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
 * \file intra16x16.h
 *
 * \brief
 *    prototypes of 16x16 intra prediction 
 *
 * \date
 *    26 September 2009
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *    Alexis Michael Tourapis
 **************************************************************************/

#ifndef _INTRA16X16_H_
#define _INTRA16X16_H_

extern distblk distI16x16_sad  (Macroblock *currMB, imgpel **img_org, imgpel **pred_img, distblk min_cost);
extern distblk distI16x16_sse  (Macroblock *currMB, imgpel **img_org, imgpel **pred_img, distblk min_cost);
extern distblk distI16x16_satd (Macroblock *currMB, imgpel **img_org, imgpel **pred_img, distblk min_cost);

extern distblk find_sad_16x16_JM      (Macroblock *currMB);

extern void set_intrapred_16x16_mbaff (Macroblock *currMB, ColorPlane pl, int *left_available, int *up_available, int *all_available);
extern void set_intrapred_16x16       (Macroblock *currMB, ColorPlane pl, int *left_available, int *up_available, int *all_available);
extern void get_intrapred_16x16       (Macroblock *currMB, ColorPlane pl, int i16x16_mode, int left_available, int up_available);

#endif //_INTRA16X16_H_
