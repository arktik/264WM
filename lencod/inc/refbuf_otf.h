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
 * \file refbuf_otf.h
 *
 * \brief
 *    Declarations of the reference frame buffer types and functions for on-the-fly interpolations
 ************************************************************************
 */
#ifndef _REBUF_OTF_H_
#define _REBUF_OTF_H_

#include "mbuffer.h"

static inline imgpel *UMVLine4X_otf (StorablePicture *ref, int y, int x )
{
  return &(ref->p_curr_img_sub[(y & 0x03)>>1][(x & 0x03)>>1][iClip3( -IMG_PAD_SIZE_Y, ref->size_y_pad, y >> 2)][iClip3(-IMG_PAD_SIZE_X, ref->size_x_pad, x >> 2)]);
}

static inline imgpel *UMVLine4Xcr_otf (StorablePicture *ref, int cmp, int y, int x)
{
  return &(ref->p_img_sub[cmp][(y & 0x03)>>1][(x & 0x03)>>1][iClip3(-ref->pad_size_uv_y, ref->size_y_cr_pad, y >> 2)][iClip3(-ref->pad_size_uv_x, ref->size_x_cr_pad, x >> 2)]);
}

static inline imgpel *UMVLine8X_chroma_otf (StorablePicture *ref, int cmp, int y, int x)
{
  return &(ref->p_img_sub[cmp][(y & ref->chroma_mask_mv_y)>>1][(x & ref->chroma_mask_mv_x)>>1][iClip3 (-ref->pad_size_uv_y, ref->size_y_cr_pad, y >> ref->chroma_shift_y)][iClip3 (-ref->pad_size_uv_x, ref->size_x_cr_pad, x >> ref->chroma_shift_x)]);
}


#endif

