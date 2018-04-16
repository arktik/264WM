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
 * \file intra_pred_common.c
 *
 * \brief
 *    functions for setting up intra prediction modes
 *
 * \author
 *      Main contributors (see contributors.h for copyright, 
 *                         address and affiliation details)
 *      - Alexis Michael Tourapis  <alexismt@ieee.org>
 *
 *************************************************************************************
 */
#include "global.h"
#include "intra4x4_pred.h"
#include "intra8x8_pred.h"
#include "intra16x16_pred.h"
#include "mb_access.h"
#include "image.h"


extern void intra_pred_chroma      (Macroblock *currMB);
extern void intra_pred_chroma_mbaff(Macroblock *currMB);


void set_intra_prediction_modes(Slice *currSlice)
{ 
  if (currSlice->mb_aff_frame_flag)
  {
    currSlice->intra_pred_4x4    = intra_pred_4x4_mbaff;
    currSlice->intra_pred_8x8    = intra_pred_8x8_mbaff;
    currSlice->intra_pred_16x16  = intra_pred_16x16_mbaff;    
    currSlice->intra_pred_chroma = intra_pred_chroma_mbaff;
  }
  else
  {
    currSlice->intra_pred_4x4    = intra_pred_4x4_normal;  
    currSlice->intra_pred_8x8    = intra_pred_8x8_normal;
    currSlice->intra_pred_16x16  = intra_pred_16x16_normal;
    currSlice->intra_pred_chroma = intra_pred_chroma;   
  }
}
