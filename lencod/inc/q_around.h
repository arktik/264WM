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
 *    q_around.h
 *
 * \author
 *    Alexis Michael Tourapis
 *
 * \brief
 *    Headerfile for Quantization Adaptive Rounding
 **************************************************************************
 */

#ifndef _Q_AROUND_H_
#define _Q_AROUND_H_

extern void update_adaptive_rounding_8x8  (VideoParameters *p_Vid, InputParameters *p_Inp, RD_8x8DATA* dataTr, int**** ARCofAdj);
extern void store_adaptive_rounding_4x4   (VideoParameters *p_Vid, int****ARCofAdj, int mode, int block_y, int block_x);
extern void update_adaptive_rounding_4x4  (VideoParameters *p_Vid, int****ARCofAdj , int mode, int block_y, int block_x);
extern void update_adaptive_rounding_16x16(VideoParameters *p_Vid, int****ARCofAdj , int mode);
extern void store_adaptive_rounding_16x16 (VideoParameters *p_Vid, int****ARCofAdj, int mode);
extern void reset_adaptive_rounding_direct(VideoParameters *p_Vid);
extern void update_offset_params          (Macroblock *currMB, int mode, byte luma_transform_size_8x8_flag);

#endif

