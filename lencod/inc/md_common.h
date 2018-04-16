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
 *    md_common.h
 *
 * \author
 *    Main contributors (see contributors.h for copyright, address and affiliation details)
 *     - Alexis Michael Tourapis         <alexismt@ieee.org>
 *
 * \date
 *    4. October 2008
 *
 * \brief
 *    Headerfile for common mode functions
 **************************************************************************
 */

#ifndef _MD_COMMON_H_
#define _MD_COMMON_H_
#include "mv_search.h"
#include "me_distortion.h"

extern void SetMotionVectorsMBPSlice (Macroblock* currMB);
extern void SetMotionVectorsMBBSlice (Macroblock* currMB);
extern void SetMotionVectorsMBISlice (Macroblock* currMB);
extern void copy_image_data    (imgpel  **imgBuf1, imgpel  **imgBuf2, int off1, int off2, int width, int height);
extern void copy_image_data_16x16 (imgpel  **imgBuf1, imgpel  **imgBuf2, int off1, int off2);
extern void copy_image_data_8x8   (imgpel  **imgBuf1, imgpel  **imgBuf2, int off1, int off2);
extern void copy_image_data_4x4   (imgpel  **imgBuf1, imgpel  **imgBuf2, int off1, int off2);
extern void ResetRD8x8Data     (VideoParameters *p_Vid, RD_8x8DATA *rd_data);
extern void set_chroma_pred_mode  (Macroblock *currMB, RD_PARAMS enc_mb, int *mb_available, char chroma_pred_mode_range[2]);
#endif

