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
 * \file refbuf.h
 *
 * \brief
 *    Declarations of the reference frame buffer types and functions
 ************************************************************************
 */
#ifndef _REBUF_H_
#define _REBUF_H_

#include "mbuffer.h"

/*!
 ************************************************************************
 * \brief
 *    Yields a pel line _pointer_ from one of the 16 sub-images
 *    Input does not require subpixel image indices
 ************************************************************************
 */
static inline imgpel *UMVLine4X (StorablePicture *ref, int y, int x)
{
  //return &(ref->p_curr_img_sub[(y & 0x03)][(x & 0x03)][iClip3( 0, ref->size_y_pad, y >> 2)][iClip3( 0, ref->size_x_pad, x >> 2)]);
  return &(ref->p_curr_img_sub[(y & 0x03)][(x & 0x03)][iClip3( -IMG_PAD_SIZE_Y, ref->size_y_pad, y >> 2)][iClip3(-IMG_PAD_SIZE_X, ref->size_x_pad, x >> 2)]);
}

/*!
 ************************************************************************
 * \brief
 *    Yields a pel line _pointer_ from one of the 16 sub-images
 *    Input does not require subpixel image indices
 ************************************************************************
 */
static inline imgpel *UMVLine4Xcr (StorablePicture *ref, int cmp, int y, int x)
{
  //return &(ref->p_img_sub[cmp][(y & 0x03)][(x & 0x03)][iClip3( 0, ref->size_y_cr_pad, y >> 2)][iClip3( 0, ref->size_x_cr_pad, x >> 2)]);
  return &(ref->p_img_sub[cmp][(y & 0x03)][(x & 0x03)][iClip3(-ref->pad_size_uv_y, ref->size_y_cr_pad, y >> 2)][iClip3(-ref->pad_size_uv_x, ref->size_x_cr_pad, x >> 2)]);
}

/*!
 ************************************************************************
 * \brief
 *    Yields a pel line _pointer_ from one of the 16 sub-images
 *    Input does not require subpixel image indices
 ************************************************************************
 */
static inline imgpel *FastLine4X (StorablePicture *ref, int y, int x)
{
  return &(ref->p_curr_img_sub[(y & 0x03)][(x & 0x03)][y >> 2][x >> 2]);
}

/*!
 ************************************************************************
 * \brief
 *    Yields a pel line _pointer_ from one of the 16 (4:4:4), 32 (4:2:2),
 *    or 64 (4:2:0) sub-images
 *    Input does not require subpixel image indices
 ************************************************************************
 */
static inline imgpel *UMVLine8X_chroma (StorablePicture *ref, int cmp, int y, int x)
{
  //return &(ref->p_img_sub[cmp][y & ref->chroma_mask_mv_y][x & ref->chroma_mask_mv_x][iClip3 (0, ref->size_y_cr_pad, y >> ref->chroma_shift_y)][iClip3 (0, ref->size_x_cr_pad, x >> ref->chroma_shift_x)]);
  return &(ref->p_img_sub[cmp][y & ref->chroma_mask_mv_y][x & ref->chroma_mask_mv_x][iClip3 (-ref->pad_size_uv_y, ref->size_y_cr_pad, y >> ref->chroma_shift_y)][iClip3 (-ref->pad_size_uv_x, ref->size_x_cr_pad, x >> ref->chroma_shift_x)]);
}

/*!
 ************************************************************************
 * \brief
 *    Yields a pel line _pointer_ from one of the 16 (4:4:4), 32 (4:2:2),
 *    or 64 (4:2:0) sub-images
 *    Input does not require subpixel image indices
 ************************************************************************
 */
static inline imgpel *FastLine8X_chroma (StorablePicture *ref, int cmp, int y, int x)
{
  return &(ref->p_img_sub[cmp][y & ref->chroma_mask_mv_y][x & ref->chroma_mask_mv_x][y >> ref->chroma_shift_y][x >> ref->chroma_shift_x]);
}


#endif

