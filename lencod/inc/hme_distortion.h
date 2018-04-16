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
 *    hme_distortion.h
 *
 * \author
 *    Yuwen He                       
 *    Alexis Michael Tourapis       
 *
 * \date
 *    11. August 2006 / Updated 18. December 2013
 *
 * \brief
 *    Headerfile for motion estimation distortion
 **************************************************************************
 */

#ifndef _HME_DISTORTION_H_
#define _HME_DISTORTION_H_


//only use integer pel reference frame memory;
static inline imgpel *UMVLine4X_int_hme(StorablePicture *ref, MEBlock *mv_block, int y, int x)
{
    return &(ref->pHmeImage[mv_block->hme_level][iClip3(-IMG_PAD_SIZE_Y, mv_block->hme_ref_size_y_max, y >> 2)][iClip3(-IMG_PAD_SIZE_X, mv_block->hme_ref_size_x_max, x >> 2)]);
}


// SAD functions

extern distblk computeSAD_hme(StorablePicture *ref1, MEBlock*, distblk, MotionVector *);


#endif
