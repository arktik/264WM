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
 *    md_distortion.h
 *
 * \author
 *    Alexis Michael Tourapis        <alexis.tourapis@dolby.com>
 *
 * \date
 *    7. February 2009
 *
 * \brief
 *    Headerfile for distortion functions
 **************************************************************************
 */

#ifndef _MD_DISTORTION_H_
#define _MD_DISTORTION_H_

#include "global.h"

// Functions
extern void    setupDistortion (Slice *currSlice);
extern int64   compute_SSE     (imgpel **imgRef, imgpel **imgSrc, int xRef, int xSrc, int ySize, int xSize);
extern distblk compute_SSE_cr  (imgpel **imgRef, imgpel **imgSrc, int xRef, int xSrc, int ySize, int xSize);
extern distblk compute_SSE16x16(imgpel **imgRef, imgpel **imgSrc, int xRef, int xSrc);
extern distblk compute_SSE8x8  (imgpel **imgRef, imgpel **imgSrc, int xRef, int xSrc);
extern distblk compute_SSE4x4  (imgpel **imgRef, imgpel **imgSrc, int xRef, int xSrc);
extern distblk compute_SSE16x16_thres(imgpel **imgRef, imgpel **imgSrc, int xRef, int xSrc, distblk min_cost);

#endif
